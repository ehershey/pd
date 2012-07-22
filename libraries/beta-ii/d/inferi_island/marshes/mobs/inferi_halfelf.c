#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Inferi Half-Elf");
    set("id", ({ "monster", "inferi", "halfelf" }) );
    set_level( 30 );
    set("short", "Inferi Half-Elf" );
    set("long", "%^RESET%^%^RED%^These creatures dwell in the %^BOLD%^%^CYAN%^cold %^RESET%^%^RED%^and %^BOLD%^%^BLACK%^darkness%^RESET%^%^RED%^, they fear %^BOLD%^%^YELLOW%^light %^RESET%^%^RED%^and %^BOLD%^%^RED%^warmth%^RESET%^%^RED%^.%^RESET%^" );
    set("race", "half-elf" ); 
    set_gender( "male" );
    set_body_type("half-elf");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 5); 
    set_skill("melee", 100);
    set_class("rogue");
    set("aggressive", 25);
    new(MARSHWEP+"chipped_dagger")->move(this_object());
    new(MARSHARM+"tattered_rags")->move(this_object());
    force_me("wear shirt");
    force_me("wield dagger");
}
