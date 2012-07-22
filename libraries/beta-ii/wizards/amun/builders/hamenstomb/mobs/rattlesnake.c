#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Rattlesnake");
    set("id", ({ "snake", "monster", "rattlesnake" }) );
    set_level( 50 );
    set("short", 
      "%^RESET%^%^ORANGE%^R%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^ttles%^BOLD%^%^WHITE%^n%^RESET%^%^ORANGE%^ake" );
    set("long", "%^RESET%^%^ORANGE%^The %^RESET%^%^ORANGE%^R%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^ttles%^BOLD%^%^WHITE%^n%^RESET%^%^ORANGE%^ake sits up ready to strike, as he rattles his tail frantically." );
    set("race", "snake" ); 
    set_gender( "male" );
    set_body_type("serpant");
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set_emotes(20, ({"%^RESET%^%^ORANGE%^The R%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^ttles%^BOLD%^%^WHITE%^n%^RESET%^%^ORANGE%^ake %^BOLD%^%^RED%^STRIKES%^RESET%^%^ORANGE%^ you!"}), 1);
    new(WEP+"poison_fangs")->move(this_object());
    new(WEP+"poison_fangs")->move(this_object());
    force_me("wield fangs");
    force_me("wield fangs 2");
}
