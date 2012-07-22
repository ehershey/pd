#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;
void init() {
    ::init();
add_action("twist_hinge" , "twist");
}

void create() {
::create();
set_short("%^YELLOW%^Within the Northeast guard tower%^RESET%^");
set_long("%^YELLOW%^The lower level of the Northeast tower is quite larger than one might imagine from outside.  Several torches line the walls of the hall and a large set of spiraling stairs leads up.  A fireplace is mounted along the northeastern section of the tower wall.%^RESET%^");
set_items(([
"stairs":"The stairs lead up into the higher levels of the tower.",
"fireplace":"A large stone fireplace designed to meet the needs of several guard occupants.",
"torches": "The torches along the walls are mounted on hinges made of gold.  One hinge however is made of iron.",
"iron torch": "It looks like it's mounted on a rotating hinge..."
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"out": GCITY "gcity36.c",
"up": GCITY "gcity56.c",
]));
}
int twist_hinge(string what) {
if(!what) return 0;
if (what != "hinge") return 0;
if(what == "hinge") {
message("info", "The fireplace slides to the side revealing a tunnel below.\n", environment(this_player()));
add_exit(GCITY "secrettower1.c", "tunnel");
return 1;
}
}

void reset() {
 ::reset();
remove_exit("tunnel");
}
