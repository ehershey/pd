inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set("short","Palace");
  set("long","Not until you enter this room does the immense "
    "size of the palace sink in.  There are two hallways that part "
    "north and south, while the main chamber continues to the east.  "
    "A large chandeleir is here with many streamers hanging from it.  "
    "The walls are adorned with many intricately carved figures around"
    " the edges.");
  set_smell("default","The smell of a great feast wafts towards you.");
  set_listen("default","The sound of people talking and making merry can be heard.");
  set_items(([({"streamer","streamers"}):"The streamers hang from the chandeleir in beautiful %^BOLD%^%^RED%^sw%^BLUE%^ir%^GREEN%^ls%^RESET%^.",
    ({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls and steps.",
    "chadeleir":"The crystal chadeleir glistens and helps to light up the whole room."]));
  set_exits((["east":ROOMS "palace08.c","west":ROOMS "palace01.c","north":ROOMS "palace02.c","south":ROOMS "palace04.c"]));
}

void reset() {
  ::reset();
  if(!present("knight")) {
    new(MOB "pknight")->move(this_object());}
  if(!present("guard")) {
    new(MOB "pguard")->move(this_object());
  }
}
