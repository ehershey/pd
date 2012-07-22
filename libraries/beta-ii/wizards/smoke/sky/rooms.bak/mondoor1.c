#include <std.h>
#include <cp.h>
inherit VAULT;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
    "no teleport" : 1]) );
  set_short("Steel Hammer Monastery");
  set_long(
   "%^BOLD%^This office is very neat and orderly. A "
   "very spacious desk made of a fine, dark wood is "
   "right infront of a majestic painting. A globe is "
   "atop the desk as well as a few stacks of papers. "
   "Two padded chairs are pointed at the desk with an "
   "ashtray in between. A colorful woven rug is on the "
   "floor in the center of the office.%^RESET%^");
  set_items(([
    "office" : "This is the office of Bishop Brum Soulstone. "
    "It is very tidy, as the Bishop is adament "
    "on organization.",
    "papers" : "A few stacks of papers are on the desk. They're"
    "neatly stacked and shouldn't be bothered.",
    "globe" : "A globe carved of marble with gold as the "
    "continents and islands stands atop the desk. It "
    "looks extremely valuable and precious.",
    "painting" : "A very important looking painting hangs "
    "behind the desk on the southern wall. It depicts "
    "an angel and a dwarf teamed together battling "
    "skeletons. In the background of the painting "
    "is an enormous White Dragon shackled and bound.",
    "chairs" : "Two wooden chairs padded with a soft leather "
    "sit infront of the desk.",
    "ashtray" : "A stone ashtray stands in between two chairs. "
    "It is carved of stone and connected to the floor, "
    "another of the permanent fixtures within the monastery.",		 
    "rug" : "A very colorful woven rug covers the floor in the "
    "center of the office."
   ]));
  set_smell("default", "The smell of insence provides a sense of tranquility.");
  set_listen("default", "It is very quiet.");
  set_exits( ([ 
    "out" : ROOMS "mon18"]));
  cover_exit_with_door("out", "bishop_office_door");
}
void reset() {
  ::reset();
  if(!present("bishop")) new(MOB"bishop.c")->move(this_object());
  if(!present("desk")) new(ITEMS"desk.c")->move(this_object());
}
