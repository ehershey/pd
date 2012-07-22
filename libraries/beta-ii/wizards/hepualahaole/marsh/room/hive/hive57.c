#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "What a stunning view of the floating city. "
      "There is no bridges connecting to the island "
      "in the middle of the river.  The current looks "
      "very strong, so swimming across is out.  A strange "
      "sight of a golden tree stands proudly out in the "
      "darkness across the way.  It doesn't seem to be "
      "on the island."
         
    );
    set_items(([
        "city" : "It's in the middle of the river.",
        "island" : "A city surrounded by torches is on it.",
        "river" : "The current is too strong to swim.",
        "tree" : "It is a %^BOLD%^YELLOW%^golden %^RESET%^"
                 "tree, and it is sitting out on a ledge.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"south" : HIVE "hive43",
    ])  );
}
