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
   "Rows of wooden pews line both sides of the aisle. A red "
   "carpet covers the floor of the aisle. An altar sits in "
   "front of the worship area. The stone walls have immaculate "
   "carvings. A tall archway is south, leading back out to the "
   "village.%^RESET%^");
  set_items(([
    "columns" : "Tall stone columns stretch towards the vaulted "
    "ceilings. They, like the entire monastery, "
    "were carved directly from the mountain.",
    "carpet" : "A deep red carpet covers the floor of the aisle.",
    "platinum street" : "Platinum Street is just outside the "
    "archway.",
    "archway" : "A tall archway is south of here and "
    "leads back out. ",
    "aisle" : "An aisle leads north into the place of worship "
    "and south to the entrance of the monastery. ",
    "pews" : "A number of wooden pews line both sides of the aisle.",
    "altar" : "An altar is visable at the very front of the aisle. "
   ]));
  set_smell("default", "The smell of insence provides a sense of tranquility.");
  set_listen("default", "It is very quiet.");
  set_exits( ([ 
    "north" :  ROOMS "mon6",
    "south" : ROOMS "mon4"]));
}
void reset() {
  ::reset();
  if(!present("worshipper")) new(MOB"worship1.c")->move(this_object());
  if(!present("worshipper 2")) new(MOB"worship1.c")->move(this_object());
  if(!present("worshipper 3")) new(MOB"worship2.c")->move(this_object());
}
