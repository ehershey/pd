#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "A dark tunnel. "
         
    );
    set_items(([
        "tunnel" : "One of many in this place.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"northeast" : NEST "est47",
"northwest" : NEST "est46",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")){ 
    new(MOB"rshovel")->move(this_object());
     if (!present("raknid")) 
    new(MOB"rpick")->move(this_object());
    }
}
