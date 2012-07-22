#include <std.h>
#include <coach.h>
inherit "/d/coach/rooms/coach_room.c";

void create() {
    ::create();

    loc = "tirun";
    dests = ({"lodos", "tenebrae"});
    todests = ({"to lodos", "to tenebrae"});
    largestring = "grumbles about having to hire a larger coach.";
    coachout = "The coach isn't back yet. Kids these days... geez.";
    nomoney = "Hmmph... back in my day, we didn't even *have* luxuries like money. You need more gold for this ride!";

    set_short("'The Beaten Track' coach house, Tirun");
    set_long("This average sized shack sits outside the western gate of Tirun, serving as a dropoff and sendoff point for the horse and carriage transportation services which operate out of the city. The inside of this shack is really old style paintings and art. Coupled with the constant sound of dripping water it's not hard to see how this would make someone grumpy. The back of this shack contains several teams of horses resting after a run. A sign stands here, listing the services offered.");
    set_smell("default", "The shack smells of sweat and horses.");
    set_listen("default", "The whinnying of horses is heard here, along with the sound of dripping water.");
    set_items(([
	({"horse", "horses"}) : "There are fewer horses here then one would expect, but still sufficient to make runs between here and Lodos.",
	({"shack", "small shack"}) : "This modest shack is functional, seeming a little more decorated then the rest.",
	({"sign"}) : "'The Beaten Track', Bastuul's premier transport service! \n \n We currenty travel to: \n \n 1) Tirun - You are here! \n 2) Lodos - Newbies Free, Mids 100g, HMs 1000g, Elites 2000g. \n 3) Tenebrae - Newbies Free, Mids 100g, HMs 1000g, Elites 2000g. \n \n Simply <coach to [desination]> to book a ticket!", 
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
	"south" : "/d/nopk/standard/highway1.c",
      ]));
}

void reset()

{

    if (!present("dwarf")) {
	new(MOB"tirun.c")->move(this_object());
    }
}
