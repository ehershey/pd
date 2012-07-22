#include <std.h>
#include <arlon.h>

inherit ROOM;

static void create()
{
 ::create();
 set_short("Path west of Arlon square");
 set_long("This cobblestone path continues to the west and the east. "
          "There are various plants and trees growing on the side of "
          "the path. Trees overtowering the path to provide shade to "
          "people that travel it.");
 
// set_listen("default", "The sound of fighting is heard to the north");
 set_exits ( ([ "east" : ROOMS "wsquare2",]) );
}

void reset()
{
 ::reset();
}
