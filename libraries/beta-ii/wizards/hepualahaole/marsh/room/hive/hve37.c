#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "A crooked stairwell leading up, is at the end of this "
      "tunnel.  To the northwest, is the beginning of another "
      "set of long tunnels."
     
    );
    set_items(([
        "stairwell" : "The stairs were made in haste, there "
                      "is no handrail for support.",
        "tunnel" : "It is very dark.",
        "tunnels" : "There are too many to count.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"northwest" : HIVE "hve35",
"up" : NEST "est79",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
    }
}
