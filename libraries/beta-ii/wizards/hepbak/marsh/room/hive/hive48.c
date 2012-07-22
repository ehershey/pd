#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Raknid's Nest");
    set_long(
      "A dark tunnel. Secret passage. "
         
    );
    set_items(([
        "tunnel" : "One of many in this place.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"east" : HIVE "hive49",
"south" : HIVE "hive45",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")){ 
    new(MOB"rshovel")->move(this_object());
    }
}
