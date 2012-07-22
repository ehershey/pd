#include <std.h>
#include <aziraphale.h>
inherit "/std/vendor";

void create() {
   ::create();
     set_id(({"cromnir", "smith", "weaponsmith"}));
     set_name("Cromnir the weaponsmith");
     set_short("Cromnir, Weaponsmith of Zartha");
     set("aggressive", 0);
     set_level(30);
     set_long("Cromnir is the weaponsmith of Zartha, he buys and sells all kinds weapons to keep his shop running.");
     set_languages(({ "selunian" }));
     set_type(({ "armour" }));
     set_gender("male");
     set_alignment(0);
     set_race("human");
     set_body_type("human");
     set_currency("gold");
     set_storage_room(KEEPROOM"weaponstorage.c");
     set_skill("bargaining", 60);
     set_property("no bump", 1);
}
