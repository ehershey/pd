#include <std.h>
#include <aziraphale.h>
inherit "/std/vendor";

void create() {
   ::create();
     set_id(({"shopkeeper", "dx'zal"}));
     set_name("Dx'zal");
     set_short("Dx'zal the shopkeeper");
     set_level(60);
     set_long("Dx'zal oversees the Kra'Toa'Kathor marketplace, and does a fair bit of buying and selling himself. Although he has spent his life trading, he always does a fair deal.");
     set_languages(({ "dragonian" }));
     set_type(({ "armour", "weapon", "other" }));
     set_gender("male");
     set_alignment(0);
     set_race("Kra'Toan");
     set_body_type("human");
     set_currency("gold");
     set_storage_room(KEEPROOM"zforest/kratoan/storage.c");
     set_skill("bargaining", 20);
     set_property("no bump", 1);
}

void die() {
   KEEPARMOUR"/zforest/kratoan/checkkill"->do_kill_check(this_object()->query_current_attacker());
   ::die(1);
}

void init() {
   ::init();
   if(this_player()->query_property("killermark") == 1) {
     this_object()->kill_ob(this_player());
   }
}
