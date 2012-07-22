#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Market Road");
    set_long("Dark shadows from the massive west gates cause the chill of the frigid "
      "mountain air to become even more bone-chilling. Various citizens hurry about "
      "their daily routines, darting in and out of buildings up and down the road. " );
    set_exits( ([ "west" : ROOMS "marketrd_w05.c",
      "east" : ROOMS "marketrd_w03.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A firm breeze blows through the streets.");

}
