// Suri's Killer Cow
#include <std.h>
inherit MOUNT;
static int oi;
void create() {
 ::create();
   set_name("cow");
   set_id(({ "cow" }));
   set_short("Suri's cute cow");
set_level(1);
set_long("A large white, cute cow with black spots.  On close inspection, a name
tag in the shape of a red heart with the words "
"\"I love Suri\" written on it.");
   set_body_type("feline");
   set("race", "cow");
   set_gender("female");
}
void heart_beat() {
  if(find_player("suri")) {
    if(environment(this_object()) != environment(find_player("suri"))) {
      say(this_object()->query_cap_name()+" mooes towards Suri.");
      this_object()->move(environment(find_player("suri")));
      say(this_object()->query_cap_name()+" walks in, lazily, mooing and
nuzzling Suri.");
}
    if(random(100) < 3)
this_object()->force_me("moo");
if(random(100) == 2)
this_object()->force_me("nuzzle suri");
if (random(100) == 40)
this_object()->force_me("lick suri");
  }
  ::heart_beat();
}
int die() { return 1; }
int is_invincible() { return 1; }
