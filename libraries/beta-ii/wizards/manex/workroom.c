#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Manex's workroom");
set_long("This is the workroom of the great Manex, thr first Pyromancer. He "
	"works here all day and night, with nothing better to do, because "
	"well, he really has no life. Nope, none. Which is why he chose to "
	"code for this mud. There is a large Zebrawood desk in the corner of "
	"his room, with a big Ironwood chair in front of it. You might think "
	"that is a little uncomforatble, but Manex kinda likes it. "
	"You can hear Manex choking his code in frot on the T.V.");
set_items(([
	"desk" : "Its a striped desk covered in sticky code, ewww!",
	"chair" : "A hard chair that seems uncomfortable to you and me",
	"tv" : "It's playing teenage white trash kids with problems creek",
	"manex" : "yep. I'm here too, I've been watching you."
]));
set_properties(([
	"light" : 3,
	"night light" : 3,
]));
set_exits(([
        "square" : "/d/standard/square",
        "hall" : "/d/standard/adv_main",
        "lobby" : "/wizards/manex/lobby.c",
]));
}

void reset() {
   if(!present("pguard"))
	new("/wizards/manex/pguard.c")->move(this_object());
}
