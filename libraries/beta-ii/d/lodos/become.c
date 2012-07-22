#include <std.h>
#include <lodos.h>                                         
#include <locations.h>
#include <daemons.h>
inherit ROOM;
void create() {
 ::create();
   set_short("So Pur att Annar");
   set_long("%^YELLOW%^The final altar past life, before death. An altar of pure "
     "light and power. This is 'so Pur att Annar', the Temple to Heaven. Purity "
     "and peace are the overwhelming sensations here. The sun floats overhead. "
     "At the temple to heaven it is said that those true of faith can %^BOLD%^%^RED%^become%^YELLOW%^ "
     "warriors of the holy spirit, Archangels.");
   set_items(([
     "sky" : "It is always day here. The sun shines brightly, warming you.",
     "sun" : "A firey yellow globe that floats high in the sky."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1,
     "no bump" : 1, "no attack" : 1, "no magic" : 1, "no teleport" : 1,
     "no steal" : 1 ]));
   set_exits(([
   ]));
}
int become(string str) {
   string primary;
   if (!str || str != "archangel") return notify_fail("Become what?\n");
   if (this_player()->query_subclass() == "antipaladin" ||
       this_player()->query_subclass() == "kataan" ||
       this_player()->query_subclass() == "necromancer") {
     write("Nothing happens.");
     this_player()->move(SQUARE_LOC, "square");
     return 1;
   }
   primary = IDENTITY_D->search_primary(this_player());
   if (primary && IDENTITY_D->query_setting(primary, "noquestrace")) {
      write("You may never become a quest race.");
      this_player()->move(SQUARE_LOC, "square");
      return 1;
   }
   write("%^BOLD%^You let forth a scream, raging against evil and corruption "
     "everywhere. Your scream echos and flows forth from you like a blast of "
     "energy.");
   write("%^YELLOW%^Your voice echos within your body and explodes, shattering "
     "everything around you! Wings rip out of your back and your old body "
     "shatters, giving birth to your new form!");
   shout("%^YELLOW%^A single, raging voice rips through this reality and tears "
     "reality asunder. The voice echos and grows!", this_player());
   message("transformation", this_player()->query_cap_name()+"'s body transforms "
     "in the fury and "+this_player()->query_subjective()+" shoots into the sky.",
     users());
   message("ascention", "%^YELLOW%^"+this_player()->query_cap_name()+" has "
     "ascended to the ranks of the heavens.", users());
   this_player()->add_exp(-(this_player()->query_exp()));;
   this_player()->set_stats("strength",(int)this_player()->query_base_stats("strength")/4);
   this_player()->set_stats("constitution",(int)this_player()->query_base_stats("constitution")/3);
   this_player()->set_stats("dexterity",(int)this_player()->query_base_stats("dexterity")/3);
   this_player()->set_stats("charisma",(int)this_player()->query_base_stats("charisma")*2/3);
   this_player()->set_stats("intelligence",(int)this_player()->query_base_stats("intelligence")*2/3);
   this_player()->set_stats("wisdom",(int)this_player()->query_base_stats("wisdom")*2/3);
  foreach (string st in this_player()->query_all_stats())
    if (this_player()->query_base_stats(st) < 1) this_player()->set_stats(st, 1);
   this_player()->set_level(1);
   this_player()->set_race("archangel");
   this_player()->new_body();
  this_player()->clear_remort_sub_data(this_player()->query_subclass());
   this_player()->set_class("child");
   this_player()->set_subclass("none");
   this_player()->init_skills("child");
   this_player()->fix_vital_bonus();
   new("/wizards/inferno/angel/halo")->move(this_player());
   write("A halo winks into existance.");
   this_player()->force_me("wear halo");
   this_player()->set_primary_start("/wizards/inferno/angel/main.c");
   this_player()->set_alignment(1500);
   this_player()->set_mini_quest("archangel", 1000, "You have completed your quest in becomming an archangel.\n");
   write("%^ORANGE%^%^BOLD%^You are now a holy force of this world.");
   write("%^BLUE%^%^BOLD%^ ***You are being forced to quit, please re-login***");
   this_player()->force_me("save");
   this_player()->force_me("quit");
   return 1;
}
void init() {
 ::init();
   add_action("become", "become");
}
