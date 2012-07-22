#include <std.h>
#include <corinthor.h>
inherit ROOM;

void create() {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor Armour Shop");
     set_long("This is the armour shop of Corinthor, shelves line the walls with all manner of items that are for sale. A counter against the back wall looks to be where all business transactions are made. the floor is made of polished wood.");
     set_exits(([
                "west" : ELFROOM"summer5.c"
                ]));
}

void init() {
   ::init();
     add_action("storage", "storage");
}

void reset() {
   ::reset();
     if(!present("aramil")) 
       new(ELFMOB"armourvend.c")->move(this_object());
}

int storage() {
    if(!wizardp(this_player()))
      return 0;
    this_player()->move_player(ELFROOM"armourstore.c", "out back");
    return 1;
}
