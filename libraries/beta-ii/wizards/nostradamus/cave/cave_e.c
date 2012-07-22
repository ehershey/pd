#include <std.h>
#include <cave.h>
 
inherit ROOM;
 
void create() {
::create();
   set_short("cave entrance");
   set_day_long("The entrance to the cave is pretty well lit.  "
    "The cave walls are covered with dried blood and there are bones "
    "half buried in the ground outside the cave.  The ground looks "
    "undisturbed like nothing has entered the cave in ages.");
   set_night_long("All you can see are the outlines of who knows what."
    "  Lucky for you the outlines aren't moving.  Wait.  What was that?"
    "  You see a flicker of movement in the shadows.  You hear noises"
    " coming from inside the cave.");
   set_items(([
    "walls" : "The walls are covered with dried blood",
    "blood" : "The blood is dried and crusty.  Hope it wasn't the "
     "blood of a friend.",
    "bones" : "They look like the bones of various creatures.",
    "outlines" : "Shadowy outlines.  Hope they are only rocks.",
    "shadows" : "Something moved.  Carefull it might be hungry.",]));
   set_properties(([
    "light" : 1,
    "night light" : 0,
    ]));
   set_exits(([
    "up" : CAVE "pcave.c",
    "north" : CAVE "cave_1.c",
    ]));
}
