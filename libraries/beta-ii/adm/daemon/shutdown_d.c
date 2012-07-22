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
"%^BLACK%^%^BOLD%^Dark storm clouds roll in blocking out the sky! "
"The end is near!!\n%^RESET%^Reboot in 10 minutes!", users());
    time = 600;
}
static void the_end() {
    time -= 60;
     if(time < 11) call_out("end_it", 0);
   else call_out("the_end", 60);
       if(time < 541 && time > 480) {
    message("broadcast", "%^BOLD%^%^CYAN%^The gods begin to wage war "
      "in the heavens, plunging the realms into chaos.%^%^RESET%^%^"
      "\nReboot in 9 minutes!", users());  }
   else if(time < 481 && time > 420) {
    message("broadcast", "%^BOLD%^%^YELLOW%^Angels descend from the "
      "heavens trying to save everything from impending doom.%^RESET%^"
      "\nReboot in 8 minutes!", users()); }
   else if(time < 421 && time > 360) {
    message("broadcast", "%^BOLD%^%^BLUE%^Demons rush in destroying "
      "all good works in their path, adding to the chaos.%^RESET%^"
      "\nReboot in 7 minutes!", users());  }
   else if(time < 361 && time > 300) {
    message("broadcast", "%^MAGENTA%^With a loud thunder clap, the "
      "ground buckles and everything around you begins to collapse.%^RESET%^"
      "\nReboot in 6 minutes!", users());  }
   else if(time < 301 && time > 240) {
    message("broadcast", "%^BOLD%^%^WHITE%^In the graveyards "
      "the dead begin to climb from their graves feeding off the chaos.%^RESET%^"
      "\nReboot in 5 minutes!", users()); }
   else if(time < 241 && time > 180) {
    message("broadcast", "%^GREEN%^You hear a rumble in the forests "
      "as trees crash to the ground, startling several dragons into flight.%^RESET%^"
      "\nReboot in 4 minutes!", users()); }
   else if( time < 181 && time > 120) {
    message("broadcast", "%^RED%^The clouds begin to glow %^RED%^red"
      "%^RESET%^%^RED%^ as fires around the realm rage out of control.%^RESET%^"
      "\nReboot in 3 minutes!", users()); }
   else if(time < 121 && time > 60) {
    message("broadcast", "%^BOLD%^%^MAGENTA%^Everywhere you look people "
      "are fleeing in %^RESET%^%^RED%^terror.%^RESET%^%^BOLD%^%^MAGENTA%^  "
      "Trampling each other in the mass panic, vainly looking for shelter."
      "%^RESET%^\nReboot in 2 minutes!", users()); }
   else if(time < 61 && time > 10) {
    message("broadcast", "%^BOLD%^%^BLACK%^The chaos is nearly here, "
      "the walls of storm clouds rapidly grow darker.  Knowing your fate "
      "you must decide either to join in the turmoil or face down the chaos."
      "%^RESET%^\nReboot in 1 minute.", users()); }
   if(time/60 == 3) message("broadcast", "%^CYAN%^Salox screams:"
        "%^RESET%^ Tell me if you want a trip to the shop!", users());
    let_everyone_know();
}
static void end_it() {
 time -= 50;
  call_out("shut", 10);
//  Changed by Whit to just displar the help credits file.
   message("broadcast", "%^YELLOW%^Chaos reigns as the world "
     "ends in 10 seconds!%^RESET%^%^BOLD%^\n\n", users());
    let_everyone_know();
}
static void shut() {
    object *who;
    int i;
    who = users();
    for(i=0; i<sizeof(who); i++) {
      message("",
        replace_string(
          read_file("/doc/help/general/reboot_screen"), "%s",
          read_file("/doc/help/general/credits")
        ),
        who[i]
      );
      catch(call_other(who[i], "force_me", "quit"));
    }
    if(find_object("/daemon/network/socket"))
	"/daemon/network/socket"->remove();
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
