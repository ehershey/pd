#include <std.h>
#include <vampq.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no bump" : 1, "light" : 2, "no scry" : 1, "indoors" : 1 ]));
    set("short", "Haunted Mansion");
    set("long", "%^BOLD%^%^BLACK%^It's haunted and it's scary!%^RESET%^");
    set_items((["nothing" : "%^BOLD%^%^BLACK%^It's nothing!%^RESET%^" ]));
    set_exits( ([ "west" : VR"haunted_MP_7", "southwest" : VR"haunted_MP_4", "south" : VR"haunted_MP_5", "southeast" : VR"haunted_MP_6", "east" : VR"haunted_MP_9", "northeast" : VR"haunted_MP_12", "north" : VR"haunted_MP_11", "northwest" : VR"haunted_MP_10" ]) );
}
