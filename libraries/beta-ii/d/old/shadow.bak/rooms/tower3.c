inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("outdoors",0);
  set_property("light",0);
  set("short","Palace Wall");
  set("long","This is one of the turrets along the outer wall of the palace. "
    " The land surrounding the city can be seen from this height.  The wind"
    " whirls about up here.  The turret has exits to the east and south.  There"
    " is a large hole in one corner of the room.  It seems to lead to another room.");
  set_smell("default","The air here is clear and refreshing.");
  set_listen("default","The soft sound of people talking can be heard below.");
  set_items((["sky":"The sky is dark as ever.",
    "turret":"The turret is where the archers hang out and protect the citizens of Tenebrae.",
    "hole":"The hole seems to lead to the floor below"]));
  set_exits((["south":ROOMS "tower2.c","east":ROOMS "tower4.c"]));
}

void reset() {
  ::reset();
  if(!present("archer")) {
    new(MOB "archer")->move(this_object());
  }
}

void init() {
  ::init();
  add_action("enter_hole","enter");
}

int enter_hole(string str) {
  if(!str) {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(str != "hole") {
    notify_fail("You can't enter that!\n");
    return 0;
  }
  else {
    this_player()->move_player(ROOMS "palace30.c", "into the hole");
    return 1;
  }
}
