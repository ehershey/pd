/*
 * virtualmap.c
 * inheritable that uses an ASCII area map to dynamically generate rooms
 * Nulvect 2010-07-14
 *
 * supports reading map and descriptions from file or from function calls,
 * settable map legend, three different map styles, room-specific static exits,
 * static rooms, and use of subareas that each have different settings
 * this last is accomplished by cloning multiple VIRTUALSERVER objects and
 * associating each with a subarea (in a mapping)
 *
 * bugfixes Nulvect 2010-12-03
 */

#include <std.h>

inherit DAEMON;

void debugprint(mixed z);
object query_room(int x, int y, int z);
varargs mixed query_server(string coords, string func, mixed args);
varargs void set_server(string coords, string func, mixed args);
void set_map(mixed *m);
mixed *query_map();
void set_legend(mapping m);
void set_compact(int x);
int query_compact();
void set_instance_group_id(string s);
string query_instance_group_id();
void set_virtual_room(string coords, string room);
string query_virtual_room(string coord);
void set_mapfile(string s);
string query_mapfile();
void set_descfile(string s);
string query_descfile();
int load_map(string f);
void set_descriptions(string coords, mixed data);
void load_descriptions(string f);
void parse_descriptions(string *data);
mapping string_to_map(string str);
varargs int format_coords(string ref coord_str, int ref *coord_arr);
object find_server(string coords);
mixed find_data(string coords, mapping search);
void set_special_exits(string coord, mapping exits);
mapping query_special_exits(string coord);
mapping query_exits(int x, int y, int z);

string mapfile;
string descfile;
string virtpath;
mixed *Map = ({});
mapping SpecialExits = ([]);
mapping VirtualRooms = ([]);
// Servers is the mapping of coordinate ranges to virtualservers
mapping Servers = ([]);
// legend can be set with set_legend()
mapping Legend = ([
  "room" : "#",
  "empty" : ".",
  "comment" : "!",
  "level separator" : ",",
  "n s" : "|",
  "e w" : "-",
  "nw se" : "\\",
  "ne sw" : "/",
  "nw se ne sw" : "X",
  "u d" : "+",
]);
int compact;
// instances not implemented yet
string instance_group_id;

void create() {
  string *tmp = path_file(file_name(this_object()));
  string virt_room;

  virtpath = tmp[0];

  // set the default room to clone
  virt_room = virtpath + "/room";
  if (file_size(virt_room) < 1)
    virt_room = VMAPROOM;

  VirtualRooms["*"] = ([
    "room" : virt_room,
  ]);
  //

  SpecialExits = ([]);

  if (mapfile && !sizeof(Map))
    load_map(mapfile);

  if (descfile && !sizeof(Servers))
    load_descriptions(descfile);
}

void clean_up() {
  object *srvs = filter(values(Servers), (: objectp($1) :) );
  if (!query_no_clean() && sizeof(srvs)) {
    srvs->set_no_clean(0);
    srvs->clean_up();
  }
  daemon::clean_up();
}

// this is our entry point - it will be called by VIRTUAL_D's compile_object,
// which is itself being called by MASTER's compile_object function,
// which is called every time the driver can't find a file it wants to load
object compile_object(string file) {
  int x, y, z;
  int *coord_arr = ({});
  string *tmp;

  if (!file) return 0;
  sscanf(file, "%s.c", file);

  tmp = path_file(file);
  file = tmp[1];

  if (format_coords(ref file, ref coord_arr) != 1)
    return 0;

  x = coord_arr[0];
  y = coord_arr[1];
  z = coord_arr[2];

  return query_room(x, y, z);
}

// find or create a room
object query_room(int x, int y, int z) {
  object room;
  string file;
  string coord = x+","+y+","+z;

  file = virtpath+"/"+coord+".c";
  if (file_size(file) > 0)
    room = load_object(file);

  // extra arguments are passed to the create() function,
  // which will query this daemon for exits, descs, etc
  if (!room) {
    room = new(query_virtual_room(coord), this_object(), x, y, z);
  }

  return room;
}

