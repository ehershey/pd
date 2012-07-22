#include <std.h>
#include <aziraphale.h>
inherit "/std/vendor";

void create() {
   ::create();
     set_id(({"garr", "smith", "armoursmith"}));
     set_name("Garr the smith");
     set_short("Garr, Zarthan Armoursmith");
     set("aggressive", 0);
     set_level(30);
     set_long("Garr is a very old man. He has lived in Zartha his entire life, and runs the local armoursmithy.");
     set_languages(({ "selunian" }));
     set_type(({ "armour" }));
     set_gender("male");
     set_alignment(0);
     set_race("human");
     set_body_type("human");
     set_currency("gold");
     set_storage_room(KEEPROOM"armourstorage.c");
     set_skill("bargaining", 60);
     set_property("no bump", 1);
}
