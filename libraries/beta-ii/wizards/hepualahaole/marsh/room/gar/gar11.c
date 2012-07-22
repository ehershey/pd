#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Umi's Gardens");
    set_long(
      "The gardens here are infested by ogre slaves, with lizard-people as
their "
      "superior race. Unlike the town, this area is embedded in solid "
      "granite, making escapes for the ogres impossible."
    );
    set_items(([
        "gardens" : "These are cultivating gardens. Meaning you eat what you
can grow.",
        "granite" : "A crystalline textured solid rock.",
         
    ]));
    set_exits( ([
"north" : GAR "gar18",
"southeast" : GAR "gar7",
    ]) );
}
