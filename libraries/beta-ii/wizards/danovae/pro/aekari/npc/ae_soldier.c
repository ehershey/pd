

#include <std.h>
inherit MONSTER;


void create() {
   ::create();
   set_name("soldier");
   set_id( ({ "soldier","aekari","faerie" }) );
   set_short("Aekari Soldier");
   set_long(
    "A being of war, dedicated to his people. Carrying the burden of deliberate slash-scars across his chest, it would seem he has a bit higher rank than the other guards. Clearly these faeries have some obsession with pain and ritual scarring. "
   );
   set_class("fighter");
   set_subclass("soldier");
   set_level(20);
   set("aggressive", 999);
   set_gender("male");
   set_body_type("faerie");
   set_race("Aekari");
   add_money("silver", 60);
   set_spell_chance(5);
   set_spells( ({ "whirl" }) );
   new("/wizards/danovae/pro/aekari/wea/wsword.c")->move(this_object());
   new("/wizards/danovae/pro/aekari/wea/wsword.c")->move(this_object());
      force_me("wield sword");
      force_me("wield sword 2");
}



