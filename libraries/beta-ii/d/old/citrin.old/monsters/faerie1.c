// Coded by Whit
// Coded for Primal Darkness
// faerie1.c

#include <std.h>
#include <citrin.h>
inherit MONSTER;
int wear_arm=0;	
void create() {
    ::create();
   set_name("blue faerie");
   set_id( ({ "faerie", "blue faerie" }) );
    set_short("a blue faerie");
    set_level(21);
   set_long("This is a blue faerie.  It lives amoung the treetops.");
   set_body_type("imp");
   set_alignment(500);
   set("race", "imp");
   set_gender("male");
   new(ARM"faeriering.c")->move(this_object());
}
void heart_beat() {
 ::heart_beat();
   if (!wear_arm) {
      this_object()->force_me("wear ring");
      wear_arm = 1;
   }
}
