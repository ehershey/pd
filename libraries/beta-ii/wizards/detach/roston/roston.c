#include <std.h>
inherit ROOM;

void create() {
   object oi;
   ::create();
   set_name("Roston Square.c");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));      
   set_properties((["light":2, "night light":3]));
   set_short("Roston Square");
   set_long("Roston Square is the meeting place of the dwarven hunters. "
            "You seem to be surrounded by snow covered mountains, to "
            "the west you can hear sounds of banging metal, the scent "
            "of leather comes from the south, there seems to "
            "be a large building to the north");
     
   set_exits( ([ "north" : "/wizards/detach/roston/roston2",
              "south" : "/wizards/detach/roston/roston3",
              "west"  : "/wizards/detach/roston/roston11",
"east":"/wizards/detach/roston/roston12" ]));
    oi = new("/std/bboard");
    oi->set_name("roston board");
    oi->set_id( ({ "board", "town board", "roston board" }) );
    oi->set_board_id("roston_board");
    oi->set_max_posts(100);
    oi->set_location("/wizards/detach/roston/roston");
    oi->set("short", "Roston Town Board");
    oi->set("long", "This board is for adventurers of Roston");
}

void reset() {
     if(!present("statue"))
        new("/wizards/detach/roston/statue")->move(this_object());
}                                              
    
