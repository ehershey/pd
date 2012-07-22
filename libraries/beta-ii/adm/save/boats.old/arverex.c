/*
 Ocean Boat by Seeker 06/01/2000
 ** 06/04/2000 (made it so if theres nobody on the boat, no heartbeat)
 ** 06/17/2000 (added <enter raft> message and can hop boats)
 ** 11/02/2000 (changed the ocean around so (0,0) is wherever i want it to be)
*/

#include <std.h>
#include <daemons.h>
#include <ocean.h>

inherit PIER;

int X, Y, xx,yy, do_sail;
int mud_coords;

string dir;

string get_long();
void heart_beat();
int *query_xy();



static void create()
{
::create(); 
 
 set_short("%^BOLD%^%^BLUE%^..sailing along the ocean..%^RESET%^");
 set_long( (: get_long() :) );
set_properties( ([ "light" : 2, "no light" : 2,
                   "no teleport" : 1, "no bump" : 1 ]) );
set_items( ([ ({"ocean","water"}) : "The ocean waves move in a constant motion",
              "helm" : "The helm is used to steer the ship",
              "sails" : "The sails stand tall flapping in the wind",
              "boat" : "The boat bobs up and down in the water" ]) );
              

set_max_catch(9999);
set_max_fishing(20);
set_chance(75);
 set_fish(([
  "rainbow fish":10,
  "trout":15,
  "gold fish":5,
  "pirch":5,
  "stingray": 10,
  "lamprey":15
 ]));

}
string query_land()
{
 string *str;
 int i;
 string tmp;

 str = ({});
 tmp = "";
 if (Y<1 && X<1)
   return "\n%^BLUE%^%^BOLD%^There are strong currents to the north, and west.";
 if (X<1)
   return "\n%^BLUE%^%^BOLD%^There are strong currents to the west.";
 if (Y<1)
   return "\n%^BLUE%^%^BOLD%^There are strong currents to the north.";
 if (tmp=OCEAN_D->get_docks( OCEAN_D->get_xy(X, Y) ))
   {
    return "\n%^YELLOW%^You are docked at "+tmp->query_short()+".";    
   }
 if (OCEAN_D->get_beach( OCEAN_D->get_xy(X, Y) ))
   {
    tmp = "\n%^YELLOW%^There is a beach here.\n"+
          "%^RESET%^%^ORANGE%^You can type %^CYAN%^<%^RESET%^enter raft%^CYAN%^>%^ORANGE%^ here.";
   }

 if (OCEAN_D->get_xy(X+1, Y)=="+") str += ({ "east" });
 if (OCEAN_D->get_xy(X-1, Y)=="+") str += ({ "west" });
 if (OCEAN_D->get_xy(X, Y+1)=="+") str += ({ "south" });
 if (OCEAN_D->get_xy(X, Y-1)=="+") str += ({ "north" });

 i = sizeof(str);
 if (!i) return "%^CYAN%^%^BOLD%^\nYou are out sailing in the open sea.";
 if (tmp)
 tmp += "\n%^BLUE%^%^BOLD%^There is land to the ";
 else
 tmp = "\n%^BLUE%^%^BOLD%^There is land to the ";
 while(i--)
  {
   if (i) tmp += str[i]+", ";
   if (!i-1) tmp += "and ";
   if (!i) tmp += str[i];
  }
 tmp += ".";
 return tmp;
}
string get_long()
{
 string str;

   str =  "The mast towers above you with the sails connected to it "
          "blowing in the wind. The deck seems to be nicely layed "
          "in the boat. The helm is located right in front of you.";
  str += ""+query_land();
 return str;
}
      

void init()
{
 ::init();

 add_action("go_raft", "enter");
 add_action("go_land", "land");
 add_action("go_sail", "sail");
 add_action("location", "location");
 add_action("go_board", "board");
 set_heart_beat(2);
 
}

