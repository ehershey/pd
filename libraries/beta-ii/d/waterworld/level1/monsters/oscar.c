#include <std.h>
#include <waterworld.h>
inherit MONSTER;
int counter;
int extra_xp;
int x;
void create() {
    ::create();

         extra_xp=0;
    set_name("oscar");
     set_id(({"oscar","octopus","dockhand"}));
    set_long("%^MAGENTA%^Oscar%^RESET%^ the octopus dockhand isn't as powerful as his brother %^ORANGE%^Orvis%^RESET%^. He does mannage to carry several of the smaller containers in his tentacles just like his bigger brother can.");
    set_short("%^MAGENTA%^Oscar%^RESET%^, the Octopus dockworker.");
     counter=(1+random(8));
    set_level(30+(4*counter));
    set_body_type("octopus");
       set_race("octopus");
    set_alignment(-50);
    set_class("fighter");
    set_subclass("ranger");
    set_money("gold",100);
    set_spells(({"whip","whirl"}));
       set_spell_chance(35);
          x=0;
//// tenticle loader
         for(x;x<counter;x++)   {
            new(WEP2"tentacle.c")->move(this_object());
              force_me("wield tentacle 1");
             extra_xp=extra_xp+2000;
}
}
