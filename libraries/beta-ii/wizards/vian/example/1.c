#include <std.h>
//#include <diran.h>

inherit "/wizards/vian/example/zone";

void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
set_short("a mountain pass");
    set_long( desc_long() );
//set_exits(([ "north" : ROOMS"mountainpath/2",
//"south" : ROOMS"tundra/92",
//]));
    set_items( ([

]) );
    set_smell("default",  "The dry arctic wind carries little scent.");
    set_listen("default", "The sound of animals and humanoids fighting can be heard throughout the mountain pass.");

set_items(desc_items());

}

