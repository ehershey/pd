

#include <std.h>
#include <aekari.h>
inherit MONSTER;


void create() {
   ::create();
   set_name("guard");
   set_id( ({ "guard", "aekari", "faerie" }) );
   set_short("Aekari Guard");
   set_long(
     "He is a dutiful guardian of the Aekari, standing watch in secret "
     "to protect his home. As most faeries go he is quite small, but very "
     "well trained. It is difficult to decipher his exact features through "
     "the %^MAGENTA%^violet%^RESET%^ flames roaring silently from his "
     "body. He does not appear to be very happy to see you. "
   );
   set_class("fighter");
   set_subclass("soldier");
   set_level(15);
   set_hp(450);
   set_max_hp(450);
   set("aggressive", 999);
   set_gender("male");
   set_body_type("faerie");
   set_race("Aekari");
   add_money("silver",20);
   new("/wizards/danovae/pro/aekari/wea/wlance.c")->move(this_object());
   force_me("wield spear");
   new(ARM"pauldron.c")->move(this_object());
   force_me("wear pauldron");
}
