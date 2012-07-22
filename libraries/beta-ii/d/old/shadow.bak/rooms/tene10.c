#include <std.h>
#include <shadow.h>
inherit ROOM;
void create() {
object board;
room::create();
   set_properties( ([ "light" : 1, "indoors" : 1]) );
    set_short("Tenebrae Square");
    set_long(
      "This is Tenebrae Square.  People hurry about their business  "
      "to the north and south.  The many shops are in those directions.  "
      "A mighty palace is to the east.  There is a board here "
      "with the current news on it."
    );
      set_items((["sky":"The sky is dark as ever.","road":"The cobblestone road
     heads north, east, and south.",
    "path":"The path is dry and worn.",
    "people":"The people here are white from the lack of a normal amount of sunlight.",
    "stone":"The cobblestones are black and grey.  Like the sky."]));

   set_listen("default", "Hollering merchants can be heard to the north and south.");
set_exits ( ([ "south" : ROOMS "tene12.c", "north" :ROOMS"tene11.c","east" : ROOMS "tene15.c","west" : ROOMS "tene08.c"]) );
 board = new("/std/bboard");
 board->set_name("board");
 board->set_id( ({ "board", "Tenebrae Board" }) );
 board->set_max_posts(80);
 board->set_location("/d/shadow/rooms/tene10.c");
 board->set("short", "Tenebrae Board");
 board->set("long", "The board has all the current news of Tenebrae posted on it.\n");
 board->set_board_id("Tenebrae");
}
