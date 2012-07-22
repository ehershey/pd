inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("outdoors",0);
  set_property("light",0);
  set("short","Rooftop");
  set("long","Welcome to the rooftops of Tenebrae.  The whole "
    "city can be seen from this height.  To the east is the palace,"
    " and the countryside can be seen everywhere else.  The roof"
    " here is low to the ground, and could allow you to jump to the ground.");
  set_smell("default","The air here is clear and refreshing.");
  set_listen("default","The soft sound of people talking can be heard below.");
  set_items((["sky":"The sky is dark as ever.",
    "house":"You're standing on it.  Hope the roof doesn't give in.",
    "rooftop":"The rooftop is made of %^BLACK%^dark shingles%^RESET%^, which blend in with the ground."]));
  set_exits((["northwest":ROOMS "roof10.c"]));
}

void reset() {
  ::reset();
  if(!present("crow")) {
    new(MOB "crow")->move(this_object());
  }
}

void init() {
  ::init();
  add_action("jump_it","jump");
}

int jump_it(string str) {
  if(!str) {
    notify_fail("You jump around.\n");
    return 0;
  }
  if(str != "down") {
    notify_fail("You can't jump that way!\n");
    return 0;
  }
  else {
    this_player()->move_player(ROOMS "tene15.c", "jumps down.");
    return 1;
  }

}
