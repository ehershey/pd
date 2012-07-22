#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
  ::create();
  set_properties( ([ "light" : 2, "night light" : 1, "plain" : 1]) );
  set_short("%^BOLD%^%^RED%^A farm%^RESET%^");
 set_long("The path here curves northeast, following the curves of the river. To the southeast a little ways off the path gets too close to the river and is swallowed whole. To the east the mill can be soon working slowly, along with the slow moving current of the water. To the northeast a wide house can be seen, with the river curving around it, to flow east, and then south to your current location.");
 set_night_long("The dark, silent path here curves northeast, following the curves of the river. To the southeast a little ways off the path gets too close to the river and is vilently swallowed whole. To the east the mill crossbreed can be seen churning slowly in the dark. To the northeast a wide house can be seen, with the river curving around it, to flow east, and then south to your current location.");
  set_items(([
    "path" : "A small dirt path to make walking easier. It goes south and north.",
    "windmill" : "It is a watermill/windmill crossbreed. It is to the east, across the river.",
   "waterwheel" : "It is a watermill/windmill crossbreed. It is to the east, across the river.",
    "river" : "It is to the east of here, the path is following it.",
    "house" : "The farmer's house."
   ]));
  set_smell("default", "It smells like freshly cut grass here.");
  set_listen("default", "The gentle rushing of the river can be heard.");
  set_exits(([
    "northeast" : ROOMS"farm20",
    "south" : ROOMS"farm18"
   ]));
}
