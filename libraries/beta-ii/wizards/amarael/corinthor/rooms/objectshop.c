#include <std.h>
#include <corinthor.h>
inherit ROOM;

void create() {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor General Store");
     set_long("One of the the three main shops of Cornthor, this one appears to trade in general items. Many examples of items for sale are spread out amongst bookshelves and display stands. A counter against the back wall appears to be the point of sale for this shop.");
     set_exits(([
                "south" : ELFROOM"summer5.c"
                ]));
}

void init() {
   ::init();
     add_action("storage", "storage");
}

void reset() {
   ::reset();
     if(!present("liaqui")) 
       new(ELFMOB"objectvend.c")->move(this_object());
}

int storage() {
    if(!wizardp(this_player()))
      return 0;
    this_player()->move_player(ELFROOM"objectstore.c", "out back");
    return 1;
}
