// Coding by Whit
// Coded for Primal Darkness
// openpath_8.c

#include <std.h>
#include <citrin.h>
inherit ROOM;
void create() {
::create();
    set_short("Citrin Forest");
    set_day_long("This is a large spiders nest.  The sound of slithering can "
                 "can be heard throughout this area of the forest.  The sun "
                 "does not shine through this area making it perfect breeding "
                 "grounds for these hideous beasts.");
    set_night_long("This is a large spiders nest.  The sound of slithering can "
                 "can be heard throughout this area of the forest.  The moon "
                 "does not shine through this area making it perfect breeding "
                 "grounds for these hideous beasts.");
    set_listen("default", "A slithering sound can be heard.");
    set_properties(([
        "light" : 1,
        "night light" : 0,
        "forest" : 1,
    ]));
    set_items(([
        "nest" : "This is a large spiders nest.",
    ]));
    set_exits(([
        "west" : ROOMS+"openpath_7.c",
        "southeast" : ROOMS+"openpath_9.c",
    ]));
}
void reset() {
    ::reset();
    if (!present("a tree spider"));
          new(MON+"spider2.c")->move(this_object());
          new(MON+"spider2.c")->move(this_object());
          new(MON+"spider2.c")->move(this_object());
    if (!present("a green snake"));
          new(MON+"snake1.c")->move(this_object());
          new(MON+"snake1.c")->move(this_object());
          new(MON+"snake1.c")->move(this_object());
  }
