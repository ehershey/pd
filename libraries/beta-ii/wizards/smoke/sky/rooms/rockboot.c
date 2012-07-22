#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
    "no teleport" : 1]) );
  set_short("a house");
  set_long(
   "This house has been carved from the stone of the mountain."
   " The walls are fairly empty, aside from a few paintings "
   "of two dwarves. A bison skin rug dominates the stone "
   "floor. Two chairs lie against the back wall.");
  set_items(([
    "paintings" : "There are several paintings of two "
    "dwarves hung from the walls.",
    "walls" : "The stone walls have been carved from "
    "the mountain itself.",
    "rug" : "The skin of a bison has been laid out here "
    "as a rug, keeping feet off of the cold stone "
    "floor.",
    "chairs" : "Two chairs against the back wall sit "
    "facing the doorway."
   ]));
  set_smell("default", "It smells like some good home cooking.");
  set_exits( ([ 
    "out" :  ROOMS "n_bronze2"]));
}
void reset() {
  ::reset();
  if(!present("woman")) new(MOB"mrs_r.c")->move(this_object());
}
