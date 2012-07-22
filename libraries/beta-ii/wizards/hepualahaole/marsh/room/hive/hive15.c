#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "Tunnel digging in progress here, there is a bowl of "
      "sticky substance next to a pile of sand.  It's looks like "
      "a slow process, but it is necessary to build a strong nest."
         
    );
    set_items(([
        "bowl" : "There is a sticky substance inside it.",
        "sticky substance" : "Regurgitated sand.",
        "substance" : "Regurgitated sand.",
        "pile" : "It's unwanted sand waiting to be removed.",
        "sand" : "Not a good choice for nest building, but "
                 "regurgitated sand is stronger then dried mud.",
        "nest" : "It's the Raknid's Home.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"west" : HIVE "hive14",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")) {
      new(MOB"rpick")->move(this_object());
      new(MOB"rpick")->move(this_object());
     if (!present("raknid")) 
      new(MOB"rshovel")->move(this_object());
      new(MOB"rshovel")->move(this_object());
    }
}
