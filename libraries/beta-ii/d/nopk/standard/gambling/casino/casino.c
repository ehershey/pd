#include <std.h>
#include <ace.h>
inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "indoor" : 1, "light" : 2, "night light" : 2]) );
    set_property("no castle", 1);
    set_property("no attack", 1);
    set_short("casino");
    set_long(
      "%^MAGENTA%^The Drowning Fish Tavern%^RESET%^\n"
      "This is the roulette area of the casino.  Look at the list of rules "
      "on the wall to see how to play.");
    set_exits((["slots" : "/d/nopk/tirun/ghall.c"]));
    set_items((["list": "+--------------------------------------------+\n"
	"|             %^BOLD%^%^RED%^Roulette Rules:%^RESET%^                |\n"
	"+--------------------------------------------+\n"
	"|   To play:     bet <amount> on <value>     |\n"
	"|  You can bet on even, odd, high, low,      |\n"
	"|  first <the first twelve>, second, third,  |\n"
	"|  one number, two numbers <# and #>, three  |\n"
	"|  numbers <# and # and #>, four numbers,    |\n"
	"|  or six numbers.    The casino is not      |\n"
	"|  responsible for bad bets, you make a      |\n"
	"|  typo then you lose.                       |\n"
	"+--------------------------------------------+"]) );
}
void reset() {
    ::reset();
    if(!present("roulette", this_object()))
	new(OTHER "roulette.c")->move(this_object());
    if(!present("greg", this_object()))
	new(MOB "g.c")->move(this_object());
}

