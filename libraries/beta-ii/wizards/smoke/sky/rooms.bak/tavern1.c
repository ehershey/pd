#include <std.h>
#include <cp.h>
inherit ROOM;

string long_desc() {
  if (present("barkeep"))
    return
    "The tavern is dimly lit. A small bar stretches across "
    "the tavern with a short, stout dwarf taking orders and "
    "pouring drinks. Small tables fill the room, giving "
    "customers a place to enjoy some drinks. An open "
    "doorway leads back to Platinum Street. \n%^BOLD%^%^CYAN%^"
    "A menu hangs from the wall behind the bar.%^RESET%^"
    ;
  else
    return
    "The tavern is dimly lit. A small bar stretches across "
    "the tavern with an empty space behind it. "
    "Small tables fill the room, giving customers a place to enjoy "
    "some drinks. An open doorway leads back to Platinum Street."
    ;
}

void create() {
  ::create();
  set_properties( ([ "light" : 1, "indoors" : 1, "night light" : 1,
    "no teleport" : 1, "town" : 1]) );
  set_short("Steel Hammer Tavern");
  set_long( (: long_desc :) );
  set_items(([
    "bar" : "A solid wooden counter that stretches across the tavern.",
    "platinum street" : "Platinum Street is outside the tavern. "
    "It's a rather busy street in the small village.",
    "tables" : "A few small tables fill the tavern. They're all "
    "round and are the perfect size for Dwarves.",
    "door" : "The door is open, leading back out to Platinum Street.",
    "doorway" : "The door is open, leading back out to Platinum Street.",
    "customers" : "A few customers sit in here all day, enjoying "
    "the atmosphere. And of course the special brew."
   ]));
  set_smell("default", "It smells of old, spilt brew.");
  set_listen("default", "Murmurs of the customers carrying on their own "
   "conversations echo about the room.");
  set_exits( ([ 
    "west" :  ROOMS "tavern2",
    "north" : ROOMS "sh_8"]));
}
void reset() {
  ::reset();
  if(!present("dwarf")) new(MOB"barkeep.c")->move(this_object());
  if(!present("dwarf 2")) new(MOB"drunk.c")->move(this_object());
  if(!present("dwarf 3")) new(MOB"drunk.c")->move(this_object());
}
