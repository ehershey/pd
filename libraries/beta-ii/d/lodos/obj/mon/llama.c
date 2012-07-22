#include <std.h>
#include <lodos.h>
inherit MOUNT;
static int oi;

void create() {
 ::create();
   set_short("a llama");
   set_id(({ "llama" }));
   set_name("llama");
   set_level(18);
   set_long("The fierce llama was trained by a gang of fighters "
      "as a joke. It has gotten loose and is wreaking havok upon "
      "the countryside.");
   set_body_type("quadrupe");
   set_spells(({ "emote aims for your throat!", "headbutt", "say Just bring it!" }));
   set_spell_chance(40);
   set_class("fighter");
   set_race("llama");
   set_gender("male");
   set_heart_beat(1);
}
