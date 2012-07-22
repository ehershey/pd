inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",1);
  set("short","South Tower");
  set("long","This is the bride's dressing room, where the princess "
    "Cassiopia is getting ready.  This room is well furnished as the "
    "bridesmaids gather around the princess, chatting amongst themselves "
    "giddily.  Everyone seems quite happy.");
  set_smell("default","The smell of sweet perfume fills the air.");
  set_listen("default","The giggling of women and gossiping fill the room.");
  set_items(([({"streamer","streamers"}):"The streamers hang from the walls in beautiful %^BOLD%^%^RED%^sw%^BLUE%^ir%^GREEN%^ls%^RESET%^.",
    ({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls and steps.",
      "furniture":"The funiture here is plush and comfy."]));
  set_exits((["down":ROOMS "palace19.c"]));
}

void reset() {
  ::reset();
  if(!present("princess")) {
    new(MOB "princess")->move(this_object());
  }
  if(!present("bridesmaid")) {
    new(MOB "bridesmaid")->move(this_object());
    new(MOB "bridesmaid")->move(this_object());
    new(MOB "bridesmaid")->move(this_object());
  }
}
