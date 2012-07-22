#include <std.h>
#include <arlon.h>

inherit ROOM;

void init()
{
    ::init();
    add_action("fRead", "read");
}
static void create()
{
    ::create();
    set_short("Stone shop");
    set_long("The room is brightly lit with an eerie green light. "
      "There is a counter on the west side of the room with "
      "a wooden box hanging from the wall behind it, emitting a "
      "green light. A small sign is here.");

    set_exits ( ([ "east" : ROOMS "s_square2" ]) );
    set_properties( ([ "no attack":1,
	"no magic": 1,
	"no bump": 1,
	"light":2,
	"night light":2 ]) );
}
int fRead(string str)
{
    if (!str || str!="sign")
        return notify_fail("Read what?\n");
    say (this_player()->query_cap_name()+" reads over the sign.");
    write("The sign reads:
-----------------------------------------
I have decided to move to Tirun. You can find me at Patrick's.
-----------------------------------------");
 return 1;
}
