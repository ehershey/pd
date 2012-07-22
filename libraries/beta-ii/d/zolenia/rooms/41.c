#include <std.h>
#include <zolenia.h>
inherit ROOM;
void create() {
::create();
set_properties( ([ "light" : 1, "indoors" : 1, "cavern" : 1, "night light" : 1]) );
set_smell("default", "The smell of the surrounding dirt is very strong.");
set_listen("default", "The echo of your footsteps on the ladder resonates throughout the tunnel.");
set_short("tunnel to Zolenia");
set_long("Climbing, climbing, climbing...  Down many stairs, the air is getting thinner and the tunnel smaller.  The ladder has ended and it's now a simple downward slanted crawl.  This better actually lead somewhere...");
set_items(([
({"dirt", "path"}) : "The thin tunnel is made up of nothing but dirt.",
"ground" : "The ground surrounding you.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
"hole" : "You're in a hole..",
({"ladder"}) : "There is no ladder anymore, better start crawling!",
({"stairs"}) : "The stairs ended, it's just a crawl now..",
]));
set_exits(([ "down" : ROOMS "42.c",
 "up" : ROOMS "40.c"]));
}
