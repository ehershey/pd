#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("demon dagger");
   set_id( ({ "plant","demon dagger","cactus"}) );
   set_short("A demon dagger cactus");
   set_long("A large menacing cactus. This catus lives on the flesh of local animals and is very aggresive.");
   set_level(50);
   set_body_type("plant");
   set_alignment(0);
   set_race("cactus");
   set_property("no stun",1);
   set("aggressive", 50);

      }
