#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 2, "indoors" : 1, "no attack" : 1, "no magic" : 1, "no bump" : 1, "no steal" :1]));
     set_name("Zartha City Oil Store");
     set_short("Zartha Oil Store");
     set_long("This is the healing store for Zartha. The demand for oils is high, due to the dangerous nature of the city, and the constant flow of adventurers in and out of the castle. An old man grins at you from behind the counter.");
     set_items(([

                ]));
     set_exits(([
                "east"	: KEEPROOM"[]southwest.c"
                ]));
}

void reset() {
   ::reset();
     if (!present("jarkun"))
        new(KEEPMOB"oilguy.c")->move(this_object());
}
