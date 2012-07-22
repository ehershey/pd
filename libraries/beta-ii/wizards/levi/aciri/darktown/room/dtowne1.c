#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^This is a road leading east and west.  Many houses fill this lifeless town and they are all shut up with no trace of light except on the occasional street lamp.  It is rather difficult to see anything past about 10 feet away, as the darkness is as much a part of this town as air.  ");
   
    set_night_long("%^BOLD%^%^BLACK%^This is a road leading east and west.  Many houses fill this lifeless town and they are all shut up with no trace of light except on the occasional street lamp.  It is rather difficult to see anything past about 10 feet away, as the darkness is as much a part of this town as air.  ");
    
    set_items(([
        "town" : "Shadows are cast everywhere from the dim lights and it seems t
hat
just 10 feet away from you in all directions there is darkness.",
        "streets" : "Cold wind rushes through the streets and whistles a tune.
",
        "mansion" : "The mansion could be considered a castle, if not for that
eerie transylvanian look to it.",                  
        "tower" : "A jet black tower, darker than the night itself, extends up
into the sky.  For some reason there are no stars out.",
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "dtown1.c",
        "east" : ROOMS "dtowne2.c",
                
    ]));
}
