/*
 Ocean Boat by Seeker 06/01/2000
 ** 06/04/2000 (made it so if theres nobody on the boat, no heartbeat)
 ** 06/17/2000 (added <enter raft> message and can hop boats)
 ** 11/02/2000 (changed the ocean around so (0,0) is wherever i want it to be)
*/
#include <std.h>
#include <ocean.h>
#include <security.h>
#define OCEAN_D  "/wizards/whit/ocean/ocean"
inherit PIER;
inherit "/wizards/whit/ocean/shipcombat";
static int X, Y, xx,yy;
static int mud_coords;
static string docked;
//  Save Variables
int speed;
string owner;
string query_docked();
void set_docked(string let);
string get_long();
int *query_xy();
string query_owner();
void set_owner(string name);
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
    object *s;
    string *str, *ice, out;
    int i, block;
    string tmp;
    str = ({});
    ice = ({});
    out = "";
    tmp = "";
    if (Y<1 && X<1)
	out += "\n%^BLUE%^%^BOLD%^There are strong currents to the north, and west.";
    if (X<1)
	out += "\n%^BLUE%^%^BOLD%^There are strong currents to the west.";
    if (Y<1)
	out += "\n%^BLUE%^%^BOLD%^There are strong currents to the north.";
    if (tmp=OCEAN_D->get_docks( OCEAN_D->get_xy(X, Y) )) {
	if(!query_docked()) out += "%^BOLD%^%^CYAN%^There are some docks near here."
	    "  You may <dock> to to dock your ship.%^RESET%^\n"; else
	    out += "\n%^YELLOW%^The ship is docked at "+tmp->query_short()+"."
	    "You may <sail out> to return to the ocean.\n";
    }
    if (OCEAN_D->get_beach( OCEAN_D->get_xy(X, Y) )) {
	out += "\n%^YELLOW%^There is a beach here.\n"+
	"%^RESET%^%^ORANGE%^You can type %^CYAN%^<%^RESET%^enter raft%^CYAN%^>%^ORANGE%^ here.";
    }
    if (OCEAN_D->get_xy(X+1, Y)=="+") str += ({ "east" });
    if (OCEAN_D->get_xy(X-1, Y)=="+") str += ({ "west" });
    if (OCEAN_D->get_xy(X, Y+1)=="+") str += ({ "south" });
    if (OCEAN_D->get_xy(X, Y-1)=="+") str += ({ "north" });
    if (OCEAN_D->get_xy(X+1, Y)=="$") ice += ({ "east" });
    if (OCEAN_D->get_xy(X-1, Y)=="$") ice += ({ "west" });
    if (OCEAN_D->get_xy(X, Y+1)=="$") ice += ({ "south" });
    if (OCEAN_D->get_xy(X, Y-1)=="$") ice += ({ "north" });
    i = sizeof(str);
    if (!i && OCEAN_D->get_xy(X, Y) != "%" && !query_docked()) 
	out += "%^CYAN%^%^BOLD%^\nYou are out sailing in the open sea.\n";
    if(!query_docked() && i) {
	out += "\n%^BLUE%^%^BOLD%^There is land to the ";
	while(i--)
	{
	    if (i) out += str[i]+", ";
	    if (!i-1) out += "and ";
	    if (!i) out += str[i];
	}
	out += ".%^RESET%^\n";
    }
    i = sizeof(ice);
    if(!query_docked() && i) {
	out += "\n%^CYAN%^%^BOLD%^There is ice to the ";
	while(i--)
	{
	    if (i) out += str[i]+", ";
	    if (!i-1) out += "and ";
	    if (!i) out += str[i];
	}
	out += ".%^RESET%^\n";
    }
    if(OCEAN_D->get_xy(X, Y) == "%") {
	out += "%^BOLD%^%^MAGENTA%^Some coral reef shines through the top of the water.%^RESET%^\n";
    }
    if(s=OCEAN_D->get_room_ships(this_object(), X, Y)) {
	s -= ({this_object()});
	i=sizeof(s);
	if(i) 
	    out += "%^BOLD%^%^BLUE%^There are "+i+" ships near here.%^RESET%^\n";
    }
    return out;
}
string get_long()
{
    string str;
    if(!query_night()) str="The ship is spacious "
	"compared to those of the fishing ships.  A "
	"tall mast rises above the deck holding the "
	"sails at the top.  Rope and normal ship "
	"supplies lay scattered about the ship.  The"
	" helm is in front of you.\n";
    if(query_night()) str="The gentle waves lap "
	"over the sides of hull gently.  A cool breeze "
	"blows slightly.  A dull lantern hangs from one "
	"of the masts that illuminats the deck of the ship.\n";
    str += "\nYou may <sail [dir]> to steer your ship.  \n";
    str += ""+query_land();
    return str;
}

