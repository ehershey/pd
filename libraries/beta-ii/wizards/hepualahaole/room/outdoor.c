#include <std.h>
#include <wildflower.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("forest",1);
    set_short("Outdoor room");
    set_day_long(
      "There's a break in the bleak forest, and birds chip once again!"
      "There's a cottage house set in the middle of a gorgous "
      "wildflower field.  Leading up to the front door of "
      "the house is a dirt pathway.  The sun is shining bright "
      "and the squirrels and the chipmunks are scattered about the "
      "field, basking in the sunlight."
    );

    set_night_long(
      "Red eyes glaring in the pitch blackness of the night.  The "
      "moons are afraid to shine down upon the fields.  There is a "
      "presence of evil living in the cottage, and in the stillness "
      "of the night, nothing dares to whisper a sound."
    );
    set_items(([
        "room" : "a room.",
    ]));
    set_smell("default", "It smells of outdoors..");
    set_listen("default", "Sounds like a forest");
    set_exits( ([
"house" :  ROOMS "newhouse",
"east" :  ROOMS "outdoor2",
    ]) );

}
