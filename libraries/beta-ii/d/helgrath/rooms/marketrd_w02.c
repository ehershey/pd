#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Market Road");
    set_long("Deep snow covers the dark stone cobbles of Market road. Slaves of the local "
      "temple labor to clear the streets as they are whipped and sworn at continuously by "
      "their masters. " );
    set_exits( ([ "west" : ROOMS "marketrd_w03.c",
      "east" : ROOMS "marketrd_w01.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The sounds of local gossip fill the air.");

}
