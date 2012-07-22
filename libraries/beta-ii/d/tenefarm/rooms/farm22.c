#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "water" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("%^BOLD%^%^BLUE%^This stream has obviously been here for a long time, because the ground suddenly dissapears for some distance underneath you. To the west and the east a small path suddenly falls into the river, but it continues more in that direction. Along the river to the north is a mill, and farther north is the farmers wide house. The water is deep enough to dive down here.");
  set_night_long("%^BLUE%^The eerie, still waters are very scary at night. It is so black that it is impossible to see more than a couple feet under the spot that you are swimming. Along to river to the north to black structures loom up in the dark, but it isn't bright enough to be able to figure out what they are. The river has obviously been here a long time, because the path to the west and east suddenly drops off, and the river is very deep.");
  set_smell("default", "It smells like cow manure.");
  set_listen("default", "The calming sounds of slow moving water are all around.");
  set_items(([
    "river" : "You are treading water in it. You would have to dive down into the river to check its depth, as you can't see the bottom from here.",
    "ground" : "You would have to dive down into the river to see that.",
    "barn" : "That is not here.",
    "stream" : "You are in it.",
   ]));
  set_exits(([
    "west" : ROOMS"farm17",
    "east" : ROOMS"farm23",
    "dive" : ROOMS"uwtr"
   ]));
  add_invis_exit("dive");
  add_pre_exit_function("dive", "go_dive");
}
int go_dive() {
  if(this_player()->query_subclass() == "blue") {
    write("You handle the waters with ease as you glide into the river.");
    tell_room(environment(this_player()), this_player()->query_cap_name()
     +" dives into the water and handles "
     +"the waters with ease.", ({ this_player() }));
  }
  else {
    write("You suck in air and prepare to dive under water.");
  }
  new(OBJ"uwtrb")->move(this_player());
  return 1;
}
void reset() {
  ::reset();
  if (!present("trout"))
    new(MOB "trout.c")->move(this_object());
  if (!present("bass"))
    new(MOB "bass.c")->move(this_object());
  if (!present("catfish"))
    new(MOB "catfish.c")->move(this_object());
}
