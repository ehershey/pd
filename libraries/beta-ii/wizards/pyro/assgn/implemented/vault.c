//      /std/vault.c
//      Lays the foundation for easy addition and
//      manipulation of doors.
//      created by Pyro789x 7/21/2008

/******Changelog*************/

/** Monday July 21 2008 ******************************************************
 * Edited by Pyro
 * Changed function names at Nulvect's request
 * set_status is now set_door_status, query_status is now query_door_status
 * set_player_message is now set_door_msg, query_player_message is now query_door_msg
 * set_env_message is now set_door_env_msg, query_env_message is now query_door_env_msg
 * set_func is now set_door_func, query_func is now query_door_func
 *
 * By Nulvect's request, when a player attempts to do an action to a door, they
 * will now attempt to perform that action on one door by that name as usual, but
 * if they typed in a direction, they will also attempt to perform that action on
 * all doors that blocked that direction.
 *****************************************************************************/

/**** Pre-Program directives *************************/

#include <std.h>
#include <rooms.h>
#include <daemons.h>

#define DOOR_D "/wizards/pyro/doors/door_d.c"

#define MASTER_KEY_ID "MUD_Master_Key"

inherit ROOM;


/****global variables*********************************/

//will keep track of how this room individually will respond to the changes
//that may happen to the door, and how this room can interact with that door
mapping doorSpecifics;
 

/****function prototypes *****************************/

static void initialize_door_specifics(string id);
void initialize_status(string id, string dstatus);
int is_door(string id);

void cover_exit_with_door(string dir, string id);
void remove_door_from_exit(string id, string dir);
string* query_exits(string id);
string* get_doors_blocking_exit(string dir);
string* get_doors();
string find_id_by_name(string str);

string query_door_status(string id);
void set_door_status(string id, string newStatus);
void set_locked(string id, int locked);
int query_locked(string id);
void set_closed(string id, int closed);
int query_closed(string id);
void set_key(string id, string key);
string query_key(string id);
void set_door_name(string id, string name);
string query_door_name(string id);

varargs void set_door_func(string id, string which, string fun, string dstatus);
mixed query_door_func(string id, string which);
varargs void set_door_msg(string id, string which, string str, string dstatus);
string query_door_msg(string id, string which);
varargs void set_door_env_msg(string id, string which, string str, string dstatus);
string query_door_env_msg(string id, string which);

int event_open(object tp, string id);
int event_close(object tp, string id);
int event_lock(object tp, string id, object key);
int event_unlock(object tp, string id, object key);

int cmd_close(string str);
int cmd_open(string str);
int cmd_lock(string str);
int cmd_unlock(string str);

varargs int exit_blocked(string dir);

varargs void write_action_string(string id, string action, object calling_player);

/****function implementations ************************/


void create() {
  ::create();
  doorSpecifics = ([ ]);
}

void init() {
  ::init();
 add_action("cmd_open", "open");
 add_action("cmd_close", "close");
 add_action("cmd_lock", "lock");
 add_action("cmd_unlock", "unlock");
}

// set up and set basic info for all doors to default values
static void initialize_door_specifics(string id) {
  if (is_door(id)) return;

  doorSpecifics[id] = ([
    "exits" : ({ }),
    "status" : ([ ]),
  ]);

  initialize_status(id, "default");
}

//Adds a specific status to the door if it does not already exist
//note: this does not need to be called to set a door to a specific status,
//      if the status is not found then the door will just respond to the
//      status as it does a default setting.
void initialize_status(string id, string dstatus) {
  if(doorSpecifics[id]["status"][dstatus])
    return;

  doorSpecifics[id]["status"][dstatus] = ([
    //functions that will be called before the specified action is executed.
    //if the function returns 1, the action will proceed as normal. If it
    //returns 0, the action will fail.
    "func" : ([
      "open" : 0,
      "close" : 0,
      "lock" : 0,
      "unlock" : 0,
      "enter" : 0,
    ]),
    //strings that will be written to the player's terminal when they
    //accomplish the specified action
    "player message" : ([
      "open" : 0,
      "close" : 0,
      "lock" : 0,
      "unlock" : 0,
      "enter" : 0,
    ]),
    //strings that will be written to the environment when an action is
    //performed on a door
    "env message" : ([
      "open" : 0,
      "close" : 0,
      "lock" : 0,
      "unlock" : 0,
    ]),
  ]);
}


