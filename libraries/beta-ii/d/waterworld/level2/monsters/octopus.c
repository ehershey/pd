#include <std.h>
#include <waterworld.h>
inherit MONSTER;
int counter;
int extra_xp;
int x;
void create() {
  ::create();

  extra_xp=0;
  set_name("octopus");
  set_id(({"octopus"}));
  set_long("It is a large grayish octopus with strong muscular tentacles. It seems to be eating anything that's not attached to the reef");
  set_short("a strong (and hungry) looking octopus");
  set_level(30);
  set_body_type("octopus");
  set_race("octopus");
  set_alignment(-50);
  set_stats("constitution",60);
  set_stats("strength",50);
  set_class("fighter");
  set_subclass("warrior");
  set_money("gold",100);
  set_spells(({"whip","whirl","entangle"}));
  set_spell_chance(35);
  counter=(1+random(4));
  x=0;
  for(x;x<counter;x++)   {
    new(WEP2"tentacle.c")->move(this_object());
    force_me("wield tentacle 1");
    extra_xp=extra_xp+2000;
  }
  set_exp(query_exp()+extra_xp);
}
