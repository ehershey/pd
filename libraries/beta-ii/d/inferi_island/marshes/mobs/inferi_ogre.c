#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Inferi Ogre");
    set("id", ({ "monster", "inferi", "ogre" }) );
    set_level( 30 );
    set("short", "Inferi Ogre" );
    set("long", "%^RESET%^%^RED%^These creatures dwell in the %^BOLD%^%^CYAN%^cold %^RESET%^%^RED%^and %^BOLD%^%^BLACK%^darkness%^RESET%^%^RED%^, they fear %^BOLD%^%^YELLOW%^light %^RESET%^%^RED%^and %^BOLD%^%^RED%^warmth%^RESET%^%^RED%^.%^RESET%^" );
    set("race", "ogre" );
    set_gender( "female" );
    set_body_type("ogre");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 5);
    set_skill("melee", 100);
    set_class("fighter");
    set("aggressive", 25);
    new(MARSHWEP+"great_sword")->move(this_object());
    new(MARSHARM+"rusty_breastplate")->move(this_object());
    force_me("wear armour");
    force_me("wield sword");
}
