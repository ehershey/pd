/*
 Ocean Daemon by Seeker 06/02/2000
*/
//  Redesigned for Ocean Combat.  -- Whit
/* You can modify anything below this line in the ocean */
#include <security.h>
static mapping ships;
static mapping coords;
static string *ocean_map = ({
  "*****************************************************************************",
  "*---------------------------------------------------------------------------*",
  "*---------------------------------------------------------------------------*",
  "*-------+++--++++--------------------+++------------------------------------*",
  "*--------+++++++++++------------++++++++++-----+++--------------------------*",
  "*--------+++++++++++++++-----+++++++++++++++--+++---------------------------*",
  "*-------++++++++++++++++++--+++++++++++++++++++++B------------++------------*",
  "*-------++++++++++++++++++++++++++++++++++++++++++----------+++++-----------*",
  "*--------++++++++++++++++++++++++++++++++++++++++---------++++++++----------*",
  "*--------++++++++++++++++++++++++++++++++++++++----------++++++++-----------*",
  "*---------++++++++++++++++++++++++++++++++++++-----------+++++++------------*",
  "*----------+++++++++++++++++++++++++++++++++++------------++++++++----------*",
  "*-----------++++++++++++++++++++++++++++++++++++-----------+++++++----------*",
  "*-----------+++++++++++++++++++++++++++++++++++++-----------+++++++---------*",
  "*----------+++++++++++++++++++++++++++++++++++++--------------++++----------*",
  "*----------++++++++++++++++++++=+++++++++++++++++--------------++j----------*",
  "*--------+++++++++++++++++++++++++++++++++++++++++--------------------------*",
  "*-------+++++++++++++++++++++++++++++++++++++++++++-------------------------*",
  "*------d++++------++++++-----+++A+++--a------+++++++------------------------*",
  "*-------+++------------------------------------+++++------------------------*",
  "*-----------------------------------------------+++-------------------------*",
  "*------------------------------------------------+--------------------------*",
  "*---------------------------------------------------------------------------*",
  "*----++---c+++--------------------------------------------------------------*",
  "*---+++++++++++-------------------------------------------------------------*",
  "*---+++++++++++----------------------------------k+-------------------------*",
  "*------++++++++------------------------+---------+--------------------------*",
  "*-----------++-------------------------+-------------------------+----------*",
  "*--------------------------------------+-------------------------++---------*",
  "*--------------------------------------+--------------------------++--------*",
  "*---------+++--------------------------h---------------------------++-------*",
  "*----+++++++++-------------------------------------------------+----i+------*",
  "*---+++++++++++-----------------------------------------------+++-----------*",
  "*---+++++++++++---+e-----g+----------------------------------+++++----------*",
  "*----++++++++b----+++-++--+----------------------------------++++-----------*",
  "*----++++++++------------------------------+++------------++++++++----------*",
  "*-------++++-----+f--++-----------------+++++++++-------+++++++++-----------*",
  "*----------------+-----------++++----++++++++++++++---++++++++++++----------*"
  "*---------------------------+++++++++++++++++++++++++++++++++++++++---------*",
  "*--------------------------+++++++++++++++++++++++++++++++++++++++----------*",
  "*---------------------------++++++++++++++++++++++++++++++++++++++----------*",
  "*---------------------------++++++++++++++++++++++++++++++++++++------------*",
  "*--------------------------+++++++++++++++++++++++++++++++++++--------------*",
  "*--------------------------++++++++++++++++++++++++++++++++++++-------------*",
  "*--------++l----------------++++++++++++++++++++++++++++++++++++------------*",
  "*-------++++----------------C++++++++++++++++++++++++++++++++++++-----------*",
  "*------++++------------------+++++++++++++++++++++++++++++++++++++----------*",
  "*------+++-------------------++++++++++++++++++++++++++++++++++++-----------*",
  "*------++++------------------++++++++++++++++++++++---------+++++++---------*",
  "*-------++--------------------++++++++++++++++++++-------------++++---------*",
  "*------------------------------++++--+++++++++++-----+++--------++----------*",
  "*-------------------------------+++----++++++++-----+++--------+------------*",
  "*----------------------------------------++++++------+++--------------------*",
  "*------------------------------------------+++++----------------------------*",
  "*--------------------------------------------++++---------------------------*",
  "*---------------------------------------------------------------------------*",
  "*****************************************************************************"});
/* 
   +-------------------+
   |        Key        |
   +-------------------+
   |                   |
   | land           +  |
   | water          -  |
   | fast currents  *  |
   | ??????         #  |
   +-------------------+
*/
mapping upgrades, hp_data;
int damaged, speed;
string owner;
#define ZERO ({ 34, 26 })

// This is places that need rafts to get to the island and back
// no docks. (these places use lowercase letters)
static mapping beach = ([ "a" : "/d/tirun/beach2",
  "b" : "/
/merkkerri/jungle/merkkirri/mjungle1",
                   "c" : "/wizards/powerman/room/patha",
                   "d" : "/d/shadow/rooms/entrance.c",
                   "e" : "/d/keys/til/beach",
                   "f" : "/d/keys/sorn/beach",
                   "g" : "/d/keys/dou/beach",
                   "h" : "/d/keys/sand/beach",
                   "i" : "/d/keys/great_sand/beach",
                   "j" : "/d/purgatory/room/landing",
                   "k" : "/d/guilds/illuminati/new/beach.c",]);
