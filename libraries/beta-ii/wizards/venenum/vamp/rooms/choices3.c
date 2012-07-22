#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("CHOOSE:");
    set_long("A choice is before thou art. Thou art an accomplished wizard and thy long-time friend's prize daughter has come of age. Thy long-time friend insists that thou art pass thy skill unto her, training the daughter in the art of the arcane, despite her lackluster talent or interest in said field. Dost thou: Stride to the southeast, tutoring the youth anyway, forcing her to adopt unto her magery against her will? Or, head southwest, denying the friend, despite the divide it may cause in thy friendship?");
    set_smell("default", "There are no scents of mention here.");
    set_listen("default", "There are no sounds here.");

    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"southwest" : ROOMS"choices4.c",
	"southeast" : ROOMS"choices5.c",
      ]));
}

void init() {
    ::init();
    add_action("peer", "peer");
    add_action("survey", "survey");
}
int survey(string what) { write("Your head spins."); return 1;}
int peer(string what) {write("You don't see anything in that direction.");return 1;}
