#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
    "no teleport" : 1]) );
  set_short("Steel Hammer Armory");
  set_long("%^BOLD%^%^CYAN%^Steel Hammer Armory%^RESET%^\n"
   "The armoury is neat and well taken care of. A "
   "long counter divides the shop. Behind the counter "
   "are a couple wooden tables with various tools "
   "covering them. A spinning wheel is in the back "
   "corner next to a rack holding yards of threads.");
  set_items(([
    "wheel" : "A wooden spinning wheel is in the "
    "back corner of the shop. It looks like it "
    "would have the day it was made.",
    "counter" : "A long counter divides the shop. It's carved "
    "of stone and looks worn from use.",
    "threads" : "Colorful threads are all rolled up and "
    "stored on a rack.",
    "tools" : "Knives, saws, hammers and other various "
    "tools litter the tables behind the counter.",
    "tables" : "Three wooden tables covered in tools stand, "
    "ready for use.",
    "rack" : "A rack holding quite a few rolls of colorful "
    "thread is near the back of the shop."
   ]));
  set_listen("default", "Annoying clanging of metal comes from next door.");
  set_exits( ([ 
    "out" : ROOMS "s_gem2"]));
}
void reset() {
  ::reset();
  if(!present("shopkeeper")) new(MOB"shpkpr.c")->move(this_object());
}
