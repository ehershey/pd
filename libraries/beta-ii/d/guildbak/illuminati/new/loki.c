#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_properties(([
"light" : 1,
"indoors" : 0
]));
set_short("loki's room");
set_long("A large room, with numerous scrolls lining the far side of the wall "
"and two large parchments sit on the wall on either side of the door. In front "
"of the far wall is a small altar, lined with gold. In the corner of the room "
"sits a large wooden arch-way laced with vines. Between the wooden arch-way sits "
"a small red pillow. There are no windows.");
set_exits(([
"east" : ROOMS"illuminati/new/floor5.c",
]));
set_items(([
"right parchment" : " Loki - Born in a time long forgot into a world of peace "
"and harmony, around for the creation and the world and all apon it,  bestowed "
"with greaty powers and bound by duty. He saw the era when demons walked the "
"earth, and fought in the great battles. Set apon the earth the protect and "
"bring about peace. Apart the Order of Angels. Strong believe in the powers of "
"the ZI, and worshipper of the Lord our God.",
"left parchment" : " A letter of the oaths taken when serving God.",
"pillow" : " A small red silk pillow, the sides are laced with gold and silver stiching.",
]));
set_smell("default", "A soft aroma fills the air.");
}
