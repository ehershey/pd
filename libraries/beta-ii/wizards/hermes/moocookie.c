// Cookie's Killer Cow
#include <std.h>
inherit MOUNT;
static int oi;
void init()
{
 ::init();
 add_action("death", "unsummon");
}
void create() {
 ::create();
   set_name("cow");
   set_id(({ "cow" }));
   set_short("Cookie's cute cow");
set_level(1);
set_long("A large white, cute cow with black spots.  On close inspection, a
name
tag in the shape of a red heart with the words "
"\"I love Cookie\" written on it.");
   set_body_type("feline");
   set("race", "cow");
   set_gender("female");
}
void heart_beat() {
  if(find_player("cookie")) {
    if(environment(this_object()) != environment(find_player("cookie"))) {
      say(this_object()->query_cap_name()+" mooes towards Cookie.");
      this_object()->move(environment(find_player("cookie")));
      say(this_object()->query_cap_name()+" walks in, lazily, mooing and
nuzzling Cookie.");
}
    if(random(100) < 3)
this_object()->force_me("moo");
if(random(100) == 2)
this_object()->force_me("nuzzle cookie");
if (random(100) == 40)
this_object()->force_me("lick cookie");
  }
  ::heart_beat();
}

int death(string str)
{
        if (!str)
        {
                write("Unsummon what?");
                return 1;
        }
        if (str == "cow")
        {
                write("You unsummon... A COW\n");
                say("\n" + this_player()->query_cap_name() + " looks at a
strange cow figure in his hand, mutters a few words, and watches a cow go POOF\n");
        
this_object()->die();
                return 1;
        }
}

int is_invincible() { return 1; }

