#include <mjungle.h>
#include <std.h>
// seeker ^^^

inherit ROOM;

object board;
int stigma;
int cmd_start(string str);

void init()
{
 ::init();
 add_action("cmd_start", "start");
}
void create() {
    ::create();
set_property("forest",1);
    set_properties( ([ "light":2,
                       "night light":2, 
                       "no steal":1,
                       "no bump":1, 
                       "no magic":1, 
                       "no castle":1,
                       "no attack":1 ]) );
set_items(([
({"moss", "vines"}): "The jungle has completely overgrown the fountain.",
]));
set_listen("default", "The jungle is strangely quiet here.");
set("short", "Overgrown fountain");
set("long", "%^BOLD%^%^MAGENTA%^You have found a fountain buried within the jungle that has been overgrown with moss and vines.  A stone wall encompasses the fountain and is covered in writing from past visitors.%^RESET%^");
    set_exits( 
(["northwest" : MJUNGLE "mjungle11.c",
"chant" : MJUNGLE "tomb1.c",
]));
add_invis_exit("chant");
board = new("std/bboard");
board->set_name("wall");
board->set_id( ({ "wall", "stone wall" }) );
board->set_max_posts(100);
board->set_location(MJUNGLE "msquare");
board->set("short", "a Stone Wall Covered in Writing");
board->set("long", "This board is covered with messages from many different travellers who have found this hidden place.\n");
board->set_board_id("stone_wall");
new (MJUNGLE "fountain")->move(this_object());
}
void reset() {
::reset();
set_search("moss", "You notice some words etched into the stone that were covered by the moss.  They say 'To enter the ancient catacomb %^MAGENTA%^<%^YELLOW%^chant%^MAGENTA%^>%^RESET%^'.");
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

this_player()->set_primary_start(MJUNGLE "msquare.c");
 write("You are now set to start here.");
 return 1;
}
