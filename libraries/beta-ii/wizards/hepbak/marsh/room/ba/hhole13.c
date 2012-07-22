#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("A messy house");
    set_long(
      "This house is a mess!  Armor, clothes and weapons are scattered all "
      "over the floor.  In a corner there is a make-shift bed made out of "
      "straw.  Right above it, there is a %^RED%^X%^RESET%^."
          );

       set_items(([
        "house" : "It is a messy one room house.",
        "mess" : "Armor, clohes and weapons lying all over the floor",
        "armor" : "A very cheap looking one.",
        "clothes" : "Looks like potatoe sacks made into articles of clothing.",
        "weapons" : "Very flimsy, feels like tin paper.",
        "floor" : "You couldn't walk around with out stepping on something.",
        "corner" : "There is a bed made of straw there.",
        "bed" : "Doesn't look very comfy, it's made of straw",
        "straw" : "Looks to be a year or more old, rather stinky.",
        "X" : "It's where another room is suppose to be, but this family is too poor for it.",


    ]));
 
    set_exits( ([
"out" : BA "ba30",
    ]) );

}
