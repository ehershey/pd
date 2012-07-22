#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "cavern" : 1, "night light" : 2]) );
  set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
  set_listen("default", "The sounds of prayer, battle, and magical incantations echo throughout the academy.");
  set_short("The Acadmey of Zolenia");
  set_long("%^BOLD%^%^BLACK%^This corridor leads to the school of %^BLUE%^Sorcere%^BLACK%^.  The school appears to take up most of the academy, as the drow mind has inclined them to study the art of Sorcere.  Students from the school seem to overflow out of their area into the corridor.");
  set_items(([
    ({"pathways", "paths"}) : "The pathway leads back to the main area of the Academy.",
    ({"air", "dust"}) : "The air is getting thinner and full of dust.",
    ({"academy", "the academy"}) : "The academy is all around you.",
   ]));
  set_exits(([ "south" : ROOMS "57.c",
    "north" : ROOMS "sorcereclone.c"]));
  set_pre_exit_functions(({"south"}), ({"check_oo"}));
}
void reset() {
  ::reset();
  if(!present("drowstudent")){
    new(MOB"drowstudent")->move(this_object());
    new(MOB"drowstudent")->move(this_object());
    new(MOB"drowstudent")->move(this_object());
    new(MOB"drowstudent")->move(this_object());
    new(MOB"drowstudent")->move(this_object());
  }
}
int check_oo() {
  if(this_player()->query_race() != "borg") {
    write("You cannot pass on the large dragon.");
    return 0;
  }
  write("You pass through with ease.");
  return 1;
}
