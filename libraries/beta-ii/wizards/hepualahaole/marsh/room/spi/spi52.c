#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 0]) );
    set_property("cave",1);
    set_property("eyelight", 1);
    set_long(
      "This cave feels like one long tunnel.  It feels hot and stuffy in "
      "here, and there seems to be no end."
    );
    set_items(([
        "cave" : "It's one of those air traps from the marsh.",
        "tunnel" : "Two exits, one you come from the one you can go to.",
    ]));
    set_exits( ([
"south" : SPI "spi44",
"east" : SPI "spi53",
    ]) );
}
void reset() {
 ::reset();
   if (!present("worm")) {
      new(MOB"worm")->move(this_object());
  if (!present("spider"))
     new(MOB"spider")->move(this_object());
 
    }
}
