#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
    "no teleport" : 1]) );
  set_short("Steel Hammer Monastery");
  set_long(
   "%^BOLD%^Tall stone columns reach to the high, vaulted ceiling. "
   "Rows of wooden pews line both sides of the aisle just "
   "south of here. Several dwarves who have come to worship "
   "line the pews. A red carpet stretches south into the entry "
   "way of the monastery.%^RESET%^");
  set_items(([
    "columns" : "Tall stone columns stretch towards the vaulted "
    "ceilings. They, like the entire monastery, "
    "were carved directly from the mountain.",
    "carpet" : "A deep red carpet covers the floor of the aisle.",
    "archway" : "A tall archway is south of here and "
    "leads back out. ",
    "aisle" : "An aisle leads north into the place of worship "
    "and south to the entrance of the monastery. ",
    "pews" : "A number of wooden pews line both sides of the aisle."
   ]));
  set_smell("default", "The smell of insence provides a sense of tranquility.");
  set_listen("default", "It is very quiet.");
  set_exits( ([ 
    "south" : ROOMS "mon5"]));
}
void reset() {
  ::reset();
  if(!present("priest")) new(MOB"priest.c")->move(this_object());
  if(!present("altar")) new(ITEMS"altar.c")->move(this_object());
}
