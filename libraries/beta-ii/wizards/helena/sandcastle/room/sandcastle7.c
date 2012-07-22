#include <sandcastle.h>
#include <std.h>

inherit ROOM;

void create() {
::create();
set_properties((["light" : 2, "night light" : 2, "indoors" : 1]) );
set_short("Upstairs");
set_long("After climbing the stairs warily, amazed they did not break under your weight, you arrive upstairs. It is eerie up here, but the room is brightened as it shines through the hole thats in the ceiling. You notice a ladder made of twigs leading up and through that hole. There are two rooms, one east, one west.");
set_night_long("After climbing the stairs warily, amazed they did not break under your weight, you arrive upstairs. It is eerie up here, but the light of the moon breaks through a hole in the ceiling nearby. You notice a ladder made of twigs leading up and through the hole. There are two exits, east and west.");
set_items((["room" : "The sand seems to be sinking through the cracks in the floor, and you notice how dry everything is. Perhaps the continual sunlight has dried up all the water holding the sand together?", "ceiling" : "There is a large hole in it, a ladder leading up and out through that hole.", "walls" : "Nothing really interesting here, its a wall made of sand.", "floor" : "There are cracks here on the floor, and as you watch, sand seems to be drifting away into those cracks, as if sucked by some force.", "hole" : "It's a hole...in the ceiling...", "ladder" : "The ladder is sturdy, although made of twigs and seaweed. Dare you climb it?"]));
set_smell("default", "The smell of decay and seaweed is greatly over ridden by the smell of fresh sea air.");
set_listen("default", "The sounds of the Ocean is so loud now, you could swear you were in it.");
set_exits( (["west" : ROOMS "sandcastle8", "east" : ROOMS "sandcastle10", "up" : "/d/nopk/tirun/beach4.c", "down" : ROOMS "sandcastle1"]) );
}
