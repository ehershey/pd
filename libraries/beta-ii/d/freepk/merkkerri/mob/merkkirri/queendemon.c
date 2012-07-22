#include <std.h>
#include <mjungle.h>
#include <gcity.h>

inherit MOB+"queen";

void create() {
  ::create();
  set_id(query_id() + ({ "demon", "demon queen" }) );
  set_short("Shallzaea, the Demon mistress");
  set_long(
    "Shallzaea is actually a demon in disguise as a gnoll! "
    "Her body is sleek and black, her wings large and imposing and "
    "her eyes burn with the flames of Hell!"
  );
  set_aggressive(600);
  set_alignment(-1000);
  set_race("demon");
  set_body_type("demon");
  set_spells(query_spells() + ({ "demonfire", "vortex", "gore" }) );
  set_die(0);
  set_languages( ({ "merkish", "kanashi" }) );
  set_speech(50, "kanashi", ({
    "You know my secret, you must die!",
    "Your death is unavoidable now...",
    "My power is infinite!",
    "Wretched creature!",
    "Feel the wrath of a true demon!"
  }), 1);
  new(MOB "cloakofmidnight.c")->move(this_object());
  command("wear cloak");
  new(GCITY "ruby_key.c")->move(this_object());
  set_level(70);
set_stats("wisdom", query_stats("wisdom") * 150 / 100);
  // the fake queen is level 65 and gives 0 exp,
  // so give them all the exp here (65 + 70 = 135)
  set_exp(135000);
}
