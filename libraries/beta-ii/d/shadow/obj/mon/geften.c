inherit "/std/vendor";
#include <shadow.h>;
create() {
    ::create();
   set_name("geften");
   set_id( ({ "geften", "vendor", "shop keeper", "keeper", "shopkeeper" }) );
   set_short("Geften, the Jolly Smithy");
   set("aggressive", 0);
   set_level(12);
   set_long("Geften has taken a break from blacksmithing to attend to the "
        "customers in his shop.");
   set_languages( ({ "eltherian" }) );
   set_gender("male");
   set_alignment(40);
   set("race", "elf");
   set_hp(480);
   add_money("gold", random(100));
    set_storage_room(ROOMS "smithy.c");
   set_body_type("human");
   set_currency("gold");
   set_skill("melee",100);
   set_skill("bargaining", 150);
   set_property("no bump", 1);
}
int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in eltherian Oh my! I'm being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}
