#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
   ::create();
   set_gender("female");
   set_name("mouse");
   set_id( ({ "mouse"}) );
   set_short("mouse");
   set_long("A cute little creature, standing on it's hind legs begging for food");
   set_level(35);
   set_body_type("ferrel");
   set_alignment(15);
   set_race("rodent");
      }
