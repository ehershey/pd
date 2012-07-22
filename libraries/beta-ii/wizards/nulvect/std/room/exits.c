//      /std/room/exits.c
//      from the Nightmare Mudlib
//      functions handling room exits
//      created by Descartes of Borg 18 june 1993

#include <rooms.h>
#include <rest.h>

int skip_obvious;
private mapping destinations;
private mapping invis_exits;
private mapping pre_exit_func;
private mapping post_exit_func;
private mixed *tracks;

int invis_exit(string str);

#define MAX_TRACKS  10

#define NUMBER   ({ "two", "three", "four", "five", "six", "seven", "eight",\
                  "nine", "ten", "many" })

#define TMPLONG  ({ "north", "northeast", "east", "southeast", "south",\
                  "southwest", "west", "northwest", "up", "down", "in",\
                  "out", "enter","exit",})

#define TMPSHORT ({ "n", "ne", "e", "se", "s", "sw", "w", "nw", "u", "d",\
                  "in","out", "enter","exit",})

int query_peace(object place);

void create() {
    destinations = ([]);
    invis_exits = ([]);
    pre_exit_func = ([]);
    post_exit_func = ([]);
    tracks = ({});
    skip_obvious = 0;
}

string query_exit(string str) {
    if (!str || !destinations || !destinations[str]) return ROOM_VOID;
    if (!functionp(destinations[str])) return destinations[str];
    else return (string)(*destinations[str])();
    /*   if(functionp(__Die)) {
	    if(!((int)((*__Die)(ob)))) return;
    */

}

string query_obvious_exit(string str) {
    if (!str || !destinations || !destinations[str]) return ROOM_VOID;
    if(invis_exits)
	if(invis_exits[str] == 1) return ROOM_VOID;
    if (!functionp(destinations[str])) return destinations[str];
    else return (string)(*destinations[str])();
}
mapping query_directions() { return destinations; }
string query_direction(string str) {
    int i;

    if(str && destinations && 
      (i=member_array(str, values(destinations))) != -1)
	return keys(destinations)[i];
    else return ROOM_VOID;
}

static void perform_post_exits(string str) {
    if(!str || !post_exit_func || !post_exit_func[str]) return;
    call_other(this_object(), post_exit_func[str]);
}

static int perform_pre_exits(string str) {
    if(!str || !pre_exit_func || !pre_exit_func[str]) return 1;
    return (int)call_other(this_object(), pre_exit_func[str]);
}

// tracking function added by Valodin
// August 10, 1993
//
// the first track is the most recent one
// after MAX_TRACKS tracks then the oldest ones get taken off
// each track is an array ({ player_name, exit_name, time })

int query_peace(object place){
    if(place->query_property("no attack") && place->query_property("no magic"))
	return 1;
    return 0;
}


void add_tracks(string verb, object ob)
{
    mixed *new_entry;
    int szt;

    new_entry = ({ 0, 0, 0 });
    new_entry[0] = ob->query_name();
    new_entry[1] = verb;
    new_entry[2] = time();
    if((szt = sizeof(tracks)) >= MAX_TRACKS)
	tracks -= ({ tracks[0] });
    if (!tracks)
	tracks = ({ new_entry });
    else
	tracks += ({ new_entry });
}

mixed *query_tracks() { return tracks; }

string *query_track_makers()
{
    string *ret;
    int i, sztr;

    ret = ({});
    for(i = 0, sztr = sizeof(tracks); i < sztr; i++)
	ret += ({ (string)tracks[i][0] });
    return ret;
}

