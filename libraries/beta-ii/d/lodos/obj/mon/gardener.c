#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("a busy gardener");
   set_id( ({ "gardener" }) );
   set_name("gardener");
   set_level(23);
   set_long("The gardener busily pulls weeds out of the ground. His "
     "clothes are muddy and tarnished.");
   set_body_type("human");
   set_race("human");
   set_gender("male");

}
