#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("The cave veers off towards the east here, the passage curving rather sharply as it swings about. The stone is darker here than it is at the entrance to the cave, although there are more patches of the bright white limestone. The walls here are approaching some kind of regularity, but are coarse and uneven in places. The trickle of water flowing here is reinforced from similar trickles from holes in the walls and the constant dripping from the roof.");
    set_smell("default", "The cave smells musty and dank.");
    set_listen("default", "The cavern is quiet except for the rhythmic drip of water from the roof.");

    set_items(([
	({"stone"}) : "The grey stone seems to be more common near the surface, with the stark white limestone being more common as the cave decends. What grey stone that can be seen, however, appears to be getting darker as the cave decends.",
	({"water", "trickle"}) : "The water begins to clear as it decends, slowly returning to a normal transparency as the dirt settles.",
	({"scratch marks", "marks", "scratch", "scratches"}) : "These scratch marks appear to be consistant with a large, clawed creature dragging a heavy load. They clearly lead deeper into the cavern."
      ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"north" : ROOMS"cave2.c",
	"southeast" : ROOMS"cave4.c"
      ]));
}

void reset() {
    if(!present("troll"))
	new(MOB"troll.c")->move(this_object());
}
