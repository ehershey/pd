#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Rhondale Weapon Storage");
    set_long("Rhondale Weapon Storage\n\nADMINS ONLY!");
    set_exits((["out" : KEEPROOM"zvillage/weapon.c"]));
}
