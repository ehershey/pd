#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 1, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("The walls inside the mountain twist and turn, making the "
          "path harder to follow. Rocks and dirt litter the ground. "
	"The walls are cold and gray and are decorated with primitave "
	"looking symbols.");
    set_items(([
({"ground", "rocks", "dirt"}) : "The ground is littered with dirt and "
	"rocks.",
({"symbols"}) : "The wisest scholars in the world couldn't determine what"
	" these primitive markings mean.",
({"hall"}) : "The hall twists and turns throughout the inside of the "
	"mountain."
    ]));
    set_exits( ([ 
       "southwest" :  "/wizards/smoke/mountain/rooms/2_15",
       "south" :  "/wizards/smoke/mountain/rooms/2_13"
    ]) );
}
void reset() {
    if(!present("ogre"))
        new("/wizards/smoke/mountain/monsters/ohunteress")->move(this_object());
        new("/wizards/smoke/mountain/monsters/ozerk")->move(this_object());
        new("/wizards/smoke/mountain/monsters/owarrior")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mammoth")->move(this_object());
}