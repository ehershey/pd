#include <std.h>
#include <dragonevent.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Ogre");
    set_id( ({ "ogre", "ogre6" }) );
    set_class("fighter");
    set_subclass("berserker");
    set_level(48);
    set_short("Ogre" );
    set_long("%^RESET%^%^GREEN%^This nasty looking ogre stands about 4 and a half feet taller than the average human. He has nasty %^BOLD%^%^YELLOW%^yellow teeth %^RESET%^%^GREEN%^that compliment his pale green skin.%^RESET%^" );
    set_race( "ogre" ); 
    set_gender( "male" );
    set_body_type("ogre");
    set_spells( ({ "pummel" }) );
    set_spell_chance(60); 
    set_skill("melee", 288);
    set_aggressive(13+random(13));
    if (random(10) < 3) set_swarm(1);
    new(DRAG_ARM "ogre_pants")->move(this_object());
    force_me("wear pants");
}
