#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Market Road");
    set_long("The dark stone of Market Road leads away into the distance. To the east "
      "is the town square and far to the west lie the Gates of the Sun." );
    set_exits( ([ "west" : ROOMS "marketrd_w02.c",
      "east" : ROOMS "wilndursquare_wm",
    ]) );
    remove_exit("north");
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The sounds of local gossip fill the air.");

}
