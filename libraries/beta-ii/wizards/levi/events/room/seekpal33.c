#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("The Inner Temple");
    set_long("%^ORANGE%^Very old symbols glow on the walls.  The material that this room is composed of is some sort of orange-gold rock. "
	"A great fire burns to the north and a hazy smoke covers everything.  The floor is tiled.%^RESET%^");
    
    set_items(([
          "walls" : "The walls glow with ancient symbols.",
	  "symbols" : "The symbols are ancient and unique looking.  They glow.",
	  "doorway" : "The doorway is fairly large, but it's just a black arch.  A dim light comes through.",
	          
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "out" : ROOMS "seekpal32.c",
	"north" : ROOMS "seekpal34.c",
    ]));
}
void reset() {
  ::reset();
    if(!present("priestess")) 
      new(MOB "grandpriestess")->move(this_object());
}
