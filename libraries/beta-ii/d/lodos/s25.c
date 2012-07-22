#include <std.h>
#include <lodos.h>
inherit ROOM;
void create() {
    ::create();
    set_name("Lodos Meadow");
    set_properties((["light":2,"nightlight":3]));
    set_short("secret building");   
    set_long("");
    set_items((["snow"   : "A very deep white snow",
	"dirt"  : "A light brown mixture"])); 
    set_exits((["south" : ROOMS "s24", "east" : ROOMS "s27", "west" : ROOMS "s23" ]));
} 
