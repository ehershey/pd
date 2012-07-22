#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Market Road");
    set_long("The dark stone of the cobbled road leads away into the distance. "
      "The narrow path is dwarfed by towering buildings to either side. To the north "
      "is the armourer's shop, and to the south lies the mages hall. " );
    set_exits( ([ "west" : ROOMS "wilndursquare_em",
      "north" : ROOMS "shop_armour.c",
      "east" : ROOMS "marketrd_e02.c",
      "south" : ROOMS "shop_mage.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The wind whistles softly through the buildings.");

}
