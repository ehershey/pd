#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 1, "night light" : 0, "no teleport" : 1, "mountain" : 1 ]));
  set_short("Dragon Lands North");
  set_day_long("The path here is wide, but it rides steeply up on the mountain peak to the south, creating a dangerous slope into the crevace far below to the north. The mountain curves southward and away from the path to the west, allowing the path to steady and right itself in that direction, where it then curves to the north and down out of view. To the east the path is no less treacherous, hugging the mountainside steeply as it curves away to the south, out of view. The sun high in the sky to the south hides behind the mountain peak, casting a strong shadow over the path and the crevace below.");
  set_night_long("The path here is wide, but it rides steeply up on the mountain peak to the south, creating a dangerous slope into the crevace far below to the north. The mountain curves southward and away from the path to the west, allowing the path to steady and right itself in that direction, where it then curves to the north and down out of view. To the east the path is no less treacherous, hugging the mountainside steeply as it curves away to the south, out of view. The moon is obscured by the mountain peak to the south, leaving the path and crevace below in darkness and making each step feel less and less stable. The crevace below seems open to any stray sacrifices that may find themselves tossed its way, laying open in complete silence in the darkness.");
  set_exits( ([
    "west" : DRAG_ROOMS"dragnorth11.c",
    "east" : DRAG_ROOMS"dragnorth13.c",
             ]) );
  set_items( ([
             ]) );
}
