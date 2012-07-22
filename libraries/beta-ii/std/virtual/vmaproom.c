#include <std.h>

inherit ROOM;

void setup();
void set_map(mixed);
object query_map();
string query_map_path();
void set_coords(int, int, int);
string query_coords();
int *query_coord_array();
void add_item(string id, string long);

object mapob;
string mappath;
string coord_str;
int coord_x, coord_y, coord_z;

varargs void create(mixed map, int x, int y, int z) {
  if (!nullp(map))
    set_map(map);
  if (!(nullp(x) || nullp(y) || nullp(z)))
    set_coords(x, y, z);
  ::create();
  setup();
}

void setup() {
  object map = query_map();
  if (map && coord_str) {
    // the virtual map figures out which virtual server to use for these
    set_short(map->query_server(coord_str, "short"));
    set_day_long( map->query_server(coord_str, "random_day_long", this_object()));
    set_night_long( map->query_server(coord_str, "random_night_long", this_object()));
    set_properties( map->query_server(coord_str, "properties") || ([]) );
    foreach (string k, mapping v in (map->query_server(coord_str, "senses_map") || ([]) ) )
      set_senses(k, v);
    // the virtual map itself takes care of the exits
    set_exits( map->query_exits(coord_x, coord_y, coord_z) || ([]) );
  }
}

void set_map(mixed map) {
  if (objectp(map)) {
    mapob = map;
    if (mapob) {
      mappath = file_name(map)+".c";
    }
  }
  if (stringp(map)) {
    if (map[<2..<1] != ".c") map += ".c";
    mappath = map;
    // this line below looks odd... I just want to load the map into memory,
    // and query_map() has all the code necessary to do that
    // just discarding the return value, it sets mapob anyway
    query_map();
  }
}
object query_map() {
  if (!mapob && mappath && file_size(mappath) > 0 && strsrch(mappath, "#") == -1)
    mapob = load_object(mappath);
  return mapob;
}
string query_map_path() { return mappath; }

void set_coords(int x, int y, int z) {
  coord_x = x;
  coord_y = y;
  coord_z = z;
  coord_str = x+","+y+","+z;
}
string query_coords() { return coord_str; }
int *query_coord_array() { return ({ coord_x, coord_y, coord_z }); }

// not sure why this is needed here
void add_item(string id, string long) {
  object map = query_map();
  if (map)
    map->set_server(coord_str, "item", ({ id, long }) );
}

void reset() {
  object map;
  object *newinv;

  ::reset();

  if (!this_object()) return;

  if ( !( map = query_map() ) ) return;

  newinv = map->query_server(coord_str, "random_inventory", ({ all_inventory() || ({}) }) );
  if (sizeof(newinv))
    newinv->move(this_object());
}

void init() {
  ::init();
}
