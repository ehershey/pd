#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;
void init() {
    ::init();
add_action("pull_lever" , "pull");
}

void create() {
::create();
set_short("%^YELLOW%^A secret hall beneath the living quarters%^RESET%^");
set_long("%^YELLOW%^You have entered a hidden passageway beneath the living quarters.  It looks as if someone has been down here recently.  The passage continues to the north.  You notice a lever mounted upon the wall near where you entered.%^RESET%^");
set_items(([
"lever":"A lever to pull.  More than likely it will open the same entrance you found before.",
]));
set_properties((["light" : 1, "indoors" : 1,]));
set_exits(([
"north": GCITY "gcity75.c",
]));
}
int pull_lever(string what) {
if (what != "lever") return 0;
if(what == "lever") {
message("info", "A hidden entrance opens up above you as the statue slides aside.\n", environment());
add_exit(GCITY "gcity63.c", "stairs");
return 1;
}
}

void reset() {
 ::reset();
if (!present("royal guard")) {
new(MOB "royalguard")->move(this_object());
new(MOB "royalguard")->move(this_object());
remove_exit("tunnel");
}
}
