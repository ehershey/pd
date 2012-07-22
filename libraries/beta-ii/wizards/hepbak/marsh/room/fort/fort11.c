#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("desert",1);
    set_short("Sabai Fortress");
    set_long(
      "This island is quite small, it is just big enough to hold a "
      "hut and a statue.  There are four bridges that leads away from "
      "the island."
    );
  
    set_items(([
        "island" : "Big enough for a hut and a statue.",
        "bridge" : "There are four of them that leads away from the island.",
        "statue" : "It is to the east of here.",
        "mirage" : "This one is the real thing.",
    ]));
    set_listen("default", "Sounds of Peace and Tranquility.");
    set_exits( ([
"east" : FORT "fort12",
"enter" : FORT "hut4",
    ]) );
}
void reset() {
 ::reset();
   if (!present("hut", this_object()))
     new( ITEMS "ahut.c" )->move(this_object());
   if (!present("bodyguard")) {
      new(MOB"bodyguard")->move(this_object());
      new(MOB"bodyguard")->move(this_object());
  
    }
}
