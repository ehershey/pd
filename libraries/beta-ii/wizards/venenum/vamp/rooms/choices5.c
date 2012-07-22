#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("CHOOSE:");
    set_long("A choice is before thou art. Thou art a senior member of the municipal council in the village. A man of dubious character offers thou art a sizable amount of coin to turn thy gaze from unspecified crimes at a later date. Thy family hast fallen upon hard times and yonder gold is needed urgently by thy own kin. Dost thou: Stride southeast, accepting the stranger's money, valuing thy family above thy community? Or, head southwest, refusing the gold?");
    set_smell("default", "There are no scents of mention here.");
    set_listen("default", "There are no sounds here.");

    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"southwest" : ROOMS"choices8.c",
	"southeast" : ROOMS"choices9.c",
      ]));
}

void init() {
    ::init();
    add_action("peer", "peer");
    add_action("survey", "survey");
}
int survey(string what) { write("Your head spins."); return 1;}
int peer(string what) {write("You don't see anything in that direction.");return 1;}
