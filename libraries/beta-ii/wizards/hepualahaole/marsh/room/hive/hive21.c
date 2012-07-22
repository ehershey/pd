#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "One lonely torch lights up this intersection of the tunnel. "
     
    );
    set_items(([
        "tunnel" : "It runs in a diagonal direction, and not used recently",
        "torch" : "It's attached to the wall, not really lighting anything",
        "intersection" : "It has two southern routes and one northen route.",
        "wall" : "Made up of sand and a sticky substance",
        "sand" : "It's brownish in color.",
        "substance" : "You can't be sure what exactly it is.",
 
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"northeast" : HIVE "hive26",
"southwest" : HIVE "hive12",
"southeast" : HIVE "hive13",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
    }
}
