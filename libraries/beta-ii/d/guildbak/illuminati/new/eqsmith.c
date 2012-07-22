#include <std.h>
#include <guild.h>
inherit "/std/vendor";

void create() {
 ::create();
   set_name("Alannah");
   set_id(({"alannah", "shopkeeper"}));
   set_short("%^BOLD%^%^WHITE%^Alannah, Keeper of Equipment%^RESET%^");
   set("aggressive", 0);
   set_level(30);
   set_long("Alannah keeps care of the general equipment for the illuminati.");
   set_languages(({ "selunian" }));
   set_type(({ "other", "object" }));
   set_gender("female");
   set_alignment(0);
   set("race", "human");
   set_body_type("human");
   set_currency("gold");
   set_storage_room(ROOMS"illuminati/new/eqstorage.c");
   set_skill("melee", 100);
   set_skill("bargaining", 60);
   set_property("no bump", 1);
}
