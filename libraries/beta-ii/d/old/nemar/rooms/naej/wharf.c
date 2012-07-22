#include <std.h>
#include <nemar.h>

inherit ROOM;

void create() {
::create();
set_name("wharf");

set_short("Marine Wharf");

set_day_long("The wharf has places for small boats to dock, though it seems 
no do.  There are several shantees set up against the walls of Naej that are 
home to old mariners and peddlers.  One elderly peddler waits patiently.");

set_night_long("The wharf is quiet.  The peddlers have closed up shop, all 
but an elderly gentleman.  You can see the closed gatehouse behind the 
cluster of shantees.");

set_listen("default","The wings of the guards on the walls can be heard.");

set_smell("default","The salt of the ocean and the sour smell of grease 
mingle in the air.");

set_items
  (([
    "shantees": "The shantees are of human construction and size.  It is 
obvious that humanoids of some type.",
    ({"wings","guards"}): "From the sounds of the wings, it seems that guards 
of the city are faeries."
  ]));

set_properties
  (([
    "light" : 3,
    "night light" : 2,
    "town" : 1
  ]));

set_exits
  (([
    "north" : NAEJ"north_wharf.c",
    "east" : NAEJ"gatehouse.c",
    "west" : NAEJ"dock.c"
  ]));
}

void reset() {
::reset();
if(!present("merchant"))
new(MOB"wharf_merchant.c")->move(this_object());
}
