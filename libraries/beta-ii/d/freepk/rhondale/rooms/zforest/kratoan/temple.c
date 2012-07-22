#include <std.h>
#include <aziraphale.h>
inherit ROOM;
void create() {
   ::create();
     set_properties((["light": 1, "night light" : 0, "indoors" : 1]));
     set_short("Kra'Toa'Kathor");
     set_long("The inside of the cathedral of Kra'Toa'Kathor is absolutely magnificent. Dozens of trees have grown in perfect rows to create four walls without a gap, the branches coming together overhead creating a roof as good as any thatcher's. The floor is simple grass and at the back of the cathedral there is a simple hedge to act as a pulpit.");
     set_exits(([
                "west"                  : KEEPROOM"zforest/kratoan/road6.c",

                ]));
     set_items(([
                ]));
}

void reset() {
   ::reset();
     if(!present("monster")) {
     new(KEEPMOB"zforest/kratoan/lyfra.c")->move(this_object());
       }
}
