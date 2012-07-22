// Shinkoro's Killer Dragon
#include <std.h>
inherit MOUNT;
static int oi;
void create() {
 ::create();
   set_name("dragon");
   set_id(({ "dragon" }));
   set_short("Shinkoro's Dragon");
set_level(1000);
set_long("This is one huge Dragon.
If you think you can %^BOLD%^%^RED%^TAKE%^RESET%^ him, let Shin know. "
);
   set_body_type("dragon");
   set("race", "male red dragon");
    set_class("dragonkin");
}
void heart_beat() {
  if(find_player("shinkoro")) {
    if(environment(this_object()) != environment(find_player("shinkoro"))) {
      say(this_object()->query_cap_name()+" looks towards Shinkoro.");
      this_object()->move(environment(find_player("shinkoro")));
      say(this_object()->query_cap_name()+" walks in, looking over the room
and nods to Shinkoro");
}
    if(random(100) < 3)
this_object()->force_me("growl");
if(random(100) == 2)
this_object()->force_me("poke shinkoro");
if (random(100) == 40)
this_object()->force_me("lick shinkoro");
  }
  ::heart_beat();
}
int die() { return 1; }
int is_invincible() { return 1; }
