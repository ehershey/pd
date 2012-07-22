#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("town",1);
    set_short("Uwagi Town Bank");
    set_day_long(
      "A roof-less building, almost compleatly covered with wild "
      "vines, struggles to keep itself from crumbling inward.  A "
      "sign hanging from the building, showing a picture of a pot "
      "of gold, dangles from one corner on a chain.  There is a "
      "small opening in the vines allowing passage through."
           );
    set_night_long(
      "Mounds of wild vines can be seen under the light of fire-"
      "flies.  A small opening in the vines, provides a way through."
           );
    set_items(([
        "sign" : "It's made of crude wood.  A picture of a pot of gold"
                 "is painted on it.",
        "vines" : "It chokes the life of everything it touches.",
        "chain" : "It's almost rusted right through, it won't be "
                  "long before the whole sign just fall off.",
        "opening" : "It will take you inside the building.",
        "flies" : "Unique, they actually have a flame for a body.",
 
    ]));
    set_exits( ([
"enter" : TOWN "building",
"east" : TOWN "town12",
    ]) );
}
void reset() {
 ::reset();
   if (!present("building", this_object()))
     new( ITEMS "abuilding.c" )->move(this_object());
}
