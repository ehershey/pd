#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "There's a rock wall up ahead.  The tunnel diggers decided "
      "it was best to turn around and go another direction instead "
      "of going through it."
    );
    set_items(([
        "tunnel" : "It's a dead end here.",
        "rock" : "It's made out of granite.",
        "wall" : "It looks very thick, no sense going in that direction."
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"northeast" : HIVE "hive7",
    ])  );
}
