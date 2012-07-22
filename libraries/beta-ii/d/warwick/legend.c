#include <std.h>
#include <daemons.h>

inherit ROOM;
object ob;

void create() {
   ::create();
   set_name("main hall");
   set_short("Warwick Castle - Legend Hall");
   set_long("Welcome to Warwick Castle - Legend Hall!\nThis is the legend hall.  Only those "
     "who have traveled the lands near and far may enter here.  Those who are here have "
     "proven themselves in the halls of the greats.  A set of stairs leads up "
     "into the highest reach of the castle.");
   set_exits(([ "north":"/d/warwick/elite",
                "south":"/d/warwick/legendstorageshop",
                "up":"/d/warwick/lshop" ]));
   set_properties(([
       "light":2, "night light":2, "no attack":1, "no magic":1, 
       "no bump":1, "no steal":1, "indoors":1, "no teleport":1,
     ]));

    ob = new(BBOARD);
    ob->set_name("legend board");
    ob->set_location("/d/warwick/legend.c");
    ob->set_id( ({ "board", "legend board" }) );
    ob->set_board_id("legend_board");
    ob->set_max_posts(999);
    ob->set_short("Legend Board");
    ob->set_long("The Legend Board.");
}
