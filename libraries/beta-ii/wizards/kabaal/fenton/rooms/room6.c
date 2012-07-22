#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 1, "indoors" : 0]) );
set_property("plain",1);
    set_short("an old busted up road");
    set_long(
      "A mist is now starting to settle over the land.  To the south, you see "
      "the tree that has looked over you this entire time.  Onward to the north is "
      "the city's square.  On the road, you notice pot holes, some very large, others small. "
    );
    set_items(([
        "pot holes" : "Some are big enough to fall in.",
	"holes" : "Some are big enough to fall in.",
        "tree" : "Through the mist, the tree has a very unsettling appearance.",
        "road" : "Full of pot holes.",
        "mist" : "It has cloaked the land, making it difficult to see.",
	"hole 1" : "It's probably big enough to lose a horse and buggy in!",
	"hole 2" : "Perhaps you could climb down....",  
	"hole 3" : "You'd probably break both of your legs if you fell.",     
    ]));
   set_listen("default", "Silence is broken by a woman's scream.");
   set_exits( ([ 
        "north" : ROOMS"square.c",
        "southeast" : ROOMS"room8.c",
        "southwest" : ROOMS"room5.c",
    ]) );
}
void init() {
  ::init();
  add_action("enter_it","enter");
}

int enter_it(string str) {
  if(!str) {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(str != "hole 2") {
    notify_fail("You can't enter that!\n");
    return 0;
  }
  else {
    this_player()->move_player(ROOMS "hole", "descends into the darkness.");
    return 1;
  }
}
