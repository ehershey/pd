/*
Ocean Boat by Seeker 06/01/2000
** 06/04/2000 (made it so if theres nobody on the boat, no heartbeat)
** 06/17/2000 (added <enter raft> message and can hop boats)
** 11/02/2000 (changed the ocean around so (0,0) is wherever i want it to be)
** 2/22/2006 (added is_boat function to check if the room is a boat - Daboura)
*/
#include <std.h>
#include <daemons.h>
#include "../ocean.h"
#include "../debug.h"

inherit SHIP_UPGRADES;
#ifndef NO_COMBAT
inherit SHIP_COMBAT;
#endif
inherit SHIP_DESCRIBE;
inherit PIER;

static int static_ship;
int X, Y;
static int mud_coords;
static string docked, ocean_short, start_room;
string owner;

void heart_beat();
int *query_xy();
string query_present_ships_string();
string query_docked();
void set_docked(string s);

void set_owner(string p) {
    owner=p;
}

string query_owner() {
    if (!owner) {
        return "";
    }
    return owner;
}

int is_boat() {
    return 1;
}

static void create() {
    pier::create(); 
#ifndef NO_COMBAT
    shipgrades::create();
#endif
    set_short("%^BOLD%^%^BLUE%^..sailing along the ocean..%^RESET%^");
    set_properties( ([ 
        "light" : 2,
        "no light" : 2,
        "no map" : 1,
	    "no teleport" : 1,
        "no bump" : 1
    ]) );
    set_items( ([ 
        ({"ocean","water"}) : "The ocean waves move in a constant motion",
    	"helm" : "The helm is used to steer the ship",
	    "sails" : "The sails stand tall flapping in the wind",
    	"boat" : "The boat bobs up and down in the water" 
    ]) );
    set_max_catch(9999);
    set_max_fishing(20);
    set_chance(75);
    set_fish(([
        "rainbow fish" : 10,
        "trout" : 15,
        "gold fish" : 5,
        "pirch" : 5,
        "stingray" : 10,
        "lamprey" : 15
    ]));
}

string query_land() {
    string *str, ships, sym;
    int i, block;
    string tmp, tmp2;

    str = ({});
    tmp = "";
    ships = "";

    if (tmp2=OCEAN_D->get_dock( OCEAN_D->get_xy(X, Y) )) {
        if(!query_docked()) {
            tmp += "\n\n%^YELLOW%^Some docks can be seen near here.  \nYou may <sail land> "
                "to land in the harbor.%^RESET%^"; 
        } else {
            return "\n%^YELLOW%^You are docked at "+query_docked()->query_short()+".\n"+query_present_ships_string();
        }
    }

    sym=OCEAN_D->get_xy(X, Y);
    if(sym == "^") tmp += "%^ORANGE%^Some Coral Reef can be seen under the water here.%^RESET%^\n";
    if(sym == "%" || sym == "@") tmp += "%^BOLD%^Storm clouds cover most of the sky.  Thunder rolls across the horizon.%^RESET%^\n";
    if (OCEAN_D->get_beach( OCEAN_D->get_xy(X, Y) )) {
        tmp = "\n%^YELLOW%^There is a beach here.\n"+
            "%^RESET%^%^ORANGE%^You can type %^CYAN%^<%^RESET%^enter raft%^CYAN%^>%^ORANGE%^ here.";
    }

    if (OCEAN_D->get_xy(X+1, Y)=="+") str += ({ "east" });
    if (OCEAN_D->get_xy(X-1, Y)=="+") str += ({ "west" });
    if (OCEAN_D->get_xy(X, Y+1)=="+") str += ({ "south" });
    if (OCEAN_D->get_xy(X, Y-1)=="+") str += ({ "north" });

    i = sizeof(str);
    if (i) {
    	tmp += "\n%^BLUE%^%^BOLD%^There is land to the ";
    }
    while(i--) {
        block=1;
        if (i) tmp += str[i]+", ";
        if (!i-1) tmp += "and ";
        if (!i) tmp += str[i];
    }

    tmp += ".";
    str=({});

    if (OCEAN_D->get_xy(X+1, Y)=="#") str += ({ "east" });
    if (OCEAN_D->get_xy(X-1, Y)=="#") str += ({ "west" });
    if (OCEAN_D->get_xy(X, Y+1)=="#") str += ({ "south" });
    if (OCEAN_D->get_xy(X, Y-1)=="#") str += ({ "north" });

    i = sizeof(str);
    if (i) {
    	tmp += "\n%^CYAN%^%^BOLD%^There is ice to the ";
    }
    while(i--) {
        block=1;
        if (i) tmp += str[i]+", ";
        if (!i-1) tmp += "and ";
        if (!i) tmp += str[i];
    }
    tmp += ".";
    if (!block) {
        tmp += "%^CYAN%^%^BOLD%^\nYou are out sailing in the open sea.";
    }

    return tmp+"\n"+query_present_ships_string();

}

