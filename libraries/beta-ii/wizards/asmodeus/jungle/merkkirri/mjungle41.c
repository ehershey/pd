#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("The top of a cliff");
set_day_long("You are standing atop a rock cliff.  Climbing down looks a bit harder than climbing up but still you think you could  manage.  The jungle here is so dense that your options for movement are limited.");
set_night_long("You stand atop a rock cliff.  Climbing down looks a bit harder than climbing up but you think you can manage.  There is little light to help you move through the dense jungle.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
"cliff" : "You think you can manage to climb down the cliff.",
]));
set_properties((["light" : 2, "night light" : 1,]));
set_exits(([
"northeast": LOST "lost1.c",
"climb": MJUNGLE "mjungle40.c",
]));
}

void reset() {
 ::reset();
}
