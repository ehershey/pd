#include <std.h>
#include <helgrath.h>

inherit ROOM;

void create(){
    ::create();
    set_properties(([
	"light" : 2,
      ]));
    set_short("Mountain Pass");
    set_long("Just outside the city gates, golfball-sized chunks of sleet and hail rain down from the clouded sky. " );
    set_exits(([ "north": ROOMS "mountaint_s04.c",
	"east" : ROOMS "marketrd_wgate.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "Nothing can be heard over the deafening howl of the wind.");
}
