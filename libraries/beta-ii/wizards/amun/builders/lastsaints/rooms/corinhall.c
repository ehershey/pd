#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties((["light":3, "indoors":1, "no scry":1]));
    set_name("Last Saints Purgatory Subhall");
    set_short("Last Saints Purgatory Subhall");
    set_long("%^BOLD%^%^WHITE%^This is the Last Saints subhall of Purgatory. Members can come here to stay away from the hustle and bustle of the main cities of just come here to chill.%^RESET%^"); 
    set_exits((["northeast" : "/d/freepk/purgatory/room/purgatorysquare.c"]));
}
void reset() {
    ::reset();
    if(!present("portal"))
	new(GUILDOBJ"portal.c")->move(this_object());
}
