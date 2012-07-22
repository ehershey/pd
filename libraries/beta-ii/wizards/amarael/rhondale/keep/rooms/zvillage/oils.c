#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 2, "indoors" : 1, "no attack" : 1, "no bump" : 1]));
     set_name("Rhondale Healing Supplies");
     set_short("Rhondale Healing Supplies");
     set_long("This is the healers house of Rhondale. Many herbs have been placed in glass cases around the room. Set in front of the back wall is a long counter, behind which stands a young woman.");
     set_items(([

                ]));
     set_exits(([
                "east"  : KEEPROOM"zvillage/insqsouth.c"
                ]));
}

void reset() {
   ::reset();
     if (!present("allisah"))
        new(KEEPMOB"zvillage/oils.c")->move(this_object());
}
