#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 2, "night light" : 2, "town" : 1]));
     set_name("Zartha City Market West");
     set_short("Zartha Market West");
     set_day_long("%^BOLD%^BLACK%^Zartha Marketplace%^RESET%^\nThis part of the markets is much more well traveled than the rest. The stones underfoot are worn smooth, and a few lamps hang off the side of the shops here. Signs show there are stone and oil shops to the south and west, and a hunter's hall to the southwest.");
     set_night_long("%^BOLD%^BLACK%^Zartha Marketplace\nEven at night the southwest market is fairly well lit, with a few lamps hanging from the side of buildings. A few people walk in out of ston and oil shops to the south and west, and the hunter's hall to the southwest sees much traffic.");
     set_items(([

                ]));
     set_exits(([
                "west"		: KEEPROOM"zarthaoils.c",
                "north"		: KEEPROOM"[]west.c",
                "east"		: KEEPROOM"[]south.c",
                "south"		: KEEPROOM"zarthastones.c",
                "southwest"	: KEEPROOM"zarthabounty.c"
                ]));
}
