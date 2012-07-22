#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "It is so dark in here, the only light visable, is "
      "a tiny yellow ball across the river on the right. "
      "Echoing sounds from the left signals there is a "
      "cave nearby.  The path continues south."
     
    );
    set_items(([
        "river" : "It is to the right of you, but it "
                  "doesn't look very inviting.",
        "light" : "It's across a very wide river, a "
                  "tiny speck of fire.",
        "cave" : "It is to your left",
        "path" : "Your not in a tunnel anymore, you "
                 "are on the side of the river.",
        "slope" : "It is up ahead to the south.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"north" : HIVE "hve10",
"south" : HIVE "hv17",
"cave" : HIVE "hve15",
    ])  );
}
