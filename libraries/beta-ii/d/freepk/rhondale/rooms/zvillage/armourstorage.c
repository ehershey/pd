#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Rhondale Item/Armour Storage");
    set_long("Rhondale Item/Armour Storage.\n\nADMINS ONLY!");
    set_exits((["out" : KEEPROOM"zvillage/armour.c"]));
}
