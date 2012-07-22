#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("The wall south of here holds a few paintings and is, itself, made of white ivory. "
	     "There are a couple of chairs against the wall for people taking a break from the "
	     "dance, not that they're going to get tired anyway.");


    set_items(([
	  "chairs" : "The chairs are mahongany with golden hind's skins sewn into them.",
	  "paintings" : "Paintings of notable vampires in the history of this town.  Strange... "
		"one of them looks like the guy who put you on this quest.",        	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"north" : ROOMS "cainball5e1.c",
	"east" : ROOMS "cainball4e2.c",
	"west" : ROOMS "cainball4.c",
       ]));
}

void reset() {
  ::reset();
    if(!present("noblevamp")) 
      new(MOB "noblevamp")->move(this_object());

    if(!present("noblevamp")) 
      new(MOB "noblevamp")->move(this_object());
}
