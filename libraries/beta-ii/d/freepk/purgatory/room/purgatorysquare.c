#include <std.h>
#include <purgatory.h>
inherit ROOM;
void create() {
    object board;
    ::create();
    set_properties( ([ 
	"no bump"     : 1,
	"light"       : 2,
	"no attack"   : 1,
	"no magic"   : 1,
	"night light" : 1,
	"no steal"    : 1, ]) );
    set_property("town",1);
    set_listen("default", "The wails of tortured souls echo around this place.");
    set_smell("default", "A strange scent wafts in from the north.");
    set_short("Purgatory Crossroads");
    set_long("Purgatory Crossroads.\n"
      "An eerie sense of foreboding permeates this place like rancid "
      "meat. The broken people of Purgatory wander aimlessly through "
      "the crossroads. The statue of Death looms over the crossroads "
      "as if reminding whomever enters this area of who dwells here. "
      "Trampled bodies line the gutters of the streets from the last mad dash "
      "for safety. ");
    set_exits((["north" : ROOMS "purgatory1",
	"south" : ROOMS "purgatory3",
	"west" :  ROOMS "purgatory2",
	"east" : ROOMS"purgatory4",
      ]));
    set_items( ([
	"Death"  : "You can feel a chill enter your bones as you gaze "
	"into the folds of Death's shrouded form.",
	"plaque" : "Death himself ordered this visage of himself to"
	" remind the people of Purgatory of who brought them all here.",
      ]) );
    board = new("/std/bboard");
    board->set_board_id("Purgatory_board");
    board->set_id(({"board", "purgatory board"}));
    board->set_name("Purgatory Board of Redemption");
    board->set_short("Purgatory Board of Redemption");
    board->set_long("This is the Purgatory Board of Redemption. All those who wish to be redeemed will post their most sincere apologies for trespassing on the Kings land!");
    board->set_location("/d/freepk/purgatory/room/purgatorysquare.c");
    board->set_edit_ok(({"luna", "stormbringer", "daboura", "nightshade", "nesoo", "azire"}));

    board->set_max_posts(100);
    board->set_board_name("Purgatory Board of Redemption");

}

void init() {
    ::init();
    add_action("cmd_start", "start");
}


void reset() {
    object mob;
    ::reset();
    if (!present("guard", this_object())) {
	mob = new(MOBS"skeleton.c" );
        mob->set_aggressive(0);
        mob->move(this_object());
    }

    if (!present("fountain", this_object()))
	new(ITEMS"fountain" )->move(this_object());
}

int cmd_start(string str)
{
    if (!str | str=="") 
    {
	notify_fail("Start where?\n");
	return 0;
    }

    if (str!="here")
    {
	notify_fail("You cannot start there.\n");
	return 0;
    }


    this_player()->set_primary_start("/d/freepk/purgatory/room/purgatorysquare");
    write("You are now set to start here.");
    return 1;
}
