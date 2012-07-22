#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 138, 17, 0 })]));
  set_short("Dragon Lands North");
  set_day_long("The crevaces on both sides of the mountain ridge both glow only faintly in the day's light, even though the one on the east must be at least ten times deeper than the one on the west. The eastern crevace's immense depths cause a dark shadow to be cast upon it from the surrounding mountain, while the western crevace seems to emanate its own malevolent form of darkness, warring with the daylight that enters it. The path below along the mountain ridge staggers slightly to the west, towards the crevace, before continuing on its way.");
  set_night_long("The crevaces on both sides of the mountain ridge are equally dark and devoid of light, even though the one on the east must be at least ten times deeper than the one on the west. The eastern crevace seems to swallow the scant light that enters it into its unfathomable depths, while the western crevace seems to emanate its own malevolent form of darkness. The path below along the mountain ridge staggers slightly to the west, towards the crevace, before continuing on its way.");
  set_exits( ([
    "north" : DRAG_ROOMS"dragnorth35.c",
    "west": DRAG_ROOMS"dragnorth37.c",
    "south" : DRAG_ROOMS"dragnorth41.c"
             ]) );
  set_items( ([
             ]) );
  add_invis_exit("west");
}
