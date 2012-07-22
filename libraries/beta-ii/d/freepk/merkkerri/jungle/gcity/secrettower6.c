#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;
void init() {
    ::init();
}

void create() {
::create();
set_short("%^YELLOW%^Heart of the Blood Warriors%^RESET%^");
set_long("%^YELLOW%^You have entered the central chamber of the blood warriors.  These are not the regular lowlifes, thugs, murderers or the like.  These are the commanders and they are far superior to the others.%^RESET%^");
set_listen("default", "The sounds of commanders discussing future battles fills the chamber.");
set_items(([
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_property("building",1);
set_exits(([
"east": GCITY "secrettower7.c",
"northwest": GCITY "secrettower5.c",
"north": GCITY "secrettower4.c",
"northeast": GCITY "secrettower3.c",
]));
}
void reset() {
 ::reset();
if(!present("olsar")) {
new(MOB "olsar.c")->move(this_object());
}
if(!present("neslem")) {
new(MOB "neslem.c")->move(this_object());
}
}
