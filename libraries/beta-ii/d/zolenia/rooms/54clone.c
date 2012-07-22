#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "cavern" : 1, "night light" : 2, "no teleport" : 1]) );
  set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
  set_listen("default", "The clamor of a busy city fills your ears.");
  set_short("Zolenia city path");
  set_long("%^BOLD%^%^BLACK%^The academy can be seen here, full of students of all sorts of arts.  The academy of Zolenia seems to be mainly concerned with the school of %^BLUE%^Sorcere%^BLACK%^, as it is a smaller drow city.  There is also a smaller school of war visible, with an attached barrack.");
  set_items(([
    ({"dirt", "path"}) : "You are walking on a dirt path going into the residential area of the city of Zolenia..  It leads either back toward the square, or to the city's academy.",
    ({"air", "dust"}) : "The air is getting thinner and full of dust.",
    ({"academy", "the academy"}) : "The academy is straight to the northwest.",
   ]));
  set_exits(([ "southeast" : ROOMS "44.c",
    "enter academy" : ROOMS "57clone.c"]));
  set_pre_exit_functions(({"southeast"}), ({"check_se"}));
  add_exit_alias("enter academy", "enter");
  add_exit_alias("enter academy", "academy");
}
void reset() {
  ::reset();
  if(!present("cityguard")){
    new(MOB"cityguard")->move(this_object());
    new(MOB"cityguard")->move(this_object());
  }
  if(!present("drowstudent")){
    new(MOB"drowstudent")->move(this_object());
    new(MOB"drowstudent")->move(this_object());
    new(MOB"drowstudent")->move(this_object());
  }
}
int check_se() {
  if(this_player()->query_race() != "borg") {
    write("You cannot pass on the large dragon.");
    return 0;
  }
  write("You pass through with ease.");
  return 1;
}