void init()
{
    ::init();
    add_action("shoot", "shoot");
    add_action("view_status", "view");
    add_action("go_raft", "enter");
    add_action("go_sail", "sail");
    add_action("location", "location");
    add_action("dock_ship", "dock"); 
    add_action("look_ships", "look");
    add_action("hail_ship", "hail");
}
int go_sail(string str)
{
    int s;
    int tempx, tempy;
    string sb, dir;
    string fil;
    fil = file_name( this_object() ) +".c";
    if (owner!=this_player()->query_name())
    {
	write("You cannot steer this ship!");
	return 1;
    } 
    if (!str || str=="")
    {
	write("Sail where?");
	return 1;
    }
    if (str!="west" && str!="east" && str!="north" && str!="south" && str!="out")
    {
	write("You cant sail in that direction.");
	return 1;
    }
    if(query_docked() && str != "out") {
	write("You cannot sail the ocean while docked!");
	return 1;
    }
    tempx = X; tempy = Y;
    if (str=="west") tempx--;
    if (str=="east") tempx++;
    if (str=="north") tempy--;
    if (str=="south") tempy++;
    if (str=="out") {
	if(!query_docked()) {
	    write("Your ship is not docked!");
	    return 1;
	}
	write("Your ship begins to sail out.\n");
	call_out("move_ship", speed, "out");
	return 1;
    }
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
    write("You steer your ship to the "+str+".");
    say( this_player()->query_cap_name()+" points the ship to the "+str+".");
    call_out("move_ship", speed, str);
    dir = str;
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
int dock_ship() {
    string tmp;
    if(this_player()->query_name() != query_owner()) {
	write("You cannot steer this ship!");
	return 1;
    }
    if (!tmp=OCEAN_D->get_docks( OCEAN_D->get_xy(X, Y) )) {
	write("You do not see any docks around here."); 
	return 1;
    }
    if(docked) {
	write("You are already docked at "+tmp->query_short());
	return 1;
    }
    write("You dock your boat.");
    say(this_player()->query_name()+" docks the boat.\n");
    add_exit(tmp, "land");
    docked=tmp;
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
void move_ship(string dir)
{
    int i, a, tmp;
    if(dir=="out") {
	docked=0;
	write("Your ship sails out into the harbor.");
	remove_exit("land");
	return;
    }
    X=xx;
    Y=yy;
    OCEAN_D->ship_location(this_object(), X,Y);
    message("", "The ship sails to the "+dir, this_object());
    if(!query_docked()) remove_exit("land");
    tmp=OCEAN_D->get_docks( OCEAN_D->get_xy(X, Y) );
    if(query_docked()) add_exit(tmp, "land");
    docked=0;
}
int location()
{
    int *i;
    i = OCEAN_D->get_mudcoord_from_graphcoord(({X, Y}));
    if(query_docked()) write("%^BOLD%^%^RED%^Your navigator tells you:%^RESET%^ "
	  "You are docked at "+query_docked()->query_short()+".\n"); else
	write("%^BOLD%^%^RED%^Your navigator tells you:%^RESET%^ You are at ("+i[0]+", "+i[1]+")\n");
    return 1;
}
void set_owner(string str) {
    owner=str;
    this_object()->load(str);
}
string query_owner() { return owner; }
void set_docked(string let) { 
    add_exit(let, "land");
    docked=let; 
}
string query_docked() { return docked; }
void load(string p) {
    seteuid(UID_BOATSAVE);
    restore_object("/adm/save/boats/"+p);
    seteuid(geteuid());
}
int look_ships(string str) {
    object *s;
    string tmp;
    int i;
    if(str != "ship" && str != "ships") return 0;
    s=OCEAN_D->get_room_ships(this_object(), X, Y);
    s -= ({this_object()});
    i=sizeof(s);
    if(!i) { 
	write("You do not see any ships near here.");
	return 1;
    }
    tmp="You can see: \n";
    while(i--) tmp += ""+capitalize(s[i]->query_owner())+"'s ship is here.\n";
    write(tmp);
    return 1;
}
int hail_ship(string str) {
    string to, msg;
    object *s, o;
    int i, x1,y1,x2,y2;
    if(sscanf(str, "%s %s", to, msg)!=2) return notify_fail("Hail who?\n");
    s=OCEAN_D->get_room_ships(this_object(), X, Y);
    s -= ({this_object()});
    i=sizeof(s);
    if(lower_case(to) == this_player()->query_name()) {
	write("Hail yourself?");
	return 1;
    }
    if(!o=OCEAN_D->get_boat(to)) {
	write("You do not notice that ship here.\n");
	return 1;
    }
    x1=query_xy()[0];
    y1=query_xy()[1];
    x2=o->query_xy()[0];
    y2=o->query_xy()[1];
    if(x1 != x2 || y1 != y2) {
	write("You do not notice that ship here.\n");
	return 1;
    }
    message("hail", "%^RED%^%^BOLD%^"+this_player()->query_cap_name()+
      " hails your ship:  %^RESET%^"+msg, o);
    write("%^BOLD%^%^RED%^You hail "+capitalize(to)+" ship: %^RESET%^"+msg);
    return 1;
}
