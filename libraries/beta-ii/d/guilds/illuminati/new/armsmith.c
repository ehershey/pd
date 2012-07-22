#include <std.h>
#include <guild.h>
inherit "/std/vendor";

void create() {
::create();
set_name("Matthew");
set_id(({"matthew", "shopkeeper", "armoursmith", "smith"}));
set_short("%^BOLD%^%^WHITE%^Matthew, Armoursmith of the Illuminati%^RESET%^");
set("aggressive", 0);
set_level(30);
set_long("%^BOLD%^%^WHITE%^Matthew is the armoursmith for the Illuminati. He makes, repairs, sells and buys armour for guild members.%^RESET%^");
set_languages(({ "selunian" }));
set_type(({ "armour" }));
set_gender("male");
set_alignment(0);
set("race", "human");
set_body_type("human");
set_currency("gold");
set_storage_room(ROOMS"illuminati/new/armstorage.c");
set_skill("melee", 100);
set_skill("bargaining", 60);
set_property("no bump", 1);
}
