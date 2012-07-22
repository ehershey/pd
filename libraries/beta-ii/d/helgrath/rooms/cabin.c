#include <std.h>
#include <daemons.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
	"light" : 2,
	"indoors" : 1
      ]));
    set_short("Cabin");
    set_long("Aged oak planks form sturdy walls in this huge room. A slight "
      "breeze flows through the open door, dragging a current of dust lazily "
      "across the cold stone floor. A large fire crackles merrily in a "
      "hearth in the eastern wall. This does nothing, however, to tame the "
      "rabid bite of the cold mountain air. "
    );
    set_exits( ([ "south" : ROOMS "mountain01.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The wind howls sharply through the peaks.");
    set_items( ([
	"fire" : "A large fire crackles merrily in a hearth in the eastern wall.",
	"hearth" : "A fireplace made of stone.  Something seems there is "
	"something strange about it.",
      ]) );
}

void reset(){
    ::reset();
    if(present("old map")) return;
    new(ITM"maphelgrath.c")->move(this_object());
}

void init() {
    ::init();
    //add_action("enter", "enter");
}

int enter(string str) {
    if(!str || str != "hearth") return notify_fail("Enter what?\n");
    if(this_player()->query_guild() != "AoD" && !wizardp(this_player()))
	return notify_fail("A magical force holds you back.\n");
    if(GUILD_D->query_locked() && !wizardp(this_player())) return 
	notify_fail(GUILD_D->query_lock_reason());

    this_player()->move_player("/d/guilds/AoD/helgrath/hall");
    return 1;
}

