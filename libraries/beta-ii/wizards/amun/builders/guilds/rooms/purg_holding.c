#include <std.h>
#include <daemons.h>
#include <guild.h>
#include <boat.h>
inherit "/wizards/amun/builders/guilds/rooms/boat_room.c";
void create() {
    ::create();

    loc = "purgatory";
    dests = ({"town"});
    todests = ({"to town"});
    largestring = "mummbles about having to be a servant.";
    sailout = "The boat is not back, calmly wait your turn.";
    costbase = 250;
    nomoney = "GET OUT OF HERE! COME BACK WHEN YOU HAVE MORE MONEY!";
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set_property("town",1);
    set_listen("default", "%^BOLD%^%^CYAN%^The smell of the sea encompasses the area.%^RESET%^");
    set_short("Purgatory Holding Dock");
    set("long","%^BOLD%^%^RED%^This is the holding room just outside of Purgatory. It is used mainly as a place for those within a guild to travel back to the Guild Town. The ship is lapping against the docks as if it is tapping it's foot, waiting for a passenger. A sign is posted for all to look at.%^RESET%^");
    set_exits((["up" : "/d/freepk/purgatory/room/purgatory10"]));
    set_items( (["sign" : "%^BOLD%^%^WHITE%^'%^RED%^The Captain's Lodge%^WHITE%^', The Guild Town boating service!%^RESET%^ \n \n %^BOLD%^WHITE%^We currently travel to:%^RESET%^ \n \n %^BOLD%^%^WHITE%^1) Guild [%^BOLD%^%^RED%^Town%^WHITE%^] - Children 200g, Youngin's 500g, Adults 750g.%^RESET%^ \n %^BOLD%^%^WHITE%^2) %^BOLD%^%^RED%^Purgatory%^WHITE%^ - Ye be thar!%^RESET%^ \n \n %^BOLD%^%^WHITE%^Simply <%^RED%^sail to %^WHITE%^[desination]> %^WHITE%^to book a ticket!%^RESET%^", "ship" : "%^ORANGE%^The ship is lapping against the dock as if impatiently waiting for a passenger.%^RESET%^" ]) );
}
void reset() {
    ::reset();
    if(!present("dockhand"))
	new(GMOB "dockhand")->move(this_object());
}
