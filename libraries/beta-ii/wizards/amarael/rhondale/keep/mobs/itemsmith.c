#include <std.h>
#include <aziraphale.h>
inherit "/std/vendor";

void create() {
   ::create();
     set_id(({"vahlia"}));
     set_name("Vahlia the shopkeep");
     set_short("Vahlia, Generalstore Owner");
     set("aggressive", 0);
     set_level(30);
     set_long("Vahlia is the local shopkeeper. She buys and sells anything of value, and specialises in making teleportation scrolls.");
     set_languages(({ "selunian" }));
     set_type(({ "armour" }));
     set_gender("female");
     set_alignment(0);
     set_race("human");
     set_body_type("human");
     set_currency("gold");
     set_storage_room(KEEPROOM"itemstorage.c");
     set_skill("bargaining", 60);
     set_property("no bump", 1);
}
