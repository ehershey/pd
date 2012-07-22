// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

int rt, mt;

void init() {
::init();
add_action("west", "west");
add_action("take", "take");
}

void reset() {
::reset();
if(!present("baby raknid")) {
new(MON2"braknid")->move(this_object());
new(MON2"braknid")->move(this_object());
}
new(MON2"braknid")->move(this_object());
rt=1;
mt=1;
}

void create() {
::create();
set_name("Citrin Forest");
set_long("This is a large nest.  The nest belongs to some type of primative creature.  "
         "Several bones lay around the nest made from the hair of people.  Inside the "
         "nest is several small eggs.");
set_properties(([ "light" : 0, "night light" : 0, "forest" : 1 ]));
set_items(([
"nest" : "There are some eggs in it.",
"eggs" : "They belong to that of a large animal.",
]));

set_exits(([
"west" : ROOM2"9.c",
]));
}

int take(string str) {
if (!str) return notify_fail("Take what?");
if(str != "egg") return notify_fail("Take what?");
if(rt==0) return notify_fail("All the eggs are gone!\n");

new("/d/citrin/objects2/egg.c")->move(this_player());
say(this_player()->query_cap_name()+" takes one of the eggs from the nest.");
write("You grab an egg from the nest.");
rt=0;
return 1;
}

int west(string str) {
if(present("egg_citrin", this_player())) {
if(mt==0) {
this_player()->move_player(ROOM2"9");
return 1;
}
write("A mother raknid comes to protect her eggs.  She is angered and starts to "
"attack.");
new(MON2"mraknid")->move(this_object());
mt=0;
return 1;
}
if(!present("raknid_citrin")) {
this_player()->move_player(ROOM2"9");
return 1;
}
write("The mother raknid stops you from going west.");
return 1;
}
