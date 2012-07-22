#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no scry" : 1 ]));
     set_short("Illuminati Tower");
     set_long("%^BOLD%^WHITE%^The Illuminati Armoury.\n%^RESET%^ORANGE%^Examples of the armourer's work hang all around the walls. Here members can sell all the armour they collect on their travels for gold. They may also purchase armour sold by other members. Various display items adorn the room, but are rather uninteresting.%^RESET%^");
     set_exits(([
		"west" : ILROOM"floor2.c"
		]));
}

void init() {
   ::init();
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
     add_action("storage", "storage");
}

void reset() {
   ::reset();
     if(!present("matthew")) 
       new(ILMOB"armsmith.c")->move(this_object());
}

int storage() {
  if(!wizardp(this_player()))
    return 0;
  this_player()->move_player(ILROOM"armstorage.c", "into the storage room");
  return 1;
}
