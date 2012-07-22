#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Ogre's Paradise");
    set_long(
      "Here, at the opening of a cave, lizard-people cannot go inside."
      "The ogre's homes and gardens are inside.  Unlike the lizard's gardens, "
      "this area is very confined, just enough head room for the ogres."
    );
    set_items(([
        "gardens" : "These are the orge's garden.  A paradise for them.",
        "granite" : "A crystalline textured solid rock.",
        "cave" :  "Made out of solid granite, and is quite small.",
        "opening" : "It has just enough headroom for the ogres.",
        "paradise" : "Ogre's feel quite safe from the lizard-people, in fact
too confident",
        "area" : "It's looks very confined compared to the rest of the city",
    ]));
    set_exits( ([
"southwest" : GAR "gar47",
"north" : FUN "fun2",
    ]) );
}
