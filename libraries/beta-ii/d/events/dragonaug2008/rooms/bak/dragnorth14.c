#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 15, 0 })]));
  set_short("Dragon Lands North");
  set_day_long("The ocean glistens gently in the daylight to the west, far out past the mountain and the land below. A cool ocean breeze sweeps across the western face of the mountain, making the steep southern ascent seem less tedious. To the north, the mountain side path stretches out past the mountain peak on the east. To the southeast, the path rounds a bend in the mountain and continues up the mountain side.");
  set_night_long("The ocean glows softly in the night to the west, far out past the looming mountain and the land below, blanketed in shadows. A chill ocean breeze scours the western face of the mountain, harshly buffeting the western face of the mountain. To the north, the mountain side path stretches out past the mountain peak on the east. To the southeast, the path rounds a bend in the mountain and continues up the mountain side.");
  set_exits( ([
    "north" : DRAG_ROOMS"dragnorth10.c",
    "southeast" : DRAG_ROOMS"dragnorth19.c",
             ]) );
  set_items( ([
             ]) );
}
