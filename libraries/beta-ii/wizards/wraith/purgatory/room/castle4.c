#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("castle4");
     set_short("The Purgatory Castle");
     set_long("%^CYAN%^Bustling servants glide through this small hallway running "
"%^CYAN%^errands for their Lords or Ladies.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
 set_exits( (["northwest" : ROOMS"castle10",
              "southeast" : ROOMS"castle1"]) );


}
