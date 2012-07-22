#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    object oi;
    ::create();
    set_name("Roston Square.c");
    set_items((["snow"   : "A very deep white snow",
	"dirt"  : "A light brown mixture"]));      
    set_properties((["light" : 2, "night light" : 3, "no attack" : 1, "no magic" : 1, "no bump" : 1, "no steal" : 1]));
    set_short("Roston Square");
    set_long("Roston Square is the meeting place of the dwarven hunters. "
      "You seem to be surrounded by snow covered mountains, to "
      "the west you can hear sounds of banging metal, the scent "
      "of leather comes from the south, there seems to "
      "be a large building to the north");

    set_exits( ([ "north" : ROOMS "roston2",
	"south" : ROOMS "roston3",
	"west"  : ROOMS "roston11",
	"east"  : ROOMS "roston12" ]));
    oi = new("/std/bboard");
    oi->set_name("roston board");
    oi->set_id( ({ "board", "town board", "roston board" }) );
    oi->set_board_id("roston_board");
    oi->set_max_posts(100);
    oi->set_location(ROOMS "roston");
    oi->set("short", "Roston Town Board");
    oi->set("long", "This board is for adventurers of Roston");
}

void reset() {
    if(!present("statue"))
	new(OBJ "statue")->move(this_object());
    if(!present("monster"))
	new(MOB "guard")->move(this_object());
} 
