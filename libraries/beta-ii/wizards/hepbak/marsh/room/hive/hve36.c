#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "On a very steep cliff.  Looking down, nothing "
      "can be seen, but looking across the vast darkness, the "
      "floating city can be seen again.  There still seems to "
      "be no way into the city."
     
    );
    set_items(([
        "tunnel" : "It is to the east.",
        "cliff" : "It almost makes you dizzy looking down.",
        "city" : "It is outlined with torches, taunting you.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"south" : HIVE "hve39",
"north" : HIVE "hve33",
    ])  );
}
