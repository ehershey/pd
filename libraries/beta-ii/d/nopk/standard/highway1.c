#include <std.h>
#include <sindarii.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set("short", "A dirt highway");
    set("day long",
      "The road underfoot is not paved and runs east into the city of Tirun "
      "and west to the Great Daroq Mountains.  The mountains look imposing "
      "in the distance and take up the skyline to the west.  Tirun is a "
      "rather large city and tales up the eastern skyline. ");
    set("night long",
      "The road underfoot is dark and trecherous.  Deep shadows to the west "
      "suggest a large object in the distance.  To the east, the Tirun east "
      "gate is lit and easily recognizable. ");
    set_items(
      (["highway" : "A highway linking Tirun to the western lands "
	"of Carnage.",
	"mountains" : "The Daroq Mountains, home to many vile creatures."
      ]) );
    set_exits( 
      (["west" : ROOMS "highway2",
	"north" : "/d/coach/rooms/tirun_coach.c",
	"east" : "/d/nopk/tirun/wgate"]) );
}
