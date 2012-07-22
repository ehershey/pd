#include <std.h>
#include <waterworld.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("shedder");
    set_id (({"shedder","fish"}));
    set_short("A small bait fish");
    set_long("A small silvery fish swims along oblivious to anything's presence. The shedder is a common food source for several species of fish.");
    set_level(15);
    set_race("shedder");
    set_body_type("fish");
    set_class("fighter");
    set_subclass("ranger");
    new(ITEMS1"fillet.c")->move(this_object());
    new(ITEMS1"fillet.c")->move(this_object());
}
