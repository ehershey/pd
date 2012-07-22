#include <std.h>
#include <corinthor.h>
inherit VENDOR;

void create() {
   ::create();
     set_id(({"shopkeeper", "storeperson", "elf", "feirian"}));
     set_name("feirian");
     set_short("Feirian the shopkeep");
     set_long("Feirian is a young elf who has learned the trade of forging weapons, and is a skilled trader besides.");
     set_languages(({ "pulchra" }));
     set_type(({ "weapon" }));
     set_level(10);
     set_gender("male");
     set_alignment(0);
     set_race("elf");
     set_body_type("elf");
     set_currency("gold");
     set_storage_room(ELFROOM"weaponstore.c");
     set_skill("bargaining", 80);
     set_property("no bump", 1);
}
