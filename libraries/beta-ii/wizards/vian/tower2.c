#include <std.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "no attack" : 1, "no magic" : 1, "no bump" : 1, "no steal" :
1, "light" : 2, "town" : 1, "night light" : 2]) );
set_smell("default", "Well, it smells mostly like a monastery, to be honest...");
set_listen("default", "There is a peaceful silence resonating here.");
set_short("Scry tower");
set_long("Atop a tower of the monastery is the location pool.  The monks and clergy of the monastery would use this pool to locate the corpses of the fallen and falling to help heal or bring them back to life.  This pool is public, though, and has sadly also been used by the scum of the earth.");
set_exits(([ "down" : "/wizards/vian/tower.c"]));
}
void reset() {
    ::reset();
        if(!present("pool"))
          new("/wizards/vian/pool.c")->move(this_object());
}
