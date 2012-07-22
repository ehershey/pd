#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("desert",1);
    set_short("Sabai Fortress");
    set_long(
      "The bridge is narrow except for the path around the statue.  "
      "Looking down into the water, there are water-lilies and other "
      "water-based plant life.  It seems that each was placed in a certain "
      "pattern which serves harmony with nature."
    );
    set_items(([
        "bridge" : "It is long and narrow except for the path around the
statue.",
        "water" : "Crystal clear, and has water-based plant life.",
        "plant" : "Plants that are situated in such a fashion that creates
harmony.",
        "water-lilies" : "They consist of a floating green leaf and a white or
pink flower.",
        "path" : "Around the statue it gets bigger so there is enough room for
kneeling and praying",
 
    ]));
    set_listen("default", "Sounds of Peace and Tranquility.");
    set_exits( ([
"northwest" : FORT "fort12",
"southeast" : FORT "fort5",
    ]) );
}
void reset() {
 ::reset();
   if (!present("statue", this_object()))
     new( ITEMS "wahailo.c" )->move(this_object());
}
