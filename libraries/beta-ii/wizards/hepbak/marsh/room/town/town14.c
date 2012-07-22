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
    set_day_long(
      "The wild vines broke through the surface through a well situated "
      "in the center of the town.  A board, half torn down, has pieces of "
      "weathered paper nailed to it.  This once was a gathering place, but "
      "clearly now, it's been taken over to serve as a home for the wild "
      "vines."
          );
    set_night_long(
       "Mounds of wild vines can be seen under the light of fire-flies."
          );
    set_items(([
        "town" : "It's been taken hostage by the vines.",
        "well" : "You can't see much of it, the plant "
                 "has taken root deep within the well.",
        "paper" : "It is clearly very old, you can't make "
                  "out any of the writing.",
        "vines" : "It has taken the town as it's home, "
                  "slowly choking the life out of the "
                  "land it sits on.",
        "flies" : "Unique, it has a flame for a body.",
    ]));
    set_exits( ([
"south" : TOWN "town9",
"northeast" : TOWN "town20",
"east" : TOWN "town15",
"west" : TOWN "town13",
"northwest" : TOWN "town18",
"southeast" : TOWN "town10",
"southwest" : TOWN "town8",
    ]) );
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "Uwagi Town board" }) );
    ob->set_board_id("Uwagi");
    ob->set_max_posts(50);
    ob->set_location("/wizards/wildflower/marsh/room/town/town14.c");
    ob->set("short", "Uwagi Board");
    ob->set("long", "Uwagi's message center.\n");
}
