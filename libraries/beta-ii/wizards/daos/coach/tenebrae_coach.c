#include <std.h>
#include <coach.h>
inherit "/d/coach/rooms/coach_room.c";

void create() {
    ::create();

    loc = "tenebrae";
    dests = ({"tirun", "lodos"});
    todests = ({"to tirun", "to lodos"});
    largestring = "stares stupidly at you for a second or two, then hires a bigger coach.";
    coachout = "Duuh... the coach isn't back yet.";
    nomoney = "Errh... you need more shinies.";

    set_short("'The Beaten Track' coach house, Tenebrae");
    set_long("This average sized shack sits just shy of the main gateway to Tenebrae, serving as a dropoff and sendoff point for the horse and carriage transportation services which operate out of the city. This shack is reasonably decorated, for a shack, although all the signs are written in big block letters and have lots of spelling mistakes. The back of this shack contains several teams of horses resting after a run. A sign stands here, listing the services offered.");
    set_smell("default", "The shack smells of sweat and horses.");
    set_listen("default", "The whinnying of horses is heard here.");
    set_items(([
	({"horse", "horses"}) : "There are fewer horses here then one would expect, but still sufficient to make runs between here and Lodos.",
	({"shack", "small shack"}) : "This modest shack is functional, seeming a little more decorated then the rest.",
	({"sign"}) : "'The Beaten Track', Bastuul's premier transport service! \n \n We currenty travel to: \n \n 1) Tenebrae - You are here! \n 2) Tirun - Newbies Free, Mids 100g, HMs 1000g, Elites 2000g. \n 3) Lodos - Newbies Free, Mids 100g, HMs 1000g, Elites 2000g. \n \n Simply <coach to [desination]> to book a ticket!", 
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
	"east" : "/d/shadow/rooms/thirtyseven.c",
      ]));
}

void reset()

{

    if (!present("dwarf")) {
	new(MOB"tenebrae.c")->move(this_object());
    }
}
