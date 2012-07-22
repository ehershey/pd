#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 2, "indoors" : 1, "no attack" : 1, "no bump" : 1]));
     set_name("Rhondale Magical Supplies");
     set_short("Rhondale Magical Supplies");
     set_long("The magical supplies store of Rhondale is filled with all sorts of artifacts, many of them are warded from touch to keep thieves and fools at bay. The place is run by a middle-aged man by the name of Jorca, who is waiting for you to purchase something.");
     set_items(([

                ]));
     set_exits(([
                "west"  : KEEPROOM"zvillage/insqsouth.c"
                ]));
}

void reset() {
   ::reset();
     if (!present("jorca"))
        new(KEEPMOB"zvillage/stones.c")->move(this_object());
}
