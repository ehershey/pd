#include <lost.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("The lost jungles of Merkkirri");
set_day_long("The dense jungle allows little movement but to the northeast.  The lush plants of the Merkkirri jungle have been replaced by enormous trees of strange appearance and giant ferns.  While the plant life is extraordinary, it seems all primitive somehow...  as if time never took its toll upon  this part of the jungle.");
set_night_long("The dense jungle allows little movement but to the northeast.  The lush plants of the Merkkirri jungle have been replaced by enormous trees of strange appearance and giant ferns.  While the plant life is extraordinary, it seems all primitive somehow...  as if time never took its toll upon  this part of the jungle.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle seems to have never been touched by evolution.  Its as if you are stepping millions of years into the past...",
({"leaves", "ferns", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  Its as if the world evolved yet this place stood still.",
]));
set_properties((["light" : 2, "night light" : 1,]));
set_exits(([
"northeast": ROOMS "lost2.c",
]));
}

void reset() {
 ::reset();
}
