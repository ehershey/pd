// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

int doors(string str);
 
void create() {
::create();
set_name("a small deserted island");
set_day_long("The path ends abruptly.  The lake is to the north "
"preventing the path from going any further.  The path is made of a "
"white sand.  The sand's weight keeps the foilagee from growing over "
"the path.  The sand glistens in the sun.");
set_night_long("The path ends abruptly.  The ocean is to the north "
"preventing the path from going any further.  The path is made of a "
"white sand.  The sand's weight keeps the foilage from growing over "
"the path.");
set_properties(([ "light" : 0, "night light" : 0, "island" : 1 ]));

set_items(([

"path" : "It is made from a white glistening sand.",
]));

set_exits(([

"southeast" : ROOM2"island3.c",
]));
}

void init() {
  ::init();
// add_action("catch_tell","say");
add_action("enter", "enter");
  add_action("doors", "doors");
}

int enter(string str) {
if (str != "lake") {
write("Enter what?");
return 1;
}
if (this_player()->query_inventory("ocean_allow_suit_citrin")) {
write("You decided to go for a swim.");
this_player()->move_player(ROOM2"lake1");
return 1;
}
write("You might drown!");
return 1;
}

int catch_tell(string str) {
    string a,b;
if (query_exit("doors") != "/d/standard/void") {
write("The gates have already been opened.");
return 1;
}
    if(sscanf(str, "%spen thy mystical gates%s", a, b) == 2) {
          write("A large door rises from the ocean depths.");
	  add_exit(ROOM2"temple1.c", "doors");
          return 1;
}
write("Nothing happens");
return 0;
}

int doors(string str) {

if (query_exit("doors") != "/d/standard/void") {
this_player()->move_player(ROOM2"temple1.c");
return 1;
}
write("You cannot go that way.");
return 1;
}

