#include <std.h>
#include <guild.h>
#include "ether.h"
inherit ETHERSTD;

void create() {
        ::create();

        set_short("%^BOLD%^%^ORANGE%^StrongBad's Armour Shop%^RESET%^");
        set_long(
		"%^BOLD%^%^ORANGE%^StrongBad's Armour Shop%^RESET%^\n"
		"%^RESET%^%^ORANGE%^Tall columns hold pieces of well-made armour in many "
		"different shapes and sizes. Small clothe items hang neatly on hooks about "
		"the shop. A tiny strange looking man sits on a wooden stool in front of a "
		"large counter waiting to be of service.%^RESET%^"
        );
        set_exits( ([
                "east" : ROOMS "2-1.c",
        ]) );


        set_items( ([
		"columns" : "Large granite columns hold pieces of metal armour.",
		"hooks" : "Tiny hooks hold pieces of clothe items."
        ]) );

        set_smell("default", "The scent of blossoms drifts in from the main room.");
        set_listen("default", "Faint gaelic chanting is accompanied with the clashing of armour.");
}
void reset() {
if (!present("strongbad")) {
	new(MOB"strongbad")->move(this_object());
}
}

