//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthian Objects Storage");
     set_long("This is the storage room for Corinthian Objects");
     set_exits(([
                "out"		: ELFROOM"objectshop.c"
                ]));
}

void reset() {
   ::reset();
     if(!present("seal"))
       new("/d/nopk/tirun/obj/misc/tirun_seal_new.c")->move(this_object());
     if(!present("seal 2"))
       new("/d/nopk/tirun/obj/misc/tirun_seal_new.c")->move(this_object());
}
