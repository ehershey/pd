// by Halo for Illuminati
#include <std.h>
#include <guild.h>
inherit ROOM;

void create() {
::create();
    set_short("Chamber");
    set_long("As you enter this room you can't help but feel a sense of "
"awe. The door you entered from is floating in thin air and "
"you find yourelf in a field filled with %^RESET%^%^MAGENTA%^black%^RESET%^ roses...now a "
"mountain top towering over all around it, then suddenly a "
"beach on a remote island. The room continues to cycle "
"endlessly through an infinte amount of locations, each more breath "
"taking than the last. However there is one constant in the room, a small "
"%^BOLD%^%^WHITE%^cloud%^RESET%^ floating at waist height.");
    set_items(([
        "cloud" : "Obviously this is where Halo sleeps, it is the most comfortable thing you have ever felt. There is a pillow at one end.",
        "pillow" : "The pillow is softer than silk. And it is stuffed with phoenix feathers...",
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 2,
    ]));
    set_exits(([
        "east" : ROOMS"illuminati/new/halo.c",    
]));

}

void init() {
   ::init();
     add_action("jumpin", "jump");
}

int jumpin(string str) {
    if (str == "on cloud") {
    this_player()->move_player(ROOMS"illuminati/new/halo3.c");
    return 1;
    }
    return 1;
}
