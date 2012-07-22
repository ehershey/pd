#include <std.h>
#include <daemons.h>

#define fail(x) { write(""+x); return 1; }
#define ALPHABET ({"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"})
// this is tirun, used only if the sky bugs out
#define EMERGENCY_ROOM "S"

inherit ROOM;

#include <sky.h>

int *coords;

void create() {
    ::create();
    skip_obvious();
    set_name("Floating in the sky");
    set_short("Floating in the sky");
    set_properties( ([ "light"  : 2,
	"night light" : 2,
	"sky"    : 1,
	"no gate" : 1,
	"no map" : 1, 
	"no teleport" : 1, ]) );
}

void set_coords(int *c) { coords = copy(c); }
int *query_coords() { return coords; }

int no_cmd() {
    fail("You cannot do that while flying!");
    return 1;
}

void init() {
    ::init();
    add_action("fly", "east");
    add_action("fly", "west");
    add_action("fly", "north");
    add_action("fly", "south");
    add_action("fly", "up");
    add_action("fly", "down");
    add_action("fly", "fly");
    add_action("land", "land");
    add_action("drop", "drop");
    add_action("no_cmd", "sleep");
    add_action("no_cmd", "rest");
    add_action("no_cmd", "lay");

    if(!"/cmds/skills/_fly"->abil() && !this_player()->query_mounting() && !this_player()->query_riding()) {
	message("", "You cannot fly!", this_player());
	message("", this_player()->query_cap_name()+" falls to "+possessive(this_player())+" death.", this_object(), 
	  ({this_player()}));
	this_player()->die();
    }
}

void clear_room() {
    int i;
    object *inv;
    inv = all_inventory(this_object());
    for(i=0; i<sizeof(inv); i++) {
	if(!inv[i]->is_player() && !inv[i]->is_monster()) {
	    message("", inv[i]->query_short()+" falls below and disappears.", this_object());
	    inv[i]->remove();
	}
    }
}

int drop() {
    call_out("clear_room", 0);
    return 0;
}

string *delay=({});


varargs int fly(string s, object p) {
    int *c = copy(coords);
    int sp;
    string op;
    object o;
    if(!s || s == "") s=query_verb();
    if(!s || s == "") fail("Syntax: <fly [direction]>");
    if (sizeof(c) != 3) fail("You cannot fly that way.\n");
    switch(s) {
    case "north": c[1]--; op="the south"; break;
    case "south": c[1]++; op="the north"; break;
    case "east": c[0]++; op="the west"; break;
    case "west": c[0]--; op="the east"; break;
    case "up": 
	if(c[2] >= 3) fail("You cannot fly that high!");
	c[2]++; op="down below";
	break;
    case "down":
	if(c[2] <= 0) fail("You cannot fly that low!");
	c[2]--; op="up above";
	break;
    default: fail("You cannot fly that way."); break;
    }
    o=SKY_D->get_room(c);
    if(!o) fail("You cannot fly that way.\n");

    if(this_player()->query_sp() < 10) fail("You are too tired to fly.");

    if(member_array(this_player(), delay) != -1 && !p) fail("You are already flying around.");
    if(this_player()->query_skill("flying") < 75 && !p) {
	write("You begin flying "+s+".");
	delay += ({ this_player() });
	call_out("fly", random(1), s, this_player());
	return 1;
    }

    if(p)
	delay -= ({p});
    message("", this_player()->query_cap_name()+" flys "+s+".", this_object(), ({ this_player() }));
    message("", this_player()->query_cap_name()+" flys in from "+op+".", o, ({ this_player() }));
    this_player()->move(o);
    if (sizeof(this_player()->query_riders())) this_player()->query_riders()->move(o);
    sp=this_player()->query_skill("fly")%11;
    if(!sp) sp=this_player()->query_skill("fly")%10;
    if(c[2] > 0) sp += c[2]*2+random(2);
    this_player()->add_sp(-(sp+random(4)));
    this_player()->force_me("look");
    return 1;
}