//makes it so that the door blocks a player's exit in that direction
//internal: associate the global door object with this room
void cover_exit_with_door(string dir, string id) {
  initialize_door_specifics(id);

  //return if this exit is already being covered by the door
  if(member_array(dir, doorSpecifics[id]["exits"]) != -1)
    return;

 doorSpecifics[id]["exits"] += ({dir});
  DOOR_D->connect_door_to_room(id, this_object());

  //todo: figure out some way to enforce not allowing people to go through this exit
  //add_pre_exit_function(dir, "GoThroughDoor");
}

//makes it so that the door no longer blocks a player's exit in that direction
//internal: unassociate the global door object with this room
void remove_door_from_exit(string id, string dir) {
  //remove the exit from the door id. If the exit array is now empty, disconnect
  //the door from the room
  doorSpecifics[id]["exits"] -= dir;

  if(sizeof(doorSpecifics[id]["exits"]) < 1)
    DOOR_D->disconnect_door_from_room(id, this_object());

  //todo: remove the enforcing of not allowing people to go through this exit
  //remove_pre_exit_function(dir);
}

int is_door(string id) {
  if (doorSpecifics[id]) return 1;
  else return 0;
}


//returns, as a string array, the exits that the door covers
string* query_exits(string id) {
  if (!is_door(id)) return 0;
  return doorSpecifics[id]["exits"];
}


// gives you an array of the door IDs of the doors covering a specific exit
string* get_doors_blocking_exit(string dir) {
  string* doors = ({ });

  //search each door for an exit that matches the exit given
  foreach (string id in keys(doorSpecifics)) {
    foreach (string exitDir in doorSpecifics[id]["exits"]) {
      if(exitDir == dir)
       doors += ({id});
    }
  }

  return doors;
}

string* get_doors() { return keys(doorSpecifics); }


string find_id_by_name(string str) {
  string door;
  int num, count = 0;

  if(!str) return 0;
  if(sscanf(str, "%s %d", door, num) != 2) {
    door = str;
    num = 1;
  }

  foreach(string doorId in get_doors()) {
    if(query_door_name(doorId) == door) {
      count++;
      if(count == num) {
        return doorId;
      }
    }
  }

  return 0;
}


string query_door_status(string id) {
  if(!is_door(id)) return 0;

  return DOOR_D->query_door_status(id);
}

void set_door_status(string id, string newStatus) {
  if(!is_door(id)) return;

  DOOR_D->set_door_status(id, newStatus);
}

void set_locked(string id, int locked) {
  if (!is_door(id)) return;

  DOOR_D->set_locked(id, locked);
}

int query_locked(string id) {
  if (!is_door(id)) return -1;
  return DOOR_D->query_locked(id);
}



void set_closed(string id, int closed) {
  if (!is_door(id)) return;

  DOOR_D->set_closed(id, closed);
}

int query_closed(string id) {
  if (!is_door(id)) return -1;
  return DOOR_D->query_closed(id);
}



void set_key(string id, string key) {
  if (!is_door(id)) return;
  DOOR_D->set_key(id, key);
}

string query_key(string id) {
  if (!is_door(id)) return "DoorNotFound";
  return DOOR_D->query_key(id);
}

void set_door_name(string id, string name) {
  if (!is_door(id)) return;
  DOOR_D->set_door_name(id, name);
}

string query_door_name(string id) {
  if (!is_door(id)) return 0;
  return DOOR_D->query_door_name(id);
}



/*** pre-action functions ***************/
 
/*adds a pre_action_function fun to the action specified by which
 *on the door specified by id, and only when the door is set to the
 *status specified by status. If no status is given, the function
 *will be added to the door's default pre_action_function for that action */
varargs void set_door_func(string id, string which, string fun, string dstatus) {
  if (nullp(id) || nullp(which)) return;
  if (nullp(dstatus)) dstatus = "default";
  if (!is_door(id)) return;

  //ensure that the status is usable
  initialize_status(id, dstatus);

  //add the function to door
  doorSpecifics[id]["status"][dstatus]["func"][which] = fun;
}

/*gets the pre_action_function for the action specified by which on the
 *door specified by id, at the door's current status. If the door's current
 *status has not been initialized (nothing has ever been added for that
 *status), then the default function for that action will be returned */
mixed query_door_func(string id, string which) {
  string doorStatus = query_door_status(id);
  if (!is_door(id)) return 0;

  //return the function specific to the door's status, if it exists
  if (doorSpecifics[id]["status"][doorStatus]) {
    return doorSpecifics[id]["status"][doorStatus]["func"][which];
  }

  //return the function specific to the default door status
  return doorSpecifics[id]["status"]["default"]["func"][which];
}

