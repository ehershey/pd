//      /std/room/exits.c
//      from the Nightmare Mudlib
//      functions handling room exits
//      created by Descartes of Borg 18 june 1993
//
//  rewritten by Nulvect 2009-08-16 to use class instances for exits,
//  in the hopes of reducing memory use (old version used 4 mappings and 2 arrays)

// for special room ROOM_VOID:
#include <rooms.h>
// for rest types SIT LAY REST SLEEP:
#include <rest.h>
// for functionp() return codes:
#include <function.h>
// for Exit class:
#include <exit_cl.h>
// for Track class:
#include <track_cl.h>

//--- configuration variables ---//

// this is a really bad error return value (why not 0, or ""??),
// but it's in use all over the mud already, so...
static private string NO_SUCH_EXIT = ROOM_VOID;

// %s is replaced here with the exit name
static private string BAD_DEST_MSG =
  "As you try to walk %s, the area shimmers and holds you back.";

// display formats for sprintf(),
// be sure there is a %s in each and all other % are doubled (%%)
static private string LONG_FORMAT =
  "%%^GREEN%%^%s%%^RESET%%^";
static private string SHORT_FORMAT =
  "%%^GREEN%%^[%%^RESET%%^%s%%^GREEN%%^]%%^RESET%%^";

// max tracks to store for each direction
static private int MAX_TRACKS = 10;

// if this is at the front of an exit name, that exit is considered an entrance
static private string ENTER_PREFIX = "enter ";

// TMPLONG and TMPSHORT *must* be in the same order!!
static private string *TMPLONG = ({
  "north", "northeast", "east", "southeast", "south",
  "southwest", "west", "northwest", "up", "down",
  "in", "out",
});
static private string *TMPSHORT = ({
  "n", "ne", "e", "se", "s",
  "sw", "w", "nw", "u", "d",
  "in", "out",
});

//--- working variables ---//

static private class Exit *exits;
static private int skip_obvious;

//--- function prototypes ---//

static private class Exit find_exit_name(string);
static private class Exit find_exit_file(string);
static private class Exit find_exit_alias(string);
static private class Exit find_exit(string);
static private string find_dest(class Exit);
class Exit *query_all_exits();
string *query_exits();
string *query_destinations();
string *query_obvious_exits();
string *query_enters();
string *query_entrances();
string *query_obvious_enters();
string *query_obvious_entrances();
string query_exit(string);
string query_obvious_exit(string);
string query_enter(string);
string query_entrance(string);
string query_obvious_enter(string);
string query_obvious_entrance(string);
mapping query_directions();
string query_direction(string);
varargs static void set_exits(mixed, string *);
void add_exit(string, string);
void remove_exit(string);
void add_exit_alias(string, string);
void remove_exit_alias(string, string);
string query_full_direction(string);
string query_long_direction(string);
string query_short_direction(string);
static private int exit_sort(string, string, string *);
static private string exit_movement(string);
string query_exit_display(string);
string query_long_exits();
string query_short_exits();
void perform_post_exits(string);
int perform_pre_exits(string);
static void set_post_exit_functions(string *, string *);
static void add_post_exit_function(string, string);
static void remove_post_exit_function(string);
static void set_pre_exit_functions(string *, string *);
static void add_pre_exit_function(string, string);
static void remove_pre_exit_function(string);
string *query_pre_exit_functions();
string query_pre_exit_function(string);
string query_pre_exit_function(string);
string *query_post_exit_functions();
string query_post_exit_function(string);
void set_invis_exits(string *);
void add_invis_exit(string);
void remove_invis_exit(string);
int invis_exit(string);
int query_invis_exit(string);
varargs void skip_obvious(int);
varargs void set_skip_obvious(int);
int query_skip_obvious();
void add_tracks(string, object);
class Track *query_all_tracks();
varargs mixed query_tracks(string);
varargs string *query_track_makers(string);
void use_exit(object, string);
int query_peace(object);

