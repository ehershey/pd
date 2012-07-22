#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("desert",1);
    set_short("Sabai Fortress");
    set_long(
      "Unbelievable!  What a spectacular mirage!  This mirage was magically sunken "
      "into a bowl shaped sand-dune.  In the center is a crystal clear waterpool "
      "which has statues and palm trees surrounding it.  In the center of the "
      "waterpool is a small island with a hut and a statue on it.  Leading away "
      "from the island is four bridges which connects with the path that is around "
      "the waterpool.  On each bridge there is a statue.  This place has a zen-"
      "like feel to it."
    );
    set_items(([
        "desert" : "Lots and lots of sand.",
        "hut" : "It is made out of sand, with a statue placed in front of it.",
        "waterpool" : "It's helps to create the illusion of a mirage.",
        "mirage" : "This one is the real thing.",
        "trees" : "Palm trees.",
        "palm" : "You know, that big leafy plant that can survive in anything.",
        "statues" : "There are eight statues in total.",
        "bridge" : "Four of them that leads to the island.",
        "island" : "It is placed in the middle of the waterpool.",
    ]));
    set_listen("default", "Sounds of Peace and Tranquility.");
    set_exits( ([
"east" : FORT "fort14",
"north" : FORT "fort18",
"south" : FORT "fort9",
    ]) );
}
void reset() {
 ::reset();
   if (!present("tonberry")){
      new(MOB"tonberry")->move(this_object());
      new(MOB"tonberry")->move(this_object());   
  
   }
}
