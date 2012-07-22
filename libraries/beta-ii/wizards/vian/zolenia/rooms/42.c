#include <std.h>
#include <zolenia.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "cavern" : 1, "night light" : 1]) );
set_smell("default", "The smell of the surrounding dirt is very strong.");
set_listen("default", "The echo of your footsteps on the ladder resonates throughout the tunnel.");
set_short("tunnel to Zolenia");
set_long("The end of the tunnel is in sight below!  The clamor of a busy city can be seen and heard, and the tunnel is starting to brighten immensely.  The width is also increasing, making the climb down harder...  It appears as if a freefall to the ground or climbing back up are the only ways to go.");
set_items(([
({"dirt", "path"}) : "The thin tunnel is made up of nothing but dirt.",
"ground" : "The ground surrounding you.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
"hole" : "You're in a hole..",
]));
set_exits(([ "down" : ROOMS "43.c",
"up" : ROOMS "41.c"]));
}