int use_exit(string str) {
    string verb, st;
    int dd;

    if(str) return 0;
    if(this_player()->query_paralyzed()) {
	notify_fail("You are unable to move.\n");
	return 0;
    }
    if( this_player()->query_disable() &&
      sizeof(this_player()->query_attackers()) ) {
	write("You can not exit while doing something else.");
	return 1;
    }
    if(!(verb = query_verb())) return 0;
    if(query_exit(verb) == ROOM_VOID) {
	write("Error:  Set to VOID.  Notify creator of room.\n");
	return 1;
    }
    if (file_size(query_exit(verb))<1&&file_size(query_exit(verb)+".c")<1
      && (sscanf(query_exit(verb), "%s#%d", st, dd)!=2))
    {
	write("As you try to walk "+verb+", the area shimmers and holds "
	  "you back.");
	return 1;
    }
    if ( this_player()->query_rest_type() )
	switch( this_player()->query_rest_type() )
    {
    case REST:
	this_player()->force_me("stand");
	break;
    case SIT:
	this_player()->force_me("stand");
	break;
    case LAY:
	this_player()->force_me("stand");
	break;

    }

    if(!perform_pre_exits(verb)) return 1;
    add_tracks(verb, this_player());
    this_player()->move_player(query_exit(verb), verb);
    perform_post_exits(verb);
    return 1;
}

static void initiate_exits() {
    string *borg;
    int i;

    i = sizeof(TMPLONG);
    while(i--) add_action("use_stupid_exit", TMPLONG[i]);
    if(!destinations) return;
    i = sizeof(borg = keys(destinations));
    while(i--) add_action("use_exit", borg[i]);
}

varargs static void set_exits(mixed dests, string *dirs) {
    int i;

    if(mapp(dests)) {
	destinations = dests;
	return;
    }
    if(!dests || !dirs || ((i = sizeof(dests)) != sizeof(dirs))) return;
    destinations = ([]);
    while(i--) destinations[dirs[i]] = dests[i];
}

void add_exit(string dest, string dir) {
    if(!dest || !dir) return;
    if(!destinations) destinations = ([]);
    destinations[dir] = dest;
    this_object()->reinitiate();
}

static void remove_exit(string dir) {
    if(!dir || !destinations || !destinations[dir]) return;
    map_delete(destinations, dir);
    this_object()->reinitiate();
}

string *query_exits() { return (destinations ? keys(destinations) : ({})); }

string query_full_direction(string str) {
    int i;

    if((i=member_array(str, TMPSHORT)) == -1) return str;
    else return TMPLONG[i];
}

string *query_destinations() {
    return (destinations ? values(destinations) : ({}));
}

string *query_obvious_exits() {
    string *exits, *sorties;
    int i;

    if(!destinations) return ({});
    else i = sizeof(sorties = keys(destinations));
    exits = ({});
    while(i--)
	if(!invis_exit(sorties[i])) exits += ({ sorties[i] });
    return (exits);
}

string query_long_exits()
{
    int i;
    string *sorties, *New=({});
    string cust = "%^GREEN%^Obvious Exits: %^RESET%^ $*";
    // Change this so it can be customized by the user -- seeker
    if (skip_obvious) return "";
    if(!(i=sizeof(sorties = query_obvious_exits())))
	return "%^GREEN%^There are no obvious exits.%^RESET%^";
    if (i==1) return "%^GREEN%^There is only one obvious exit: "+sorties[0]+".";
    if (member_array("north", sorties)!=-1) New += ({ "north" }); sorties -= ({ "north" });
    if (member_array("south", sorties)!=-1) New += ({ "south" }); sorties -= ({ "south" });
    if (member_array("west", sorties)!=-1) New += ({ "west" }); sorties -= ({ "west" });
    if (member_array("east", sorties)!=-1) New += ({ "east" }); sorties -= ({ "east" });
    if (member_array("up", sorties)!=-1) New += ({ "up" }); sorties -= ({ "up" });
    if (member_array("down", sorties)!=-1) New += ({ "down" }); sorties -= ({ "down" });
    New += sorties;
    New[sizeof(New)-1] = "and "+New[sizeof(New)-1];
    cust = "%^GREEN%^There are "+cardinal(sizeof(New))+" obvious exits: ";
    return sprintf("%s %s.", cust, implode(New, ", ")); 

}

