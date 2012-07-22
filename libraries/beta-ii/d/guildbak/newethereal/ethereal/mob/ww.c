#include <std.h>
#include <ether.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("William Wallace");
   set_id(({ "william","william wallace","man" }));
  set_short("%^RESET%^%^BLUE%^W%^BOLD%^%^BLACK%^i%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^l%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^m%^BOLD%^%^BLACK%^ W%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^l%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^c%^BOLD%^%^BLACK%^e%^RESET%^");
   set_long( "William Wallace is a 13th century Scottsman. He has sworn to watch over the Ethereal Hall." );
   set_gender("male");
   set_level(77);
   set_alignment(300);
   set("race", "human");
   set_body_type("human");
   set_property("no bump", 1);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_moving(1);
   set_speed(60);
   new(ARM"w_shield.c")->move(this_object());
   new(WEP"w_sword.c")->move(this_object());
   new(ARM"w_kilt.c")->move(this_object());
   command("wield sword");
   command("wear shield");
   command("wear kilt");
}

