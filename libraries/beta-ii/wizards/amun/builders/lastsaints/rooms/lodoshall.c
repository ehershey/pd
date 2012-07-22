#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties((["light":3, "indoors":1, "no scry":1]));
    set_name("Last Saints Lodos Subhall");
    set_short("Last Saints Lodos Subhall");
    set_long("%^BOLD%^%^WHITE%^This is the Last Saints subhall of Lodos. Members can come here to stay away from the hustle and bustle of the main cities of just come here to chill.%^RESET%^");
    set_exits((["northwest" : "/d/lodos/square"]));
}
void reset() {
    ::reset();
    if(!present("portal"))
	new(GUILDOBJ"portal.c")->move(this_object());
}