string query_long() {
    string str;

    if(!query_long_short()) {
        if(!query_night()) {
            str="The ship is spacious "
                "compared to those of the fishing ships.  A "
                "tall mast rises above the deck holding the "
                "sails at the top.  Rope and normal ship "
                "supplies lay scattered about the ship.  The"
                " helm is in front of you.\n";
        }
        if(query_night()) {
            str="The gentle waves lap "
                "over the sides of hull gently.  A cool breeze "
                "blows slightly.  A dull lantern hangs from one "
                "of the masts that illuminates the deck of the ship.\n";
        }
    } else {
        str = query_long_short();
    }

    str += "\nYou may <sail [dir]> to steer your ship.  \n";
    str += ""+query_land();

    return str;

}

void init() {
    pier::init();
#ifndef NO_COMBAT
    shipcombat::init();
#endif
    add_action("go_raft", "enter");
    add_action("get_status", "view");
    add_action("go_sail", "sail");
    add_action("location", "location");
    add_action("look", "look");
    add_action("go_land", "land");
}

int go_sail(string str) {
    int s;
    int newX, newY;
    string *valid_directions;

    if(this_object()->is_static_ship()) {
        return 0;
    }

    if (query_owner()!=this_player()->query_name()) {
        return notify_fail("You may not steer this ship!\n");
    } 

    if (!str || str=="") {
        return notify_fail("Sail where?\n");
    }

    valid_directions = ({
        "west",
        "east",
        "north",
        "south",
        "out",
        "land"
    });

    if (member_array(str, valid_directions) == -1) {
        return notify_fail("You can't sail in that direction.\n");
    }

    if(str=="out" && !query_docked()) {
        return notify_fail("You are not docked!\n");
    }

    if(str=="land" && query_docked()) {
        return notify_fail("You are already docked!\n");
    }

    if(str=="land" && !OCEAN_D->get_dock( OCEAN_D->get_xy(X, Y) )) {
        return notify_fail("You do not notice any docks around here.\n");
    }

    if(str=="out") {
        remove_call_out("move_ship");
        call_out("move_ship", speed, str);
        message("move_ship", "The ship begins to leave port.\n", this_object());
        return 1;
    }
    if(str=="land") {
        remove_call_out("move_ship");
        call_out("move_ship", speed, str);
        message("move_ship", "The ship begins to dock.\n", this_object());
        return 1;
    }
    if(query_docked()) {
        return notify_fail("You must <sail out> before you can sail the ocean.\n");
    }

    newX = X;
    newX = Y;
    if (str=="west") newX--;
    if (str=="east") newX++;
    if (str=="north") newY--;
    if (str=="south") newY++;

    s = OCEAN_D->valid_xy(newX, newY);
    if (!s) {
        write("Strong currents prevent you from going in that direction.");
        return 1;
    }
    if (s==STRONG_CURRENTS) {
        write("Strong currents prevent you from going that direction.");
        return 1;
    }
    if (s==LAND) {
        write("Land prevents you from going in that direction.");
        return 1;
    }
    if(s==ICE) {
        write("The Ice Flows prevent you from going in that direction.\n");
        return 1;
    }

    write("You point your sails "+str+".");
    say( this_player()->query_cap_name()+" points the sails "+str+".");
    remove_call_out("move_ship");
    call_out("move_ship", query_speed(), str, newX, newY);

    return 1;

}

