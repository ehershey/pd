#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("CHOOSE:");
    set_long("A choice is before thou art. Disease hath claimed the life of thy old comrade, and during thy youth a pact you swore that, if either should fall, the survivor would attend to the fallen other's funeral arrangements. Thy honour demands thou art travel to the place of his death and see to his remains. However, thy own village is under the threat of a powerful dragon, and every sword arm is needed to defend the innocent. Dost thou: Head southwest, staying to defend thy village, forsaking thy honour and promising on thy word to attend to the buriel later? Or head southeast, forsaking thy home town in the pursuit of honour?");
    set_smell("default", "There are no scents of mention here.");
    set_listen("default", "There are no sounds here.");

    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"southwest" : ROOMS"passed.c",
	"southeast" : ROOMS"failed.c",
      ]));
}

void init() {
    ::init();
    add_action("peer", "peer");
    add_action("survey", "survey");
}
int survey(string what) { write("Your head spins."); return 1;}
int peer(string what) {write("You don't see anything in that direction.");return 1;}
