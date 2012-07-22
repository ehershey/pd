#include <std.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "no attack" : 1, "no magic" : 1, "no bump" : 1, "no steal" :
1, "light" : 2, "town" : 1, "night light" : 2]) );
set_smell("default", "Well, it smells mostly like a monastery, to be honest...");
set_listen("default", "There is a peaceful silence resonating here.");
set_short("Scry tower");
set_long("This staircase leads up toward the monastery tower.  It is fairly plain, even crumbling in parts.  There are blood-stains on the ground, possibly from clerics trying to mend the injured, and definitely from the bloodshed of mortals of Primal Darkness.");
set_exits(([ "down" : "/d/nopk/tirun/monastery.c",
"up" : "/wizards/vian/tower2.c"]));
}
