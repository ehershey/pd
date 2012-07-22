#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1, "no steal" : 1]));
     set_short("Zartha Item Shop");
     set_long("The local general store, this is the place to go for buying and selling miscellaneous goods. The room is mostly bare, with just a few items shown on the counter.");
     set_exits(([
		"northwest" : KEEPROOM"[]southeast.c"
		]));
}

void init() {
   ::init();
     add_action("storage", "storage");
}

void reset() {
   ::reset();
     if (!present("vahlia")) 
        new(KEEPMOB"itemsmith.c")->move(this_object());
}

int storage() {
    if (!wizardp(this_player())) {
       message("my_action", "No, you are not allowed in the back room.", this_player());
       message("other_action", this_player()->query_cap_name()+" moves towards the storage room, but then thinks better of it.", this_object(), this_player());
       return 1;
       }
    this_player()->move_player(KEEPROOM"itemstorage.c", "storage");
    return 1;
}

