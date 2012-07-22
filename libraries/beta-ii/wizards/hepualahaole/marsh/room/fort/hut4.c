#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 1]) );
    set_property("building",1);
    set_short("Sabai Fortress");
    set_long(
      "Inside the hut is quite spacious.  There are two thrones which "
      "the king and queen sits.  Outlining the hut is candles, that lights "
      "up the room, each candle placed in such a fashion that no shadows "
      "are casted."
    );
  
    set_items(([
        "hut" : "The outside decieves how big it is inside.",
        "thrones" : "Both are made of solid gold.",
        "candles" : "Placed in such a fashion that shadows do not form.",
        "mirage" : "This one is the real thing.",
    ]));
    set_listen("default", "Sounds of Peace and Tranquility.");
    set_exits( ([
"out" : FORT "fort11",
    ]) );
}
void reset() {
 ::reset();
   if (!present("isha")) {
      new(MOB"isha")->move(this_object());
   if (!present("adel"))
      new(MOB"adel")->move(this_object());
   if (!present("servant"))
      new(MOB"servant")->move(this_object());
      new(MOB"servant")->move(this_object());
    
  
    }
}
