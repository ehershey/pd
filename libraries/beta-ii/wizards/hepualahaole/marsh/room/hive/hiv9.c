#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":1, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "Outside a pub called, %^BOLD%^YELLOW%^The Local Bar%^RESET%^.  "
      "The pub itself looks to be completed, but there is a huge "
      "construction mess right behind it."
     
    );
    set_items(([
        "pub" : "It's a stone hut, right in front of a huge junk "
                "pile.",
        "junk" : "No idea what it could be at this point.",
        "hut" : "It's made of the same stone that is on the path.  "
                "Rock from the river bed.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"northwest" : HIVE "hiv12",
"southeast" : HIVE "hiv6",
    ])  );
}