//todo: add status specific elements, including default

/*** post-action strings ****************/


/*Adds an action string, string to the action specifid by which, on the door
 *specified by id, and only when the door is set to the status
 *specified by status. If no status is given, the string will be
 *added to the door's default action string for that action. */
varargs void set_door_msg(string id, string which, string str, string dstatus) {
  if (nullp(id) || nullp(which)) return;
  if (nullp(dstatus)) dstatus = "default";
  if (!is_door(id)) return;

  //ensure that the status is usable
  initialize_status(id, dstatus);

  //add the function to door
  doorSpecifics[id]["status"][dstatus]["player message"][which] = str;
}

/*gets the action string for the action specified by which on the
 *door specified by id, at the door's current status. If the door's current
 *status has not been initialized (nothing has ever been added for that
 *status), then the default string for that action will be returned */
string query_door_msg(string id, string which) {
  string doorStatus = query_door_status(id);
  if (!is_door(id)) return 0;

  //return the string specific to the door's status, if it exists
  if (doorSpecifics[id]["status"][doorStatus]) {
    return doorSpecifics[id]["status"][doorStatus]["player message"][which];
  }

  //return the string specific to the default door status
  return doorSpecifics[id]["status"]["default"]["player message"][which];
}

/*Adds a string that will be printed to the room when a door's status changes. */
varargs void set_door_env_msg(string id, string which, string str, string dstatus) {
  if (nullp(id) || nullp(which)) return;
  if (nullp(dstatus)) dstatus = "default";
  if (!is_door(id)) return;

  //ensure that the status is usable
  initialize_status(id, dstatus);

  //add the function to door
  doorSpecifics[id]["status"][dstatus]["env message"][which] = str;
}

/*returns the env_message string */
string query_door_env_msg(string id, string which) {
  string doorStatus = query_door_status(id);
  if (!is_door(id)) return 0;

  //return the string specific to the door's status, if it exists
  if (doorSpecifics[id]["status"][doorStatus]) {
    return doorSpecifics[id]["status"][doorStatus]["env message"][which];
  }

  //return the string specific to the default door status
  return doorSpecifics[id]["status"]["default"]["env message"][which];
}

//todo: add status specific elements, including default


/*** player-door interaction functions **/

// to be called from commands
int event_open(object tp, string id) {
  object env = this_object();
  mixed func;
  //the message that will be printed to the player when they open the door
  string ostring;
  if (!tp || environment(tp) != env || !is_door(id)) return 0;

  if (query_locked(id)) {
    message("cmd_open", "The "+query_door_name(id)+" is locked.", tp);
    return 0; //todo: check to see if return 0; will cause issues here
  }

  if (!query_closed(id)) {
    message("cmd_open", "The "+query_door_name(id)+" is already opened.", tp);
    return 0; //todo: perhaps use notify_fail instead of return 0?
  }

  if (functionp(func = query_door_func(id, "open")))
    if (!(*func)()) return 0;

  if (!stringp(ostring = query_door_msg(id, "open")))
    ostring = "You open the "+query_door_name(id)+".";

  if(ostring != "NO_MESSAGE")
    message("cmd_open", ostring, tp);


  //message("cmd_open", tp->query_cap_name()+" opens the "+id+".", env, tp);
  DOOR_D->set_closed(id, 0);
  DOOR_D->notify_rooms_of_change(id, "open", this_player());

  return 1;
}

int event_close(object tp, string id) {
  object env = this_object();
  mixed func;
  string cstring;
  
  if (!tp || environment(tp) != env || !is_door(id)) return 0;

  if (query_locked(id)) {
    message("cmd_close", "The "+query_door_name(id)+" is locked.", tp);
    return 0;
  }

  if (query_closed(id)) {
    message("cmd_close", "The "+query_door_name(id)+" is already closed.", tp);
    return 0;
  }

  if (functionp(func = query_door_func(id, "close")))
    if (!(*func)()) return 0;

  if (!stringp(cstring = query_door_msg(id, "close")))
    cstring = "You close the "+query_door_name(id)+".";

  if(cstring != "NO_MESSAGE") message("cmd_close", cstring, tp);

//  message("cmd_close", tp->query_cap_name()+" closes the "
//        +query_door_name(id)+".", env, tp);
  DOOR_D->set_closed(id, 1);
  DOOR_D->notify_rooms_of_change(id, "close", this_player());


  return 1;
}

