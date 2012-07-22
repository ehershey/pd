#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 1, "night light" : 0, "indoors" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 15, 0 })]));
  set_short("Dragon Lands North");
  set_day_long("A cave boring into the heart of the mountain. The cave is both deep and wide, although it is large enough to accommodate the largest of creatures, it goes so deep into the mountain that you can't help but feel a little claustrophobic. The only source of light comes from a hole in the mountainside to the west leading out into the open air. The sun beats down upon the opening of the cave, casting a soft warm light against the walls of the cave. To the south, the mountain path bores upward, higher into the mountain.");
  set_night_long("A cave boring into the heart of the mountain. The cave is both deep and wide, although it is large enough to accommodate the largest of creatures, it goes so deep into the mountain that you can't help but feel a little claustrophobic. The only source of light comes from a hole in the mountainside to the west leading out into the open air. The night light encroaches upon the entrance to the cave, pooling lazily upon the rocky floor. To the south, the mountain path bores upward, higher into the mountain.");
  set_exits( ([
    "west" : DRAG_ROOMS"dragnorth16.c",
    "south" : DRAG_ROOMS"dragnorth21.c",
             ]) );
  set_items( ([
             ]) );
}

void reset() {
  ::reset();
  if(!present("dragon"))
    new(DRAG_MOBS"dragon.c")->move(this_object());
}
