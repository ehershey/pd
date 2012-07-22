#include <std.h>
inherit ROOM;

void create() {
   object oi;
   ::create();
   set_name("Vik Square.c");
   set_properties((["light":2, "night light":3]));
   set_short("Vik Square");
   set_long("This is the center of the Viking community Vik. "
            "Here Vikings meet and consult on their everlasting "
            "quest of terror.");     
   set_exits( ([ "south" : "/wizards/marduk/vik/vik2",
              "east" : "/wizards/marduk/vik/vik3",
              "west"  : "/wizards/marduk/vik/vik4" ]));
    oi = new("/std/bboard");
    oi->set_name("Vik board");
    oi->set_id( ({ "board", "town board", "vik board" }) );
    oi->set_board_id("vik_board");
    oi->set_max_posts(100);
    oi->set_location("/wizards/marduk/vik/vik");
    oi->set("short", "Vik Board");
    oi->set("long", "This board was created for the people of Vik");
}

void reset() {
  ::reset();
    if(!present("human"))
        new("/wizards/marduk/vik/beggar.c")->move(this_object());
}
