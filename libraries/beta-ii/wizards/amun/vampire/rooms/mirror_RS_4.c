#include <std.h>
#include <vampq.h>
inherit ROOM;
string make_a_long();
void create() {
    ::create();
    set_properties(([  "no bump" : 1, "light" : 2, "no scry" : 1, "indoors" : 1 ]));
    set("short", "Hall of Mirrors");
    set_long( (: make_a_long :) );
    set_items((["mirrors" : "%^BOLD%^%^WHITE%^Mirrors line the walls making it hard to find the exits.%^RESET%^","reflection" : "%^BOLD%^%^WHITE%^You look at yourself in the mirror.%^RESET%^" ]));
    set_exits( ([ "southwest" : VR"mirror_RS_2", "northwest" : VR"mirror_RS_6", "south" : VR"mirror_RS_3" ]) );
    set_invis_exits( ({"northwest", "southwest", "south"}) );
    skip_obvious();
}
string make_a_long() {
    return "%^BOLD%^%^BLACK%^The room is full of mirrors. All that can be seen is your reflection, making it hard to move around the area. \n\n\n%^BOLD%^%^WHITE%^The reflection of, "+this_player()->query_cap_name()+" is here.%^RESET%^";
}
