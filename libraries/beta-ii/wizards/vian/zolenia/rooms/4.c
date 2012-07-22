#include <std.h>
#include <zolenia.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 4, "night light" : 4, "indoors" : 1]) );
set_smell("default", "A strong, earthy smell fills the air");
set_listen("default", "Sounds of animals fighting can be heard to the south, while the bustling crowd of a city is heard to the east.");
set_short("climbing down the rocky slope");
set_long("The entire ground appears to be made of onyx, a strange circumstance for a naturally formed hole in the earth.  It feels as if it should be dark, although through some sort of magic, everything seems to be quite illuminated.  There is some scribbling on the ground.");
set_items(([
({"rock", "rocks"}) : "Although many rocks are sharp and jagged, there are plenty of flat ones to aide climbing down..",
({"onyx", "ground"}) : "The ground is constructed of very dark and shiny onyx.  There is some scribbling on the ground.",
({"scribbles", "scribbling"}) : "%^BOLD%^%^BLACK%^Dragons beware, we know how you fare.  Do not go to the east, or you'll be our next feast.  If it's a guard of Roston that you may be, this will be the last day you see.  We have our ways, we live in peace, but we'll end your days if you enter our lease.",
]));
    set_exits(([        "south" : ROOMO "a3_0.c",
			"climb" : ROOMS "climb1.c",
                                "east" : ROOMS "5.c"]));}
void init() {
  ::init();
   if (this_player()->is_player()) {
   write("You fall, finally, to some solid ground.  Oh, the adventures that await.");
   say(""+this_player()->query_cap_name()+" falls from above, landing with a loud thud.");
   this_player()->add_hp(-random(100));
 }
}