int event_lock(object tp, string id, object key) {
  object env = this_object();
  mixed func;
  string lstring;
  
  if (!tp || environment(tp) != env || !is_door(id)) return 0;

  if (query_locked(id)) {
    message("cmd_lock", "The "+query_door_name(id)+" is already locked.", tp);
    return 0;
  }

  if (!query_key(id)) {
    message("cmd_lock", "The "+query_door_name(id)+" does not have a lock.", tp);
    return 0;
  }

  if (!key->id(query_key(id)) && !key->id(MASTER_KEY_ID)) {
    message("cmd_lock", "The "+key->query_short()+" does not fit in the lock.", tp);
    return 0;
  }


  if (functionp(func = query_door_func(id, "lock")))
    if (!(*func)()) return 0;

  if (!stringp(lstring = query_door_msg(id, "lock")))
    lstring = "You lock the "+query_door_name(id)
             +" with the "+key->query_short()+".";

  if(lstring != "NO_MESSAGE") message("cmd_lock", lstring, tp);

//  message("cmd_lock", tp->query_cap_name()+" locks the "+id+
//    " with the "+key->query_short()+".", env, tp);
  DOOR_D->set_locked(id, 1);
  DOOR_D->notify_rooms_of_change(id, "lock", this_player());

  
  return 1;
}

int event_unlock(object tp, string id, object key) {
  object env = this_object();
  mixed func;
  string ustring;
  
  if (!tp || environment(tp) != env || !is_door(id)) return 0;

  if (!query_locked(id)) {
    message("cmd_unlock", "The "+query_door_name(id)+" is already unlocked.", tp);
    return 0;
  }

  if (!query_key(id)) {
    message("cmd_unlock", "The "+query_door_name(id)+" does not have a lock.", tp);
    return 0;
  }

  if (!key->id(query_key(id)) && !key->id(MASTER_KEY_ID)) {
    message("cmd_unlock", "The "+key->query_short()+" does not fit in the lock.", tp);
    return 0;
  }

  if (functionp(func = query_door_func(id, "unlock")))
    if (!(*func)()) return 0;

  if (!stringp(ustring = query_door_msg(id, "unlock")))
    ustring = "You unlock the "+query_door_name(id)
             +" with the "+key->query_short()+".";

  if(ustring != "NO_MESSAGE") message("cmd_unlock", ustring, tp);

  DOOR_D->set_locked(id, 0);
  DOOR_D->notify_rooms_of_change(id, "unlock", this_player());

  
  return 1;
}


int cmd_close(string str) {
  string* doorIds;

  if(!str) return 0;

  doorIds = get_doors_blocking_exit(str);
  doorIds += ({ find_id_by_name(str) }) ;
  doorIds = filter(doorIds, (: ($1 != 0) :) );

  if(sizeof(doorIds) < 1) {
    return notify_fail("There is no "+str+" here.\n");
  }
  
  //apply action to each door it could apply to
  foreach(string doorId in doorIds) {
    event_close(this_player(), doorId);
  }
  return 1;
}

int cmd_open(string str) {
  string* doorIds;

  if(!str) return 0;

  doorIds = get_doors_blocking_exit(str);
  doorIds += ({ find_id_by_name(str) }) ;
  doorIds = filter(doorIds, (: ($1 != 0) :) );

  if(sizeof(doorIds) < 1) {
    return notify_fail("There is no "+str+" here.\n");
  }
  
  //apply action to each door it could apply to
  foreach(string doorId in doorIds) {
    event_open(this_player(), doorId);
  }
  return 1;
}

int cmd_lock(string str) {
  string doorName, key;
  string* doorIds;
  object keyobj;

  if(!str) return 0;
  if(sscanf(str, "%s with %s", doorName, key) != 2)
    return 0;

  keyobj = present(key, this_player());
  if(!keyobj) {
    return notify_fail("You do not have a "+key+"\n");
  }

  doorIds = get_doors_blocking_exit(doorName);
  doorIds += ({ find_id_by_name(doorName) });
  doorIds = filter(doorIds, (: ($1 != 0) :) );

  if(sizeof(doorIds) < 1) {
    return notify_fail("There is no "+doorName+" here.\n");
  }

  //apply action to each door it could apply to
  foreach(string doorId in doorIds) {
    event_lock(this_player(), doorId, keyobj);
  }
  return 1;
}

