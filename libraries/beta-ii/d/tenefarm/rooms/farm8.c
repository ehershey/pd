#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
  set_long("The small dirt path forks east and northeast of here, yet it leads west in one piece. The grass is short and well groomed, but to the southwest in the pasture it grows long and fresh. A well-sized cloud drifts slowly overhead, casting a gentle shadow on the crossroads. To the north a freshly painted barn lays with its huge doors open. Behind the barn a small stream gently flows east.");
  set_night_long("The night is cold, but not cold enough to cause discomfort in beings lightly clothed. The path here splits up northeast and east, and comes back together to the west. To the southwest, the large grass in the pasture waves back and forth in the wind. A barn of generous proportions covered in shadows waits patiently in the night to the north. Somewhere to the north the constant, flowing sound of a stream can be heard, but the stream itself is nowhere to be seen.");
  set_smell("default", "The potent smell of cows.");
  set_items(([
    "pasture" : "To the southwest. It is full of wonderful grass.",
    "path" : "A small dirt path to make walking easier. It goes west, east, and northeast.",
    "barn" : "A very large barn. It is north-east of your current location.",
    "stream" : "It is to the north of here. If flows east behind the barn."
   ]));
  set_exits(([
    "west" : ROOMS"farm7",
    "east" : ROOMS"farm9",
    "northeast" : ROOMS"farm10"
   ]));
}
