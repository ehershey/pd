#include <std.h>
#include <amun.h>
#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties((["light":3, "indoors":1, "no scry":1]));
    set_name("Last Saints Tirun Subhall");
    set_short("Last Saints Tirun Subhall");
    set_long("%^BOLD%^%^WHITE%^This is the Last Saints subhall of Tirun. Members can come here to stay away from the hustle and bustle of the main cities of just come here to chill.%^RESET%^"); 
    set_exits((["south" : "/d/nopk/standard/outlands/fork.c"]));
}
void reset() {
    ::reset();
    if(!present("portal"))
	new(GUILDOBJ"portal.c")->move(this_object());
}
