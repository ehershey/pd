#include <std.h>
#include <lidelas.h>

inherit "/std/vendor.c";

void create() {
 ::create();
   set_name("Sabert");
   set_id( ({ "sabert", "vendor", "shop keeper", "keeper", "shopkeeper" }) );
   set_short("Sabert, the General Shop owner.");
   set("aggressive", 0);
   set_level(50);
   set_long("An old man who owns the only shop in Lidelas. He enjoys selling merchandise to the newcomers of the lands. To see a list of shop commands type <help shop>.\n");
   set_gender("male");
   set_alignment(340);
   set("race", "human");
   set_exp(0);
   set_body_type("human");
   set_property("no bump", 1);
   set_currency("copper");
   set_skill("bargaining", 100);
   set_storage_room(ROOMS "storage.c");



}
