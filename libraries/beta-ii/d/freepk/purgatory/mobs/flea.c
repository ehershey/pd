#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("Sand flea");
   set_short("sand flea");
   set_id(({"monster", "flea", "sand flea"}));
   set_long("A small mite of a flea that has mutated into a HUGE biting foe!! Youd better run before you get the itch of your life!");
    set_level(63+random(10));
   set("aggressive", 25);
   set_gender("female");
   set_race("flea");
   set_body_type("insectoid");


}
