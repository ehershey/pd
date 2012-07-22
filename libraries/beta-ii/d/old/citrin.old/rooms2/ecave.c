// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

int cave(string str);

void create() {
::create();
set_name("A long path");
set_long("An entrance to a small cave stands here.  Looking inside is "
"very dark and not much can be seen.  Bat droppings litter the path.");
set_properties(([ "light" : 0, "night light" : 0, "forest" : 1 ]));
set_items(([

"path" : "It is littered with bat droppings.",
(({"bat droppings", "bat dropping", "droppings", "droppings"})) : "Bats "
"that come from the cave have left there droppings along the path.",
]));


set_exits(([
"north" : ROOM2"16.c",
"cave" : ROOM2"cave1.c",
]));
}


int cave(string str) {
   if (present("victor")) {
      write("The cave has collapsed in on itself.");
      return 1;
   }
this_player()->move_player(ROOM2"cave1");
   return 1;
}

void init() {
 ::init();
   add_action("cave", "cave");
}