// query information from the correct virtualserver object for this coordinate
varargs mixed query_server(string coords, string func, mixed args) {
  object srv = find_server(coords);
  if (nullp(args))
    args = ({ });
  else if (!arrayp(args))
    args = ({ args });
  args = ({ "query_"+func }) + args;
  if (srv)
    return call_other(srv, args);
  return 0;
}

// set information in the correct virtualserver object
// can set up all area info using this function in your create():
// set_server("1,2,3-7,8,9", "day_sentences", ({ ({
//   "sentence 1",
//   "sentence 2",
// }) }) );
// set_server("1,2,3-7,8,9", "listens", ({ ([
//   "default" : "It's loud.",
//   "socks" : "They smell like feet.",
// ]) }) );
varargs void set_server(string coords, string func, mixed args) {
  object srv = find_server(coords);
  if (nullp(args))
    args = ({ });
  else if (!arrayp(args))
    args = ({ args });
  args = ({ "set_"+func }) + args;
  if (srv)
    call_other(srv, args);
}

// can send 1 or multi-level maps
// set_map( ({
//   "#-#-#",
//   "|/| |",
//   "# #-#"
// }) ); // 1 level (2d)
//
// set_map( ({
//   ({ "#-#-#",
//      "|/| |",
//      "# #-#" }),
//   ({ "  +  ",
//      "     ",
//      "+ +  " }),
//   ({ "  # #",
//      "   X|",
//      "#-#-#" }),
// }) ); // 2 level (3d)
void set_map(mixed *m) {
  if (m && arrayp(m) && sizeof(m)) {
    // m[0] is an array if they specified multiple levels (up/down):
    if (m[0] && arrayp(m[0]) && sizeof(m[0]))
      Map = copy(m);
    // otherwise it's a (2d) string array, make it 3d
    else if (stringp(m[0]))
      Map = ({ m });
  }
}
mixed *query_map() { return copy(Map); }

void set_legend(mapping m) {
  if (m && sizeof(m))
    foreach (string sym in (keys(Legend) & keys(m)))
      Legend[sym] = m[sym];
}

// just for fun/bragging, count up how many rooms this daemon serves
int query_room_count() {
  int count;
  foreach (string *level in Map) {
    foreach (string row in level) {
      for (int i = 0; i < strlen(row); i++) {
        if (row[i..i] == Legend["room"]) {
          count++;
        }
      }
    }
  }
  return count;
}

// for compact-style maps
// ###.
// .#.#
// .###
// ,
// #...
// ##..
// ....
// set_compact(2) means don't use ne/se/nw/sw exits
void set_compact(int x) {
  switch (x) {
    case 0: case 1: case 2:
      compact = x;
    break;
    default:
      compact = 1;
  }
}
int query_compact() { return compact; }

// not yet implemented
void set_instance_group_id(string s) { instance_group_id = s; }
string query_instance_group_id() { return instance_group_id; }

// clone up specific rooms for each subarea
void set_virtual_room(string coords, string room) {
  if (!VirtualRooms) VirtualRooms = ([]);
  if (!VirtualRooms[coords]) VirtualRooms[coords] = ([]);
  VirtualRooms[coords]["room"] = room;
}
string query_virtual_room(string coord) {
  mapping data = find_data(coord, VirtualRooms);
  if (data["room"])
    return data["room"];
  return VMAPROOM;
}

void set_mapfile(string s) { mapfile = s; }
string query_mapfile() { return mapfile; }
void set_descfile(string s) { descfile = s; }
string query_descfile() { return descfile; }

// load a map from a file
int load_map(string f) {
  string *entire_file;
  int curlevel;

  if (!f || !strlen(f) || file_size(f) < 1) return 0;

  entire_file = explode(read_file(f), "\n");

  Map = ({ });
  curlevel = 0;

  // parse each line
  foreach (string read in entire_file) {
    // ignore comment lines
    if (read[0..0] == Legend["comment"])
      continue;
    // remove the carriage return character \r if present
    if (read[<1..<1] == "\r")
      read = read[0..<2];
    if (!strlen(read))
      continue;
    // level separator goes on a line by itself
    if (read == Legend["level separator"]) {
      curlevel++;
      continue;
    }
    if (sizeof(Map) < curlevel+1)
      Map += ({ ({ read }) });
    else
      Map[curlevel] += ({ read });
  }

  return 1;

}

