#include <mjungle.h>
#include <std.h>
#include <dquest.h>
inherit ROOM;

void init() {
  ::init();
add_action("peer", "peer");
add_action("survey", "survey");
add_action("follow_war", "follow");
add_action("follow_pain", "follow");
add_action("follow_strength", "follow");
add_action("follow_hate", "follow");
}

void create() {
::create();
set_short("A cave lit by several torches");
set_long("%^BOLD%^BLACK%^You thank yourself for remembering to take a better look at those runes earlier as a wrong turn may have meant death.  But here you are in yet another strange cavern.  Four winged demons stand here each bearing a mark upon its chest.%^RESET%^");
set_properties((["light" : 2, "indoors" : 1,]));
set_exits(([
]));
set_items(([
"torches": "The torches are glowing with strange flames that dont seem to radiate heat of any kind.  You notice that the torch mounts are not actually fastened to the cave walls, but are magically suspended in air and are impossible to move.",
"demons":"The demons are stand nearly 8ft tall and are winged.  Two large horns protrude from the temples and a spiked tail whips around madly.  All are identical except the marks upon their chests.",
]));
}

void reset() {
::reset();
if(!present("demon")) {
new(DQUEST "strength.c")->move(this_object());
new(DQUEST "hate.c")->move(this_object());
new(DQUEST "pain.c")->move(this_object());
new(DQUEST "war.c")->move(this_object());
}
}
int survey(string what) {
write("Your mind is unable to focus.");
    return 1;
}

int peer(string what) {
write("Your mind is unable to focus.");
    return 1;
}

int follow_war(string what) {
if (what != "war") return 0;
write("%^BOLD%^RED%^You choose to follow the demon of war...%^RESET%^");
this_player()->move_player(DQUEST "dquest7.c", "follows the demon of war into the darkness...");
     return 1;
}
int follow_hate(string what) {
if (what!="hate")return 0;
write("%^BOLD%^RED%^You choose to follow the demon of hate...%^RESET%^");
this_player()->move_player(DQUEST "dquest5.c", "follows the demon of hate into the darkness...");
return 1;
}
int follow_pain(string what) {
if (what !="pain")return 0;
write("%^BOLD%^RED%^You choose to follow the demon of pain...%^RESET%^");
this_player()->move_player(DQUEST "dquest5.c", "follows the demon of pain into the darkness...");
return 1;
}
int follow_strength(string what) {
if(what !="strength")return 0;
write("%^BOLD%^RED%^You choose to follow the demon of strength...%^RESET%^");
this_player()->move_player(DQUEST "dquest5.c", "follows the demon of strength into the darkness...");
return 1;
}
