#include <locations.h>
#include <std.h>
#include "defs.h"

inherit ROOM;

void create()
{
    ::create();

    set_night_long("Long night descrip.\n");
    set_day_long("Long day descrip.\n");

    set_exits( ([
                  "northwest" : BEACH"/room092",
                  "south" : BEACH"/room090",
               ]) );
}
