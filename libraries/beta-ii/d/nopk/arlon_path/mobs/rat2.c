#include <std.h>
inherit MONSTER;

void create() {
 ::create();
    set_name("rat");
    set_short("a rat");
    set_level(random(2)+1);
    set_race("rat");
    set_body_type("feline");
    set_gender("male");
    set_class("animal");
    set_subclass("fast");
   set_id(({ "rat" }));
   set_long("A small furry rodent.");
  set_swarm(1);
}
