#include <std.h>
#include <vampq.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no bump" : 1, "light" : 2, "no scry" : 1, "outdoors" : 1, "night light" : 0 ]));
    set("short", "Outdoors");
    set_long("%^BOLD%^%^BLACK%^description..oh joy%^RESET%^");
    set_items((["vegetation" : "%^BOLD%^%^BLACK%^There is no vegetation in the area.%^RESET%^", "sun" : "%^BOLD%^%^YELLOW%^The sun is beating down on you as if trying to take your life away.%^RESET%^" ]));
    set_exits( ([ "northeast" : VR"g_11", "east" : VR"g_6", "west" : VR"g_4", "northwest" : VR"g_10" ]) );
}
