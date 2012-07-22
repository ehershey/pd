#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 3, "indoors" : 1]) );
set_property("building",1);
    set_short("inside a large tower");
    set_long(
      "The inside of the tower is majestic looking.  The floors are covered with rugs that "
      "look as though they belong in a castle, the large chandelier hanging in the center of "
      "the room brigtens up the whole first floor, and the furniture is well upholstered.  "
      "The ceiling stands about 12 feet high, and is well decorated with paintings of a wise "
      "looking man slaying dragons with his mind. "
    );
    set_items(([
        "ceiling" : "They stand 12 feet high and are beautifully decorated.",
        "furniture" : "The furniture looks so comfortable, you could fall asleep in it.",
	"floor" : "The rugs on the floor are royally embroidered.",
	"chandelier" : "It looks to be made out of diamond and never ending candles.",
    ]));
   set_exits( ([ 
        "out" : ROOMS"room16.c",
        "north" : ROOMS"tower2.c",
    ]) );
}
