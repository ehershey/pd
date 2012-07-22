#include <std.h>
#include <id4.h>
#include <dragonevent.h>
inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
    set_smell("default", "The tunnel has a smokey, burning smell to it.");
    set_listen("default", "The bubbling of lava can be heard throughout the tunnels.");
    set_short("venturing through tunnels");
    set_long("The molten tunnels steer in many directions, leading to nowhere in a %^RED%^%^BOLD%^heated %^RESET%^daze. The air is composed of a stiffling mixture of heat and sulfur. Heat and smoke makes traveling the tunnels dangerous. The bubbling of %^RED%^l%^BOLD%^a%^YELLOW%^v%^RED%^a%^RESET%^ echoes off the walls. All of the air seems to vibrate in the waves of heat.");
    set_items(([
	"lava" : "There is a pool of lava on either side of you.",
	"smoke" : "Wisps of smoke float through the air..",
	"ground" : "The ground beneath you is a very hot looking rock path, surrounded by pools of lava..",
	({"rock", "rocks"}) : "The path below you is made of rocks..",
      ]));
    set_exits(([ "east" : ROOMS "/moltenlava/2.c",
	"southeast" : ROOMS "/moltenlava/4.c"]));
}

void reset() {
    object ob;
    ::reset();
    if (!present("ogre")) {
	new(MOBS+"ogremage")->move(this_object());
    }
/*
    ob = new("/wizards/daos/obj/red");
    if(ob) ob->move(this_object());
*/
    if(!DRAG_D->query_data("denyOldCaveEntrance")) {
      if(!present("portal")) {
        ob = new(ID4BASE+"items/blue");
        ob->set_destination(DRAG_ROOMS"py/daroqscave");
        ob->move(this_object());
      }
    }
}


void init() {
  ::init();
  if(present("portal") && DRAG_D->query_data("denyOldCaveEntrance"))
    present("portal")->remove();
}