int go_raft(string str) {
    object ob;
    string fil;
    if(this_object()->is_static_ship()) return 0;
    if (str!="raft") {
        return notify_fail("Enter what?");
    }
    fil = OCEAN_D->get_beach( OCEAN_D->get_xy(X,Y) );
    if (!fil) {
        return notify_fail("You cannot use a raft here.");
    }

    write("You enter a raft and float to land.");
    ob = new("/std/obj/raft");
    ob->move( fil );
    ob->set_goto(this_object()->query_owner());
    ob->set_letter(OCEAN_D->get_xy(X, Y));
    this_player()->move_player(fil, "in a raft");

    return 1;

}
int *query_xy() {
    return ({X,Y});
}
void set_xy(int x, int y) {
    X = x;
    Y = y;
}
int location() {
    int *i;

    if(this_object()->is_static_ship()) return 0;

    i = OCEAN_D->get_mudcoord_from_graphcoord(({X, Y}));
    if(OCEAN_D->get_xy(X, Y) == "@") {
        write("Your navigational instruments seem to be malfunctioning.\n");
        return 1;
    }
    write("You are at ("+i[0]+", "+i[1]+")");

    return 1;

}
string query_present_ships_string() {
    string out;
    object *s;

    out="";
    s=OCEAN_D->get_present_ships(query_xy());
    if(s) s-=({this_object()});
    if(!s || s==({})) return "";

    if(sizeof(s)==1) {
        return "%^BOLD%^%^BLUE%^There is one ship here.%^RESET%^\n";
    }

    return "%^BOLD%^%^BLUE%^There are "+sizeof(s)+" ships here.%^RESET%^\n";

}
int look(string s) {
    object *o, blah;
    int i;
    string which, sym;
    string out="", *str=({});

    if(!s) {
        return notify_fail("Look at what?\n");
    }

    if (OCEAN_D->get_xy(X+1, Y)=="+") str += ({ "east" });
    if (OCEAN_D->get_xy(X-1, Y)=="+") str += ({ "west" });
    if (OCEAN_D->get_xy(X, Y+1)=="+") str += ({ "south" });
    if (OCEAN_D->get_xy(X, Y-1)=="+") str += ({ "north" });

    sym=OCEAN_D->get_xy(X, Y);
    if(s=="land" && sizeof(str) > 0) {
        i=sizeof(str); while(i--) if(i!=0) out += str[i]+", "; else out += str[i]+".";
        write("Land can be seen to the "+out);
        return 1;
    }

    str=({});

    if (OCEAN_D->get_xy(X+1, Y)=="#") str += ({ "east" });
    if (OCEAN_D->get_xy(X-1, Y)=="#") str += ({ "west" });
    if (OCEAN_D->get_xy(X, Y+1)=="#") str += ({ "south" });
    if (OCEAN_D->get_xy(X, Y-1)=="#") str += ({ "north" });

    if( (s=="dock" || s=="docks") && OCEAN_D->get_dock(sym)) {
        write("You can see "+OCEAN_D->get_dock(sym)->query_short()+" here.\n");
        return 1;
    }

    if( (s=="ice") && sizeof(str) > 0) {
        i=sizeof(str); while(i--) if(i!=0) out += str[i]+", "; else out += "and "+str[i]+".";
        write("Ice flows block the passage to the "+out);
        return 1;
    }

    if(sscanf(s, "%s ship", which)!=1 && s != "ship" && s != "ships") {
	    return "/cmds/mortal/_look"->cmd_look(s);
    }
    if(which) {
        if(!blah=OCEAN_D->ship_present(query_xy(), which)) {
	        return notify_fail("You do not notice that ship here.\n");
        } else {
            if(blah->is_static_ship()) {
                this_player()->move(blah->query_start_room());
            } else {
                this_player()->move(blah);
                this_player()->describe_current_room(1);
                this_player()->move(this_object());
                return 1;
            }
        }
	}

    o=OCEAN_D->get_present_ships(query_xy());
    if(o) o-=({this_object()});
    i=sizeof(o);
    if(!i) {
        write("You do not notice any ships near here.\n");
        return 1;
    }

    write("There are a total of "+i+" ships near here\n\n");
    while(i--) {
        if(o[i]->is_static_ship()) {
            out += o[i]->query_ocean_short()+"\n";
            break;
        }

        if (o[i]->query_sunk()) {
            out += "The wreckage of "+capitalize(o[i]->query_owner())+"'s boat is here.";
        } else {
            out += capitalize(o[i]->query_owner())+"'s boat is here";

            if(o[i]->query_docked()) {
                out += " (Docked)";
            }
        }
        out += "\n";
    }
    write(out);
    return 1;
}

void set_docked(string s) { 
    docked=s; 

    if(docked==0 || docked=="") {
    	remove_exit("land");
    } else {
    	add_exit(docked, "land");
    }

}

string query_docked() { return docked; }

varargs void move_ship(string dir, int x, int y) {

    if(this_object()->is_static_ship()) return 0;

    if(dir=="out") {
        message("move_ship", "The ship safely leaves the port.\n", this_object());
        set_docked(0);
        remove_exit("land");
        return;
    }

    if(dir=="land") {
        message("move_ship", "The ship safely enters the port.\n", this_object());
        set_docked(OCEAN_D->get_dock( OCEAN_D->get_xy(X, Y) ));
        return;
    }

    message("move_ship", "The ship sails to the "+dir+".\n", this_object());
    OCEAN_D->notify_ships(query_owner(), dir);

    X=x;
    Y=y;
    dir=0;
    OCEAN_D->notify_ships(query_owner(), "in");

    if(this_player()->getenv("BOAT_DESC")==1) {
        this_player()->force_me("look");
    }

    return;

}

int get_status() {

    if(this_object()->is_static_ship()) {
        return 0;
    }
    write(get_status_string());

    return 1;

}

int go_land() {

    if(!query_docked()) return 0;

    write("You leave your ship.\n");
    this_player()->move_player(query_docked(), "off the ship");

    return 1;

}

void set_is_static_ship(int i) {
    static_ship=i;
}

int is_static_ship() {
    return static_ship;
} 

void set_ocean_short(string s) {
    ocean_short=s;
}

string query_ocean_short() { 
    if(!is_static_ship()) return 0;
    
    return ocean_short; 
}

void set_start_room(string s) {
    start_room=s;
}

string query_start_room() {
    if(!is_static_ship()) return 0;

    return start_room; 
}

