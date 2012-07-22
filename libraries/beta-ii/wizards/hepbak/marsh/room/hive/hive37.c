#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The tunnel splits off in three directions.  A very dark looking "
      "tunnel leads the way north.  In the west direction, there "
     
      "appears to be a bridge.  To the south is the guard's station."
    );
    set_items(([
        "tunnel" : "It splits off into three directions.",
        "station" : "It's in the southern direction.",
        "bridge" : "Can't see much of it standing here.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"south" : HIVE "hive27",
"northeast" : HIVE "hive44",
"west" : HIVE "hive36",
    ])  );
}
