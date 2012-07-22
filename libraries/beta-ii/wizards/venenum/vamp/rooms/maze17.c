#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("A dark and musty mausoleum");
    set_long("This stone passage twists and winds, being deliberately constructed to confuse and ward off any thieves. A body lies on the floor here, boated and bloody, appearing reasonably fresh. The walls are crafted from stone bricks set in place by mortar.");
    set_smell("default", "The sweet smell of crushed roses and earth is present here.");
    set_listen("default", "As quiet as a grave.");

    set_properties(([
	"light" : 1,
	"night light" : 0,
	"no_clean" : 1,
	"no clean" : 1,
	"indoors" : 1,
	"outdoors" : 0,
      ]));
    set_exits(([
	"north" : ROOMS"maze26.c",
      ]));
    set_no_clean(1);
}

void init() {
    ::init();
    add_action("peer", "peer");
    add_action("survey", "survey");
    new(ITEM"body.c")->move(this_object());
}
int survey(string what) { write("Your head spins."); return 1;}
int peer(string what) {write("You don't see anything in that direction.");return 1;}
