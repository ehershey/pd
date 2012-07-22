#include <std.h>
#include <amun.h>
#include <helgrath.h>
inherit ROOM;
void create() {
    ::create();
    set_properties((["light":3, "indoors":1, "no scry":1]));
    set_name("Last Saints Helgrath Subhall");
    set_short("Last SaintsHelgrath Subhall");
    set_long("%^BOLD%^%^WHITE%^This is the Last Saints subhall of Helgrath. Members can come here to stay away from the hustle and bustle of the main cities of just come here to chill.%^RESET%^"); 
    set_exits((["southwest" : ROOMS"wilndursquare"]));
}
void reset() {
    ::reset();
    if(!present("portal"))
	new(GUILDOBJ"portal.c")->move(this_object());
}
