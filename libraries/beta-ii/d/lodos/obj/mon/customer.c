#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("a customer");
   set_id(({ "customer", "thief" }));
   set_name("customer");
   set_level(18);
   set_long("The customer is looking around rather frantically. When she "
      "is sure you are not looking, she slips a potion into her robe. The "
      "little thief!");
   set_body_type("human");
   set_class("rogue");
   set_skill("stealing", 50);
   set_race("human");
   set_gender("female");
   add_money("silver", random(200));
   add_money("gold", random(5));
   add_money("copper", random(200));
}
