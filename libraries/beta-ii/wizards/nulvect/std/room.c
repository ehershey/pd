//      /std/room.c
//      from the Nightmare Mudlib
//      the room object
//      written by Descartes of Borg 17 june 1993
//      ::create() added by Pallando (93-06-18)
//      ::create() changed to container::create() with calls to
//      items::create(), exits::create(), and senses::create() added
//      by Descartes 930619
//      this_object()->setup(); removed from reset() by Pallando (93-06-20)
//      seteuid(getuid()) removed from create() by Pallando (93-06-23)
//      query_long() changed not to give error if none set by Pallando 93-07-10

#include <std.h>
#include <rooms.h>
#include <move.h>

inherit "/wizards/nulvect/std/container";
inherit "/wizards/nulvect/std/room/exits";
inherit "/wizards/nulvect/std/room/items";
inherit "/wizards/nulvect/std/room/senses";

private int reset_number;
int blm, foraged;

void reset();
void init();
void reinitiate();
void set_short(string str);
void set_long(string str);
void set_block_light(int x);
void set_day_long(string str);
void set_night_long(string str);
string query_short();
string query_long(string str);
string query_extra_long();
int query_block_light();
int move(mixed dest);
int query_reset_number();
int do_forage();
int is_room();

void create() {
    container::create();
    exits::create();
    items::create();
    senses::create();
    reset_number = 0;
    this_object()->reset(); 
    call_out("reinitiate", 0);
}

mixed query_property(string str) {
    if(strlen(base_name(this_object())) >= strlen("/d/guilds/"))
	if(base_name(this_object())[0..9] == "/d/guilds/" && str == "no teleport")
	    return 1;

    return container::query_property(str);
}

void reset() {
    container::reset();
    foraged = 6 + random(4);
    reset_number++;
}

void init() {
    // if (!reset_number) this_object()->reset(); 
    exits::initiate_exits();
    senses::initiate_senses();
}

int do_forage() {
    if(foraged) {
	foraged--;
	return 1;
    }
    return 0;
}

void set_short(string str) { container::set_short(str); }

void set_long(string str) 
{ 
    container::set_long(str); 
}
void set_day_long(string str)
{
    container::set("day long", str);
}
void set_night_long(string str)
{
    container::set("night long", str);
}
string query_short() { 
    return container::query_short();
}

string query_long(string str) {
    string ret;

    if(str) return describe(str);
    else {
	if(query_night() && query("night long")) ret = query("night long");
	else if(!query_night() && query("day long")) ret = query("day long");
	else ret = container::query_long(str);
    }
    if( !ret ) ret = "";
    if(query_extra_long() != "") ret += query_extra_long();
    return ret;
}

string query_extra_long() {
    object *inv;
    string ret, tmp;
    int i;

    ret = "";
    i = sizeof(inv = all_inventory(this_object()));
    while(i--)
	if(tmp = (string)inv[i]->affect_environment()) ret += tmp;
    return ret;
}

void reinitiate() {
    object *inv;
    int i;

    i = sizeof(inv = all_inventory(this_object()));
    while(i--) {
	inv[i]->move(ROOM_VOID);
	inv[i]->move(this_object());
    }
}

int query_reset_number() { return reset_number; }

int move(mixed dest) { return MOVE_NOT_ALLOWED; }

string *query_id() { return items::query_id(); }

status id(string str) { return items::id(str); }

void set_block_light(int x) { blm = x; }

int query_block_light() { return blm; }

int is_room() { return 1; }
