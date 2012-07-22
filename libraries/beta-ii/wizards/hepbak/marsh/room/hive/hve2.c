#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "A dead end.  The solid rock must have stopped the "
      "raknids from digging." 
     
    );
    set_items(([
        "rock" : "It is solid, raknids are avoiding it.",
        "darkness" : "You can't see anything in front of "
                     "your face."
  
    ]));
    set_listen("default", "A waterfall can be heard.");
    set_exits( ([
"south" : HIVE "hve4",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")) {
      new(MOB"rpick")->move(this_object());
      new(MOB"rpick")->move(this_object());
     if (!present("raknid")) 
      new(MOB"rshovel")->move(this_object());
    }
}
