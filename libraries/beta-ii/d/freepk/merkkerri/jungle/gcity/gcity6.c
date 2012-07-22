#include <dquest.h>
//#include <gcity.h>
#define GCITY "/d/freepk/merkkerri/jungle/gcity/"
#include <std.h>
// seeker
inherit ROOM;
object board;
int oldman;
int cmd_start(string str);
void init()
{
 ::init();
 add_action("cmd_start", "start"); 
add_action("pray_asmodeus" , "pray");
}
void create() {
    ::create();
    set_properties( ([ "light":2,
                       "night light":2, 
                       "no steal":1,
                       "no bump":1, 
                       "no magic":1, 
                       "no castle":1,
                       "no attack":1 ]) );
set_items(([
"statue": "The statue of the lord of demons, %^BOLD%^BLACK%^Asmodeus%^RESET%^.",
]));
set_listen("default", "The town square is noisy from the sounds of busy Merkkirri going about their business.");
set_short("%^YELLOW%^Quixxiol Square%^RESET%^");
set_long("%^YELLOW%^You stand in the city square of Quixxiol, the Lost city of %^YELLOW%^Gold.  Here the four major roads of the city converge.  The %^YELLOW%^Merkkirri have kept this city hidden from outsiders for ages.  %^YELLOW%^Shops and houses line the streets and to the far west you see %^YELLOW%^a golden palace.%^RESET%^");
    set_exits( 
(["north" : GCITY "gcity7.c",
"east": GCITY "gcity5.c",
"west": GCITY "gcity11.c",
"south": GCITY "gcity8.c",
]));
board = new(BBOARD);
board->set_name("board");
board->set_id( ({ "board", "Quixxiol board" }) );
board->set_max_posts(100);
board->set_location("/d/freepk/merkkerri/jungle/gcity/gcity6.c");
board->set("short", "Quixxiol Board");
board->set("long", "This board is covered with messages from many different travellers who have found this hidden place.\n");
board->set_board_id("quixxiol_board");
new (GCITY "asmodeus.c")->move(this_object());
}
void reset() {
 ::reset();
if (!find_living("Kolbrook") || !environment(find_living("Kolbrook")))
     {
       new(MOB "oldman")->move(this_object());
     oldman=1;
    }
 
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

this_player()->set_primary_start(GCITY "gcity6.c");
 write("You are now set to start here.");
 return 1;
}

int pray_asmodeus(string what) {
if (what!= "to asmodeus")  return 1;

if (this_player()->query_paralyzed()) return 0;
if (this_player()->query_race() == "demon") {
  this_player()->move_player(DQUEST"dquest115", "into the darkness");
  return 1;
}
write("You feel a cold chill down your spine.");
this_player()->add_alignment(-5);
this_player()->set_paralyzed(5, "You are held in prayer.");
if (this_player()->query_level() > 49 &&
this_player()->query_alignment() < -1000 && this_player()->query_race() != "demon") {
  if (date(time()) == 6)
    this_player()->move_player(DQUEST"dquest104.c", "");
}
    return 1;
}
