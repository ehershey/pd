#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("town",1);
    set_short("Uwagi Town");
    set_day_long(
      "A huge branch of the vine blocks the path, making "
      "it impossible to pass through."
          );
    set_night_long(
      "Mounds of wild vines can be seen under the light of "
      "fire-flies.  A thick branch blocks the path, making "
      "it impossible to pass through."
    );
    set_items(([
        "branch" : "It blocks your direction going south.",
        "vine" : "It's very thick, and very much alive.",
        "mound" : "Nothing but branches, tangled up with itself.",
        "flies" : "Unique, it actually has a flame for a body.",
    ]));
    set_exits( ([
"northeast" : TOWN "town8",
    ]) );
}
