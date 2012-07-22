/* ---Danovae-2002-Jan-24--- */
/* --- The Wheel of Fortune --- */


#include <std.h>
inherit OBJECT;
int uses;

void create() {
   ::create();
   uses = 3;
   set_name("wheel");
   set_id( ({ "wheel","wheel of fourtune" }) );
   set_short("%^CYAN%^%^BOLD%^The Wheel of Fortune%^RESET%^");
   set_long(
     "A wheel with many section with various images on each. "
     "You may be able to 'spin' it. "
   );
   set_value(0);
   set_mass(1000);
   set_prevent_get("The wheel is far too large to lift.");
}

void init() {
   ::init();
   add_action("spin","spin");
}

int spin(string str) {
   int x, spins;
   x = 8;
   spins = random(x);
   if(str != "wheel")
   { return notify_fail("Spin what?\n"); }
   write("'round and 'round and 'round she goes,");
   write("where she stops, nobody knows.\n");
   say(this_player()->query_cap_name()+" spins the %^CYAN%^%^BOLD%^Wheel of Fortune%^RESET%^.\n");
   random(x);
     if(spins == 0) {
     this_player()->add_money("gold", 100);
     write("The wheel stops on a picture of a single coin.\n");
     }
     if(spins == 1) {
     this_player()->add_money("gold", 1000);
     write("The wheel stops on a picture of an elf holding up a coin.\n");
     }
     if(spins == 2) {
     this_player()->die();
     write("The wheel stops on a picture of the Grim Reaper.\n");
     }
     if(spins == 3) {
     this_player()->add_money("gold", 5000);
     write("The wheel stops on a picture of a pot of gold.\n");
     }
     if(spins == 4) {
     if(this_player()->query_class() == "rogue")
      { this_player()->add_skill_points("murder", 10); }
     if(this_player()->query_class() == "mage")
      { this_player()->add_skill_points("magic attack", 10); }
     if(this_player()->query_class() == "clergy")
      { this_player()->add_skill_points("faith", 10); }
     if(this_player()->query_class() == "fighter")
      { this_player()->add_skill_points("attack", 10); }
     if(this_player()->query_class() == "wanderer")
      { this_player()->add_skill_points("euphony", 10); }
     write("The wheel stops on a picture of two arrows pointing up.\n");
     }
     if(spins == 5) {
     this_player()->add_exp(1000);
     write("The wheel stops on a picture of a circle around a small 'X'.\n");
   }
     if(spins == 6) {
     this_player()->add_exp(10000);
     write("The wheel stops on a picture of a circle around an 'X'.\n");
   }
     if(spins == 7) {
     this_player()->add_exp(100000);
     write("The wheel stops on a picture of a circle around a large 'X'.\n");
   }



   uses--;
   if(uses < 1) {
   write("The wheel is jammed and will not spin any more.\n");
   new("/wizards/danovae/wheel2.c")->move(environment(this_object()));
   this_object()->remove();
   return 1;
   }
return 1;
}




