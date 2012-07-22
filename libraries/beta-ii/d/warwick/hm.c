#include <std.h>
#include <daemons.h>

inherit ROOM;
object ob;

void create() {
   ::create();
   set_name("High Mortal Hall");
   set_short("Warwick Castle - High Mortal Hall");
   set_long("Welcome to Warwick Castle - High Mortal hall!\nThis is the high mortal area of "
     "the castle.  Only those of high mortal status and above may enter here, for it is a safe haven "
     "for only high mortals.  A small couch sits in the center of the room.  A cozy "
     "fire is burning heavily in a fireplace.  A large fountain also sits here "
     "in the room.  There is a spiral staircase here, "
     "leading up into the upper level of the castle.");
   set_exits(([ "south":"/d/warwick/main", 
                "north":"/d/warwick/hmstorageshop",
                "up":"/d/warwick/elite" ]));
   set_properties(([
       "light":2, "night light":2, "no attack":1, "no magic":1, 
       "no bump":1, "no steal":1, "indoors":1, "no teleport":1,
     ]));
   set_pre_exit_functions(({"up"}), ({"go_stairs"}));
    ob = new(BBOARD);
    ob->set_name("high mortal board");
    ob->set_location("/d/warwick/hm.c");
    ob->set_id( ({ "board", "high mortal board" }) );
    ob->set_board_id("high_mortal_board");
    ob->set_max_posts(999);
    ob->set_short("High Mortal Board");
    ob->set_long("The High Mortal Board.");
}

void reset() {
   ::reset();
   if(!present("fountain"))
   new("/d/warwick/fountain")->move(this_object());
}

int go_stairs() {
   if(this_player()->query_level() < 50) {
     write("A force repels you.");
     say(this_player()->query_cap_name()+" tries to walk up the stairs but is forced back.");
     return 0;
   }
   return 1;
}