void set_descriptions(string coords, mixed data) {
  if (mapp(data)) {
    foreach (string key, mixed value in data)
      set_server(coords, key, ({ value }));
  }
  else if (arrayp(data)) {
    parse_descriptions(data);
  }
}

// load area information from a file
void load_descriptions(string f) {
  string *entire_file;

  if (!f || !strlen(f) || file_size(f) < 1) return;

  entire_file = explode(read_file(f), "\n");

  parse_descriptions(entire_file);
}


void parse_descriptions(string *data) {
  string coords = "*";

  foreach (string read in data) {
    string firstword = 0, rest = 0;
    string func = 0;
    int space;
    mixed tmp = 0;

    if (read[0..0] == Legend["comment"])
      continue;
    if (read[<1..<1] == "\r")
      read = read[0..<2];
    if (!strlen(read))
      continue;

    space = strsrch(read, " ");
    firstword = read[0 .. space-1];
    rest = read[space+1 .. <1];

    switch (firstword) {
      // coords X,Y,Z-X,Y,Z
      // the magic word that begins each section
      // stored as a string
      case "coordinates":
      case "coords":
        coords = rest;
      break;
      // argument: a single int
      case "mobcap":
      case "mob_cap":
      case "maxinventory":
      case "max_inventory":
        func = "max_inventory";
        tmp = to_int(rest);
      break;
      case "maxsentences":
      case "max_sentences":
        func = "max_sentences";
        tmp = to_int(rest);
      break;
      case "minsentences":
      case "min_sentences":
        func = "min_sentences";
        tmp = to_int(rest);
      break;
      // argument: a string
      case "short":
        func = "short";
        tmp = "" + rest;
      break;
      case "firstsentence":
      case "first_sentence":
        func = "first_sentence";
        tmp = "" + rest;
      break;
      case "lastsentence":
      case "last_sentence":
        func = "last_sentence";
        tmp = "" + rest;
      break;
      // argument: an array of strings
      case "long":
      case "daylong":
      case "day_long":
      case "daysentences":
      case "day_sentences":
      case "day_sentence":
        func = "day_sentences";
        tmp = query_server(coords, func) || ({});
        tmp += ({ rest });
      break;
      case "nightlong":
      case "night_long":
      case "nightsentences":
      case "night_sentences":
      case "night_sentence":
        func = "night_sentences";
        tmp = query_server(coords, func) || ({});
        tmp += ({ rest });
      break;
      // argument: a mapping
      case "reset":
      case "resetlist":
      case "livinginventory":
      case "living_inventory":
        func = "living_inventory";
        tmp = map(string_to_map(rest), (: to_int($2) :) );
        tmp = query_server(coords, func) + tmp;
      break;
      case "inventory":
      case "object":
      case "objectinventory":
      case "object_inventory":
        func = "inventory";
        tmp = map(string_to_map(rest), (: to_int($2) :) );
        tmp = query_server(coords, func) + tmp;
      break;
      case "property":
        func = "properties";
        tmp = map(string_to_map(rest), (: to_int($2) :) );
        tmp = query_server(coords, func) + tmp;
      break;
      case "item":
        func = "items";
        tmp = string_to_map(rest);
        tmp = query_server(coords, func) + tmp;
      break;
      case "listen":
        func = "listens";
        tmp = string_to_map(rest);
        tmp = query_server(coords, func) + tmp;
      break;
      case "smell":
        func = "smells";
        tmp = string_to_map(rest);
        tmp = query_server(coords, func) + tmp;
      break;
      case "search":
        func = "searches";
        tmp = string_to_map(rest);
        tmp = query_server(coords, func) + tmp;
      break;
      case "touch":
        func = "touches";
        tmp = string_to_map(rest);
        tmp = query_server(coords, func) + tmp;
      break;
      case "read":
        func = "reads";
        tmp = string_to_map(rest);
        tmp = query_server(coords, func) + tmp;
      break;
      case "taste":
        func = "tastes";
        tmp = string_to_map(rest);
        tmp = query_server(coords, func) + tmp;
      break;
    } // end switch

    if (func)
      set_server(coords, func, ({ tmp }) );

  } // end foreach
}

