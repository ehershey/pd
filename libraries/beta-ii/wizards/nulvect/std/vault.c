//      /std/vault.c
//      from the Nightmare mudlib
//      A room with as many doors as exits will allow
//      created by Descartes of Borg 23 february 1993

#include <std.h>
#include <rooms.h>

#define MASTER_KEY_ID "infmastakey"

inherit ROOM;
 
mapping doors;
 
static void initialize_door(string id);
void set_door(string id, string dest, string dir, string key);
int is_door(string id);
void set_destination(string id, string dest);
void set_direction(string id, string dir);
mixed query_destination(string id);
string query_direction(string id);
string query_door(string dir);
int remove_door(string id);

void set_open(string id, int open);
void set_closed(string id, int closed);
int toggle_closed(string id);
int query_open(string id);
int query_closed(string id);

void set_locked(string id, int locked);
int query_locked(string id);
void set_key(string id, string key);
string query_key(string id);
string query_lock(string id);
int pick_lock(string id);

void set_func(string id, string which, string fun);
mixed query_func(string id, string which);
void set_string(string id, string which, string str);
string query_string(string id, string which);
void set_door_pre_exit_function(string id, string fun);
mixed query_door_pre_exit_function(string id);

void set_both(string id, string func, mixed args);

int event_open(object tp, string id);
int event_close(object tp, string id);
int event_lock(object tp, string id, object key);
int event_unlock(object tp, string id, object key);

int GoThroughDoor();


void create() {
  ::create();
  doors = ([ ]);
}
 
void clean_up() { return; }

// set up and basic info for all doors
static void initialize_door(string id) {
  doors[id] = ([
    "destination" : "",
    "direction" : "",
    "key" : 0,
    "locked" : 0,
    "closed" : 1,
    "pre exit" : 0,
    "func" : ([
      "open" : 0,
      "close" : 0,
      "lock" : 0,
      "unlock" : 0,
    ]),
    "string" : ([
      "open" : 0,
      "close" : 0,
      "lock" : 0,
      "unlock" : 0,
    ]),
  ]);
}

void set_door(string id, string dest, string dir, string key) {
  if (query_exit(dir) == ROOM_VOID) return;
  initialize_door(id);
  // destination is a filename - "/d/nopk/tirun/square"
  set_destination(id, dest);
  // direction is the direction it covers - "north"
  set_direction(id, dir);
  add_pre_exit_function(dir, "GoThroughDoor");
  if (key)
    set_key(id, key);
}

int is_door(string id) {
  if (doors[id]) return 1;
  else return 0;
}

void set_destination(string id, string dest) {
  if (is_door(id))
    doors[id]["destination"] = dest;
}
void set_direction(string id, string dir) {
  if (is_door(id))
    doors[id]["direction"] = dir;
}
// returns the object if it can find it
mixed query_destination(string id) {
  mixed dest;
  if (is_door(id)) {
    if (dest = load_object(doors[id]["destination"]))
      return dest;
    else
      return doors[id]["destination"];
  }
  else return 0;
}
string query_direction(string id) {
  if (is_door(id)) return doors[id]["direction"];
  else return 0;
}
// gives you the door ID for a given direction or destination
string query_door(string dir) {
  foreach (string id in keys(doors))
    if (doors[id]["direction"] == dir || doors[id]["destination"] == dir)
      return id;
  return 0;
}

// I see no reason to return an int here, but preserved for compatibility
int remove_door(string id) {
  if (is_door(id)) {
    map_delete(doors, id);
    return 1;
  }
  return 0;
}
// ---

// open/close 
void set_open(string id, int open) {
  set_closed(id, !open);
}
void set_closed(string id, int closed) {
  if (is_door(id))
    doors[id]["closed"] = closed;
}
int toggle_closed(string id) {
  set_closed(id, !query_closed(id));
  return query_closed(id);
}

int query_open(string id) {
  if (is_door(id))
    return !query_closed(id);
  else return 0;
}
int query_closed(string id) {
  if (is_door(id))
    return doors[id]["closed"];
  else return 0;
}
// ---

// locks
void set_locked(string id, int locked) {
  if (is_door(id) && query_key(id))
    doors[id]["locked"] = locked;
}
int query_locked(string id) {
  if (is_door(id))
    return doors[id]["locked"];
  else return 0;
}
void set_key(string id, string key) {
  if (is_door(id))
    doors[id]["key"] = key;
}
string query_key(string id) {
  if (is_door(id))
    return doors[id]["key"];
  else return 0;
}
string query_lock(string id) {
  return query_key(id);
}
int pick_lock(string id) {
  if (!is_door(id))
    return 0;
  set_both(id, "set_locked", 0);
  return 1;
}
// ---

// functions/etc
void set_func(string id, string which, string fun) {
  if (is_door(id))
    doors[id]["func"][which] = fun;
}
mixed query_func(string id, string which) {
  if (is_door(id))
    return doors[id]["func"][which];
  else return 0;
}
 
void set_string(string id, string which, string str) {
  if (is_door(id))
    doors[id]["string"][which] = str;
}
string query_string(string id, string which) {
  if (is_door(id))
    return doors[id]["string"][which];
  else return 0;
}

void set_door_pre_exit_function(string id, string fun) {
  if (is_door(id))
    doors[id]["pre exit"] = fun;
}
mixed query_door_pre_exit_function(string id) {
  if (is_door(id))
    return doors[id]["pre exit"];
  else return 0;
}
// ---

