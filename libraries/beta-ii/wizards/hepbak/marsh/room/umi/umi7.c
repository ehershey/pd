#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Umi Town");
    set_long(
      "The town sits in a %^GREEN%^garden%^RESET%^. "
      "Small buildings pop up everywhere, and there is a path that leads to "
      "each of the buildings.   "
    );
    set_items(([
        "town" : "Unlike the one up on land, this is very modern looking.",
        "buildings" : "Are very small looking, but something tells you that
isn'
t so.",
        "garden" : "Very pretty, it is lush and full of life.",
        "path" : "Made of the finest polish coral around.",
        "coral" : "Pretty, its pink and white, and shimmers in the light.",
        "up" : "The top of the air-bubble can be seen.",
    ]));
    set_exits( ([
"west" :  UMI "umi6",
"east" : UMI "umi8",
"north" : UMI "umi11",
"south" : UMI "umi5",
    ]) );
}
