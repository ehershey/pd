#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Neverending Tundra");
    set_long("Just to the north lie the southern gates of the inner city. Their massive stone "
      "walls boast impenetrable iron gates, fortified by huge, menacing guard towers standing "
      "vigil over the great, southern wall of the city. To the south, a vast tundra stretches off to the horizon. " );
    set_exits( ([ "gate" : ROOMS "yullblvd_sgate.c",
      "south" : ROOMS "tundra_path02.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A slight breeze whistles through the gates.");

}
