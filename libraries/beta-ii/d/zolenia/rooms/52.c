#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "cavern" : 1, "night light" : 2]) );
  set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
  set_listen("default", "The clamor of a busy city fills your ears.");
  set_short("Zolenia city path");
  set_long("%^BOLD%^%^BLACK%^The palace sits straight ahead, frivolously colorful and gaudy.  Although the palace is not the largest building in the Drow city, it is obviously the most expensive, with precious gemstones encrusted into the outer walls.  There seems to be quite a bit of security in the palace, as small as it is.");
  set_items(([
    ({"dirt", "path"}) : "You are walking on a dirt path going into the residential area of the city of Zolenia..  It leads either back toward the square, or to the city's palace.",
    ({"air", "dust"}) : "The air is getting thinner and full of dust.",
    ({"palace", "building", "castle"}) : "The palace is straight to the north.",
    ({"gems", "walls", "gemstones"}) : "Precious gemstones such as rubies, diamonds, and sapphires have been encrusted into the outer walls of the palace.",
   ]));
  set_exits(([ "south" : ROOMS "44.c",
    "enter palace" : ROOMS "55.c"]));
  add_exit_alias("enter palace", "palace");
  add_exit_alias("enter palace", "enter");
  add_exit_alias("enter palace", "castle");
}
void reset() {
  ::reset();
  if(!present("palaceguard")){
    new(MOB"palaceguard")->move(this_object());
    new(MOB"palaceguard")->move(this_object());
    new(MOB"palaceguard")->move(this_object());
  }
  if(!present("drowwoman")){
    new(MOB"drowwoman")->move(this_object());
  }
  if(!present("drowchild")){
    new(MOB"drowchild")->move(this_object());
  }
}
