#include <std.h>
#include <waterworld.h>
inherit MONSTER;
int counter;
int extra_xp;
int x;
void create()  {
  ::create();

  extra_xp=0;
  set_name("squid");
  set_id(({"squid","fish"}));
  set_short("a squid resting against the coral");
  set_long("This is one mean looking animal. Several muscular tentacles "
   "coil around the remains of its last victim which is too dismembered to recognize.");
  set_body_type("squid");
  set_race("squid");
  set_class("fighter");
  set_subclass("warrior");
  set_level(25);
  set_alignment(-50);
  set_stats("strength",40);
  set_gender("male");
  set_stats("dexterity",40);
  set_stats("constitution",40);
  set_money("gold",100);
  set_spells(({"whip","whirl","entangle"}));
  set_spell_chance(35);

  counter=(1+random(4));
  x=0;
  for(x;x<counter;x++)  {
    new(WEP2"tentacle.c")->move(this_object());
    force_me("wield tentacle 1");
    extra_xp=extra_xp+2000;
  }
  set_exp(query_exp()+extra_xp);
}
