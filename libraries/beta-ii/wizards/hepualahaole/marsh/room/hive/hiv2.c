#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":1, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The path leading inward, is right up ahead to the "
      "north.  To the east,  there is a smaller path "
      "leading inside some bushes.  Torches lines the "
      "beach, and the foot path to the north."
     
    );
    set_items(([
        "path" : "There are two paths, one leading north "
                 "and one leading east into the bushes.",
        "bushes" : "It looks a little bit thorny, but it "
                   "is growing out of the rocky island.",
        "torches" : "It is all along the outside of the "
                    "beach, and two more torches light "
                    "the foot path up to the north.",
        "beach" : "It's not a sandy beach, it made of "
                  "smooth pebbles.",
        "rock" : "It is in the middle of earth, not "
                 "a very common type of rock.",
        "pebbles" : "It is smoothed over from the years "
                    "of water running over them.",
  
    ]));
    set_exits( ([
"east" : HIVE "hiv3",
"west" : HIVE "hiv",
"north" : HIVE "hiv5",
    ])  );
}
