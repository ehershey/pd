#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("a knight's squire");
   set_id( ({ "squire" }) );
   set_name("squire");
   set_level(18);
   set_long("The squire dreams to some day grow up to be like the his "
      "hero, the knight he works under.");
   set_body_type("human");
   set_race("human");
   set_gender("male");
}
