//      /std/bag_logic.c
//      from the Nightmare mudlib
//      an inheritable container object
//      based on the broken bag_logic.c created by Brian November 1991
//      written by Descartes of Borg 04 October 1992
//      lockable functions added 21 October 1992 by Descartes

// moved code for closing into this file from container.c,
// cleaned up functions, took out the add_actions and turned them
// into commands, made separate functions for the extra strings
// in the long description

#include <teststd.h>
#include <move.h>

inherit CONTAINER;

private static mapping CloseData;
private static mapping LockData;

void set_possible_to_close(int pos);
void set_can_close(int pos);
int query_possible_to_close();
int query_can_close();
void set_closed(int cl);
int query_closed();
int toggle_closed();

void set_can_lock(int pos);
void set_lockable(int pos);
int query_can_lock();
int query_lockable();
int toggle_lock();
int pick_lock();
void set_locked(mixed stat);
void set_lock(mixed stat);
int query_locked();
int query_lock();
void set_key(string key);
string query_key();

string query_long_closed();
string query_long_contents();
string query_long_full();
string query_long_more();

varargs int receive_objects(object ob);
int remove();
int is_bag();

void create() {
  ::create();
  
  // initialize to default values
  // by default can't close or lock
  CloseData = ([
    "closeable" : 0,
    "closed" : 0
  ]);
  LockData = ([
    "lockable" : 0,
    "locked" : 0,
    "key" : 0
  ]);

}

// closing functions
void set_possible_to_close(int pos) {
  CloseData["closeable"] = pos;
}

void set_can_close(int pos) {
  set_possible_to_close(pos);
}

int query_possible_to_close() {
  return CloseData["closeable"] ? 1 : 0;
}

int query_can_close() {
  return query_possible_to_close();
}

void set_closed(int cl) {
  if (query_possible_to_close())
    CloseData["closed"] = cl;
}

int query_closed() {
  return CloseData["closed"] ? 1 : 0;
}

int toggle_closed() {
  set_closed(!query_closed());
  return query_closed();
}
// -----

// locking functions
void set_can_lock(int pos) {
  LockData["lockable"] = pos;
}

void set_lockable(int pos) {
  set_can_lock(pos);
}

int query_can_lock() {
  return LockData["lockable"] ? 1 : 0;
}

int query_lockable() {
  return query_can_lock();
}

int toggle_lock() {
  set_locked(!query_locked());
  return query_locked();
}

int pick_lock() {
  return toggle_lock();
}

void set_locked(mixed stat) {
  if (stringp(stat)) {
    switch(stat) {
      case "locked": stat=1; break;
      case "unlocked": stat=0; break;
    }
  }
  if (intp(stat))
    LockData["locked"] = stat;
}

void set_lock(mixed stat) {
  set_locked(stat);
}

int query_locked() {
  return LockData["locked"] ? 1 : 0;
}

int query_lock() {
  return query_locked();
}

void set_key(string str) {
  LockData["key"] = str;
}

string query_key() {
  return sizeof(LockData["key"]) ? LockData["key"] : 0;
}
// -----

// descriptions
string query_long_closed() {
  if (!query_can_close()) return "";
  if (!query_closed()) return "It is open.";
  return "It is closed.";
}
string query_long_contents() {
  if (!sizeof(all_inventory(this_object())))
    return "";
  else
    return "It contains:\n  "+
      implode(this_object()->consolidate_contents(({})), "\n  ");
}
string query_long_full() {
  if (this_object()->query_max_internal_encumbrance())
    return "It is "+
      to_int(percent(
        this_object()->query_internal_encumbrance(),
        this_object()->query_max_internal_encumbrance()
      ))+"% full.";
  else
    return "";
}
string query_long_more() {
  string tmp;
  string l = "";
  // use -> so multiple inheritance works correctly
  //l += this_object()->query_long()+"\n";
  if (sizeof(tmp=query_long_closed())) l += tmp + "\n";
  if (!query_closed() || this_object()->clear()) {
    if (sizeof(tmp=query_long_contents()))
      l += tmp + "\n";
    if (sizeof(tmp=query_long_full()))
      l += tmp + "\n";
  }
  return l;
}
// -----

// move() does encumbrance checks, so don't worry about them here
varargs int receive_objects(object ob) {
  if (query_closed()) return 0;
  if (ob && ob->is_bag()) return 0;
  return ::receive_objects(ob);
}

int remove() {
  object *ai = all_inventory(this_object());

  ai->remove();

  if (sizeof(ai=all_inventory(this_object())))
    foreach (object ob in ai)
      destruct(ob);

  return ::remove();
}

int is_bag() { return 1; }

