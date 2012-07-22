#include <std.h>
#include <djerr.h>
inherit VENDOR;

create() {
    ::create();
   set_name("Maritime Merchant");
   set_id( ({ "Merchant","monster" }) );
    set_short("A meritime merchanth");
   set("aggressive", 0);
  set_level(20);
    set_long("The elderly human merchant sells trade goods brought in to port by the sailors.");
    set_languages( ({ "farsi" }) );
   set_gender("male");
   set_alignment(40);
   set("race", "human");
   add_money("silver", random(1000));
    set_body_type("human");
    set_currency("silver");
    set_storage_room(ROOMS "naej_wharf_vault.c");
    set_skill("bargaining", 150);
    set_property("no bump", 1);
    set_property("no attack", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in farsi Noo! "+
      (string)previous_object()->query_cap_name()+" is trying to kill me!");
    return 0;
}
