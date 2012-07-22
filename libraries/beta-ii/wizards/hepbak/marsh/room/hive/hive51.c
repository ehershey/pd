#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "Inside a dark tunnel. "
         
    );
    set_items(([
        "tunnel" : "One of many in this place.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"south" : HIVE "hive46",
"west" : HIVE "hive50",
    ])  );
}
void reset() {
 ::reset();
   if (!present("raknid")) {
      new(MOB"rguard")->move(this_object());
 
    }
}
