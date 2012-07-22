#include <std.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("test room");
        set_short("Combat Test Room");
        set_long("A room designed to test the new dynamic combat system. Please go easy on the poor room, it is fragile.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
	    ]));
	    set_listen("default", "You can hear nothing in this strange void.");
	    set_smell("default", "The air is stale.");
	    set_exits(([
			"square"		: "/d/nopk/tirun/square.c",
        ]));
        set_dynamic_combat(1);
        //new("/wizards/daboura/combat/range.c")->move(this_object());
        new("/wizards/daboura/combat/hare.c")->move(this_object());
        new("/wizards/daboura/combat/demon.c")->move(this_object());
        
}
