// Shay 12/10/01

#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Nilven Caverns");
    set_properties( (["light" : 1, "night light" : 1, "indoors" : 1]) );
    set_listen("default", "Water dripping can be heard");
    set_smell("default", "It smells of dampess here.");
    set_long("The long slender path seems to go on forever twisting "
      "and turning in all directions. The walls are damp and "
      "rigid from the many years of weathering to the rocks. "
      "The floor is a bit slippery but is still safe to walk "
      "with caution. Sounds of water dripping almost sound like "
      "footsteps in the near distance. ");
    add_exit("/wizards/shay/project/Nilven/nil9.c","west");
    add_exit("/wizards/shay/project/Nilven/nil11.c","east");
    set_items( ([ "floor" : "Moisture drips down the walls making the floor slick." ]) );
}

void reset() {
    ::reset();
    if(!present("behir",this_object()))
	new("/wizards/shay/project/npcs/behir")->move(this_object());
}
