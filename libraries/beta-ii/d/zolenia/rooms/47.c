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
  set_long("%^BOLD%^%^BLACK%^The residential pathway south of the city leads you to the Talabune Manor.  In ashes and flame on the building is written '%^RED%^Burning %^YELLOW%^Fate%^BLACK%^', the meaning of the family's name.  The pathway leads back toward the city in the northeast, but there are no doors in the city of Zolenia, and the Talabune Manor is open.");
  set_items(([
    ({"dirt", "path"}) : "You are walking on a dirt path going into the residential area of the city of Zolenia..  It leads either back toward the square, or to the Talabune Manor.",
    ({"air", "dust"}) : "The air is getting thinner and full of dust.",
    ({"house", "ashes", "flame", "building", "manor"}) : "The Talabune Manor, a very large house here, has '%^RED%^Burning %^YELLOW%^Fate%^RESET%^' scrawled upon the walls.",
   ]));
  set_exits(([ "northeast" : ROOMS "45.c",
    "enter talabune" : ROOMS "50.c"]));
  add_exit_alias("enter talabune", "talabune");
  add_exit_alias("enter talabune", "enter");
  add_exit_alias("enter talabune", "house");
}
void reset() {
  ::reset();
  if(!present("cityguard")){
    new(MOB"cityguard")->move(this_object());
  }
  if(!present("drowwoman")){
    new(MOB"drowwoman")->move(this_object());
  }
  if(!present("drowchild")){
    new(MOB"drowchild")->move(this_object());
  }
}