// utility func, turns "blah:1" or "blah 1" into ([ "blah" : 1 ])
mapping string_to_map(string str) {
  int pos;
  string name, val;
  mapping ret = ([]);

  pos = strsrch(str, ":");
  if (pos == -1)
    pos = strsrch(str, " ");

  if (pos != -1) {
    name = str[0 .. pos-1];
    val = str[pos+1 .. <1];
    ret[name] = val;
  }

  return ret;
}

// takes a string representing a coordinate set such as "5, 7" or "4, 3, 9",
// OR a coordinate range such as "15, 3, 1 - 17, 8, 4"
// makes it conform to a standard like "5,7,0" or "15,3,1-17,8,4"
// special case: does not change a coordinate of "*" (default server)
// returns the string by reference
//
// also will set the array, if passed, to the coordiniates
//
// NOTE: to return by reference, you must use "ref" in front of each variable
// IN THE FUNCTION CALL:
// format_coords(ref coords);
//
// return 0 for failure, 1 means input is a single coordinate, 2 if it's a range
varargs int format_coords(string ref coord_str, int ref *coord_arr) {
  string *range_arr;
  string *tmp_arr;
  string range1, range2;

  if (!coord_str)
    return 0;

  if (coord_str == "*")
    return 1;

  // strip spaces
  coord_str = replace_string(coord_str, " ", "");
  if (!strlen(coord_str))
    return 0;

  // check if it's a range
  // if not, range_arr will have one entry containing coord_str
  range_arr = explode(coord_str, "-") || ({});
  range1 = range_arr[0];
  if (sizeof(range_arr) > 1)
    range2 = range_arr[1];

  // break the coordinate string into an array and ensure it is 3d
  tmp_arr = explode(range1, ",") || ({});
  while (sizeof(tmp_arr) < 3)
    tmp_arr += ({ "0" });

  // set the array if passed
  if (!nullp(coord_arr))
    coord_arr = ({ to_int(tmp_arr[0]), to_int(tmp_arr[1]), to_int(tmp_arr[2]) });

  // only care about the first 3 entries, in case of shenanigans
  coord_str = implode(tmp_arr[0..2], ",");

  // now do the above all over again for the second coordinate in a range
  if (range2) {
    tmp_arr = explode(range2, ",") || ({});
    while (sizeof(tmp_arr) < 3)
      tmp_arr += ({ "0" });

    // add on
    if (!nullp(coord_arr))
      coord_arr += ({ to_int(tmp_arr[0]), to_int(tmp_arr[1]), to_int(tmp_arr[2]) });

    coord_str += "-" + implode(tmp_arr[0..2], ",");

    return 2;
  }

  return 1;
}

// find the virtual server that serves a specific coordinate or range
// if you look for a range that does not already have a server,
// then one will be created
// use of overlapping ranges is undefined - don't do it
object find_server(string coords) {
  object srv;
  int *dummy = ({});

  int howmany = format_coords(ref coords, ref dummy);

  srv = find_data(coords, Servers);

  if (!srv && (howmany == 2 || coords == "*")) {
    srv = new(VIRTUALSERVER);
    srv->set_no_clean(1);
    Servers[coords] = srv;
  }

  return srv;
}

// searches the specified mapping for the data associated with a coordinate
// or coordinate range
mixed find_data(string coords, mapping search) {
  int *coord_arr = ({});

  int howmany = format_coords(ref coords, ref coord_arr);

  // looking for a single coordinate - find the range it's in
  // skip this whole thing if looking for default range specifically
  if (coords != "*" && howmany == 1) {

    foreach (string key, mixed value in search) {
      int *key_coord_arr = ({});

      // skip default range until the end
      if (key == "*") continue;

      howmany = format_coords(ref key, ref key_coord_arr);
      if (howmany == 2) {
        if (coord_arr[0] >= key_coord_arr[0] &&
            coord_arr[0] <= key_coord_arr[3] &&
            coord_arr[1] >= key_coord_arr[1] &&
            coord_arr[1] <= key_coord_arr[4] &&
            coord_arr[2] >= key_coord_arr[2] &&
            coord_arr[2] <= key_coord_arr[5]) {
              return value;
        }
      }
      if (howmany == 1) {
        if (coord_arr[0] == key_coord_arr[0] &&
            coord_arr[1] == key_coord_arr[1] &&
            coord_arr[2] == key_coord_arr[2]) {
              return value;
        }
      }
    }
    // found nothing - look at default range
    coords = "*";
  }

  // either found nothing above, or looking for a range
  if (search[coords])
    return search[coords];

  return 0;
}

