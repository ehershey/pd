#include <std.h>
#include <waterworld.h>
inherit MONSTER;
int counter;
int extra_xp;
int x;
void create() {
    ::create();

         extra_xp=0;
    set_name("orvis");
     set_id(({"orvis","octopus","dockhand"}));
     set_short("%^ORANGE%^Orvis%^RESET%^, the octopus dockhand");
      set_long("%^ORANGE%^Orvis%^RESET%^ is a brutish octopus that hauls the containers around the docks for Manatee Mike. He is carrying several large containers right now.....one in each tentacle!!");
      counter=(1+random(8));
    set_level(40+(counter*4));
    set_body_type("octopus");
       set_race("octopus");
    set_alignment(-50);
    set_class("fighter");
    set_subclass("ranger");
    set_money("gold",100);
    set_spells(({"whip","whirl"}));
       set_spell_chance(35);
       set_emotes(1,({
                   "%^ORANGE%^Orvis%^RESET%^ asks %^BLUE%^%^BOLD%^Blueboy%^RESET%^ about Manatee Mike.",
                   "%^ORANGE%^Orvis%^RESET%^ slings a couple of containers from %^BLACK%^%^BOLD%^Humpy%^RESET%^ onto the piles behind him.",
                  "%^ORANGE%^Orvis%^RESET%^ directs %^MAGENTA%^Oscar%^RESET%^ to start cleaning the barnacles off of the whales."
                     }),0);
//// Tenticle loader
          x=0;
         for(x;x<counter;x++)   {
            new(WEP2"tentacle.c")->move(this_object());
              force_me("wield tentacle 1");
             extra_xp=extra_xp+2000;
}
           }
