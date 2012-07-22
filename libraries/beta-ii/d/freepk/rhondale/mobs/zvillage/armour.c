#include <std.h>
#include <aziraphale.h>
inherit "/std/vendor";

void create() {
   ::create();
     set_id(({"garin", "smith", "armoursmith"}));
     set_name("Garin the smith");
     set_short("Garin, Armourer of Rhondale");
     set("aggressive", 0);
     set_level(30);
     set_long("Garin is a very old man. He has lived in Rhondale his entire life, and runs the local armour and general goods store.");
     set_languages(({ "selunian" }));
     set_type(({ "armour", "object", "other" }));
     set_gender("male");
     set_alignment(0);
     set_race("human");
     set_body_type("human");
     set_currency("gold");
     set_storage_room(KEEPROOM"zvillage/armourstorage.c");
     set_skill("bargaining", 50);
     set_property("no bump", 1);
}
