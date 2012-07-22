#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 0, "indoors" : 1]) );
set_property("cave",1);
    set_short("inside a dark cave");
    set_long(
      "Inside the cave, the temperature is quite comfortable.  The stone walls "
      "are drawn to your attention.  They harbor strange markings that look ancient. "
      "A pile of rubble sits in the corner.");
    set_items(([
        "markings" : "Ancient symbols that you can't make out the meaning of.",
        "walls" : "The walls have strange markings on them.",
        "pile" : "It's a pile of rubble.",
        "rubble" : "It's a pile of rubble.",
    ]));
   set_exits( ([ 
        "west" : ROOMS"cave1.c",
        "east" : ROOMS"cave7.c",
    ]) );
}
void reset() {
    set_search("rubble", (: this_object(), "rubble_searching" :));
}

void rubble_searching() {
    message("my_action", "After searching through all the rubble "
      "you find a giant %^BOLD%^%^GREEN%^emerald%^RESET%^!", this_player());
    message("other_action", this_player()->query_cap_name()+" finds "
      "a a giant %^BOLD%^%^GREEN%^emerald%^RESET%^ in the rubble!", this_object(), ({ this_player() }));
    new(OBJ"emerald")->move(this_object());
    remove_search("rubble");
}
