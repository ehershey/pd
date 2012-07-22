#include <std.h>
#include <guild.h>
#include "ether.h"
inherit ETHERSTD;

void create() {
        ::create();

        set_short("%^BOLD%^%^ORANGE%^The Cheat's Weapon Shop%^RESET%^");
        set_long(
		"%^BOLD%^%^ORANGE%^The Cheat's Weapon Shop%^RESET%^\n"
		"%^RESET%^%^ORANGE%^The walls of this shop are adorned with archaic weaponry. "
		"Prodigious displays of swords sit thoughtfully in glass cases. A strange yellow "
		"creature neurotically paces about the room, muttering to himself in an "
		"unknown tongue.%^RESET%^" 
        );
        set_exits( ([
                "west" : ROOMS "2-1.c",
        ]) );


        set_items( ([
		"walls" : "Granite walls lined with weapons.",
		"cases" : "Glass cases with ancient swords on display."
        ]) );

        set_smell("default", "The strong odor of metal lingers in the air.");
        set_listen("default", "Faint gaelic chanting is accompanied with the clashing of weapons.");
}
void reset() {
if (!present("cheat")) {
        new(MOB"cheat")->move(this_object());

}
}
