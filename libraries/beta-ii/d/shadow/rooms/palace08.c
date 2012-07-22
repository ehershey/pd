
inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",1);
  set("short","Palace");
  set("long","The main hallway of the palace continues east "
    "and west.  Streamers line the walls, hung over large tapestries "
    "and pictures.  The ceiling is a majestic arch, beautifully painted "
    "with scenes of Tenebrae's history.");
  set_smell("default","The smell of a great feast wafts towards you.");
  set_listen("default","The sound of people talking and making merry can be heard to the east.");
   set_items(([({"streamer","streamers"}):"The streamers hang from the chandeleir in beautiful %^BOLD%^%^RED%^sw%^BLUE%^ir%^GREEN%^ls%^RESET%^.",
    ({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls and steps.",
    "chadeleir":"The crystal chadeleir glistens and helps to light up the whole room.",
    "tapestiries":"One large tapestry of finely woven silk depicts the royal family.",
    ({"ceiling","arch"}):"Scenes of wizards and warriors fighting viciously array the ceiling."]));
  set_exits((["east":ROOMS "palace14.c","west":ROOMS "palace03.c"]));
}

void reset() {
  ::reset();
  if(!present("guard")) {
    new(MOB "pguard")->move(this_object());
    new(MOB "pguard")->move(this_object());
  }
}