//--- applies ---//

void create() {
  exits = ({});
  skip_obvious = 0;
}

//--- internal exit finding code ---//
static private class Exit find_exit_name(string str) {
  class Exit *filt;
  class Exit ret;

  if (str) {
    filt = filter(exits, (: $1->name == $2 :), str);
    if (sizeof(filt))
      ret = filt[0];
  }

  return ret;
}

static private class Exit find_exit_file(string str) {
  class Exit *filt;
  class Exit ret;

  if (str) {
    filt = filter(exits, (: $1->file == $2 :), str);
    if (sizeof(filt))
      ret = filt[0];
  }

  return ret;
}

static private class Exit find_exit_alias(string str) {
  class Exit *filt;
  class Exit ret;

  if (str) {
    filt = filter(exits, (: member_array($2, $1->aliases) != -1 :), str);
    if (sizeof(filt))
      ret = filt[0];
  }

  return ret;
}

// search by name OR alias:
static private class Exit find_exit(string str) {
  class Exit *filt;
  class Exit ret;

  if (str) {
    filt = filter(exits, (:
      ($1->name == $2) || (member_array($2, $1->aliases) != -1)
    :), str);
    if (sizeof(filt))
      ret = filt[0];
  }

  return ret;
}

static private string find_dest(class Exit ex) {
  if (ex) {
    if (functionp(ex->dest_func) && !(functionp(ex->dest_func) & FP_OWNER_DESTED))
      return evaluate(ex->dest_func);
    else
      return ex->file;
  }
  return NO_SUCH_EXIT;
}

//--- basic exit set/query functions ---//
class Exit *query_all_exits() {
  return copy(exits);
}
string *query_exits() {
  return map(query_all_exits(), (: $1->name :) ) || ({});
}
string *query_destinations() {
  return map(query_all_exits(), (: $1->dest_func || $1->file :) ) || ({});
}
string *query_obvious_exits() {
  class Exit *exs = filter(query_all_exits(), (: $1->invis == 0 :) );
  return map(exs, (: $1->name :) ) || ({});
}
string *query_enters() {
  return filter(query_exits(), (: strsrch($1, ENTER_PREFIX) == 0 :));
}
string *query_entrances() { return query_enters(); }
string *query_obvious_enters() {
  return filter(query_obvious_exits(), (: strsrch($1, ENTER_PREFIX) == 0 :));
}
string *query_obvious_entrances() { return query_obvious_enters(); }

string query_exit(string str) {
  class Exit ex = find_exit(str);

  return find_dest(ex);
}

string query_obvious_exit(string str) {
  class Exit ex = find_exit(str);

  if (ex && ex->invis == 0)
    return query_exit(str);

  return NO_SUCH_EXIT;
}

string query_enter(string str) {
  class Exit ex = find_exit(str);
  
  if (ex && strsrch(ex->name, ENTER_PREFIX) == 0)
    return find_dest(ex);

  return NO_SUCH_EXIT;
}
string query_entrance(string str) {
  return query_enter(str);
}
string query_obvious_enter(string str) {
  class Exit ex = find_exit(str);

  if (ex && strsrch(ex->name, ENTER_PREFIX) == 0 && ex->invis == 0)
    return find_dest(ex);

  return NO_SUCH_EXIT;
}
string query_obvious_entrance(string str) {
  return query_obvious_enter(str);
}

mapping query_directions() {
  mapping tmp_exits = allocate_mapping(sizeof(exits));

  foreach (class Exit ex in exits)
    tmp_exits[ex->name] = ex->dest_func || ex->file;

  return tmp_exits;
}

string query_direction(string str) {
  class Exit ex = find_exit_file(str);

  if (ex)
    return ex->name;

  return NO_SUCH_EXIT;
}

