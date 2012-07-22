#include <locations.h>
#include <locations.h>
#include <std.h>
inherit OBJECT;
static int red, green, yellow, blue;

void create() {
 ::create();
   set_name("slab");
   set_short("a game slab");
   set_long("A stone slab with points inscribed on it.");
   set_weight(1);
   set_value(0);
   set_id(({ "slab", "tablet" }));
   red = 0;
   green = 0;
   yellow = 0;
   blue = 0;
}

void init() {
 ::init();
   add_action("total", "total");
   add_action("endgame", "endgame");
}

int total() {
   tell_object(users(), "%^RESET%^%^CYAN%^Total points from the paintball tag game:%^RESET%^");
   tell_object(users(), "%^RESET%^The %^RED%^ Red%^RESET%^    Team   : "
         +(string)red);
   tell_object(users(), "%^RESET%^The %^GREEN%^ Green%^RESET%^  Team   : "
         +(string)green);
   tell_object(users(), "%^RESET%^The %^YELLOW%^ Yellow%^RESET%^ Team   : "
         +(string)yellow);
   tell_object(users(), "%^RESET%^The %^BLUE%^ Blue%^RESET%^   Team   : "
         +(string)blue);
   return 1;
}

int endgame()
{
 object *players; 
 int i;

 players = "/d/paintball/start"->query_players(); 
 i = sizeof(players);
 while(i--)
   {
   if (!players[i]) continue;
    present("gun", players[i])->remove();
    players[i]->move_player(SQUARE_LOC, "out of the arena");
    message("info", "You are transported out of the arena.", players[i]);
   }
 message("info", "The scores for paintball were:", users());
 message("info", "%^RED%^[Red]%^RESET%^ Score: "+red, users());
 message("info", "%^GREEN%^[Green]%^RESET%^ Score: "+green, users());
 message("info", "%^BLUE%^[Blue]%^RESET%^ Score: "+blue, users());
 message("info", "%^YELLOW%^[Yellow]%^RESET%^ Score: "+yellow, users());

 if (i < red) i = red;
 if (i < green) i = green; 
 if (i < blue) i = blue; 
 if (i < yellow) i = yellow;
 if (i==red) message("info", "%^RED%^The RED team won!!!!!%^RESET%^", users());
 if (i==green) message("info", "%^GREEN%^The GREEN team won!!!!!%^RESET%^", users());
 if (i==blue) message("info", "%^BLUE%^The BLUE team won!!!!!%^RESET%^", users());
 if (i==yellow) message("info", "%^YELLOW%^The YELLOW team won!!!!!%^RESET%^", users());
 
 return 1;
}
void do_points(string str, int i) {
 if (i) 
   {
   if (str == "red")      red--;
   if (str == "green")    green--;
   if (str == "blue")     blue--;
   if (str == "yellow")   yellow--;
   return;
   }

   if (str == "red")      red++;
   if (str == "green")    green++;
   if (str == "blue")     blue++;
   if (str == "yellow")   yellow++;
}
