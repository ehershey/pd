#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("On a path leading into a mountainous forest");
   set_properties((["light" : 2, "forest" : 1, "mountain" : 1,
     "town" : 1 ]));
   set_day_long("The path begins to slope and turn northwards into a "
     "mountainous forest. The sun beats down upon the winding path. "
     "A slight breeze takes the edge off of the blazing heat.");
   set_night_long("The path twists and bends northwards into a dark, "
     "mountainous forest. The large mass of trees all look like strange "
     "nether creatures, a shadowy mass.");
   set_items(([
     "trees" : "There are many trees upon the mountains here."
   ]));
   set_exits(([ "west" : ROOMS"etown6",
                "north" : ROOMS"farm/room/yard2.c",
                "east" : "/d/distopia/room/startlod" ]));
}

void reset() {
 ::reset();
   if (!present("deer"))
     make(MOB"deer");
}
