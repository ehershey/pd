#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 2, "indoors" : 1, "no attack" : 1, "no magic" : 1, "no bump" : 1, "no steal" :1]));
     set_name("Zartha City Stone Store");
     set_short("Zartha Stone Store");
     set_long("Here is the Zarthan stoneshop. The store seems to get alot customers, many of which being the undead hunters that patrol the city. The owner sits behind a counter looking expectant.");
     set_items(([

                ]));
     set_exits(([
                "north"		: KEEPROOM"[]southwest.c"
                ]));
}

void reset() {
   ::reset();
     if (!present("marlon"))
        new(KEEPMOB"stoneguy.c")->move(this_object());
}
