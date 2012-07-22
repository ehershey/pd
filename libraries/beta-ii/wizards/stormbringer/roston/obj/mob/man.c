#include <std.h>
#include <roston.h>
inherit MONSTER;

void create() {
::create();
    set_name("drifter");
    set_short("drifter");
    set_long("An old drifter freezing in the cold.");
    set_id(({"drifter", "dwarf"}));
    set_level(20+random(10));
    set_race("dwarf");
    set_body_type("human");
    set_gender("male");
    add_money("gold", random(2));

   if(random(200) > 190) {
   new("/wizards/daboura/arm/dull_brass_bracers.c")->move(this_object());
   }
}