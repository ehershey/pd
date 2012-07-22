#include <std.h>
#include <zolenia.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "indoors" : 1, "cavern" : 1, "night light" : 1]) );
set_smell("default", "The smells from the forest have finally subsided, and all that remains outside of the gate is stale air.");
set_listen("default", "To the southeast, the sounds of animals can be heard fighting, and straight past the gate chimes the commotions of a busy city.");
set_short("a large onyx gateway");
set_long("The onyx path leads straight to a giant closed gateway.  Although there seems to be no way around or through it, a makeshift ladder has been scratched into the wall of the gate.  There is a visible pathway from the gate door to the ladder on the wall.  It seems to be the only way to get to the city.");
set_items(([
({"onyx", "pathway", "path"}) : "In the middle of treacherous rocks, a path of onyx stays maintained and unbothered.",
({"dirt", "footprints"}) : "Dirt and dust cover the path, and footprints can be seen, some appear to have been dragged.",
"ground" : "The ground is covered in treacherous rocks, although there is an onyx path.",
({"bars", "cut out"}) : "There is a small cut out on the gate covered in bars..",
({"rock", "stones", "rocks"}) : "The rocks are jagged and large for the most part, and without the path, travel would be difficult..",
({"air", "dust"}) : "Particles of dust can be seen floating throughout the air.",
({"gateway", "gate door", "gate"}) : "The gate is gigantic, made of dark wood, with bars covering a small cut out.",
"ladder" : "Scratched into the onyx wall beside the gate door, and definitely not the safest climb, it will have to do if you want to enter the city.",
"shadows" : "The darkness makes for no shadows, although a presence can be felt.",
"wall" : "The wall of the gate is made completely of onyx.  There seems to be a ladder scratched in to it...",
"darkness" : "The absolute darkness makes traveling through the path quite uneasy.",
]));
set_exits(([ "climb" : ROOMS "16.c",
"south" : ROOMS "14.c"]));}
void init() {
  object room = find_object(ROOMS "16");
  object archer;
  ::init();
   if (this_player()->is_player() && room && present("archer", room)) {
   write("%^BOLD%^%^RED%^An arrow shoots down from the top of the gate, landing in your shoulder!%^RESET%^");
   say(""+this_player()->query_cap_name()+" has been hit by an arrow from above!.");
   this_player()->do_damage("torso", 50+random(150));
 }
}
