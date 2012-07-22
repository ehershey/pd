#include <std.h>
#include <helgrath.h>
inherit VAULT;

void create() {
    ::create();
    set_properties(([
      "light" : 1,
      "indoors" : 1
    ]));
    set_short("Cavern of the Black Sorceror");
    set_long("Stepping through the massive entrance, the air suddenly becomes uncomfortably "
      "hot. A massive, intricately woven rug dominates the rigid stone floor of the room. Towering "
      "bookshelves house an infintie variety of literature, from decaying, arcane works to "
      "astronomy  and mythological writings. A large darkwood table occupies the center "
      "of the room, open books lye scattered about the table, depicting the arcance runes "
      "of various complex spells and enchantments. " );
    set_exits( ([ "north" : ROOMS "draege_greatroom.c",
      "south" : ROOMS "draege_outside.c" ]));
    set_door("door", ROOMS "draege_outside.c", "south", "dkey");
    set_smell("default", "The smell of burning flesh lingers in the air.");
    set_listen("default", "a faint humming noise can be heard.");

}

