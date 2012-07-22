#include <std.h>
#include <guild.h>
#include "ether.h"
inherit ETHERSTD;


void create() {
	::create();

	set_short("%^BOLD%^%^ORANGE%^Ethereal Tower: Level 2%^RESET%^");
	set_long(
		"%^BOLD%^%^ORANGE%^Ethereal Tower: Level 2%^RESET%^\n"
		"%^RESET%^%^ORANGE%^The second level of the tower is home to all the shops "
		"of Ethereal. The white marble floors have swirls of gold flecks in them. The "
		"walls and pilasters are engraved with golden celtic motifs. Millions of tiny "
		"gold particles float near the ceiling of the room, which seem to emit a stunning display of light.%^RESET%^"
	);
	set_exits( ([
		"north" : ROOMS "2-2.c",
		"south" : ROOMS "2-3.c",
		"east" : ROOMS "2-4.c",
		"west" : ROOMS "2-5.c",
		"up" : ROOMS "3-1.c",
		"down" : ROOMS "1-1.c",
	]) );


	set_items( ([
		"floors" : "A beautiful %^BOLD%^white%^RESET%^ and %^ORANGE%^gold%^RESET%^ marble floor.",
		"walls" : "The walls are engraved with an exquisite celtic design.",
		"pilasters" : "The pilasters are engraved with an exquisite celtic design.",
		"particles" : "%^RESET%^%^ORANGE%^Millions of tiny gold particles emit light onto the room.%^RESET%^"
	]) );

	set_smell("default", "The scent of aromatic blossoms intertwine with stench of blood.");
	set_listen("default", "Faint gaelic chanting drifts into the room from the marble halls.");
}

