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
      "This is the bones area of the casino.  Look at the list of rules "
      "on the wall to see how to play.");
    set_exits((["slots" : "/d/nopk/tirun/ghall.c"]));

    set_items((["list": "+--------------------------------------------+\n"
	"|               %^BOLD%^%^RED%^Bones Rules:%^RESET%^                 |\n"
	"+--------------------------------------------+\n"
	"| Type: play bones, bet <amount>, toss bones.|\n"
	"|  In the game of bones you have a set of    |\n"
	"| twelve bones and a mat with a small circle |\n"
	"| in the center.  When playing first the     |\n"
	"| player must make a bet.  After making a    |\n"
	"| bet the player tosses the bones towards    |\n"
	"| the middle of the circle, the two closest  |\n"
	"| to the center are used for the players     |\n"
	"| total.  The total deterimes the outcome of |\n"
	"| the game.  The player wins if his first    |\n"
	"| roll is 7 or 11 (a natural); he loses if   |\n"
	"| it is 2, 3, or 12 (bones); he has a point  |\n"
	"| to make if it is 4, 5, 6, 8, 9, or 10.     |\n"
	"| When he gets a point, the result is not    |\n"
	"| yet decided. He must toss the bones again  |\n"
	"| and again, as often as necessary; and he   |\n"
	"| will win if his point appears again before |\n"
	"| a 7, but will lose if a 7 appears first.   |\n"
	"| If a player wins he doubles his money.     |\n"
	"+--------------------------------------------+"]) );
}
void reset() {
    ::reset();
    if(!present("bones", this_object()))
	new(OTHER "bones.c")->move(this_object());
    if(!present("bones mat", this_object()))
	new(OTHER "mat.c")->move(this_object());
}