varargs static void set_exits(mixed dests, string *dirs) {

  if (nullp(dests))
    return;

  if (nullp(dirs) && mapp(dests)) {
    foreach (string dir, string file in dests)
      add_exit(file, dir);
  }

  else if (sizeof(dests) == sizeof(dirs)) {
    for (int i = 0; i < sizeof(dests); i++)
      add_exit(dests[i], dirs[i]);
  }

}

void add_exit(string dest, string dir) {
  class Exit ex = find_exit_name(dir);

  if (!ex) {
    ex = new(class Exit);
    ex->name = dir;
    ex->file = dest;
    ex->aliases = ({});
    exits |= ({ ex });
  }

}

void remove_exit(string dir) {
  class Exit ex = find_exit_name(dir);

  if (ex) {
    ex->doors = 0;
    ex->tracks = 0;
    exits -= ({ ex });
  }

}

// an exit alias is another name for the same exit, it only functions to
// let people enter multiple commands to travel in the same direction
void add_exit_alias(string dir, string alias) {
  class Exit ex = find_exit_name(dir);

  if (ex)
    ex->aliases |= ({ alias });

}

void remove_exit_alias(string dir, string alias) {
  class Exit ex = find_exit_name(dir);

  if (ex)
    ex->aliases -= ({ alias });

}

string query_full_direction(string str) {
  int i;

  i = member_array(str, TMPSHORT);

  if (i == -1)
    return str;

  return TMPLONG[i];
}
string query_long_direction(string str) {
  return query_full_direction(str);
}
string query_short_direction(string str) {
  int i;

  i = member_array(str, TMPLONG);

  if (i == -1)
    return str;

  return TMPSHORT[i];
}

//--- exit display functions ---//
string query_exit_display(string how) {
  string *exs;
  string *ents;
  string msg;
  string entermsg;
  string format;

  if (query_skip_obvious())
    return "";

  ents = query_obvious_enters();
  exs = query_obvious_exits() - ents;
  switch (sizeof(exs)) {
    case 0:
      if (how == "short")
	msg = "%^GREEN%^no exits%^RESET%^";
      else
	msg = "There are no obvious exits.";
    break;

    case 1:
      if (how == "short")
	msg = "%^GREEN%^exit:%^RESET%^ "+query_short_direction(exs[0])+" ";
      else
	msg = "There is only one obvious exit: "+exs[0]+".";
    break;

    default:
      exs = sort_array(exs, (: exit_sort :), TMPLONG);
      if (how == "short") {
	exs = map(exs, (: query_short_direction($1) :));
	msg = "%^GREEN%^exits:%^RESET%^ "+
	  replace_string(list(exs, 0, 0), ",", "%^GREEN%^,%^RESET%^");
      }
      else
	msg = "There are "+cardinal(sizeof(exs))+" obvious exits: "+list(exs)+".";
  }
  switch (sizeof(ents)) {
    case 0: /* do nothing */ break;

    case 1:
      if (how == "short")
	entermsg = "%^GREEN%^entrance:%^RESET%^ "+ents[0][sizeof(ENTER_PREFIX)..<1];
      else
	entermsg = "There is one entrance: "+ents[0][sizeof(ENTER_PREFIX)..<1];
    break;

    default:
      ents = sort_array(ents, 1);
      ents = map(ents, (: $1[sizeof($2)..<1] :), ENTER_PREFIX);
      if (how == "short")
	entermsg = "%^GREEN%^entrances:%^RESET%^ "+
	  replace_string(list(ents, 0, 0), ",", "%^GREEN%^,%^RESET%^");
      else
	entermsg = "There are "+cardinal(sizeof(ents))+" entrances: "+list(ents)+".";
  }
  
  // be sure LONG_FORMAT and SHORT_FORMAT have %s in them and other % chars are doubled (%%)
  if (how == "short")
    format = SHORT_FORMAT;
  else
    format = LONG_FORMAT;

  msg = sprintf(format, msg);
  if (entermsg)
    msg += "\n"+sprintf(format, entermsg);

  return msg;
}

