
#include <std.h>
#include <vplain.h>

inherit MONSTER;

int do_sing(string str);

void create() {
  ::create();
  set_name("nymph");
  set_race("nymph");
  set_body_type("human");
  set_gender("female");
  set_level(40);
  set_class("wanderer");
  set_subclass("bard");
  set_skill("knife", 60);
  set_skill("blade", 60);
  set_id(({"nymph"}));
  set_short("nymph");
  set_long("She has a fair complexion and long flowing "+
    ({"blonde","brown","black","red"})[random(4)]+" hair. "
    "Her graceful body is covered by a knee-length dress.");
  set_spells(({"singasong"}));
  set_spell_chance(20);
  add_action("do_sing", "singasong");

  force_me("wear dress");
}

int do_sing(string str) {
  object a;
  if (this_player() != this_object())
    return 0;
  else{
    if (a=query_current_attacker())
      this_object()->force_me("sing song of "+({"blades","winter"})[random(2)]+" to "+a->query_name());
    return 1;
  }
}

void init() {
  ::init();
  add_action("do_sing", "singasong");
}
