#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 1, "town" : 1]));
     set_name("Rhondale North Gates");
     set_short("Rhondale North Gates");
     set_day_long("Rhondale is heavily fortified against the dangerous inhabitants of the forest. The outer path circles the entire village just inside the walls. The cobblestones underfoot are smooth though not at all slippery. Here the northern gates allow access to the forest.");
     set_night_long("The outer path of Rhondale leads a circle all around the city just inside the main walls. Torches are placed every fifteen meters eliminating the shadows of night.  The cobblestones are worn smooth by the various night patrols. Here the north gates lead out to the forest.");
     set_exits(([
                "gate"         : KEEPROOM"zvillage/gates.c",
                "west"          : KEEPROOM"zvillage/outer1130.c",
                "east"          : KEEPROOM"zvillage/outer1230.c",
                "south"         : KEEPROOM"zvillage/inoutnorth.c"
                ]));
     set_pre_exit_functions( ({"gate"}), ({"leave_rhondale"}) );
}

void reset() {
   ::reset();
     if (!present("monster")) {
        new(KEEPMOB"zvillage/townguard.c")->move(this_object());
        new(KEEPMOB"zvillage/townguard.c")->move(this_object());
        new(KEEPMOB"zvillage/townguard.c")->move(this_object());
        }
}

int leave_rhondale() {
    object guard;
    if ((guard = present("guard"))) {
       if (this_player()->query_level() < 35) {
          guard->force_me("say I cannot allow you to proceed, the lands beyond are death to such as you.");
          return 0;
          }
       guard->force_me("say The lands outside are death to the ill prepared, you are warned.");
       return 1;
       }
    return 1;
}
