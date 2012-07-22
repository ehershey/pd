#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("plain",1);
    set_short("outside a tower");
    set_long(
      "Trees block the path from going west. A marvelous fountain rises "
      "up from the ground. There is grass here, which is very short and "
      "looks as though it has been trampled by the woodland creatures. The "
      "tower stands to the east, blocking traffic from going that way. "
    );
    set_items(([
	"tower" : "It stretches above the trees. ",
	"trees" : "They make up Fenton Woods.",
	"grass" : "There isn't much grass and it is almost dead.",
	"garden" : "Dead flowers lie in the garden.",
	"plaque" : "Angeline the Defender",
    ]));
   set_listen("default", "Birds chirping from the forest.");
   set_exits( ([ 
        "north" : ROOMS"room21.c",
        "south" : ROOMS"room23.c",
    ]) );
}
void init() {
::reset();
  ::init();
  add_action("enter_it","enter");
}

int enter_it(string str) {
  if(!str) {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(str != "fountain") {
    notify_fail("You can't do that!\n");
    return 0;
  }
  else {
    this_player()->move_player(ROOMS "fountain", "leaps into the fountain.");
    return 1;
  }
}
void reset() {
     if(!present("fountain.c"))
new(OBJ"fountain")->move(this_object());
}
