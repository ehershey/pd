#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1, "no steal" : 1]));
     set_short("Zartha Weapon Shop");
     set_long("This is the Zarthan armour shop. It has been here for decades, and it shows. The walls and floor look old and worn, and many of the sets of armour on display have lost their lustre. An old man waits to serve you.");
     set_exits(([
		"north" : KEEPROOM"[]southeast.c"
		]));
}

void init() {
   ::init();
     add_action("storage", "storage");
}

void reset() {
   ::reset();
     if (!present("garr")) 
        new(KEEPMOB"armoursmith.c")->move(this_object());
}

int storage() {
    if (!wizardp(this_player())) {
       message("my_action", "No, you are not allowed in the back room.", this_player());
       message("other_action", this_player()->query_cap_name()+" moves towards the storage room, but then thinks better of it.", this_object(), this_player());
       return 1;
       }
    this_player()->move_player(KEEPROOM"armourstorage.c", "storage");
    return 1;
}

