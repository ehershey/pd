#include <std.h>
#include <saahr.h>

inherit VIRTUALSERVER;

string *riverfiles;

void make_river_list();
string check_river_dir(object);
int sort_exits(string, string);

void create() {
  ::create();
  set_properties( ([ "light" : 1, "night light" : 0, "forest" : 1 ]) );
  set_short("a dense forest");
  set_day_sentences( ({
    "Trees tower over you in all directions.",
    "A squirrel scurries up a tree trunk nearby.",
    "There are many short shrubs growing between the trees.",
    "A fallen tree is lying here rotting.",
    "Stray leaves rustle and then drift down from overhead.",
    "A single beam of sunlight manages to get through the foliage here.",
    "The ground is littered with leaves, mosses and an occaisonal stone.",
    "Many tiny insects flit through the air.",
    "The land all around is very flat.",
    "A large flat rock pokes out of the ground.",
    "A bird can be seen gliding in the sky directly above you."
  }) );
  set_night_sentences( ({
    "Trees tower over you in all directions.",
    "Something scurries up a tree trunk nearby.",
    "There are many short shrubs growing between the trees.",
    "A fallen tree is lying here rotting.",
    "Stray leaves rustle and then drift down from overhead.",
    "Moonlight barely manages to get through the foliage here.",
    "The ground is littered with leaves, mosses and an occaisonal stone.",
    "Many tiny insects flit through the air.",
    "The land all around is very flat.",
    "A large flat rock pokes out of the ground.",
    "An owl flies between the trees directly above you."
  }) );
  set_items( ([
    ({"tree","trees"}) : "Very tall and with thick leaves, more trees "
      "are visible as far as the eye can see.",
    ({"squirrel","something"}) : "It's already gone.",
    "trunk" : "The trunk extends about 50 feet upward from the ground "
      "with branches starting halfway up.",
    "shrubs" : "Small scrubby plants similar to the ones on the plains, "
      "but these are green and look healthier.",
    ({"leaves","foliage"}) : "Thick, green, and roughly diamond-shaped leaves.",
    ({"sunlight","moonlight","light"}) : "Not much light gets down here.",
    ({"land","ground"}) : "A lot of leaves and moss cover the rich black "
      "earth of the forest.",
    ({"mosses","moss"}) : "Green webs that grow across the ground and trees.",
    "stone" : "Mostly pebble-sized, a few stones are scattered here "
      "and there on the ground.",
    "insects" : "Mosquitos, gnats, and other bothersome things buzz quietly "
      "around the air.",
    "rock" : "Long, flat, and low to the ground. A good resting place.",
    "bird" : "It's way up there and very hard to see clearly.",
    "owl" : "The owl is gone before you can get a clear look."
  ]) );
  set_listen("Only an occaisonal rustling of leaves breaks the silence.");
  set_smell("The scent of rich soil and many trees is everywhere.");
  set_living_inventory( ([
    MOBS "hog" : 1,
    MOBS "fhare" : 1,
    MOBS "fox" : 1,
    MOBS "fweimic" : 1,
    MOBS "goblin" : 1,
    MOBS "nymph" : 2,
    MOBS "satyr" : 2,
  ]) );
  set_max_sentences(5);
  set_min_sentences(4);
  set_max_inventory(3);

  make_river_list();
}

void make_river_list() {
  riverfiles = get_dir(VPROOMS+"river*_*.c");
  riverfiles -= ({ RIVER_ROOM, RIVER_DAEMON });
  riverfiles = map(riverfiles, (:
    replace_string(
      replace_string(
	$1,
	".c", ""
      ),
      "river", ""
    )
  :) );
}

string check_river_dir(object ob) {
  string file = base_name(ob);
  string *dirs = ({});
  string junk;
  int x, y;

  file = path_file(file)[1];

  if (sscanf(file, "%s%d_%d", junk, x, y) == 3 &&
      member_array(junk, ({ "p", "f", "town" }) ) != -1) {
        // look for river files
        string *riversearch = ({});
	mapping coordsearch = ([
	  x+"_"+(y+1) : "south",
	  x+"_"+y+"h" : "south",
	  x+"_"+(y-1) : "north",
	  x+"_"+(y-1)+"h" : "north",
	  (x+1)+"_"+y : "east",
	  x+"h"+"_"+y : "east",
	  (x-1)+"_"+y : "west",
	  (x-1)+"h"+"_"+y : "west",
	  (x+1)+"_"+(y+1) : "southeast",
	  x+"h"+"_"+y+"h" : "southeast",
	  (x-1)+"_"+(y+1) : "southwest",
	  (x-1)+"h"+"_"+y+"h" : "southwest",
	  (x+1)+"_"+(y-1) : "northeast",
	  x+"h"+"_"+(y-1)+"h" : "northeast",
	  (x-1)+"_"+(y-1) : "northwest",
	  (x-1)+"h"+"_"+(y-1)+"h" : "northwest",
	]);

	riversearch = keys(coordsearch) & riverfiles;

	foreach (string coord in riversearch)
	  dirs |= ({ coordsearch[coord] });

  }

  if (sizeof(dirs)) {
    dirs = sort_array(dirs, (: sort_exits :) );
    return list(dirs);
  }

  return 0;
}

varargs string query_random_long(int night, object room) {
  string ret = ::query_random_long(night, previous_object());
  string dir = check_river_dir(previous_object());
  if (dir) {
    ret += "\n%^RESET%^%^CYAN%^A river flows along to the "+dir+".%^RESET%^";
  }
  return ret;
}

mapping query_senses_map() {
  object ob = previous_object();
  mapping ret = ::query_senses_map();
  if (ob->query_property("saahr_riverside")) {
    ret = (ret || ([])) + ([
      "listen" : ([ "default" : "Water rushing by." ]),
      "item" : ([ "river" : "It rushes along quickly and looks very deep." ]),
    ]);
  }
  return ret;
}

int sort_exits(string e1, string e2) {
  string *exlist = ({
    "north", "northeast", "east", "southeast",
    "south", "southwest", "west", "northwest",
    "up", "down", "enter house"
  });

  int a1 = member_array(e1, exlist);
  int a2 = member_array(e2, exlist);

  if (a1 == -1 || a2 == -1 || a1 == a2) return 0;
  if (a1 < a2) return -1;
  if (a2 < a1) return 1;
  return 0;
}
