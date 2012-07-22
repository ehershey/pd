inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set("short","Palace");
  set("long","This is the south wing of the palace.  To the north is the "
    "main hall.  Servants bustle back and forth, fetching things for various "
    "nobility.  Streamers line the wall along with other wedding decorations.  "
    "There is a feeling of celebration in the air.");
  set_smell("default","The smell of a great feast wafts towards you.");
  set_listen("default","The sound of people talking and making merry can be heard to the north.");
  set_items(([({"streamer","streamers"}):"The streamers hang from the walls in beautiful %^BOLD%^%^RED%^sw%^BLUE%^ir%^GREEN%^ls%^RESET%^.",
    ({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls and steps."]));
  set_exits((["north":ROOMS "palace14.c","south":ROOMS "palace16.c"]));
}

void reset() {
  ::reset();
  if(!present("knight")) {
    new(MOB "pknight")->move(this_object());
  }
  if(!present("servant")) {
    new(MOB "fservant")->move(this_object());
  }
}
