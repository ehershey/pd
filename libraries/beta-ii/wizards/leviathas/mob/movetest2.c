#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("silver snake");
   set_id( ({ "snake" }) );
   set_short("%^RESET%^%^BOLD%^Silver Snake%^RED%^");
   set("aggressive", 1);
   set_level(50);
   set_long("This snake is silver.  It is extremely rare.");    
   set_body_type("human");
   set("race", "snake");
   set_gender("male");
   set_moving(1);
   set_speed(4);
}
