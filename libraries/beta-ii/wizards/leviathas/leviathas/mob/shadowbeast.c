#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("shadow beast");
   set_id( ({ "beast" }) );
   set_short("%^BOLD%^%^BLACK%^Beast of the Shadows%^RED%^");
   set("aggressive", 1);
   set_level(90);
   set_long("%^BOLD%^%^BLACK%^The Beast of the Shadows stands here to watch the tower.");    
   set_body_type("human");
   set_class("monk");
   set_subclass("dark");
   set_spell_chance(70);
   set_spells( ({ "armageddon",}) );
   set_skill("melee", 300);
   set_skill("attack", 300);
   set("race", "shadowbeast");
   set_gender("male");


if(this_player()->query_race()!="vampire")force_me("kill"+this_player()->query_name());
}

