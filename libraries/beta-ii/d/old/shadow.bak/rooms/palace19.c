inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set("short","Palace");
  set("long","This is the south tower of the palace.  An excited buzz"
    "fills the air.  Someone involved with the wedding must be preparing "
    "near here.  The decorations here are quite well done, and have definately "
    "had a woman's touch.  The rest of the palace is to the west.");
  set_smell("default","The smell of a great feast wafts towards you.");
  set_listen("default","The giggling of women and gossiping can be heard upstairs.");
  set_items(([({"streamer","streamers"}):"The streamers hang from the walls in beautiful %^BOLD%^%^RED%^sw%^BLUE%^ir%^GREEN%^ls%^RESET%^.",
    ({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls and steps."]));
  set_exits((["west":ROOMS "palace16.c","up":ROOMS "palace21.c"]));
}

void reset() {
  ::reset();
  if(!present("knight")) {
    new(MOB "pknight")->move(this_object());
  }
  if(!present("bridesmaid")) {
    new(MOB "bridesmaid")->move(this_object());
  }
}
