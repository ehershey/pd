#include <std.h>
#include <helgrath.h>

inherit ROOM;

void create(){
    ::create();
    set_properties(([
	"light" : -2,
	"indoors" : 1
      ]));
    set_short("Icey Cave");
    set_long("Icy stalagmites stand intermittently about this room, all but barring "
      "the path forward. Large puddles of melted ice litter the floor of the cave. "
      "Small creatures scurry about in the darkness. Just beyond the edge of the "
      "shadows, their luminescent eyes watch every move. "
    );
    set_exits(([ "north": ROOMS "cave04.c",
	"south": ROOMS "cave02.c",
	"west": ROOMS "cave05.c" ]));
    set_smell("default", "Fowl odors waft in upon a cold breeze.");
    set_listen("default", "Faint scratching noises can be heard.");
    set_items( ([
	"walls" : "The walls are covered in ice.",
	"stalagmites" : "Water dripping then freezing over time has allowed these to form.",
	"creatures" : "Small albino ice lizards and other creatures of the cold.",
	"eyes" : "Glowing faintly, the creatures eyes follow your every move.",
      ]));
}
void reset(){
    ::reset();
    if(present("cave lurker")) return;
    new(MOB"cave_lurker.c")->move(this_object());
}
