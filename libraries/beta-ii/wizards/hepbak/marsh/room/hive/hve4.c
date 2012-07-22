#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "Walking along the side of the river in total darkness." 
     
    );
    set_items(([
        "river" : "It is very wide.",
        "darkness" : "You can't see anything in front of "
                     "your face."
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"south" : HIVE "hve10",
"north" : HIVE "hve2",
    ])  );
}
