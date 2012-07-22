#include <std.h>
#include <tirun.h>
#undef VOTE_CLOSED
#define ELECTION_CLOSED
inherit ROOM;
void create() {
    object board;
    ::create();
    set_properties(([ "light" : 2,  "night light" : 2,  "no steal" : 1,
        "no wander" : 1,
	"indoors" : 1, "no magic" : 1, "no castle" : 1, "no attack" : 1 ]));
    set_short("Lar's Message Board Room");
    set_long(
      "The Drowning Fish Tavern\n"
      "This is the south end of the bar.  An extremely old message "
      "board hangs from the wall to the south.  The floor, composed "
      "of long pieces of mahogany, has been worn greatly with years "
      "of use.  This is the best place in town to keep up with current "
      "events, as most everyone passing by the bar with any news, will "
      "post it on the message board.  A barkeep tends the bar to the north. ");
    set_items(([
	"bar" : "A large counter that has been polished smooth with years of use.",
      ]));

    set_exits( ([
//	"up" :  ROOMS "booth.c",
	"up" :  ROOMS "voteroom.c",
	"east" :  ROOMS "electionhall",
	"north" :  ROOMS "pub.c",
      ])
    );

    add_pre_exit_function("up", "go_up");
    add_pre_exit_function("east", "go_east");
    board = new("std/bboard");
    board->set_name("board");
    board->set_id( ({ "board", "tirun board" }) );
    board->set_max_posts(999);
board->set_edit_ok(({"stormbringer","nulvect","azire","daos","whit","daboura","carina","vian","gob", "amun" }));
    board->set_location("d/nopk/tirun/pubstart");
    board->set("short", "Tirun Board");
    board->set("long", "This is the main board of Primal Darkness.\n");
    board->set_board_id("newbie");
}

int go_up() {
#ifdef VOTE_CLOSED
    if(wizardp(this_player())) return 1;
    write("The voting booth is closed.");
    say(this_player()->query_cap_name()+" is prevented from going up.\n");
    return 0;
#else
    return 1;
#endif
}
int go_east() {
#ifdef ELECTION_CLOSED
    if(wizardp(this_player())) return 1;
    write("The polls are currently closed.");
    say(this_player()->query_cap_name()+" is prevented from going east.\n");
    return 0;
#else
    return 1;
#endif
}
