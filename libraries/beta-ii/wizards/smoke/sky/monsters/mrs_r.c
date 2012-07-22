#include <std.h>
#include <cp.h>
inherit MONSTER;

void create() {
  ::create();
  set_name("Mrs. Rockboot");
  set_id(({ "woman", "lady", "rockboot", "mrs rockboot" }));
  set_short("Mrs. Rockboot");
  set_long("This woman paces around her home muttering "
   "to herself. She has a scowl worn across "
   "her face. She looks like she's about ready "
   "to go off.");
  set_race("dwarf");
  set_class("fighter");
  set_subclass("warrior");
  set_body_type("dwarf");
  set("aggressive", 65);
  set_spell_chance(20);
  set_spells(({"rush", "jab", }));
  set_gender("female");
  set_level(74);
  set_emotes(10, ({"%^CYAN%^Mrs. Rockboot mutters:%^RESET%^ If Durg thinks "
    "I'll run his lunch to him every day he's got another "
    "thing coming.",
    "%^CYAN%^Mrs. Rockboot says:%^RESET%^ That moron can come down "
    "here and get his own food..."}), 0);
  new(ITEMS"lunchbox.c")->move(this_object());
}
