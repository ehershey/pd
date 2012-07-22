#include <std.h>
#include <venenum.h>
inherit ROOM;

int gathered = 0;

void create() {
    ::create();
    set_short("A long corridor");
    set_long("A long rectangular corridor stretches out north to south, constructed of grey stone bricks packed together with grey mortar. Clumps of mold dot the floor, walls and ceiling here, although their growth appears to be hampered by the lack of light. The corridor is perfectly straight with little apparent purpose and the end is impossible to see.");
    set_smell("default", "It smells musty and dank here.");
    set_listen("default", "There are no sounds here.");
    set_no_clean(1);
    set_properties(([
	"light" : 1,
	"night light" : 0,
	"no teleport" : 1,
	"no_clean" : 1,
	"no clean" : 1,
	"indoors" : 1,
	"outdoors" : 0,
      ]));
    set_exits(([
	"north" : ROOMS"riddles1.c",
      ]));
    set_items(([
	({"mold"}) : "This mold appears to be growing in clumps on the surfaces of this corridor. It would appear to favor the floor as it's preferred growing place, possibly due to the larger amount of water that would gather there.",
	({"floor"}) : "The floor bears more mold then exists in other areas. The mold there appears to be less firmly attached, as well, and it's possible that a little could be gathered with some effort.",
      ]));
}

void init() {
    ::init();
    add_action("peer", "peer");
    add_action("survey", "survey");
    add_action("gather_func", "gather");
}
int survey(string what) { write("Your head spins."); return 1;}
int peer(string what) {write("You don't see anything in that direction.");return 1;}

int gather_func(str) {

    if (!str || str == "") {return 0;}
    if (str == "mold" && gathered == 0)
    {
	write("You gather up some of the mold and clump it together into a ball.");
	new(ITEM"mold.c")->move(this_player());
	gathered = 1;
	return 1;
    }
    else
    {
	return 0;
    }
}
