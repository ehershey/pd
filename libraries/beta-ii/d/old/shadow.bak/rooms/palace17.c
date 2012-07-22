inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set("short","Palace");
  set("long","This is the north tower of the palace.  There is a hushed "
    "tenseness in the air.  Someone involved with the wedding must be preparing "
    "near here.  The decorations here are a bit more simple, but the room is still "
    "well decorated.  The rest of the palace is to the west.");
  set_smell("default","The smell of a great feast wafts towards you.");
  set_listen("default","The sound of men joking and preparing can be heard upstairs.");
  set_items(([({"streamer","streamers"}):"The streamers hang from the walls in beautiful %^BOLD%^%^RED%^sw%^BLUE%^ir%^GREEN%^ls%^RESET%^.",
    ({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls and steps."]));
  set_exits((["west":ROOMS "palace12.c","up":ROOMS "palace20.c"]));
}

void reset() {
  ::reset();
  if(!present("knight")) {
    new(MOB "pknight")->move(this_object());
  }
  if(!present("servant")) {
    new(MOB "mservant")->move(this_object());
  }
}
