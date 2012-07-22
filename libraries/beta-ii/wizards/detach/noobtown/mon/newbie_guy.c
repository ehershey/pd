
#include <std.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("Nabanis");
   set_id( ({ "nabanis","nabanis the newbie helper","helper","newbie helper" }) );
   set_short("%^BOLD%^%^WHITE%^Nabanis the %^GREEN%^Newbie%^WHITE%^ Helper%^RESET%^");
   set_long(
     "Nabanis is here to help the local newbies with their problems. He is full of useful information.\n"
     "You may:\n"
     "%^BOLD%^%^CYAN%^<ask nabanis for [weapon type]>%^RESET%^ : Nabanis will provide you with a weapon of your choice.\n"
   "Available weapons: Sword, Two Handed, Spear, Mallet, Axe, Whip, Dagger "
   );
   set_level(10);
   set_race("human");
   set_body_type("human");
   set_class("mage");
   set_gender("male");
}
void init() {
   ::init();
   add_action("askMe","ask");
}

int askMe(string str) {
   if(this_player()->query_level() > 5)
   { force_me("say You are too old for my help."); return 1; }
   say(this_player()->query_cap_name()+" asks Nabanis a question.");
   if(str == "nabanis for sword") {
     new("/d/radyne/wep/nsword.c")->move(this_player()); 
     write("Nabanis snaps his fingers and a sword appears in your hands.");
     return 1; }

}




