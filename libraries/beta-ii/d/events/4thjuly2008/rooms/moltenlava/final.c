#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 1, "no teleport" : 1, "no teleport" : 1, "night light" : 1]) );
    set_smell("default", "The tunnel has a smokey, burning smell to it.");
    set_listen("default", "The bubbling of lava can be heard throughout the tunnels.");
    set_short("a flame-filled cavern");
    set_long("The heat here is really intense. A huge fire ball takes up most of the "
      "cavern. Some of the rocks are melting into lava around it. A crack in one wall "
      "lets in more lava. Every surface is scalding hot.");
    set_items(([
	"lava" : "There is a pool of lava on either side of you.",
	"smoke" : "Wisps of smoke float through the air..",
	"ground" : "The ground beneath you is a very hot looking rock path, surrounded by pools of lava..",
	({"rock", "rocks"}) : "The path below you is made of rocks..",
      ]));
    set_exits(([
	"south" : ROOMS "/moltenlava/33.c"]));
    set_no_clean(1);
}

void reset() {
    object ob;
    ::reset();
    /*
  if (!present("flames") && !query_property("finished_quest")) {
  new(ITEMS+"flames")->move(this_object());
  }
  */
    if (!present("white portal")) {
	ob = new("/d/events/4thjuly2008/items/white");
	ob->set_destination("/d/events/4thjuly2008/rooms/icystuff/1");
	ob->move(this_object());
    }
}