// function to perform an action on both sides of the door at once
void set_both(string id, string func, mixed args) {
  object *obs = ({ this_object() });
  object dest;

  if (objectp(dest = query_destination(id)))
    obs += ({ dest });

  if (!arrayp(args)) args = ({ args });
  if (!sizeof(args)) args = ({});
  
  call_other(obs, ({ func, id })+args);
}
// ---

// to be called from commands
int event_open(object tp, string id) {
  object env = this_object();
  object dest;
  mixed func;
  string ostring;
  
  if (!tp || environment(tp) != env || !is_door(id)) return 0;

  if (query_locked(id)) {
    message("cmd_open", "The "+id+" is locked.", tp);
    return 0;
  }

  if (!query_closed(id)) {
    message("cmd_open", "The "+id+" is already opened.", tp);
    return 0;
  }

  if (functionp(func = query_func(id, "open")))
    if (!(*func)()) return 0;

  if (!stringp(ostring = query_string(id, "open")))
    ostring = "You open the "+id+".";

  message("cmd_open", ostring, tp);

  message("cmd_open", tp->query_cap_name()+" opens the "+id+".", env, tp);

  set_both(id, "set_open", 1);

  if (objectp(dest = query_destination(id)))
    message("cmd_open", "You notice the "+id+" suddenly open "
      "from the other side.", dest);
  
  return 1;
}

int event_close(object tp, string id) {
  object env = this_object();
  object dest;
  mixed func;
  string cstring;
  
  if (!tp || environment(tp) != env || !is_door(id)) return 0;

  if (query_locked(id)) {
    message("cmd_close", "The "+id+" is locked.", tp);
    return 0;
  }

  if (query_closed(id)) {
    message("cmd_close", "The "+id+" is already closed.", tp);
    return 0;
  }

  if (functionp(func = query_func(id, "close")))
    if (!(*func)()) return 0;

  if (!stringp(cstring = query_string(id, "close")))
    cstring = "You close the "+id+".";

  message("cmd_close", cstring, tp);

  message("cmd_close", tp->query_cap_name()+" closes the "+id+".", env, tp);

  set_both(id, "set_closed", 1);

  if (objectp(dest = query_destination(id)))
    message("cmd_close", "The "+id+" is closed by someone "
      "on the other side.", dest);
  
  return 1;
}

int event_lock(object tp, string id, object key) {
  object env = this_object();
  object dest;
  mixed func;
  string lstring;
  
  if (!tp || environment(tp) != env || !is_door(id)) return 0;

  if (query_locked(id)) {
    message("cmd_lock", "The "+id+" is already locked.", tp);
    return 0;
  }

  if (!query_key(id)) {
    message("cmd_lock", "The "+id+" does not have a lock.", tp);
    return 0;
  }

  if (!key->id(query_key(id)) && !key->id(MASTER_KEY_ID)) {
    message("cmd_lock", "The "+key->query_short()+" does not fit in the lock.", tp);
    return 0;
  }

  if (!query_closed(id)) {
    message("cmd_lock", "The "+id+" is not closed.", tp);
    return 0;
  }

  if (functionp(func = query_func(id, "lock")))
    if (!(*func)()) return 0;

  if (!stringp(lstring = query_string(id, "lock")))
    lstring = "You lock the "+id+" with the "+key->query_short()+".";

  message("cmd_lock", lstring, tp);

  message("cmd_lock", tp->query_cap_name()+" locks the "+id+
    " with the "+key->query_short()+".", env, tp);

  set_both(id, "set_locked", 1);

  if (objectp(dest = query_destination(id)))
    message("cmd_lock", "You hear some scratching noises on the "
      "other side of the "+id+".", dest);
  
  return 1;
}

int event_unlock(object tp, string id, object key) {
  object env = this_object();
  object dest;
  mixed func;
  string ustring;
  
  if (!tp || environment(tp) != env || !is_door(id)) return 0;

  if (!query_locked(id)) {
    message("cmd_unlock", "The "+id+" is already unlocked.", tp);
    return 0;
  }

  if (!query_key(id)) {
    message("cmd_unlock", "The "+id+" does not have a lock.", tp);
    return 0;
  }

  if (!key->id(query_key(id)) && !key->id(MASTER_KEY_ID)) {
    message("cmd_unlock", "The "+key->query_short()+" does not fit in the lock.", tp);
    return 0;
  }

  if (!query_closed(id)) {
    message("cmd_unlock", "The "+id+" is not closed.", tp);
    return 0;
  }

  if (functionp(func = query_func(id, "unlock")))
    if (!(*func)()) return 0;

  if (!stringp(ustring = query_string(id, "unlock")))
    ustring = "You unlock the "+id+" with the "+key->query_short()+".";

  message("cmd_unlock", ustring, tp);

  message("cmd_unlock", tp->query_cap_name()+" unlocks the "+id+
    " with the "+key->query_short()+".", env, tp);

  set_both(id, "set_locked", 0);

  if (objectp(dest = query_destination(id)))
    message("cmd_unlock", "You hear some scratching noises on the "
      "other side of the "+id+".", dest);
  
  return 1;
}
// ---


int GoThroughDoor() {
  object tp=this_player();
  string id;
  string verb;
  mixed func;

  verb = query_verb();

  if (!(id = query_door(verb)))
    return 1;

  if (!query_open(id)) {
    message("info", "You bump into the closed "+id+".\n", tp);
    message("info", tp->query_cap_name()+" bumps into the closed "+id+".\n",
      environment(tp), tp);
    return 0;
  }
  
  if (functionp(func = query_door_pre_exit_function(id)))
    if (!(*func)()) return 0;

  return 1;
}

