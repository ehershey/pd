#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Yull Boulevard");
    set_long("Yull Boulevard is a highly traveled road. The northern path leads to the "
      "Temple of Helgrath, while far to the south, lie the Gates of Yaenel. Huge, frozen "
      "tapestries hang down from the aged stone walls of the west building, depicting "
      "an epic battle on the temple grounds. " );
    set_exits( ([ "north" : ROOMS "yullblvd_n03.c",
      "south" : ROOMS "yullblvd_n01.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The sounds of local gossip linger in the air.");

}
