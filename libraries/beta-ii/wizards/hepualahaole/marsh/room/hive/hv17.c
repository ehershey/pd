#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "A sharp incline heading upwards into darkness." 
     
    );
    set_items(([
        "incline" : "It is very steep.",
        "darkness" : "You can't see anything in front of "
                     "your face."
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"down" : HIVE "hve14",
"up" : HIVE "hve28",
    ])  );
}
