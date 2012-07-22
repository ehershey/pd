inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set("short","North Tower");
  set("long","This is the groom's dressing room.  Prince Nichusar is preparing "
    "for the wedding while chatting with his servants and close friends.  The room "
    "is simply adorned with a mirror and some sofas and a table where some of the "
    "guests are seated.  Everyone seems to be having a good time.");
  set_smell("default","The smell of men's cologne is prevelant here.");
  set_listen("default","The men joke and enjoy the occasion.");
  set_items(([({"streamer","streamers"}):"The streamers hang from the walls in beautiful %^BOLD%^%^RED%^sw%^BLUE%^ir%^GREEN%^ls%^RESET%^.",
    ({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls and steps."]));
  set_exits((["down":ROOMS "palace17.c"]));
}

void reset() {
  ::reset();
  if(!present("prince")) {
    new(MOB "prince")->move(this_object());
  }
  if(!present("servant")) {
    new(MOB "mservant")->move(this_object());
    new(MOB "mservant")->move(this_object());
  }
  if(!present("guest")) {
    new(MOB "guest")->move(this_object());
    present("guest")->force_me("sit");
    new(MOB "guest")->move(this_object());
    present("guest 2")->force_me("sit");
  }
}
