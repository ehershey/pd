#include <std.h>
#include <marsh.h>
inherit ROOM;
object board;
void create() {
  object ob;
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Umi Town Square");
    set_long(
      "Welcome to the town of Umi!"
          );
    set_items(([
        "town" : "Safely hidden from unknown visitors.",
    ]));
    set_listen("default", "Sounds of a busy clamoring town");
    set_exits( ([
"south" : UMI "umi11",
"north" : UMI "umi25",
"east" : UMI "umi18",
"west" : UMI "umi16",
    ]) );
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "Umi Town board" }) );
    ob->set_board_id("Umi");
    ob->set_max_posts(50);
    ob->set_location("/wizards/wildflower/marsh/room/umi/umi17.c");
    ob->set("short", "Umi Board");
    ob->set("long", "Umi's message center.\n");
}
