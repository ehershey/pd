#include <std.h>
#include <diran.h>

inherit ROOMS"tundra/zone";

void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
    set_short( "a snowy tundra" );
    set_long( desc_long() );
set_exits(([ "south" : ROOMS"tundra/89",
"east" : ROOMS"tundra/95",
"west" : ROOMS"tundra/93",]));
    set_items( ([

]) );
    set_smell("default",  "The dry arctic wind carries little scent.");
    set_listen("default", "The sound of animals and humanoids fighting can be heard throughout the tundra.");

set_items(desc_items());


}