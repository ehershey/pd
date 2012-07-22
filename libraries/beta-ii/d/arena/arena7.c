#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_short("Colleseum");
    set_day_long("The Colleseum is large with stands on all sides.  "
      "People sit in the stands watching and cheering as the "
      "fight progresses.  The ground is stained in places "
      "where other combatants have bled.");
    set_night_long("The Colleseum is large and deserted.  Darkness obscures "
      "anything that may be moving around.  No one is watching "
      "at this time of night.");
    set_exits( ([ 
	"north" : "/d/arena/arena4",
	//              "south" : "/d/arena/arena9",
	//              "west" : "/d/arena/arena8", 
	"east" : "/d/arena/arena8",
	"northeast" : "/d/arena/arena5",
	"southeast" : "/d/arena/arena10",
	//              "northwest" : "/d/arena/arena2",
	//              "southwest" : "/d/arena/arena8",
      ]) );
    set_properties( ([ "no teleport":1 , "light":2 , "night light":1]));
}

void init() {
    ::init();
    this_player()->set_arena(1);
}
