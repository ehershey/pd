#include <std.h>

inherit "/std/police.c";

void create() {
  ::create();
    set_short("Sir Guy of the Eggs");
    set_id( ({ "guy", "sir guy", "egg guy" }) );
    set_name("Sir Guy of the Eggs");
    set_level(300);
    set_long("Sir Guy was brought up in the land of Egg. He is very noble, and also an important guard. Standing about 18 feet tall, its a wonder he fits into this room. He is not one for nonsense.");
    set_body_type("giant");
    set_race("giant");
    set_gender("male");
    set_property("no attack", 1);
}

int stop_me() {
  write("Guy holds you back as he stares stonily at you.");
    return 1;
}

void init() {
  ::init();
    add_action("stop_me", "square");
}
