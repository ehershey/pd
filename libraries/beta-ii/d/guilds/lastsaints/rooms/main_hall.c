#include <std.h>
#include <amun.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_properties((["light":2, "indoors":1, "no scry":1]));
    set_name("Last Saints");
    set_short("Last Saints");
    set_long("%^BOLD%^%^WHITE%^This is the Last Saints subhall of Tirun. Members can come here to stay away from the hustle and bustle of the main cities of just come here to chill.%^RESET%^"); 
    set_exits(([ "northwest" : GUILDROOM"portal_room.c"]));
}
void reset() {
    ::reset();
    if(!present("portal"))
	new(GUILDOBJ"portal.c")->move(this_object());
}
