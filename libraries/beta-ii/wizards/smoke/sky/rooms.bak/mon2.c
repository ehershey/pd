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
            "A giant archway on the southern wall leads back out to "
            "Platinum Street. An aisle leads north to a place of worship, "
            "where many wooden pews sit. In front of the worship area is "
            "an altar. A hallway leads east and west, where colorful "
            "light shines through stained glass windows, "
            "creating a rainbow of colors on the wall.%^RESET%^");
   set_items(([
            "columns" : "Tall stone columns stretch towards the vaulted "
                        "ceilings. They, like the entire monastery, "
                        "were carved directly from the mountain.",
            "windows" : "Colorful windows decorate the monastery.",
            "platinum street" : "Platinum Street is just outside the "
                 "archway.",
            "archway" : "A tall archway leads back out. ",
            "aisle" : "An aisle leads north into the place of worship. ",
            "pews" : "A number of wooden pews line both sides of the aisle.",
            "altar" : "An altar is visible at the very front of the aisle. "
   ]));
   set_smell("default", "The smell of insence provides a sense of tranquility.");
   set_listen("default", "It is very quiet.");
   set_exits( ([ 
        "out" :  ROOMS "mon1",
        "north" :  ROOMS "mon3",
        "east" : ROOMS "mon29",
        "west" : ROOMS "mon7"]));
}
void reset() {
::reset();
    if(!present("monk")) new(MOB"monk.c")->move(this_object());
}
