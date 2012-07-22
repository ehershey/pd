#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("town",1);
    set_short("Uwagi Town Library");
    set_day_long(
      "A roof-less building, almost compleatly covered with "
      "wild vines, struggles to keep itself from crumbling "
      "inward.  Etched in stone, the letters L I B, can "
      "vaguely be seen through the vines. "
          );
   set_night_long(
      "Mounds of wild vines can be seen under the light of "
      "fire-flies."
          );
    set_items(([
        "vines" : "They are choking the life of everything.",
        "stone" : "The letters L I B can be seen through the vines.",
        "flies" : "Unique, the body is made from an actual flame.",
    ]));
    set_listen("default", "Sounds of the building creaking");
    set_exits( ([
"west" : TOWN "town16",
"enter" : TOWN "building2",
    ]) );
}
void reset() {
 ::reset();
   if (!present("building", this_object()))
     new( ITEMS "abuilding.c" )->move(this_object());
}
