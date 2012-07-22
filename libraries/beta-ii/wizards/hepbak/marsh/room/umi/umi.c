#include <std.h>
#include <marsh.h>
inherit ROOM;

object board;

void create() {
  object ob;
room::create();

   set_properties( ([ "light" : 2]) );
    set_property("town",1);
    set_short("Uwagi Town Square");
    set_long(
      "Welcome to Uwagi's town square!  There is not much to look at "
      "because the town is still under construction.  Lizard-people, (as they "
      "prefered to be called) are working hard to get their town up and running. "
      "To the south there is a shipping port, and to the north homes are being built."


          );

    set_items(([
        "town" : "Safely hidden from unknown visitors.",

    ]));
    set_listen("default", "Sounds of a busy clamoring town");
    set_exits( ([
"south" : ROOMS "town9",
"northeast" : ROOMS "town20",
"east" : ROOMS "town15",
"west" : ROOMS "town13",
"northwest" : ROOMS "town18",
"southeast" : ROOMS "town10",
"southwest" : ROOMS "town8",
    ]) );


    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "Uwagi Town board" }) );
    ob->set_board_id("Uwagi");
    ob->set_max_posts(50);
    ob->set_location("/wizards/wildflower/marsh/room/town14.c");
    ob->set("short", "Uwagi Board");
    ob->set("long", "Uwagi's message center.\n");

}
