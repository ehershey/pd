#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("A Disused Fane");
    set_day_long("%^YELLOW%^L%^RESET%^%^BOLD%^i%^YELLOW%^g%^RESET%^%^BOLD%^h%^YELLOW%^t %^RESET%^%^BOLD%^%^BLACK%^filters through several sets of broken windows, the glass within having been shattered some time ago. The occasional shard remains, creating patches of kaleidoscopic colour amongst otherwise dull illuminance. Off in one corner, to the northeast of the room, lies a small wooden %^RESET%^%^ORANGE%^trapdoor%^RESET%^%^BOLD%^%^BLACK%^, leading down below the church. Against the back wall of the church, leading upwards, is a sturdy %^RESET%^%^BOLD%^s%^BLACK%^i%^RESET%^%^BOLD%^l%^BLACK%^v%^RESET%^%^BOLD%^e%^BLACK%^r ladder.%^RESET%^");
    set_night_long("%^BOLD%^%^BLACK%^An eerie kind of darkness cloaks this disused church while moonlight filters through several sets of broken windows, the glass within having been shattered some time ago. The beams of moonlight are clearly visible in the ambient dust of the room, like the fingers of some forgotten diety reaching into his or her place or worship. Off in one corner, to the northeast of the room, lies a small wooden %^RESET%^%^ORANGE%^trapdoor%^RESET%^%^BOLD%^%^BLACK%^, leading down below the church. Against the back wall of the church, leading upwards, is a sturdy %^RESET%^%^BOLD%^s%^BLACK%^i%^RESET%^%^BOLD%^l%^BLACK%^v%^RESET%^%^BOLD%^e%^BLACK%^r ladder.%^RESET%^");
    set_smell("default", "The smell of wet wood and dust is here.");
    set_listen("default", "This place is eerily quiet.");
    set_items(([
	({"window", "windows"}) : "These once glorious stained glass windows have been long destroyed by vandals and storms.",
	({"ladder"}) : "The ladder leads to the top of the tower. It looks sturdy enough to climb.",
	({"trapdoor", "door"}) : "The trapdoor is as old as the rest of the church, but seems to be clear of any dust or grime as though recently opened."
      ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
	"no scry" : 1,
	"no gate" : 1,
	"no kill" : 1,
	"no magic" : 1,
	"outdoors" : 0,
	"indoors" : 1,
      ]));
    set_exits(([
	"out" : "/d/nopk/tirun/edovin4.c",
      ]));

}

void init() 

{
    ::init();
    add_action("climb", "climb");
    add_action("open", "open");
}

int climb(string str)
{

    if(str != "ladder") { 
	write("What?");
	return 1;
    }

    write("You scale the ladder up to the upper room of the disused fane.");
    message("info", this_player()->query_cap_name()+" climbs up the ladder into the upper room of the disused fane.", this_object(), this_player());
    this_player()->move("/d/nopk/tirun/houses/tauran2.c");
    return 1;
}

int open(string str)
{

    if(str != "trapdoor") { 
	write("What?");
	return 1;
    }

    write("The trapdoor refuses to budge.");
    message("info", this_player()->query_cap_name()+" attempts to open the trapdoor but it refuses to budge.", this_object(), this_player());
    return 1;
}
