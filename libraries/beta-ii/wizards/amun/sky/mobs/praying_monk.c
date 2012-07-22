#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Praying Monk");
    set_id( ({ "monk" "praying monk", "praying", "pray" }) );
    set_level( 60 );
    set_short("Praying Monk" );
    set_long("This monk is one of the most peaceful ones here, he prays day in and day out to his higher power." );
    set_race( "human" ); 
    set_gender( "male" );
    set_body_type("human");
    set_spells( ({ "chistrike", "eagleclaw" }) );
    set_spell_chance(60); 
    set_skill("melee", 250);
    set_class("clergy");
    set_subclass("monk");
    set_aggressive(40);
    set_alignment(1000);
    new(SKYARM "brown_robes")->move(this_object());
    new(SKYARM "rope_belt")->move(this_object());
    force_me("wear robes");
    force_me("wear belt");
}
