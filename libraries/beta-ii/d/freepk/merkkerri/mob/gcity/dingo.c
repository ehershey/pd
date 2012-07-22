#include <gcity.h>
inherit "/std/vendor";

create() {
    ::create();
set_name("dingo");
set_id(({"dingo", "vendor", "shop keeper", "keeper", "shopkeeper", "gnoll"}));
set_short("Dingo, the store owner");
   set("aggressive", 0);
set_level(30);
set_long("Dingo has been through many adventures and shows it.  He has several scars and walks with a noticable limp.  To see a list of shop commands type <help shop>.\n");
    set_languages( ({ "farsi" }) );
   set_gender("male");
set_alignment(-100);
set_race("gnoll");
   add_money("gold", random(200));
set_body_type("gnoll");
set_currency("gold");
set_storage_room(GCITY "storage.c");
   set_skill("melee",100);
    set_skill("bargaining", 100);
    set_property("no bump", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
this_object()->force_me("shout in merkish Help!! I am being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}
