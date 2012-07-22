#include <std.h>
#include <illuminati.h>

inherit ILOBJ"homeroom.c";

void create() {
    ::create();
    set_properties(([ "no scry" : 1, "indoors" : 1, "light" : 3 ]));
    set_short("Blits' Room");
    set_long("%^BOLD%^BLACK%^As you enter this room, you notice the great height "
      "of it.  The stone walls are covered in%^RESET%^ %^BOLD%^sticky "
      "white%^RESET%^ %^BOLD%^BLACK%^Raknid webbing acting as a ladder for Blits "
      "to get to his %^BOLD%^cocoon-like%^RESET%^ %^BOLD%^BLACK%^bed. Embedded "
      "into the webbed framework are large stone shelves with assorted rare items " 
      "that Blits has collected on his journeys throughout the realm.%^RESET%^");





    set_exits(([
	"down"  : ILROOM"newhall.c"
      ]));
    set_smell("default", "There is a musky smell to the room.");
    set_listen("default", "The room echoes.");


}
