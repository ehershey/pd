#include <kabaal.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Logan");
set_long("The road here leads east to west. The gates are south of here "
             "preventing an exit into the jungle. A building is seen north "
	     "of here, however there is no obvious way in.");
set_property("plain",1);
set_items(([
"jungle" : "The jungle lies south of here, but the gates pervent enterance to it.",
"gates" : "The gates prevent enterance to the jungle. They stand very tall and look rather old.",
"building" : "A small building lies north of here, but no enterance can be seen from here.",
]));
set_properties((["light" : 3, "night light" : 2,]));
set_exits(([
"west": ROOMS "logan3.c",
"east": ROOMS "logan6.c",
]));
}

void reset() {
::reset();
if(!present("citizen"))
new(MOB "lc1.c")->move(this_object());
}
