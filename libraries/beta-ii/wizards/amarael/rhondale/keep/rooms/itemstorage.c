#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Illuminati Item Supply Room");
    set_long("The Zartha Item  Supply Room. Get outta here biatch!");
    set_exits((["out" : KEEPROOM"itemshop.c"]));
}
