#include <std.h>
#include <coach.h>
inherit "/d/coach/rooms/coach_room.c";

void create() {
    ::create();

    loc = "lodos";
    dests = ({"tirun", "tenebrae", "roston"});
    todests = ({"to tirun", "to tenebrae", "to roston"});
    largestring = "swears and curses, growling something about you being too big for a regular coach.";
    coachout = "It's nae back yet! Wait a sec!";
    nomoney = "Ye got not enough MONEY, now!";

    set_short("'The Beaten Track' coach house, Lodos");
    set_long("This sizable shack sits just shy of the entrance to Lodos, serving as a dropoff and sendoff point for the horse and carriage transportation services which operate out of the city. This shack is of sturdy construction, but despite that appears to be heavily damaged- as though an angry dwarf tore half the place to bits. The back of this shack is teaming with horses as this is one of the busiest transportation lanes on this continent. A sign stands here, listing the services offered.");
    set_smell("default", "The shack smells of sweat and horses.");
    set_listen("default", "The whinnying of horses is heard here.");
    set_items(([
	({"horse", "horses"}) : "There are fewer horses here then one would expect, but still sufficient to make runs between here and Lodos.",
	({"shack", "small shack"}) : "This modest shack is functional but sparcely decorated.",
	({"sign"}) : "'The Beaten Track', Bastuul's premier transport service! \n \n We currenty travel to: \n \n 1) Lodos - You are here! \n 2) Tirun - Newbies Free, Mids 100g, HMs 1000g,Elites 2000g. \n 3) Tenebrae - Newbies Free, Mids 100g, HMs 1000g, Elites 2000g.\n 4) Roston - Newbies Free, Mids 100g, HMs 1000g, Elites 2000g. \n \n Simply <coach to [desination]> to book a ticket!", 
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
	"west" : "/d/lodos/stown5",
      ]));
}

void reset()

{

    if (!present("dwarf")) {
	new(MOB"lodos.c")->move(this_object());
    }
}
