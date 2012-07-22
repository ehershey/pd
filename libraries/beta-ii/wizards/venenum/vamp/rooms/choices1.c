#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("CHOOSE:");
    set_long("A choice is presented to thou art. Thou art a virtuous person, but thy friend hath been slain by a dragon most fierce. Alas the dragon is the sole benefactor for an impecunious waif in the city. Dost thou: Traipse southeast, exterminating yonder dragon and soliciting just revenge? Or wander to the southwest, staying thy righteous hand out of concern for the child?");
    set_smell("default", "There are no scents of mention here.");
    set_listen("default", "There are no sounds here.");

    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"southeast" : ROOMS"choices3.c",
	"southwest" : ROOMS"choices2.c",
      ]));
}

void init() {
    ::init();
    add_action("peer", "peer");
    add_action("survey", "survey");
}
int survey(string what) { write("Your head spins."); return 1;}
int peer(string what) {write("You don't see anything in that direction.");return 1;}
