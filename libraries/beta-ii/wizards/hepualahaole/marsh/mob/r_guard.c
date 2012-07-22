#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
::create();
set_name("raknid guard");
set_short("A raknid guard");
set_id( ({ "guard","raknid","r_guard","raknid guard" }) );
set_long("This is a fairly small raknid. He has no rippling muscles or any"
        " type of facial features. You feel this is an easy prey.");
set("aggressive",35);
set_subclass("monk");
set_level(60);
set_skill("attack",100);
set_skill("blade",300);
set_race("raknid");
set_body_type("raknid");
set_gender("male");
new(WEP "rsword")->move(this_object());
force_me("wield sword");
new(ARM "rshield")->move(this_object());
force_me("wear shield");
}
