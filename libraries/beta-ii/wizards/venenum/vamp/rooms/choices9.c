#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("CHOOSE:");
    set_long("A choice is before thou art. Thou art hath slain a dragon which has rained dispair down upon a hapless village for many a'year. However, thy long-time friend hath also laid claim to the kill (and the subsequent reward) for himself. Thy friend hath many kin to support, but the killing blow was thine. Dost thou: Walk southwest, holding thy tongue, allowing thy friend to claim glory and wealth undeserving? Or head southeast, stepping up to claim thy just reward?");
    set_smell("default", "There are no scents of mention here.");
    set_listen("default", "There are no sounds here.");

    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"southwest" : ROOMS"failed.c",
	"southeast" : ROOMS"passed.c",
      ]));
}

void init() {
    ::init();
    add_action("peer", "peer");
    add_action("survey", "survey");
}
int survey(string what) { write("Your head spins."); return 1;}
int peer(string what) {write("You don't see anything in that direction.");return 1;}
