#include <std.h>
#include <wildflower.h>
inherit ROOM;

object board;

void create() {
  object ob;
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Inside a cave");
    set_day_long(
      "There is a board here.  "

    );

    set_night_long(
      "There is a large board here."
    );
    set_items(([
        "room" : "a room.",
    ]));
    set_smell("default", "It smells of acid..");
    set_listen("default", "Sounds of hissing demons");
    set_exits( ([
"west" :  ROOMS "tunnel.c",
"north" : ROOMS "yami2.c",
"northeast" : ROOMS "yami3.c",
"east" : ROOMS "yami5.c",
"south" : ROOMS "yami6.c",
"down" : ROOMS "wfo.c",
    ]) );


    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "yami board" }) );
    ob->set_board_id("yami");
    ob->set_max_posts(50);
    ob->set_location("/wizards/wildflower/room/yami4.c");
    ob->set("short", "Yami Board");
    ob->set("long", "Yami Sensai message center.\n");

}
