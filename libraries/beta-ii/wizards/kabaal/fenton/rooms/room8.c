#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("plain",1);
    set_short("old road");
    set_long(
      "The worn road leads southern and northwestern.  The road has "
      "defenetly seen better days.  The tree looms over you.  Its dead "
      "branches hang over your head. "
    );
    set_items(([
        "tree" : "The tree has a sign on it.",
        "sign" : "Emios Nerli Tralla Erelose Raems Musio Eythro",
        "road" : "The road is cracked and worn badly.",
        "branches" : "They sway in the cool breeze.",
    ]));
   set_listen("default", "Groaning of an old, dead tree dancing in the wind.");
   set_exits( ([ 
        "northwest" : ROOMS"room6.c",
        "south" : ROOMS"room4.c",
    ]) );
}
void init() {
  ::init();
  add_action("enter_it","enter");
}

int enter_it(string str) {
  if(!str) {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(str != "tree") {
    notify_fail("You can't enter that!\n");
    return 0;
  }
  else {
    this_player()->move_player(ROOMS "tree", "is sucked in by the tree.");
    return 1;
  }
}
