#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("behir");
   set_id( ({ "behir" }) );
   set_short("A Behir");
   set("aggressive", 1);
   set_level(1);
   set_long("This is a Behir.  It has a snake-like body and many legs.");    
   set_body_type("snake");
   set("race", "behir");
   set_gender("neuter");


}
