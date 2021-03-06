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

#define DEFAULT_MSG "You do not notice that here."
#define DEFAULT_NO_ITEM_MSG "There is nothing extraordinary about it."

inherit CONTAINER;
inherit "/std/room/exits";
//inherit "/std/room/range";

static string *NO_TELEPORT_DIRS = ({
  "/d/guilds/",
  "/wizards/.+/workroom.c",
  "/d/nopk/immortal_hall/",
});
static string NO_TELEPORT_PATTERN;
private int reset_number;
int blm, foraged;
string zone;

void reset();
void init();
void reinitiate();
void set_short(string str);
void set_long(string str);
void set_block_light(int x);
void set_day_long(string str);
void set_night_long(string str);
void set_dynamic_combat(int d);
string query_short();
string query_long(string str);
string query_extra_long();
int query_block_light();
int move(mixed dest);
int query_reset_number();
int do_forage();
int is_room();
int query_dynamic_combat();
string describe(string str);
void set_zone(string z);
string query_zone();
void show_zone(mixed who);
int query_arena();

void create() {
  container::create();
  exits::create();
  reset_number = 0;
  this_object()->reset(); 
  call_out("reinitiate", 0);
  NO_TELEPORT_PATTERN = "^(" + implode(NO_TELEPORT_DIRS, "|") + ")";
}

void set_zone(string z) { zone = z; }

string query_zone() {
  string fname;
  if (zone) return zone;
  fname = file_name(this_object());
  if (fname[0..7] == "/d/nopk/") return "nopk";
  if (fname[0..9] == "/d/freepk/") return "freepk";
  return "pk";
}

void show_zone(mixed who) {
  string msg;

  if (!arrayp(who)) who = ({ who });
  who = filter(who, (: environment($1) == this_object() :) );
  if (!sizeof(who)) return;

  switch (this_object()->query_zone()) {
    case "nopk": msg = "%^RESET%^%^BOLD%^You feel safe from attack from other players here.%^RESET%^"; break;
    case "freepk": msg = "%^BOLD%^%^RED%^You feel the lack of law in this area!%^RESET%^"; break;
    default:
    case "pk": msg = "%^BOLD%^%^BLUE%^You feel like there is a lawful presence here.%^RESET%^"; break;
  }

  message("info", msg, who);
}

int query_arena() {
  if (this_object()->query_property("arena") ||
      file_name(this_object())[0..8] == "/d/arena/")
        return 1;
  return 0;
}

mixed query_property(string str) {
  if (str == "no teleport" && regexp(file_name(this_object()), NO_TELEPORT_PATTERN))
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

void set_block_light(int x) { blm = x; }

int query_block_light() { return blm; }

int is_room() { return 1; }

string *query_id() { return keys(this_object()->query_items()); }
int id(string str) { return (str && member_array(str, keys(this_object()->query_items())) != -1); }
mixed query_item_description(string str) { return this_object()->query_item(str); }
string query_no_item(string str) { return (str && strlen(str) && strsrch(this_object()->query_long(), str) == -1 ? DEFAULT_MSG : DEFAULT_NO_ITEM_MSG); }
string describe(string str) {
  mixed item;
  string tmp;
  if (!str || !strlen(str) || !strlen(this_object()->query_item(str))) return query_no_item(str);
  item = this_object()->query_item(str);
  if (functionp(item)) {
    tmp = evaluate(item, str);
    if (stringp(tmp)) return tmp;
    else return "";
  }
  else return item;
}
/*
void set_items(mapping m) { ::set_items(m); }
void add_item(string str, mixed val) { ::set_item(str, val); }
void remove_item(string str) { ::remove_item(str); }
void set_search(string item, mixed desc) { ::set_search(item, desc); }
void set_listen(string item, mixed desc) { ::set_search(item, desc); }
void set_smell(string item, mixed desc) { ::set_search(item, desc); }
void remove_search(string item) { ::remove_search(item); }
void remove_listen(string item) { ::remove_search(item); }
void remove_smell(string item) { ::remove_search(item); }
mixed query_search(string item) { return ::query_search(item); }
mixed query_listen(string item) { return ::query_search(item); }
mixed query_smell(string item) { return ::query_search(item); }
*/
