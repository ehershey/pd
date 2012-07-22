#include <std.h>
#include <daemons.h>
#include <guild.h>
inherit "/wizards/amun/builders/guilds/rooms/coach_room.c";
void create() {
    ::create();

    loc = "town";
    dests = ({"helgrath", "tenebrae", "lodos", "roston", "citrin", "desert"});
    todests = ({"to helgrath", "to tenebrae", "to lodos", "to roston", "to citrin", "to desert"});
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
    set_listen("default", "%^BOLD%^%^GREEN%^The smell of horses encompasses the area.%^RESET%^");
    set_short("Guild Town");
    set("long","%^ORANGE%^The stable on the south side of the room is filled with horses waiting on their turn to pull the coaches. In the corral there is a single carriage with a %^BOLD%^%^WHITE%^bright white horse %^RESET%^%^ORANGE%^hooked up to it. The horse is tall with %^BOLD%^%^WHITE%^hair whiter %^RESET%^%^ORANGE%^than it's back. There is a sign posted on the stable for all to look at.%^RESET%^");
    set_items( (["sign" : "%^BOLD%^%^WHITE%^'%^RED%^The Keeper's Coaches%^WHITE%^', The Guild Town coach service!%^RESET%^ \n \n %^BOLD%^WHITE%^We currently travel to:%^RESET%^ \n \n %^BOLD%^%^WHITE%^1) Guild [%^BOLD%^%^RED%^Town%^WHITE%^] - You're Here Silly!%^RESET%^ \n %^BOLD%^%^WHITE%^2) %^BOLD%^%^RED%^Helgrath%^WHITE%^ - Children 200g, Youngin's 500g, Adults 750g. %^RESET%^\n %^BOLD%^%^WHITE%^3) %^BOLD%^%^RED%^Tenebrae%^WHITE%^ - Children 200g, Youngin's 500g, Adults 750g.%^RESET%^ \n %^BOLD%^%^WHITE%^4) %^BOLD%^%^RED%^Lodos%^WHITE%^ - Children 200g, Youngin's 500g, Adults 750g.%^RESET%^ \n %^BOLD%^%^WHITE%^5) %^BOLD%^%^RED%^Roston%^WHITE%^ - Children 200g, Youngin's 500g, Adults 750g.%^RESET%^ \n %^BOLD%^%^WHITE%^6) %^BOLD%^%^RED%^Citrin%^WHITE%^ - Children 200g, Youngin's 500g, Adults 750g.%^RESET%^ \n %^BOLD%^%^WHITE%^7) %^BOLD%^%^RED%^Desert%^WHITE%^ - Children 200g, Youngin's 500g, Adults 750g.%^RESET%^ \n \n %^BOLD%^%^WHITE%^Simply <%^RED%^coach to %^WHITE%^[desination]> %^WHITE%^to book a ticket!%^RESET%^", "stable" : "%^ORANGE%^The stable is filled with horses resting until they are needed.%^RESET%^", "corral" : "%^ORANGE%^There is a single carriage being pulled by a %^BOLD%^%^WHITE%^white horse%^RESET%^%^ORANGE%^.%^RESET%^", "carriage" : "%^ORANGE%^The carriage is being pulled by a %^BOLD%^%^WHITE%^white horse%^RESET%^%^ORANGE%^.%^RESET%^", "horse" : "%^BOLD%^%^WHITE%^The horse is very tall and muscular and is all white, with even whiter hair flowing down it's side.%^RESET%^" ]) );
    set_exits((["west" : GROOM "coach_entrance2"]));
}
void reset() {
    ::reset();
    if(!present("master"))
	new(GMOB "horse_master")->move(this_object());
}
