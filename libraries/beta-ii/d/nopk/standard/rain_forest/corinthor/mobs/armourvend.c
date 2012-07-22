#include <std.h>
#include <corinthor.h>
inherit VENDOR;

void create() {
   ::create();
     set_id(({"shopkeeper", "storeperson", "elf", "aramil"}));
     set_name("aramil");
     set_short("Aramil the shopkeep");
     set_long("Aramil is an elf skilled in the forging of armour, and also in the art of bargaining. He buys and sells armour in Corinthor");
     set_languages(({ "pulchra" }));
     set_type(({ "armour" }));
     set_level(10);
     set_gender("male");
     set_alignment(0);
     set_race("elf");
     set_body_type("elf");
     set_currency("gold");
     set_storage_room(ELFROOM"armourstore.c");
     set_skill("bargaining", 80);
     set_property("no bump", 1);
}
