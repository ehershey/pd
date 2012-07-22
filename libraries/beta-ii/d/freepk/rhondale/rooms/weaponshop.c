#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1, "no steal" : 1]));
     set_short("Zartha Weapon Shop");
     set_long("This is the Weapon shop of Zartha. All kinds of show weapons hang around the walls, prizes of the owner no doubt. A counter seperates you from the goods, and a man is standing behind it.");
     set_exits(([
		"west" : KEEPROOM"[]southeast.c"
		]));
}

void init() {
   ::init();
     add_action("storage", "storage");
}

void reset() {
   ::reset();
     if (!present("cromnir")) 
        new(KEEPMOB"weaponsmith.c")->move(this_object());
}

int storage() {
    if (!wizardp(this_player())) {
       message("my_action", "No, you are not allowed in the back room.", this_player());
       message("other_action", this_player()->query_cap_name()+" moves towards the storage room, but then thinks better of it.", this_object(), this_player());
       return 1;
       }
    this_player()->move_player(KEEPROOM"weaponstorage.c", "storage");
    return 1;
}

