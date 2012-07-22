#include <std.h>
#include <wildfire.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "forest" : 1, "light" : 2, "night light" : 1]) );
    set_smell("default", "The musty smell of farm bovine reaches your nose.");
    set_listen("default", "You can hear a faint mooing in the distance.");
    set_short("%^GREEN%^Forest%^RESET%^");
    set_long("There are only a few trees scattered around here to make room for more agriculture and farmland. Directly to the east a simple wooden fence stretches far north and south to keep the livestock in, but it is short enough to allow people free access. To the west the trees thicken as the effects of civilizaion has not yet spread that far.");
    set_night_long("Almost all of the trees in this area have been cleared to make room for a budding new farm. Directly east of here a long intimidating wooden fence stretches like a black snake across the ground to the north and south. The forest due west of your current position looms big and exciting, with a little bit of danger.");
    set_items(([
	"tree" : "This tree is fairly tall.",
	"stump" : "This stump used to be a tree, now it just sits there, dead.",
         "trees" : "There are a few, here and there, there and here.",
	"stumps" : "They increase in number to the west.",
	"path" : "It goes east and west."
      ]));
    set_exits(([
	"west" : ROOMS"beginning.c",
	"east" : ROOMS"farm2.c"
      ]));
    add_pre_exit_function("east", "go_east");
}
int go_east() {
    write("%^ORANGE%^You place one hand on the top of the fence and heave yourself over.%^RESET%^");
    say(this_player()->query_name()+" places one hand on the top of the fence and jumps over.", this_player());
    return 1;
}
void reset() {
    ::reset();
    if (!present("sign"))
	new(OBJ "sign.c")->move(this_object());
}
