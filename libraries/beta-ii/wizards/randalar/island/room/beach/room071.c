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
                  "south" : BEACH"/room070",
                  "northwest" : BEACH"/room072",
               ]) );
}