int land(string s) {
    string sym, room;
    if (sizeof(coords) != 3) sym = EMERGENCY_ROOM;
    else {
       sym = SKY_D->get_xy(coords);
       if(sym=="+" || sym=="-" || sym=="#" || sym=="%" || coords[2]) fail("You cannot land here!");
    }
    if(!ROOMS[sym]) fail("You cannot land here!");
    room=ROOMS[sym]["room"];
    if(!room || room=="") fail("You cannot land here!");
    write("You land in "+ROOMS[sym]["name"]);
    this_player()->move_player(room, "descends below");
    return 1;
}

int swap_out() {
    object *inv = all_inventory(this_object());
    if(!sizeof(inv)) { remove(); return 1; }
    return 0;
}

string query_long() { 
    string out="", end="", c, map;
    string sym;
    if(!sizeof(query_coords())) return "Error:  coords=NULL";
    sym=SKY_D->get_xy(coords);
    switch(sym) {
    case "+":
	out += "Small clouds can be seen around here.  The wind is blowing lightly as "
	"you are soaring through the air.";
	end += "Land can be seen far below.  ";
	break;
    case "-":
	out += "Small clouds can be seen around here.  The wind is blowing lightly as "
	"you are soaring through the air.";
	end += "Nothing but ocean can be seen below you.  ";
	break;
    case "#":
	out += "Small clouds can be seen around here.  The wind is blowing lightly as "
	"you are soaring through the air.";
	end += "Large masses of ice can be seen below.  ";
	break;
    case "%":
	out += "Violent gusts of wind try to blow you off course.  Dark stormclouds "
	"prevent you from seeing very far.  The rain and wind makes it hard to fly.";
	end += "You cannot see below you.  ";
	break;
    default:
	out += "Small clouds can be seen around here.  The wind is blowing lightly as "
	"you are soaring through the air.";
	if(ROOMS[sym]) {
	    if(!ROOMS[sym]["room"] || ROOMS[sym]["room"] == "") end += ROOMS[sym]["name"]+" can be seen far below.  "; else
		end += "Looking below you see a landing spot in "+ROOMS[sym]["name"]+".";
	} else  end += "Land can be seen far below.  ";
	break;
    }
    if(coords[2]) end="You are very high in the sky and cannot see below.";
    map=this_object()->get_map();
    return out+"\n\n"+map+" "+end;
}

string get_map() {
    int i, x, *c, alt;
    string sym, out="", *b, *d;
    mapping a=([]);
    c=copy(environment(this_player())->query_coords());
//    if(!c) return "You are not in the sky.";
    if (!c) return "";
    if(c[2] > 0) alt = c[2]*2;
    c[0]=c[0]+4+(alt/2);
    c[1]=c[1]-2-(alt/2);
    for(i=0; i<(5+alt); i++) {
	a[i]=SKY_D->get_line( ({ c[0], c[1]+i }), 9+alt);
    }
    i=sizeof(a);
    a[2+alt/2][4+alt/2..4+alt/2]="*";
    for(i=0; i<sizeof(a); i++) 
	out += a[i]+"\n";
    b=explode(out, "\n");
    i=sizeof(b);
    d=({});
    while(i--) {
	x=sizeof(b[i]);
	sym="";
	while(x--)
	    sym += b[i][x..x];
	b[i]=sym;
    }
    out=implode(b, "\n");
    i=sizeof(ALPHABET);
    while(i--) {
	out=replace_string(out, ALPHABET[i], "^");
    }
    out=replace_string(out, "^", "%^MAGENTA%^%^BOLD%^^%^RESET%^");
    out=replace_string(out, "+", "%^YELLOW%^+%^RESET%^");
    out=replace_string(out, "*", "%^GREEN%^%^BOLD%^*%^RESET%^");
    out=replace_string(out, "-", "%^BOLD%^%^CYAN%^+%^RESET%^");
    out=replace_string(out, "%%", "%^BOLD%^%^BLACK%^+%^RESET%^");
    out=replace_string(out, "#", "%^CYAN%^+%^RESET%^");
    return out;
}

