#include <std.h>
#include <marsh.h>
inherit BREEZE;
void create() {
::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "There's a bridge to the east, and westward there seems to be another "
      "tunnel project going on. "
     
    );
    set_items(([
        "tunnel" : "It runs in a diagonal direction, and not used recently.",
        "bridge" : "It crosses over a deep ravine.",
        "ravine" : "If you listen carefully, you can hear trickling water.",
        "north" : "A black force field blocks your view north.",
        "force field" : "It looks like you can walk through it.",
"north" : HIVE "hive42",
    ])  );
void reset() {
 ::reset();
     if (!present("raknid")){ 
      new(MOB"rpick")->move(this_object());
      new(MOB"rshovel")->move(this_object());
