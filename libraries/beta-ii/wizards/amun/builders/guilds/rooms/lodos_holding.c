#include <std.h>
#include <daemons.h>
#include <guild.h>
#include <boat.h>
inherit "/wizards/amun/builders/guilds/rooms/coach_room.c";
void create() {
    ::create();

    loc = "lodos";
    dests = ({"town"});
    todests = ({"to town"});
    largestring = "mummbles about having to break his routine.";
    coachout = "The coach is not back, sit down and wait please.";
    costbase = 250;
    nomoney = "GET OUT OF HERE! COME BACK WHEN YOU HAVE MORE MONEY!";
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set_property("town",1);
    set_short("Lodos Coach");
    set("long","%^ORANGE%^This is the holding room just outside of Lodos. It is used mainly as a place for those within a guild to travel back to the Guild Town. The horse snuffs loudly as if it is tapping it's foot, waiting for a passenger. A sign is posted for all to look at.%^RESET%^");
    set_exits((["up" : "/d/distopia/room/startlod"]));
    set_items( (["sign" : "%^BOLD%^%^WHITE%^'%^RED%^The Keeper's Coaches%^WHITE%^', The Guild Town boating service!%^RESET%^ \n \n %^BOLD%^WHITE%^We currently travel to:%^RESET%^ \n \n %^BOLD%^%^WHITE%^1) Guild [%^BOLD%^%^RED%^Town%^WHITE%^] - Children 200g, Youngin's 500g, Adults 750g.%^RESET%^ \n %^BOLD%^%^WHITE%^2) %^BOLD%^%^RED%^Lodos%^WHITE%^ - You're here silly!%^RESET%^ \n \n %^BOLD%^%^WHITE%^Simply <%^RED%^coach to %^WHITE%^[desination]> %^WHITE%^to book a ticket!%^RESET%^", "horse" : "%^BOLD%^%^WHITE%^The horse snuffs loudly as if it is tapping it's foot, waiting for a passenger.%^RESET%^"  ]) );
}
void reset() {
    ::reset();
    if(!present("master"))
	new(GMOB "horse_master")->move(this_object());
}
