#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "cavern" : 1, "night light" : 2]) );
  set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
  set_listen("default", "The clangs of swords clashing with each other can be heard.");
  set_short("The Acadmey of Zolenia");
  set_long("%^BOLD%^%^BLACK%^The school of %^RED%^war %^BLACK%^is a very loud and boisterous room.  There are racks of weapons and armour lining the walls.  Many books on the art of war can be seen scattered along the ground.  There is a podium in the back of the room.");
  set_items(([
    ({"pathways", "paths"}) : "There is a pathway back to the main area of the Academy.",
    ({"air", "dust"}) : "The air is getting thinner and full of dust.",
    ({"book", "books"}) : "The books are quite torn up from use.",
    ({"rack", "racks", "wall", "walls", "armour", "weapons", "armour racks", "armour rack", "weapon rack", "weapon racks"}) : "The racks of armour and weapons lining the walls are full of shiny new items.",
    ({"podium"}) : "The podium seems to be where the teacher would teach.",
   ]));
  set_exits(([ "east" : ROOMS "prebarrack.c",
    "barrack" : ROOMS "barracks2.c",
    "cell" : ROOMS "cell.c"]));
  set_pre_exit_functions(({"cell"}), ({"check_cell"}));
}
void reset() {
  ::reset();
  if(!present("drowwarrior")){
    new(MOB"drowwarrior")->move(this_object());
    new(MOB"drowwarrior")->move(this_object());
    new(MOB"drowwarrior")->move(this_object());
    new(MOB"drowwarrior")->move(this_object());
  }
  if(!present("drowmasterwarrior")){
    new(MOB"drowmasterwarrior")->move(this_object());
  }
}
int check_cell() {
  if(this_player()->query_race() != "borg") {
    write("It's not very advisable to break into jail.");
    return 0;
  }
  write("You pass through with ease.");
  return 1;
}
