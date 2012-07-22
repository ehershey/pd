#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;
void init() {
    ::init();
add_action("pull_arm" , "pull");
}

void create() {
::create();
set_short("%^YELLOW%^Main hall of the living quarters%^RESET%^");
set_long("%^YELLOW%^You have entered the main hall that intersects each part of the living quarters.  Lush plantlife and hanging carpets provide a wonderful splash of color.  A statue of the Queen is proudly displayed in the middle of the hall.%^RESET%^");
set_items(([
"statue":"A golden statue of the Queen.  Something feels strange about this statue...",
"carpets":"Carpets adorn the walls adding color and warmth to the hall.",
"plantlife": "The plants give life to the room.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
new(GCITY "queenstatue.c")->move(this_object());
set_exits(([
"northeast": GCITY "gcity65.c",
"northwest": GCITY "gcity66.c",
"southeast": GCITY "gcity64.c",
"north":GCITY "gcity62.c",
"southwest": GCITY "gcity67.c",
]));
}
int pull_arm(string what) {
if(!what) return 0;
if (what != "arm") return 0;
if(what == "arm") {
message("info", "A hidden entrance has been revealed below the statue!\n", environment(this_player()));
add_exit(GCITY "gcity74.c", "stairs");
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
