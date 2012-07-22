#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("CHOOSE:");
    set_long("A choice is before thou art. Thou art are a king, newly appointed. A long time friend of thy self is on trial for murder. In thy mind thou art be certain of his guilt, but thy friend appeals to thy friendship. Thou art aware thy friend regrets his rash actions and thou art doth have the power to release him should thou art choose. Do you: Wander southeast, having thy friend tried and executed for crimes truely commited? Or, head southwest, pardoning thy friend, knowing him to be a good person at heart?");
    set_smell("default", "There are no scents of mention here.");
    set_listen("default", "There are no sounds here.");

    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"southwest" : ROOMS"choices7.c",
	"southeast" : ROOMS"choices8.c",
      ]));
}

void init() {
    ::init();
    add_action("peer", "peer");
    add_action("survey", "survey");
}
int survey(string what) { write("Your head spins."); return 1;}
int peer(string what) {write("You don't see anything in that direction.");return 1;}
