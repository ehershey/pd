// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;
int read(string str);

void init() {
::init();
add_action("read", "read");
}

void create() {
::create();
set_name("A long path");
set_long("The cave is littered with the droppings of bats.  Not much "
"can be seen though the darkness that covered the cave.  On the rear "
"wall can be seen some odd markings.  Water drips from the ceiling of "
"this small cave.");
set_properties(([ "light" : 0, "night light" : 0, "forest" : 1 ]));
set_items(([

(({"marking", "markings"})) : "It is of ancient ancestors.  Maybe you "
"can read it?",
"path" : "It is littered with bat droppings.",
(({"bat droppings", "bat dropping", "droppings", "droppings"})) : "Bats "
"that come from the cave have left there droppings along the path.",
]));

set_exits(([
"out" : ROOM2"ecave.c",
]));
}

int read(string str) {
if (str != "markings") {
write("Read what?");
return 1;
}
if (present("scope", this_player())) {
object slave, env;
write("You look through the scope");
write("The strange writings seem to be of an old man.  It tells "
"a story of someone that tried to stop an evil man from discovering "
"the truth about the lake.  The rest has been wiped away.");
call_out("start_script", 7);
return 1;
}
write("The wall writing is strange and cannot be understanded without "
"aid.");
return 1;
}

void start_script(object tp) {
write("A skinny man comes from no where.");
write("He takes his hand and hits your head bearing you unconcious.");
this_player()->move_player(ROOM2"scene1.c");
}
