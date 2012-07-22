#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_property("plain",1);
    set_short("a dark alley");
    set_long(
      "This is just the back of an alley where people dispose "
      "of their garbage.  You'll have the occassional mugger appear "
      "but something is wrong when a vampire comes. "
    );
    set_items(([
        "garbage" : "Heaps and heaps of garbage.",
        "alley" : "It leads back to the north.",
    ]));
   set_listen("default", "You hear some lunatic mutter something about blood.");
   set_exits( ([ 
        "north" : ROOMS"room7.c",
    ]) );
}
void reset() {
::reset();
    if(!present("vampire.c"))
      new(MOB"vampire.c")->move(this_object());
}
