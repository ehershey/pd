#include <std.h>
#include <illuminati.h>
inherit "/std/vendor";

void create() {
 ::create();
   set_name("Alannah");
   set_id(({"alannah", "shopkeeper"}));
   set_short("%^BOLD%^WHITE%^Alannah the shopkeeper%^RESET%^");
   set("aggressive", 0);
   set_level(30);
   set_long("Alannah keeps care of the general equipment for the illuminati.");
   set_languages(({ "selunian" }));
   set_type(({ "other", "object" }));
   set_gender("female");
   set_alignment(800);
   set_race("human");
   set_body_type("human");
   set_currency("gold");
   set_storage_room(ILROOM"eqstorage.c");
   set_skill("bargaining", 1);
   set_property("no bump", 1);
}

string query_guild() {
       return "illuminati";
}