//                   "l" : "/d/metaisland/area/beach1" ]);
// This is the places that have docks and the boat can <sail land> to,
// no rafts needed to get to the land or island 
// (these places use uppercase letters)
static mapping docks = ([ "A" : "/d/tirun/loadb",
                   "B" : "/d/helgrath/rooms/forest_pier",
                   "C" : "/d/rhondale/keep/rooms/zvillage/docks" ]);
 
/* --- Dont mess with anything below this line ----- */
 
 
#include <std.h>
#include <daemons.h>
#include <ocean.h>
 
static int MAX_OCEAN_X = sizeof(ocean_map[0]);
static int MAX_OCEAN_Y = sizeof(ocean_map);
int *get_graphcoord_from_mudcoord(int *coord)
{
 int x2,y2,x1,y1, *i, x3,y3;
 x2 = coord[0]; y2 = coord[1];
 i = OCEAN_D->query_zero();
 x1 = i[0]; y1 = i[1];
 x3 = x2-x1;
 y3 = y1 - y2;
 return ({x3, y3});
}
int *get_mudcoord_from_graphcoord(int *coord)
{
 int x2,y2, x1, y1, *i, x3, y3;
 x2 = coord[0]; y2 = coord[1];
 i = OCEAN_D->query_zero();
 x1 = i[0]; y1 = i[1];
 
 x3 = x2 - x1;
 y3 = y1 - y2;
 return ({ x3 , y3 });
}
 
int *query_coord_from_letter(string str)
{
 int a, y;
 a = MAX_OCEAN_Y;
 while(a--)
  {
   if (strsrch(ocean_map[a], str)!=-1)
     {
      y = a;
      a = sizeof(ocean_map[a]);
      while(a--)
       if (ocean_map[y][a..a]==str)
         return ({a,y});
     }
  }
 return ({});
}
int *query_zero() { return ZERO; }
int valid_xy(int x, int y)
{
 if (x>=MAX_OCEAN_X || y>=MAX_OCEAN_Y || x<=0 || y<=0)
   return STRONG_CURRENTS;
 
 if (ocean_map[y][x..x]=="*") return STRONG_CURRENTS;
 if (ocean_map[y][x..x]=="+") return LAND;
 return OK_TO_MOVE;
}
string get_xy(int x, int y)
{
 
 return ocean_map[y][x..x];
}
string get_beach(string a)
{
 return beach[a];
}
string get_docks(string a)
{
 return docks[a];
}
int set_boat(object o) {
   if(!ships[o->query_owner()]) ships[o->query_owner()]=([]);
   ships[o->query_owner()]["boatob"]=o;
   return 1;
}
object get_boat(string p) {
   if(!ships[p]) return 0;
   if(!ships[p]["boatob"]) return 0;
   return ships[p]["boatob"];
}
void ship_location(object o, int x, int y) {
   int *old;
   string a;
   if(!ships[o->query_name()]) set_boat(o);
   old=ships[o->query_owner()]["boatob"]->query_xy();
   ships[o->query_owner()]["xy"]=({x,y});
   a=x+","+y;
   if(!coords[a]) coords[a]=({});
   if(old != 0 && sizeof(old) != 0) {
     a=old[0]+","+old[1];
     if(!coords[a]) return;
     coords[a] -= ({ o });
   }
   coords[a] += ({ o });
}
int *get_ship_location(mixed o) {
   string name;
   if(!objectp(o) && !stringp(o)) error("Invalid Type Argments.\n");
   if(objectp(o)) name=o->query_owner();
   else name=o;
   if(!ships[name]) return ({});
   if(!ships[name]["xy"]) return ({ 32, 18 });
   return (int *)ships[name]["xy"];
}
object *get_room_ships(object o, int x, int y) {
   object *s;
   int *c,i;
   string a;
   object *out;
   if(!x && !y) {
     c=get_ship_location(o);
     x=c[0]; y=c[1];
   }
   a=x+","+y;
   out=({});
   if(!coords[a]) return ({});
   i=sizeof(coords[a]);
   while(i--) {
     if(!(object)coords[a][i]) (object)coords[a]-= ({ (object)coords[a][i] });
   }
   return coords[a];
}
void create() {
   coords=([]);
   ships=([]);
   this_object()->clean_up_ocean();
}
string *get_map() { return ocean_map; }
void clean_up_ocean() {
   object *o, cur;
   int i, x, y;
   o=children("/wizards/whit/ocean/boat");
   if(!o) {
     call_out("clean_up_ocean", 60);
     return;
   }
   i=sizeof(o);
   while(i--) {
     cur=o[i];
     if(file_name(cur) == "/wizards/whit/ocean/boat.c") continue; //  Leave the main alone.
     if(!cur) continue;
     if(!cur->query_owner()) { cur->remove(); continue; }
     if(sizeof(cur->query_xy()) == 2)
       ship_location(cur, cur->query_xy()[0], cur->query_xy()[1]);
   }
   call_out("clean_up_ocean", 60);
}
mapping get_ships() { return ships; }
mapping get_coords() { return coords; }
void init_new_boat(string s) {
   damaged=0;
   speed=3;
   upgrades=([]);
   upgrades["armour"]=1;
   upgrades["cannon"]=1;
   hp_data=([]);
   owner=s;
   seteuid(UID_BOATSAVE);
   save_object("/adm/save/boats/"+s);
   seteuid(geteuid());
}
