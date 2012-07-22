#include <std.h>
#include <saahr.h>

inherit VIRTUALSERVER;

string *riverfiles;

void make_river_list();
string check_river_dir(object);
int sort_exits(string, string);

void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1 ]) );
  set_short("a wide plain");
  set_day_sentences( ({
    "The plain stretches out in all directions.",
    "Small shrubs are growing here and there.",
    "The ground here is a little bit rocky.",
    "Thick, yellow grass grows nearly everywhere.",
    "A shallow depression has saved a little bit of water from the last rain.",
    "Some birds are flying in a formation far overhead.",
    "A patch of bare earth peeks out from the grass.",
    "A few tall trees can be seen off in the distance.",
    "The horizon is clearly visible just above the gently rolling plains.",
    "Many flowers are blooming all around.",
    "Some dry cattails stick up out of the grass.",
    "A tiny animal disturbs the grasses as it darts away."
  }) );
  set_items( ([
    ({"plain","plains"}) : "A wide plain with not much to see besides grass.",
    "shrubs" : "Short, scrubby plants that offer a little green to the landscape.",
    ({"ground","earth"}) : "Brown and hard, it seems to be enough for the grass.",
    ({"grass","grasses"}) : "Long ago it might once have been a vibrant green, now it looks dry and yellow.",
    "depression" : "Nothing more than a dent in the earth where a bit of water sits.",
    "water" : "Stagnant, but clear. Probably left over from the last rain.",
    ({"birds","formation"}) : "The birds make a giant V in the sky.",
    "trees" : "They're hard to see from here but it might be a forest.",
    "horizon" : "The seperation between earth and sky.",
    "flowers" : "Small white wildflowers.",
    "cattails" : "Dry and prickly plants that are eager to stick into fabric or fur.",
    "animal" : "It is already gone."
  ]) );
  set_listen("The grass blows gently in the wind.");
  set_living_inventory( ([
    MOBS "hare" : 2,
    MOBS "fox" : 2,
    MOBS "weimic-adult" : 2,
    MOBS "weimic-adolescent" : 2,
    MOBS "weimic-cub" : 2,
    MOBS "goblin" : 2,
    MOBS "nymph" : 1,
    MOBS "satyr" : 1,
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
    previous_object()->set_property("saahr_riverside", 1);
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

