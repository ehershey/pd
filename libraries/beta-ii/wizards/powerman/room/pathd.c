#include <forest.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Entrance to Burham Woods");
set_day_long("You reach a long line of trees which signals your entrance to
Burham Woods. The daylight here is partly blocked by the trees which tower
above you. You can only make out the top of the castle in the distance. You can
see figures moving slyly at inside the forest.");
set_night_long("You reach a wall of trees. The shadows that the trees cast
darken the whole area considerably. The ground feels lumpy and metallic as you
walk over the many corpses in the dark. You can see a glowing light and smoke
hovering above to the far east and west.");
set_items(([
"soldiers" : "Dead and wounded, they are ignored.",
"castle" : "A huge castle in the distance.",
"smoke" : "Seems like there's a base set up in the forest.",
"light": "A light glows in the forest. It is as if someone started a bonfire in
Burham Woods",
"woods": "Burham Woods, the perimeter of Macbeth's Castle."
]));
set_smell("default","The smell of fresh blood and corpses fill the air.");
set_listen("default","The sounds of swords clashing echoes throughout.");
set_properties((["light" : 1, "night light" : 0,]));
set_exits( ([ "southwest" : "/wizards/powerman/room/forestmidb1",
              "south"     : "/wizards/powerman/room/forestmidc1",
              "southeast" : "/wizards/powerman/room/forestmidd1",
              "north"     : "/wizards/powerman/room/pathc" ]));

}
void reset()
{
 ::reset();
if(query_night() && !present("man"))
{
new("/wizards/powerman/arm/wiseman.c")->move(this_object());
}
else
if(!present("man")) {
new("/wizards/powerman/arm/wiseman.c")->move(this_object());
}

}

