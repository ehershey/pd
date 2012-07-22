#include <std.h>
#include <illuminati.h>
inherit ROOM;

void create() {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no scry" : 1]));
     set_short("Illuminati Tower");
     set_long("%^BOLD%^WHITE%^The Illuminati Weapon Store.\n%^RESET%^ORANGE%^Examples of weapons are hung up around the walls and placed in various stands around the room. They are quite uninsteresting compared to anything in stock however. Illuminati members may buy and sell weapons here.%^RESET%^");
     set_exits(([
		"east" : ILROOM"floor2.c"
	]));
}

void reset() {
   ::reset();
     if(!present("masamune")) 
     new(ILMOB"weaponsmith.c")->move(this_object());
}

void init() {
   ::init();
     add_action("storage", "storage");
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
     ILOBJ"ejection"->eject(this_player());
}

int storage() {
    if(!wizardp(this_player()))
      return 0;
    this_player()->move_player(ILROOM"weapstorage.c", "into the storage room");
    return 1;
}
