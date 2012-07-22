#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The trail leads east and west in the bushes."
     
    );
    set_items(([
        "bushes" : "It is a big green thorny plant.",
        "trail" : "Another name for foot path.",
  
    ]));
    set_exits( ([
"east" : HIVE "hiv4",
"west" : HIVE "hiv2",
    ])  );
}
