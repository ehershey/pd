#include <std.h>
#include <guild.h>
#include "ether.h"
inherit ETHERSTD;


void create() {
	::create();

	set_short("%^RESET%^%^CYAN%^Ethereal Prayer Room%^RESET%^");
	set_long(
		"%^RESET%^%^CYAN%^Ethereal Prayer Room%^RESET%^\n"
		"%^BOLD%^%^WHITE%^A faint mist dances about the white marble floor. Luminous light floods into "
		"the room from an obscure source. Tiny orbs of light playfully shroud a large stone altar, which "
		"stands alone in the center of the room, as if it yearns to be prayed to.%^RESET%^"
	);
	set_exits( ([
		"east" : ROOMS "1-1.c",
	]) );


	set_items( ([
		"mist" : "A faint mist.",
		"floor" : "%^BOLD%^%^WHITE%^A beautiful white marble floor.%^RESET%^",
		"light" : "%^BOLD%^%^WHITE%^Bright light that fills the room with a holy glow.%^RESET%^",
		"orbs" : "%^RESET%^%^CYAN%^Tiny orbs of light which surround a large stone altar.%^RESET%^",
		"altar" : "%^BOLD%^%^WHITE%^A large altar made from white stone. It yearns to have members of Ethereal pray.%^RESET%^"
	]) );

	set_smell("default", "The scent of aromatic blossoms intertwine with stench of blood.");
	set_listen("default", "Faint gaelic chanting drifts into the room from the marble halls.");
}
void init() {
    ::init();
    add_action("cmd_pray", "pray");
}

int cmd_pray(string str)
{
    write("Your wounds are healed.\n");
    this_player()->add_hp(this_player()->query_max_hp());
    this_player()->add_sp(this_player()->query_max_sp());
    this_player()->add_mp(this_player()->query_max_mp()); 
    return 1;
}
