#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The tunnel comes to an end here.  There seems to be no apparent reason "
      "why it ended here, it just did. "
     
    );
    set_items(([
        "tunnel" : "It just ends.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"southwest" : HIVE "hive55",
    ])  );
}
