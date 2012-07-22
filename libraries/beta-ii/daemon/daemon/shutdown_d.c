#include <std.h>
#include <security.h>
#include <objects.h>

inherit DAEMON;

object *in_the_know;
int time;

void let_everyone_know();

void do_armageddon() {
/*
    if (previous_object()->is_player())
      if ((string)previous_object()->query_name()!="seeker") return;
    if (!previous_object()->is_player())
    if(geteuid(previous_object()) != UID_SHUTDOWN) return; 
*/
    call_out("the_end", 60);
    message("broadcast", 
"%^BLACK%^%^BOLD%^Dark storm clouds hover you blocking out the sun. "
"You feel the end is near.\n%^RESET%^Reboot in 10 minutes!", users());
    time = 600;
}

static void the_end() {
    time -= 60;
     if(time < 11) call_out("end_it", 0);
    else call_out("the_end", 60);
       if(time < 541 && time > 480) {
  message("broadcast", "%^BOLD%^%^CYAN%^The gods begin to wage a war "
            "across the sky.%^%^RESET%^%^"
        "\nReboot in 9 minutes!",
         users());  }
    else if(time < 481 && time > 420) {
   message("broadcast", "%^BOLD%^%^BLUE%^Peacekeepers "
    "rush to save everything from the impending doom.%^RESET%^"
             "\nReboot in 8 minutes!",
    users()); }
    else if(time < 421 && time > 360) {
  message("broadcast", "%^BOLD%^%^YELLOW%^Lightning strikes "
    "down from the clouds, smiting everything it hits.%^RESET%^"
            "\nReboot in 7 minutes!",
   users());  }
  else if(time < 361 && time > 300) {
    message("broadcast", "%^MAGENTA%^With a loud thunder clap, the "
      "ground buckles and everything around you begins to collapse.%^RESET%^"
       "\nReboot in 6 minutes!",
      users());  }
  else if(time < 301 && time > 240) {
    message("broadcast", "%^BOLD%^%^WHITE%^In the graveyards "
         "the dead begin to climb from their graves.%^RESET%^"
      "\nReboot in 5 minutes!",
     users()); }
   else if(time < 241 && time > 180) {
     message("broadcast", "%^RED%^The moon slowly rises on the "
   "horizon, blood red.%^RESET%^"
     "\nReboot in 4 minutes!",
  users()); }
   else if( time < 181 && time > 120) {

   message("broadcast", "%^GREEN%^You hear a rumble in the forests "
  "as trees crash to the ground, %^BOLD%^%^RED%^burning.%^RESET%^"
   "\nReboot in 3 minutes!",
  users()); }
     else if(time < 121 && time > 60) {
     message("broadcast", "%^BOLD%^%^MAGENTA%^Everywhere you look people "
    "are fleeing in %^RESET%^%^RED%^terror.%^RESET%^%^BOLD%^%^MAGENTA%^  Trampling "
"each other in the general panic, they throw down their belongings and vainly "
    "look for shelter.%^RESET%^"
     "\nReboot in 2 minutes!",
 users()); }
   else if(time < 61 && time > 10) {
    message("broadcast", "%^BOLD%^%^BLACK%^The destruction is nearly here, "
     "walls of storm clouds are rapidly closing in, you see your fate and "
     "war with either joining the surrounding turmoil, or facing down the clouds."
     "%^RESET%^\nReboot in 1 minute.",
     users()); }
    if(time/60 == 3) message("broadcast", "%^CYAN%^Salox screams:"
        "%^RESET%^ Tell me "
      "if you want a trip to the shop!", users());
    let_everyone_know();
}

static void end_it() {
    time -= 50;
    call_out("shut", 10);
   message("broadcast", "Chaos reigns as the mud reboots in "
      "10 seconds!", users());
    let_everyone_know();
}

static void shut() {
    object *who;
    int i;

    who = users();
    for(i=0; i<sizeof(who); i++)
      catch(call_other(who[i], "force_me", "quit"));
    shutdown();
}

int query_time_remaining() { return time; }

void notify_armageddon(object ob) {
    if(!ob) return;
    if(!in_the_know) in_the_know = ({ ob });
    else {
	if(member_array(ob, in_the_know) == -1) in_the_know += ({ ob });
    }
}

void clean_up() {
    object *tmp;
    int i;

    if(!in_the_know) return;
    tmp = ({});
    for(i=0; i<sizeof(in_the_know); i++) { 
	if(!in_the_know[i]) continue;
	tmp += ({ in_the_know[i] });
    }
    in_the_know = tmp;
}

void let_everyone_know() {
    int i;

    for(i=0; i<sizeof(in_the_know); i++) {
	if(!in_the_know[i]) continue;
	in_the_know[i]->call_end(time);
    }
}
