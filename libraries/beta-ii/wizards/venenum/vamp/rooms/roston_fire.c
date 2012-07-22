#include <std.h>
#include <venenum.h>
inherit ROOM;

int searched=0;

void create() {
    ::create();
    set_short("Destroyed house");
    set_long("This house has been completely destroyed by some kind of fire. There is nothing left now but the ashes of what would otherwise be a small, stately house. Debris is scattered all around- it is unlikely that anything survived this inferno.");
    set_smell("default", "This place smells strongly of ash.");
    set_listen("default", "There are not many noises here.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_items(([
	({"debris"}) : "There is so much rubble and debris it is hard to know if anything survived at all.",
      ]));
    set_exits(([
	"east" : "/d/roston/rooms/roston17.c",
      ]));
}

void init() 

{
    ::init();
    add_action("search", "search");
}

int search(string str)
{
    if (str != "debris") {return 0;}
    if (searched == 0)
    {
	write("You search the debris. After a moment or two of searching, you uncover the grisly remains of several humans buried under the rubble, a woman and four children of various ages. They clearly succumbed to smoke and were burned to death.");
	searched++;
	return 1;
    }
    if (searched == 1)
    {
	write("You search the debris. You find nothing save for the partial remains of several works of art.");
	searched++;
	return 1;
    }
    if (searched == 2)
    {
	write("After some searching you uncover a pretty stone. There is nothing else to find here.");
	new(ITEM"stoneofpassage.c")->move(this_player());
	searched++;
	return 1;
    }
    if (searched > 2 && searched < 10)
    {
	write("There is nothing to find here.");
	searched++;
	return 1;
    }

    if (searched > 9)
    {
	write("There is REALLY REALLY REALLY nothing to find here. Please go away.");
	return 1;
    }
}
