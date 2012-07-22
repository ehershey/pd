#include <std.h>
#include <corinthor.h>
inherit VENDOR;

void create() {
   ::create();
     set_id(({"shopkeeper", "storeperson", "elf", "liaqui"}));
     set_name("liaqui");
     set_short("Liaqui the shopkeep");
     set_long("Liaqui has taken over the local general goods business. She is a rather pretty elf, and uses this to her advantage againt outsiders.");
     set_languages(({ "pulchra" }));
     set_type(({ "object" }));
     set_level(10);
     set_gender("male");
     set_alignment(0);
     set_race("elf");
     set_body_type("elf");
     set_currency("gold");
     set_storage_room(ELFROOM"objectstore.c");
     set_skill("bargaining", 90);
     set_property("no bump", 1);
}
