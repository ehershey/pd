#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "It is so dark in here, the only light visable, is "
      "a tiny yellow ball across the river on the left. "
      "Echoing sounds from the right signals there is a "
      "cave nearby.  The path continues to the north."
     
    );
    set_items(([
        "river" : "It is to the left of you, but it "
                  "doesn't look very inviting.",
        "light" : "It's across a very wide river, a "
                  "tiny speck of fire.",
        "cave" : "It is to your right",
        "path" : "Your not in a tunnel anymore, you "
                 "are on the side of the river.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"north" : HIVE "hve10",
"south" : HIVE "hve17",
"cave" : HIVE "hve15",
    ])  );
}
