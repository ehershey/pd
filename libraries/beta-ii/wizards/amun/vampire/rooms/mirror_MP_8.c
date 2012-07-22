#include <std.h>
#include <vampq.h>
inherit ROOM;
string make_a_long();
void create() {
    ::create();
    set_properties(([  "no bump" : 1, "light" : 2, "no scry" : 1, "indoors" : 1 ]));
    set("short", "Hall of Mirrors");
    set_long( (: make_a_long :) );
    set_items((["mirrors" : "%^BOLD%^%^WHITE%^Mirrors line the walls making it hard to find the exits.%^RESET%^", "reflection" : "%^BOLD%^%^WHITE%^You look at yourself in the mirror.%^RESET%^" ]));
    set_exits( ([ "west" : VR"mirror_MP_7", "southwest" : VR"mirror_MP_4", "south" : VR"mirror_MP_5", "southeast" : VR"mirror_MP_6", "east" : VR"mirror_MP_9", "northeast" : VR"mirror_MP_12", "north" : VR"mirror_MP_11", "northwest" : VR"mirror_MP_10" ]) );
    set_invis_exits( ({"west", "southeast", "south", "east", "north", "northwest"}) );
    skip_obvious();
}
string make_a_long() {
    return "%^BOLD%^%^BLACK%^The room is full of mirrors. All that can be seen is your reflection, making it hard to move around the area. A few exits can be seen, but there are so many mirrors that it is hard to tell if these are the only exits.\n\n\n%^BOLD%^%^WHITE%^The reflection of, "+this_player()->query_cap_name()+" is here.%^RESET%^";
}
