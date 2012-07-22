#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("goddess");
   set_id( ({ "goddess" }) );
   set_short("Terra, Goddess of Life");
   set("aggressive", 1);
   set_level(1);
   set_long("The goddess of life has become extremely weak. Although powerful enough to defy her true enemy, she was abandoned and imprisoned by the wills of her own followers.  Powerless and holding onto the last breath of life she can, Terra slowly dies.");    
   set_body_type("human");
   set_class("monk");
   set_subclass("light");
   set_spell_chance(90);
   set_spells( ({ "armageddon", "snapkick" }) );
   set_skill("melee", 10000);
   set_skill("belief", 20000);
   set("race", "goddess");
   set_gender("female");
}


