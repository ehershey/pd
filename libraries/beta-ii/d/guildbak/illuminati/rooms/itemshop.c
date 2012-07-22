#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no scry" : 1]));
     set_short("Illuminti Tower");
    set_long("%^BOLD%^WHITE%^The Illuminati Equipment Store.\n%^RESET%^ORANGE%^All sorts of items adorn the many cabinets and display stands within the room. Although none of it is of any real value in the adventuring world. Here Illuminati members may buy and sell equipment.");
     set_exits(([
		"northwest" : ILROOM"floor2.c"
		]));
}

void init() {
   ::init();
     add_action("storage", "storage");
     if(this_player()->query_guild()  != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection.c"->eject(this_player());
}

void reset() {
   ::reset();
     if(!present("monster"))
       new(ILMOB"eqsmith.c")->move(this_object());
}

int storage() {
    if(!wizardp(this_player()))
      return 0;
    this_player()->move_player(ILROOM"eqstorage.c", "into the storage room");
    return 1;
}
