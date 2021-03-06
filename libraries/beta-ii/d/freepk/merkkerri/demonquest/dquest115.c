#include <dquest.h>
#include <std.h>
// seeker
inherit ROOM;
object board;
int stigma;
int cmd_start(string str);
int pray_for;
void init()
{
    ::init();
    add_action("cmd_start", "start"); 
    add_action("pray_for", "pray");
}
void create() {
    ::create();
    set_properties( ([ "light":2,
	"night light":2, 
	"no steal":1,
	"no bump":1, 
	"no magic":1, 
	"no teleport":1,
	"indoors":1,
	"no attack":1 ]) );
    set_items(([
      ]));
    set_listen("default", "The screams of tortured souls echo throughout the Underworld.");
    set_smell("default", "The air reeks of thick sulfur and steam.");
    set_short("The Underworld");
    set_long("You stand within the haunting depths of oblivion that can only be "
      "described as the Underworld.  Here the Nether demons find sanctuary within the "
      "smoldering hell that surrounds them.  Screaming souls echo throughout the "
      "darkness, forever lost to the demon lord Asmodeus.");
    set_exits(([
	"up": "/d/freepk/merkkerri/jungle/gcity/gcity6.c",
      ]));
    board = new("std/bboard");
    board->set_name("board");
    board->set_id( ({ "board", "Nether board" }) );
    board->set_max_posts(100);
    board->set_edit_ok(({"stormbringer","wraith","nightshade","seeker","detach","daos"}));
    board->set_location(DQUEST "dquest115.c");
    board->set("short", "The Nether Board");
    board->set("long", "The Nether board is where Demons may post DEMON related topics and ideas.\n");
    board->set_board_id("nether_board");
}

void reset() {
    ::reset();


}
int cmd_start(string str)
{
    if (!str || str=="") 
    {
	notify_fail("Start where?\n");
	return 0;
    }

    if (str!="here")
    {
	notify_fail("You cant start there.\n");
	return 0;
    }
    this_player()->set_primary_start(DQUEST "dquest115.c");
    write("You are now set to start here.");
    return 1;
}

int pray_for(string str) {
  object tp=this_player();
  if (tp->query_disable()) return notify_fail("You are busy.\n");
  switch (str) {
    case "for amulet":
      if (present("amulet of the nether demon", tp))
        return notify_fail("You already have one!\n");
      message("info", "Your amulet is returned!", tp);
      new("/d/freepk/merkkerri/demonquest/amulet")->move(tp);
      tp->set_disable();
      return 1;
    break;
    case "to asmodeus":
      message("info", "%^BOLD%^%^WHITE%^You feel a cold chill down your spine.%^RESET%^", tp);
      tp->add_alignment(-15);
      tp->set_disable();
      return 1;
    break;
  }
  return 0;
}