string query_short_exits() {
    int i, x, max;
    string s;
    string *lx, *sx;

    s = "";
    sx = allocate(max = sizeof(lx = query_obvious_exits()));
    for(x=0; x< max; x++) {
	if( (i=member_array(lx[x], TMPLONG)) != -1)
	    sx[x] = TMPSHORT[i];
	else sx[x] = lx[x];
    }
    if(!sizeof(sx)) return "%^BOLD%^%^CYAN%^[%^BLUE%^no exits%^CYAN%^]%^RESET%^";
    if(max == 1) return "%^BOLD%^%^CYAN%^[%^RESET%^ "+sx[0]+" %^BOLD%^%^CYAN%^]%^RESET%^";
    s = ("%^BOLD%^%^CYAN%^[%^RESET%^ ");
    for(x=0; x<max; x++) {
	if(x) s += " %^CYAN%^:%^RESET%^ ";
	s += sx[x];
    }
    return s + " %^BOLD%^%^CYAN%^]%^RESET%^";
}

static void set_post_exit_functions(string *dirs, string *funcs) {
    int i;

    if(!dirs || !funcs || ((i=sizeof(dirs)) != sizeof(funcs))) return;
    post_exit_func = ([]);
    while(i--) post_exit_func[dirs[i]] = funcs[i];
}

static void add_post_exit_function(string dir, string func) {
    if(!post_exit_func) post_exit_func = ([]);
    post_exit_func[dir] = func;
    this_object()->reinitiate();
}

static void remove_post_exit_function(string dir) {
    if(!dir || !post_exit_func || !post_exit_func[dir]) return;
    map_delete(post_exit_func, dir);
    this_object()->reinitiate();
}

static void set_pre_exit_functions(string *dirs, string *funcs) {
    int i;

    if(!dirs || ! funcs || (sizeof(dirs) != sizeof(funcs))) return;
    if(!pre_exit_func) pre_exit_func = ([]);
    i = sizeof(dirs);
    while(i--) pre_exit_func[dirs[i]] = funcs[i];
}

static void add_pre_exit_function(string dir, string func) {
    if(!dir || !func) return;
    if(!pre_exit_func) pre_exit_func = ([]);
    pre_exit_func[dir] = func;
    this_object()->reinitiate();
}

static void remove_pre_exit_function(string dir) {
    if(!pre_exit_func || !pre_exit_func[dir]) return;
    map_delete(pre_exit_func, dir);
    this_object()->reinitiate();
}

void set_invis_exits(string *dirs) {
    int i;

    invis_exits = ([]);
    i = sizeof(dirs);
    while(i--) invis_exits[dirs[i]] = 1;
}

void add_invis_exit(string dir) {
    if(!invis_exits) invis_exits = ([]);
    invis_exits[dir] = 1;
}

void remove_invis_exit(string dir) {
    if(!invis_exits) return;
    if(!invis_exits[dir]) return;
    map_delete(invis_exits, dir);
}

int invis_exit(string dir) {
    if(!invis_exits) return 0;
    else return invis_exits[dir];
}

void skip_obvious() { skip_obvious = 1; }

status use_stupid_exit() {
    /* i put this here because it doesnt even work for monsters
       use the "go" command to go places with mobs "go west" etc..
    */
    if (this_player()->is_monster()) return 0;
    write("You cannot go that way.\n");
    return 1;
}

string *query_pre_exit_functions() {
    if(pre_exit_func) return keys(pre_exit_func);
    else return ({});
}

string query_pre_exit_function(string sortie) {
    if(!pre_exit_func) return 0;
    else return pre_exit_func[sortie];
}

string *query_post_exit_functions() {
    if(!post_exit_func) return ({});
    else return keys(post_exit_func);
}

string query_post_exit_function(string sortie) {
    if(!post_exit_func) return 0;
    else return post_exit_func[sortie];
}
