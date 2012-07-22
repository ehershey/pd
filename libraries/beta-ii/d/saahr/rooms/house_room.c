
#include <std.h>

inherit VAULT;

static private string doorid;

void check_door();

void create() {
  ::create();
}

void reset() {
  ::reset();
  check_door();
}

string my_door_id() {
  string id;
  if (doorid) return doorid;
  id = file_name(this_object());
  id = path_file(id)[1];
  id = replace_string(id, "town", "saahr");
  doorid = id;
  return id;
}

void check_door() {
  string file;
  object inside;
  int opened, locked;

  inside = find_object(query_exit("enter house"));

  if (!inside) {
    inside = load_object(query_exit("enter house"));
  }

  if (my_door_id() != (query_door_id("door") || "")) {
    cover_exit_with_door("enter house", my_door_id());
    set_key(my_door_id(), my_door_id()+"key");
  }

  if (my_door_id() != (inside->query_door_id("door") || "")) {
    inside->cover_exit_with_door("out", my_door_id());
  }

  // be very careful not to lock people in... there are no keys!
  if (query_night()) {
    object *players = filter(all_inventory(inside), (: $1->is_player() :));

    if (!sizeof(players))
      locked = 1;
    else
      locked = 0;
    opened = 0;
  }
  else {
    locked = 0;
    if (random(100) < 25)
      opened = 0;
    else
      opened = 1;
  }

  set_open(my_door_id(), opened);
  set_locked(my_door_id(), locked);
}

