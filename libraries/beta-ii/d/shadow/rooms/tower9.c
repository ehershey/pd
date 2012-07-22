inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",1);
  set("short","Wall Shelter");
  set("long","This cozy shelter is nice and warm.  It is protecting from the "
    "large gusts of wind outside.  The room is scantily furnished, with only "
    "a few benches for archers to sit on, and a desk where the head archer does"
    " paperwork.  The room seems nice and quiet right now.");
  set_smell("default","The smell of old gruel emanates from some old bowls.");
  set_listen("default","The wind is whistling around the shelter.");
  set_items((["desk":"The desk only has a few papers on it.",
    "benches":"The benches are solid oak, but still look comfy.",
    "shelter":"This shelter is quite small to be housing so many archers."]));
  set_exits((["out":ROOMS "tower6.c"]));
}

void reset() {
  ::reset();
  if(!present("archer")) {
    new(MOB "bigarcher")->move(this_object());
  }
}
