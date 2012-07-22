#include <std.h>
#include <coach.h>
inherit "/d/coach/rooms/coach_room.c";

void create() {
    ::create();

    loc = "roston";
    dests = ({"lodos"});
    todests = ({"to lodos"});
    largestring = "mutters something under his breath about 'voluminous consignment'.";
    coachout = "Alas, the medium is unavailable at this contemporary junction.";
    nomoney = "My disapprobation for compunctious discourse aside, you accost a enunciated mercantile paucity.";

    set_short("'The Beaten Track' coach house, Roston");
    set_long("This tiny shack sits to the north of Roston town, serving as a dropoff and sendoff point for the horse and carriage transportation services which operate out of the city. Books pile around here, a testiment to the operator's scholarly nature. There are not many horses here as this is a lesser-travelled route, but still there are several teams out the back. A sign stands here, listing the services offered.");
    set_smell("default", "The shack smells nice for a change.");
    set_listen("default", "The whinnying of horses is heard here.");
    set_items(([
	({"book", "books"}) : "These books are on a wide variety of topic, ranging from the best way to grow mushrooms indoors to history and art.",
	({"horse", "horses"}) : "There are fewer horses here then one would expect, but still sufficient to make runs between here and Lodos.",
	({"shack", "small shack"}) : "This modest shack is functional but sparcely decorated.",
	({"sign"}) : "'The Beaten Track', Bastuul's premier transport service! \n \n We currenty travel to: \n \n 1) Roston - You are here! \n 2) Lodos - Newbies Free, Mids 100g, HMs 1000g, Elites 2000g. \n \n Simply <coach to [desination]> to book a ticket!", 
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
	"no attack" : 1,
	"no kill" : 1,
	"no magic" : 1,
	"no teleport" : 1,
      ]));
    set_exits(([
	"east" : "/d/roston/rooms/roston30.c",
      ]));
}

void reset()

{

    if (!present("dwarf")) {
	new(MOB"roston.c")->move(this_object());
    }
}
