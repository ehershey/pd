#include <std.h>
#include <wildflower.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("Standard Workroom");
    set_long(
      "Wow!  What a strange place!  A flower garden!  In the "
      "middle of the garden is a waterfall, but looking up it "
      "is coming from a strange source, and the water is slowly "
      "filling up the room. Surrounding the garden is a drab lookin "
      "clay wall.  The ground here is pitch black, and very moist. "
      "All this seems very familiar, hmmm, a flower pot?  Ah HAH!  "
      "This is Wildflower's home!"
    );
    set_items(([
        "room" : "The room is filled with sweet smelling flowers.",
        "poster" : "1 : Type 'cd /wizards/(yourname)', this"
           " will change your current directory to your home directory."
  "\n2 : Type ls, this will give you a list of whats in your current
directory."
  "\n3 : Type 'more workroom.c', this will display the contents of "
  "this file."
  "\n4 : Now, be brave, and type 'ed workroom.c'.  As soon as you do this, "
  "type 'h', this will display a list of commands for the built in editor."
   "\nIf you need any more help, leave goto the hall from this room.",
   ({"wall", "the wall"}):
     "The wall has a poster on it, maybe you should look at it."
    ]));
    set_smell("default", "Aromas of sweet smelling flowers fill the room");
    set_listen("default", "The sound of flowers whispering in the breeze"
    );
    set_exits( ([
        "square" :  "/d/nopk/tirun/square",
        "hall"  :  "/d/nopk/standard/adv_inner",
        "down"  :  ROOMS "outdoor2",
    ]) );
}
