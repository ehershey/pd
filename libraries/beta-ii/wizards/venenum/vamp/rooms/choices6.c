#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("CHOOSE:");
    set_long("A choice is before thou art. Thou art a poor farmer of the land. Thy family starves due to drought and a keen winter, but a noble offers thou art a loan to help thou art and thy kin pass the bleak months. However such debt would be impossible to repay on a farmer's profit. Alternatively, thou art possesses a rusty sword- thou art could turn to robbery to survive. Dost thou: Walk southeast, turning to banditry only to survive? Or, head southwest, accepting the loan?");
    set_smell("default", "There are no scents of mention here.");
    set_listen("default", "There are no sounds here.");

    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"southwest" : ROOMS"choices9.c",
	"southeast" : ROOMS"choices10.c",
      ]));
}

void init() {
    ::init();
    add_action("peer", "peer");
    add_action("survey", "survey");
}
int survey(string what) { write("Your head spins."); return 1;}
int peer(string what) {write("You don't see anything in that direction.");return 1;}
