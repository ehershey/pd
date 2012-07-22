#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("CHOOSE:");
    set_long("A choice is before thou art. Thou art a wealthy man, walking down yonder path when thou art dost catch a homeless vagabond fleecing thy purse. Dost thou: Go southeast, hailing the guards to arrest the thief? Or head unto the southwest, by thy grace considering it a gift as his need outweighs thy own?");
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