string query_long_exits() {
  return query_exit_display("long");
}
string query_short_exits() {
  return query_exit_display("short");
}

static private int exit_sort(string a, string b, string *master) {
  int apos = member_array(a, master);
  int bpos = member_array(b, master);
  if (apos == -1 && bpos == -1)
    return strcmp(a, b);
  else if (apos == -1) // but not bpos
    return 1;
  else if (bpos == -1) // but not apos
    return -1;
  else if (a < b)
    return -1;
  else
    return 1;
  return 0;
}

static private string exit_movement(string dir) {
  if (query_enter(dir) != NO_SUCH_EXIT)
    return "into "+definite_article(dir[sizeof(ENTER_PREFIX)..<1]);
  return dir;
}

//--- pre and post exit functions ---//
void perform_post_exits(string str) {
class Exit ex = find_exit_name(str);

if (ex && ex->post_func)
  return call_other(this_object(), ex->post_func);
}

int perform_pre_exits(string str) {
class Exit ex = find_exit_name(str);

if (ex && ex->pre_func)
    return call_other(this_object(), ex->pre_func);

  // default: let people through
  return 1;
}

static void set_post_exit_functions(string *dirs, string *funcs) {
  if (sizeof(dirs) == sizeof(funcs)) {
    for (int i = 0; i < sizeof(dirs); i++)
      add_post_exit_function(dirs[i], funcs[i]);
  }
}

static void add_post_exit_function(string dir, string func) {
  class Exit ex = find_exit_name(dir);
  if (ex)
    ex->post_func = func;
}

static void remove_post_exit_function(string dir) {
  class Exit ex = find_exit_name(dir);
  if (ex)
    ex->post_func = 0;
}

static void set_pre_exit_functions(string *dirs, string *funcs) {
  if (sizeof(dirs) == sizeof(funcs)) {
    for (int i = 0; i < sizeof(dirs); i++)
      add_pre_exit_function(dirs[i], funcs[i]);
  }
}

static void add_pre_exit_function(string dir, string func) {
  class Exit ex = find_exit_name(dir);
  if (ex)
    ex->pre_func = func;
}

static void remove_pre_exit_function(string dir) {
  class Exit ex = find_exit_name(dir);
  if (ex)
    ex->pre_func = 0;
}

string *query_pre_exit_functions() {
  return map(query_all_exits(), (: $1->pre_func :) );
}

string query_pre_exit_function(string dir) {
  class Exit ex = find_exit_name(dir);
  if (ex)
    return ex->pre_func;
}

string *query_post_exit_functions() {
  return map(query_all_exits(), (: $1->post_func :) );
}

string query_post_exit_function(string dir) {
  class Exit ex = find_exit_name(dir);
  if (ex)
    return ex->post_func;
}

//--- invis exits ---//
void set_invis_exits(string *dirs) {
  foreach (string dir in dirs) {
    add_invis_exit(dir);
  }
}

void add_invis_exit(string dir) {
  class Exit ex = find_exit_name(dir);
  if (ex)
    ex->invis = 1;
}

void remove_invis_exit(string dir) {
  class Exit ex = find_exit_name(dir);
  if (ex)
    ex->invis = 0;
}

int invis_exit(string dir) {
  class Exit ex = find_exit_name(dir);
  if (ex && ex->invis == 1)
    return 1;
  return 0;
}
int query_invis_exit(string dir) {
  return invis_exit(dir);
}

//--- skip obvious exit list ---//
varargs void skip_obvious(int x) {
  if (nullp(x) || x != 0)
    x = 1;
  skip_obvious = x;
}
varargs void set_skip_obvious(int x) {
  skip_obvious(x);
}
int query_skip_obvious() {
  return skip_obvious;
}

//--- tracks made by walking ---//
//
// tracking function added by Valodin
// August 10, 1993
//
// the first track is the most recent one
// after MAX_TRACKS tracks then the oldest ones get taken off
// each track is an array ({ player_name, exit_name, time })
//
// rewritten by Nulvect 2009-08-16 to use class instances,
// also added some more functionality