int cmd_unlock(string str) {
  string doorName, key;
  string* doorIds;
  object keyobj;

  if(!str) return 0;
  if(sscanf(str, "%s with %s", doorName, key) != 2)
    return 0;

  keyobj = present(key, this_player());
  if(!keyobj) {
    return notify_fail("You do not have a "+key+"\n");
  }

  doorIds = get_doors_blocking_exit(doorName);
  doorIds += ({ find_id_by_name(doorName) });
  doorIds = filter(doorIds, (: ($1 != 0) :) );

  if(sizeof(doorIds) < 1) {
    return notify_fail("There is no "+doorName+" here.\n");
  }

  //apply action to each door it could apply to
  foreach(string doorId in doorIds) {
    event_unlock(this_player(), doorId, keyobj);
  }
  return 1;
}

// ---


/*returns 0 if the exit can be taken
 *returns 1 if the exit cannot be taken */
//if no direction is given, query_verb will be set as the direction
varargs int exit_blocked(string dir) {
  string *doorIds;
  mixed func;
  object tp = this_player();
  if(dir) doorIds = get_doors_blocking_exit(dir);
  else doorIds = get_doors_blocking_exit(query_verb());

  foreach(string doorId in doorIds) {
   if(query_closed(doorId)) {
      message("info", "You bump into the closed "
        +query_door_name(doorId)+".\n", tp);
      message("info", tp->query_cap_name()+" bumps into the closed "
       +query_door_name(doorId)+".\n", environment(tp), tp);
      return 1;
    }

    if (functionp(func = query_door_func(doorId, "enter"))) {
      if(!(*func)()) {
        return 1;
      }
    }
  }

  foreach(string doorId in doorIds) {
    write(query_door_msg(doorId, "enter"));
  }
  return 0;
}


varargs void write_action_string(string id, string action, object calling_player) {
  string str;
  if (nullp(id) || nullp(action)) return;

  str = query_door_env_msg(id, action);
  if(!str) {
    if(action == "open") str = "The "+query_door_name(id)+" slides open.";
    else if(action == "close") str = "The "+query_door_name(id)+" slides shut.";
    else if(action == "lock") str = "The "+query_door_name(id)+"'s lock clicks.";
    else if(action == "unlock") str = "The "+query_door_name(id)+"'s lock clicks.";
    else return;
  }
  else if(str == "NO_MESSAGE")
    return;

  if (nullp(calling_player))
    message("say", str, this_object());
  else
    message("say", str, this_object(), calling_player);
}


/** Legacy Support **********************************************
 *                                                              *
 * These functions attempt to change the door IDs passed        *
 * and received to make them compatable with the new system     *
 * do NOT call them unless you use only them and none of the    *
 * newer functions, or you will have issues referencing doors   *
 ****************************************************************/
//note: the functions set_locked(string id, int locked) and query_locked(string id)
//could not be represented here, as another version of these functions already
//exist above. As such, referencing these functions with old IDs may fail.
string fixId(string oldId) {
  return path_file(base_name(this_object()))[0]+"/"+oldId;
}
string breakId(string newId) {
  return path_file(newId)[1];
}
int remove_door(string id) {
  if(!is_door(id)) return 0;
  foreach(string exit in query_exits(id)) {
    remove_door_from_exit(id, exit);
  }
  return 1;
}
int GoThroughDoor() { return !exit_blocked(); }
int OpenDoor(string str) { return cmd_open(str); }
int CloseDoor(string str) { return cmd_close(str); }
int UnlockDoor(string str) { return cmd_unlock(str); }
int LockDoor(string str) { return cmd_lock(str); }
int query_open(string id) { id = fixId(id); return !query_closed(id); }
string query_door(string dir) { return breakId(get_doors_blocking_exit(dir)[0]); }
string query_lock(string id) { id = fixId(id); return query_key(id); }
void set_door_pre_exit_function(string id, string fun) { id = fixId(id); set_door_func(id, "enter", fun); }
void set_string(string id, string which, string str) { id = fixId(id); set_door_msg(id, which, str); }
void set_func(string id, string which, string fun) { id = fixId(id); set_door_func(id, which, fun); }
void set_open(string id, int open) { id = fixId(id); set_closed(id, !open); }
varargs void set_door(string id, string dest, string dir, string key) {
  string doorName = id;
  id = fixId(id);
  if(nullp(id) || nullp(dest) || nullp(dir)) return;
  cover_exit_with_door(dir, id);
  set_door_name(id, doorName);
  if(!nullp(key))
    set_key(id, key);
}
/***************************************************************/
