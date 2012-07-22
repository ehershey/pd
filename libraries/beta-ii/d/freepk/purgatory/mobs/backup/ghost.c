#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("A Ghost");
   set_short("A Ghost");
   set_id(({"ghost"}));
   set_long("This ghost is a spectre of the past trapped within a realm between the living and the truly dead. Fitful wailings emerge as small gusts of cold wind from the lips of this Ghost.");
   set_level(70+random(10));
   set_gender("male");
   set_race("Ghost");
   set_invis();
   set_skill("melee", 500);
   set_body_type("human");
   set_class("rogue");
   set_subclass("assassin");
   set_skill("stealth", 500);
   set_skill("perception", 500);
   force_me("stealth on");
   set_moving(1);
   set_speed(5);
}


