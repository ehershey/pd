#include <std.h>
#include <arlon2.h>
inherit ROOM;
void create() {
    ::create();
    set_short("A large room.");
    set_long(
      "This is a very basic looking manor, except for the two oversized doors that take up most of the front wall of the house.  There are large claw shaped indentions in the grass seen outside the front window.  This room does not seem very accomodating, and is empty except for a tunnel leading downward."
    );
    set_exits( 
      (["down" : ROOMS + "phouses/kilir/2.c",
      "out" : ROOMS + "roads/38.c",
      ]) );
    set_property("light", 3);
    set_property("night light", 3);
    set_property("indoors", 1);
    set_property("house", 1);
    set_items(
      (["doors" : "The large wooden doors are big enough for a dragon to fit through!",
        "indentions" : "It seems as if something very large was walking around outside.",
        "grass" : "The grass is fresh and green, all alive except for where it has been clawed apart.",
        "tunnel" : "A dark tunnel leads to some underground area.",
        "window" : "The doors take up so much of the front wall that the window is actually on one of the doors."
      ]) );

}
