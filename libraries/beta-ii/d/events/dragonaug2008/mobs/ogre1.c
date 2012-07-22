#include <std.h>
#include <dragonevent.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Ogre");
    set_id( ({ "ogre", "ogre1" }) );
    set_class("fighter");
    set_subclass("berserker");
    set_level(35);
    set_short("Ogre" );
    set_long("%^RESET%^%^GREEN%^This nasty looking ogre stands about 2 feet taller than the average human. He has nasty %^BOLD%^%^YELLOW%^yellow teeth %^RESET%^%^GREEN%^that compliment his pale green skin.%^RESET%^" );
    set_race( "ogre" ); 
    set_gender( "male" );
    set_body_type("ogre");
    set_spells( ({ "rush" }) );
    set_spell_chance(60); 
    set_skill("melee", 210);
    set_aggressive(13+random(13));
    new(DRAG_ARM "ogre_pants")->move(this_object());
    new(DRAG_WEP "ogre_club")->move(this_object());
    force_me("wear pants");
    force_me("wield club");
}
