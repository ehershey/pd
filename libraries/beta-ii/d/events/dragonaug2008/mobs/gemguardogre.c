
#include <std.h>
#include <dragonevent.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("ogre");
  set_id( ({ "large ogre", "gem_carrying_ogre" }) );
  set_short("a large ogre");
  set_long("This ogre is quite tall and very muscular. He seems to be "
    "guarding something.");
  set_race("ogre");
  set_body_type("human");
  set_class("rogue");
  set_subclass("thief");
  set_aggressive("hide_and_stab");
  set_level(50);
  set_gender("male");
  set_alignment(-750);
  set_spell_chance(70);
  set_spells( ({ "slice", "seize", "snatch", "dodge", "pin", "dirt", "slice", "stab" }) );
  set_stats("strength", 90);
  set_stats("dexterity", 90);
  set_stats("intelligence", 25);
  set_max_hp(6000);
  set_hp(query_max_hp());
  set_says(6, ({
    "Harr harr we hided er unner der!",
  }), 1);
  new(DRAG_WEP+"knife")->move(this_object());
  command("wield knife");
  new(DRAG_WEP+"knife")->move(this_object());
  command("wield knife");
}

void set_color(string col) {
  if (col && file_exists(DRAG_ITEMS+col+"gem.c") && !sizeof(children(DRAG_ITEMS+col+"gem")))
    load_object(DRAG_ITEMS+col+"gem")->move(this_object());
}

void hide_and_stab() {
  object tp = this_player();
  command("hide gem under rocks");
  if (tp->is_player() && tp->query_level() >= 20 && !tp->query_invis() &&
      !query_current_attacker())
        call_out("force_me", 2, "backstab "+tp->query_name());
}

