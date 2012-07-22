#include <std.h>
#include <cp.h>
inherit MONSTER;

void create() {
  ::create();
  set_name("Bishop Brum Soulstone");
  set_id(({ "dwarf", "bishop", "brum", "brum soulstone", "bishop brum soulstone" }));
  set_short("Bishop Brum Soulstone");
  set_long("The Bishop is the head of this monestary. He is a "
   "highly respected authority figure in Steel Hammer Village. "
   "He is a kind soul who would do anything for anybody. Bishop "
   "Soulstone is one of the Village Elders and there isn't "
   "much that happens in the Village that he doesn't catch "
   "wind of.");
  set_race("dwarf");
  set_class("clergy");
  set_subclass("monk");
  set_body_type("dwarf");
  set("aggressive", 0);
  set_gender("male");
  set_level(110);
  set_spell_chance(70);
  set_spells(({"supplication me", "eagleclaw", "chistrike", "ironskin"}));
  new(ARM"monksrobe.c")->move(this_object());
  command("wear robe");
  new(ARM"sandals.c")->move(this_object());
  command("wear sandals");
}
