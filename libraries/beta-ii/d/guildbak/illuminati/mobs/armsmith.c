#include <std.h>
#include <illuminati.h>
inherit "/std/vendor";

void create() {
::create();
set_name("Matthew");
set_id(({"matthew", "shopkeeper", "armoursmith", "smith"}));
set_short("%^BOLD%^WHITE%^Matthew the armoursmith%^RESET%^");
set("aggressive", 0);
set_level(30);
set_long("Matthew is the armoursmith for the Illuminati. He makes, repairs, sells and buys armour for guild members.");
set_languages(({ "selunian" }));
set_type(({ "armour" }));
set_gender("male");
set_alignment(0);
set_race("human");
set_body_type("human");
set_currency("gold");
set_storage_room(ILROOM"armstorage.c");
set_skill("bargaining", 1);
set_property("no bump", 1);
}

string query_guild() {
       return "illuminati";
}
