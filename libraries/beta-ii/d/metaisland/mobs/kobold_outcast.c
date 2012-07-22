#include <std.h>
#include <metallicana.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("Kobold Outcast");
   set_id(({"kobold", "outcast", "Kobold Outcast"}));
   set_short("Kobold Outcast");
   set_long("A small kobold, he doesnt look much but he has been "
       "outcast from his village for hidious acts of violence, "
       "he looks at you and licks his lips.");
   set_gender("male");
   set_race("kobold");
   set_body_type("human");
   set_level(37);
   new(ARM "palm_boots")->move(this_object());
   force_me("wear boots");
   new(WEP "butterfly_knife.c")->move(this_object());
   force_me("wield knife");
}
