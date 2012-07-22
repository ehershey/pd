#include <std.h>
#include <daemons.h>
#include <guild.h>
#include <boat.h>
inherit "/wizards/amun/builders/guilds/rooms/boat_room.c";
void create() {
    ::create();

    loc = "town";
    dests = ({"tirun", "merkkirri", "rhondale", "purgatory", "inferi", "dunsinane"});
    todests = ({"to tirun", "to merkkirri", "to rhondale", "to purgatory", "to inferi", "to dunsinane" });
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
    set_short("Guild Town");
    set("long","%^BOLD%^%^CYAN%^Large waves can be seen crashing, with thier %^WHITE%^whitecaps %^CYAN%^stretching many yards in length. Many %^WHITE%^s%^BLACK%^e%^WHITE%^agul%^BLACK%^l%^WHITE%^s %^CYAN%^are flying low over the sea in hopes of catching their next meal. The area is very rocky and only one large ship can be seen tied to the wooden dock. A sign is posted for all to look at.%^RESET%^");
    set_exits((["north" : GROOM "docks_entrance", "east" : GROOM "boat_dock"]));
    set_items( (["sign" : "%^BOLD%^'%^RED%^The Captain's Lodge%^WHITE%^', The Guild Town boating service! \n \n We currently travel to: \n \n %^BOLD%^%^WHITE%^1) %^RED%^Guild %^WHITE%^[%^BOLD%^%^RED%^Town%^WHITE%^] - Ye be thar!%^RESET%^ \n %^BOLD%^%^WHITE%^2) %^RED%^Tirun %^WHITE%^- Children 200g, Youngin's 500g, Adults 750g.%^RESET%^ \n %^BOLD%^%^WHITE%^3) %^BOLD%^%^RED%^Merkkirri%^WHITE%^ - Children 200g, Youngin's 500g, Adults 750g. %^RESET%^\n %^BOLD%^%^WHITE%^4) %^BOLD%^%^RED%^Rhondale%^WHITE%^ - Children 200g, Youngin's 500g, Adults 750g.%^RESET%^ \n %^BOLD%^%^WHITE%^5) %^BOLD%^%^RED%^Purgatory%^WHITE%^ - Children 200g, Youngin's 500g, Adults 750g.%^RESET%^ \n %^BOLD%^%^WHITE%^6) %^BOLD%^%^WHITE%^[%^RED%^Inferi%^WHITE%^]%^RED%^ Island%^WHITE%^ - Children 200g, Youngin's 500g, Adults 750g.%^RESET%^ \n %^BOLD%^%^WHITE%^7) %^BOLD%^%^RED%^Dunsinane%^WHITE%^ - Children 200g, Youngin's 500g, Adults 750g.%^RESET%^ \n \n %^BOLD%^%^WHITE%^Simply <%^RED%^sail to %^WHITE%^[desination]> %^WHITE%^to book a ticket!%^RESET%^" ]) );
    set_items( (["waves" : "%^BOLD%^%^CYAN%^The waves are crashing hard and fast.%^RESET%^", "whitecaps" : "%^BOLD%^%^WHITE%^These whitecaps are longer than normal, they're going to make for a choppy ride.%^RESET%^", "seagulls" : "%^BOLD%^%^WHITE%^The s%^BLACK%^e%^WHITE%^agul%^BLACK%^l%^WHITE%^s are flying over the ocean in hopes of food.%^RESET%^", "ship" : "%^ORANGE%^The large ship is ready to take travelers on their next adventure.%^RESET%^" ]) );
}
void reset() {
    ::reset();
    if(!present("dockhand"))
	new(GMOB "dockhand")->move(this_object());
}