// add special exits that use names besides the cardinal directions
// also good for setting the exit points from your area since it
// overrides normal exits
// set_special_exits("6,19,0", ([
//   "east" : OTHERAREA+"entryroom",
//   "enter tree" : MYAREA+"tree",
// ]) );
void set_special_exits(string coord, mapping exits) {
  if (!SpecialExits) SpecialExits = ([]);
  if (!SpecialExits[coord]) SpecialExits[coord] = ([]);
  SpecialExits[coord]["exits"] = exits;
}
mapping query_special_exits(string coord) {
  mapping data = find_data(coord, SpecialExits);
  if (data && data["exits"])
    return data["exits"];
  return ([]);
}

mapping query_exits(int x, int y, int z) {
  mapping exits = ([]);
  mapping check = ([]);

  int orig_x = x;
  int orig_y = y;
  int orig_z = z;

  check = copy(Legend);

  if (compact) {
    foreach (string k in keys(check))
      check[k] = Legend["room"];
  }
  else {
    x *= 2;
    y *= 2;
    z *= 2;
  }

  if (x > 0 && Map[z][y][x-1..x-1] == check["e w"])
    exits["west"] = (orig_x-1) + "," + orig_y + "," + orig_z;
  if (x < sizeof(Map[z][y])-1 && Map[z][y][x+1..x+1] == check["e w"])
    exits["east"] = (orig_x+1) + "," + orig_y + "," + orig_z;

  if (y > 0) {
    if (Map[z][y-1][x..x] == check["n s"])
      exits["north"] = orig_x + "," + (orig_y-1) + "," + orig_z;
    if (Map[z][y-1][x-1..x-1] == check["nw se"] ||
        Map[z][y-1][x-1..x-1] == check["nw se ne sw"])
          if (compact != 2)
            exits["northwest"] = (orig_x-1) + "," + (orig_y-1) + "," + orig_z;
    if (Map[z][y-1][x+1..x+1] == check["ne sw"] ||
        Map[z][y-1][x+1..x+1] == check["nw se ne sw"])
          if (compact != 2)
            exits["northeast"] = (orig_x+1) + "," + (orig_y-1) + "," + orig_z;
  }

  if (y < sizeof(Map[z])-1) {
    if (Map[z][y+1][x..x] == check["n s"])
      exits["south"] = orig_x + "," + (orig_y+1) + "," + orig_z;
    if (Map[z][y+1][x-1..x-1] == check["ne sw"] ||
        Map[z][y+1][x-1..x-1] == check["nw se ne sw"])
          if (compact != 2)
            exits["southwest"] = (orig_x-1) + "," + (orig_y+1) + "," + orig_z;
    if (Map[z][y+1][x+1..x+1] == check["nw se"] ||
        Map[z][y+1][x+1..x+1] == check["nw se ne sw"])
          if (compact != 2)
            exits["southeast"] = (orig_x+1) + "," + (orig_y+1) + "," + orig_z;
  }

  if (z > 0 && Map[z-1][y][x..x] == check["u d"])
    exits["up"] = orig_x + "," + orig_y + "," + (orig_z-1);
  if (z < sizeof(Map)-1 && Map[z+1][y][x..x] == check["u d"])
    exits["down"] = orig_x + "," + orig_y + "," + (orig_z+1);

  // add pathname to the front of each exit
  exits = map(exits, (: $3 + "/" + $2 :), virtpath);

  // adding two mappings == duplicate keys will take on the values from
  //   the SECOND mapping added, so special exits will override normal ones
  exits = exits + query_special_exits(orig_x+","+orig_y+","+orig_z);

  return exits;
}

void debugprint(mixed z) {
  if (this_player() && this_player()->query_name() == "nulvect")
    printf("%O\n", z);
}

