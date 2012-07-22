#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Yull Boulevard");
    set_long("Towering walls of the adjacent buildings line the sides of this well traveled "
      "road. Flies buzz vehemently around a pile of filth in the gutter. Just to the north lies the "
      "courtyard of the Great Temple of Helgrath. " );
    set_exits( ([ "north" : ROOMS "temple_courtyard.c",
      "south" : ROOMS "yullblvd_n04.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The buzz of small insects can be heard.");

}