int go_sail(string str)
{
 int s;
 int tempx, tempy;
 string sb;
 string fil;
 fil = file_name( this_object() ) +".c";
 sscanf(fil, "/adm/save/boats/%s.c", sb);
 if (sb!=this_player()->query_name())
   {
    write("Only the owner of the boat can steer.");
    return 1;
   } 
 if (!str || str=="")
   {
    write("Sail where?");
    return 1;
   }
 if (str!="west" && str!="east" && str!="north" && str!="south")
   {
     write("You cant sail in that direction.");
     return 1;
   }
 tempx = X; tempy = Y;
 if (str=="west") tempx--;
 if (str=="east") tempx++;
 if (str=="north") tempy--;
 if (str=="south") tempy++;

 s = OCEAN_D->valid_xy(tempx, tempy);
 if (!s)
   {
    write("Strong currents prevent you from going in that direction.");
    return 1;
   }
 if (s==STRONG_CURRENTS)
   {
    write("Strong currents prevent you from going that direction.");
    return 1;
   }
 if (s==LAND)
   {
    write("Land prevents you from going in that direction.");
    return 1;
   }
 xx = tempx;
 yy = tempy;
 do_sail = 1;
 write("You point your sails "+str+".");
 say( this_player()->query_cap_name()+" points the sails "+str+".");
 dir = str;

 return 1;
}
int go_land()
{
 string str;

   if ( !str = OCEAN_D->get_docks( OCEAN_D->get_xy(X,Y) ))
   {
    write("...There is no land to goto...");
    return 1;
   }
 write("You exit the boat.");
 this_player()->move_player(str, "off the boat"); 
 
 return 1;
}

int go_raft(string str)
{
 object ob;
 string fil;

 if (str!="raft")
   {
    write("Enter what?");
    return 1;
   }
  fil = OCEAN_D->get_beach( OCEAN_D->get_xy(X,Y) );
    if (!fil) 
      {
       write("You cannot use a raft here.");
       return 1;
      }
    write("You enter a raft and float to land.");
    ob = new("/std/obj/raft");
    ob->move( get_object(fil) );
    ob->set_goto( file_name(this_object()) );
    this_player()->move_player(fil, "in a raft");

    
    return 1;
   
}
int go_board(string str)
{
 string st; 
 int X,Y,x,y;
 if (!str || str=="")
   return notify_fail("Board what?\n");
 st = "/adm/save/boats/"+str+".c";
 X = st->query_xy()[0]; Y = st->query_xy()[1];
 x = query_xy()[0]; y = query_xy()[1];
 if (X!=x || y!=Y)
   return notify_fail("You do not see that boat anywhere.\n");
 write("You board "+capitalize(str)+"'s boat.");
 say( this_player()->query_cap_name()+" boards "+capitalize(str)+"'s boat.");
 this_player()->move("/adm/save/boats/"+str);
 say( this_player()->query_cap_name()+" boards the boat.");
 return 1;
}
int *query_xy()
{
 return ({X,Y});
}
void set_xy(int x, int y)
{
 X = x;
 Y = y;
}

void heart_beat()
{
 object *ob;
 int i, a;
 
 // shuts off the heart beat if there is no interactive players in the room
 ob = all_inventory(this_object()); 
 i = sizeof(ob);
 while(i--) { if (interactive(ob[i])) a=1; }
 if (!a) { set_heart_beat(0); return; }
 
if (do_sail)
{
 i = sizeof(ob);
 while(i--)
  {
   if (ob[i]->is_player()) {
     message("info", "The boat sails to the "+dir+".", ob[i]);
     }
  }
 do_sail = 0;
 X=xx;
 Y=yy;
 all_inventory(this_object())->describe_current_room(1);
 }
}
int location()
{
 int *i;
 i = OCEAN_D->get_mudcoord_from_graphcoord(({X, Y}));
 write("You are at ("+i[0]+", "+i[1]+")");
 return 1;
}
