#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Illuminati Weapon Supply Room");
    set_long("The Zartha Weapon Supply Room. Get outta here biatch!");
    set_exits((["out" : KEEPROOM"weaponshop.c"]));
}
