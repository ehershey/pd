#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 2, "town" : 1, "no attack" : 1, "no magic" : 1, "no bump" : 1, "no steal" : 1]));
     set_name("Zartha City Square");
     set_short("Zartha Square");
     set_day_long("%^BOLD%^BLACK%^Zartha City Park\n%^RESET%^This park was once the centre of a busy marketplace. Now the grass is left uncut, the trees are losing their leaves, and the fountain no longer flows. In the very centre of the park is a circle of benches.");
     set_night_long("%^BOLD%^BLACK%^Zartha City Park\nThe park at night is not a comfortable place to be. The entire place is wracked with shadows, and the trees seem to claw out from the darkness. A group of people sit on benches around an altar.");
     set_items(([
                "flame"         : "The flame burns pure white, and floats just off the altar. It never stops burning...",
                "benches"       : "The benches are placed in a circle around an altar topped with a white flame, they are there for those who need a break from walking.",
                "people"        : "They seek refuge from the night in the safety of the sqaure. The people of this city look sad and lost, they have been beaten by the evil of the castle.",
                "altar"         : "The altar is just a metre tall circular pillar of stone. Glyphs ethced into the surface glow at night. A white flame burns atop it."
                ]));
     set_exits(([
                "north"         : KEEPROOM"[]north.c",
                "south"         : KEEPROOM"[]south.c",
                "east"          : KEEPROOM"[]east.c",
                "west"          : KEEPROOM"[]west.c"
                ]));
}
