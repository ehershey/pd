#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("A Disused Fane");
    set_day_long("%^BOLD%^%^BLACK%^This room is filled by %^YELLOW%^sunlight%^RESET%^%^BOLD%^%^BLACK%^ which pours in through the broken remains of the roof. Apparently destroyed by some long-forgotten storm, it is now nothing more then a sunken hole lined with broken hunks of rotting wood through which the bright blue %^RESET%^%^BOLD%^%^BLUE%^s%^%^RESET%^%^BOLD%^k%^BLUE%^y%^RESET%^%^BOLD%^%^BLACK%^ can be seen. Nestled up against the back of the room is an ancient %^RESET%^%^BOLD%^%^RED%^a%^RESET%^%^BOLD%^l%^RED%^t%^RESET%^%^BOLD%^a%^RED%^r %^RESET%^%^BOLD%^BLACK%^which has somehow survived both the violent destruction of the room and the ravages of time. A sturdy silver ladder leads back down into the main area of the church.%^RESET%^");
    set_night_long("%^BOLD%^%^BLACK%^This room is brighter then below, but still dark by most standards. Moonlight trickles through the broken remains of the roof, giving some light to this area. Apparently destroyed by some long-forgotten storm, the roof is now nothing more then a sunken hole lined with broken hunks of rotting wood through which the dark velvet of the night sky, lined with the shining pinpoints of stars, can be seen. Nestled up against the back of the room is an ancient %^RESET%^%^BOLD%^%^RED%^a%^RESET%^%^BOLD%^l%^RED%^t%^RESET%^%^BOLD%^a%^RED%^r %^RESET%^%^BOLD%^BLACK%^which has somehow survived both the violent destruction of the room and the ravages of time. A sturdy silver ladder leads back down into the main area of the church.%^RESET%^");
    set_smell("default", "The scent of fresh air is refreshing.");
    set_listen("default", "This place is eerily quiet.");
    set_items(([
	({"altar"}) : "The altar is old and slightly weathered but has survived remarkably well.",
	({"ladder"}) : "The ladder leads down to the rest of the church. It looks sturdy enough to climb.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));

}

void init() 

{
    ::init();
    add_action("climb", "climb");

}

int climb(string str)
{

    if(str != "ladder") { 
	write("What?");
	return 1;
    }

    write("You climb down the ladder into the main area of the disused fane.");
    message("info", this_player()->query_cap_name()+" climbs down the ladder into the main area of the disused fane.", this_object(), this_player());
    this_player()->move("/d/nopk/tirun/houses/tauran1.c");
    return 1;
}
