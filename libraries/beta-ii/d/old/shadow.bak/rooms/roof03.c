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
    " and the countryside can be seen everywhere else.");
  set_smell("default","The air here is clear and refreshing.");
  set_listen("default","The soft sound of people talking can be heard below.");
  set_items((["sky":"The sky is dark as ever.",
    "house":"You're standing on it.  Hope the roof doesn't give in.",
    "rooftop":"The rooftop is made of %^BLACK%^dark shingles%^RESET%^, which blend in with the ground."]));
  set_exits((["northwest":ROOMS "roof05.c","northeast":ROOMS "roof07.c","southwest":ROOMS     "roof02.c","southeast":ROOMS "roof04.c"]));
}

void reset() {
  ::reset();
  if(!present("sweeper")) {
    new(MOB "sweeper")->move(this_object());
  }
}