void add_tracks(string dir, object ob) {
  class Track tr;
  class Exit ex = find_exit_name(dir);

  if (!ex || !ob || !ob->is_living())
    return;
  
  // vampires don't leave tracks
  if (ob->query_race() == "vampire")
    return;

  tr = new(class Track);
  tr->name = ob->query_name();
  tr->dir = dir;
  tr->time = time();

  if (!sizeof(ex->tracks))
    ex->tracks = ({});

  ex->tracks += ({ tr });

  if (sizeof(ex->tracks) > MAX_TRACKS)
    ex->tracks = ex->tracks[1..<1];
}

class Track *query_all_tracks() {
  class Track *trs = ({});
  class Exit *exs = filter(exits, (: sizeof($1->tracks) :));

  // ex->tracks is an array so no need for ({ }) when adding it
  foreach (class Exit ex in exs)
    trs += ex->tracks;

  return copy(trs);
}

// query_tracks() will give you the same info as before,
// which looks like ({ ({ name, dir, time }), ({ name2, dir2, time2 }) })
// query_tracks("east") gives you a list of the tracks to the east,
// as an array of class instances
varargs mixed query_tracks(string dir) {
  class Exit ex;

  if (nullp(dir))
    return map(query_all_tracks(), (: ({ $1->name, $1->dir, $1->time }) :));

  if (ex = find_exit_name(dir) && sizeof(ex->tracks))
    return ex->tracks;

  return ({});
}

varargs string *query_track_makers(string dir) {
  string *names = ({});
  class Track *trs;
  
  if (nullp(dir))
    trs = query_all_tracks();
  else
    trs = query_tracks(dir);

  names = map(trs, (: $1->name :) );

  return names;
}

//--- action: attempt to use an exit ---//
// this func will be called by the command hook
// tp could be a player or a monster
void use_exit(object tp, string dir) {
  class Exit ex;

  if (tp->query_busy() && sizeof(tp->query_attackers())) {
    if ((tp->query_magic_round() == tp->query_magic_round_start()) ||
        (tp->query_disable() == tp->query_disable_start()) || tp->query_casting()) {
          message("info", "You cannot exit while doing something else.", tp);
          return;
    }
  }

  ex = find_exit(dir);

  if (!ex) {
    message("info", sprintf(BAD_DEST_MSG, exit_movement(dir)), tp);
    return;
  }

  if (!find_object(ex->file)) {
    if (!(sscanf(ex->file, "%*s#%*d") != 2 && load_object(ex->file))) {
      message("info", sprintf(BAD_DEST_MSG, exit_movement(ex->name)), tp);
      return;
    }
  }

  if (!tp->query_mobile()) {
    message("info", "You cannot walk!", tp);
    return;
  }

  switch(tp->query_rest_type()) {
    case REST:
    case SIT:
    case LAY:
      tp->force_me("stand");
    break;
  }

  // block_func is for outside influences to temporarily block an exit
  // function should return 0 to block, 1 to allow
  // called as func(playerob, roomob, exitname);
  if (functionp(ex->block_func) &&
      !(functionp(ex->block_func) & FP_OWNER_DESTED) &&
      !evaluate(ex->block_func, tp, this_object(), dir))
        return;

  // this is for inherent conditions in the room to possibly block exiting
  if (!perform_pre_exits(dir))
    return;

  // this is primarily to check for doors:
  if (function_exists("exit_blocked", this_object()) && this_object()->exit_blocked(dir)) return;

  add_tracks(dir, tp);

  tp->move_player(ex->file, exit_movement(ex->name));
  if (sizeof(tp->query_followers()))
    tp->move_followers(this_object(), dir);

  perform_post_exits(ex->name);
}

// why is this in this file??
int query_peace(object place) {
  if (place->query_property("no attack") && place->query_property("no magic"))
    return 1;
  return 0;
}

