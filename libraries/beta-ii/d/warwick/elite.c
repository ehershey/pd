#include <std.h>
#include <daemons.h>

inherit ROOM;

object ob;

void create() {
   ::create();
   set_name("main hall");
   set_short("Warwick Castle - Elite Hall");
   set_long("Welcome to Warwick Castle - Elite Hall!\nThis is the wonderful "
     "elite hall.  Several paintings adorn the walls of fierce battles "
     "across the lands.  Here is an area where elites may rest without fear "
     "from the rest of the world.");
   set_exits(([ "south":"/d/warwick/legend",
                "north":"/d/warwick/elitestorageshop",
                "down":"/d/warwick/hm" ]));
   set_properties(([
       "light":2, "night light":2, "no attack":1, "no magic":1, 
       "no bump":1, "no steal":1, "indoors":1, "no teleport":1,
       ]));
   set_pre_exit_functions(({"south"}), ({"go_south"}));
    ob = new(BBOARD);
    ob->set_name("elite board");
    ob->set_location("/d/warwick/elite.c");
    ob->set_id( ({ "board", "elite board" }) );
    ob->set_board_id("elite_board");
    ob->set_max_posts(999);
    ob->set_short("Elite Board");
    ob->set_long("The Elite Board.");
}

int go_south() {
   if(this_player()->query_level() < 100) {
     write("A force repels you.");
     say(this_player()->query_cap_name()+" tries to walk south but is forced back.");
     return 0;
   }
   return 1;
}

