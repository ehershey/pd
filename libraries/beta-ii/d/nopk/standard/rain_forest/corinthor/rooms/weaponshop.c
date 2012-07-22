#include <std.h>
#include <corinthor.h>
inherit ROOM;

void create() {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor Weapon Store");
     set_long("This is obviously the weapons store of Corinthor, as the walls are adorned with many well crafted examples of weapons. The ones on display are blunted however, to prevent anyone from taking them to to rob the store. A counter sits at the back wall, obviously where the business is conducted.");
     set_exits(([
                "west" : ELFROOM"stars6.c"
                ]));
}

void init() {
   ::init();
     add_action("storage", "storage");
}

void reset() {
   ::reset();
     if(!present("feirian")) 
       new(ELFMOB"weaponvend.c")->move(this_object());
}

int storage() {
    if(!wizardp(this_player()))
      return 0;
    this_player()->move_player(ELFROOM"weaponstore.c", "out back");
    return 1;
}
