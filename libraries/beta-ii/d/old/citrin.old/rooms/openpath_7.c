//Coded by Whit

#include <citrin.h>
#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Citrin Forest");
    set_properties( (["light" : 3, "night light" : 2]) );
    set_property("forest", 1);
    set_listen("default", "The sounds of creepers can be heard.");
    set_long("The shade of the oak still shades this small area making this a dark area.  Many small animals live here in darkness feeding upon whoever is stupid enough to come this far.");
    set_exits( (["northwest" : ROOMS+"openpath_5.c"
             ,"south" : ROOMS+"unknown"
             ,"east" : ROOMS+"openpath_8.c"
              ]) );
}

void reset() {
::reset();
if (!present("wild dog"))
new(MON+"dog.c")->move(this_object());
}
