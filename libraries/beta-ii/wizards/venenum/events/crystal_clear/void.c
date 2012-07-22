#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Void");
    set_long("A floating void. This functions as a magical safe house.");
    set_listen("default", "There are no sounds here.");
    set_smell("default", "There are no smells here.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"out" : "/d/nopk/tirun/square.c",
      ]));

    set_pre_exit_functions( ({"portal"}), ({"sort"}) );


}

int sort()
{
    write("You feel disorientated.");
    if (this_player()->query_guild() == "illuminati")
    {
	this_player()->move("/wizards/venenum/events/crystal_clear/rooms/cc1.c");
    }
    else
    {
	this_player()->move("/wizards/venenum/events/crystal_clear_unguild/rooms/cc1.c");
    }
}

