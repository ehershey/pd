#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
::create();
set_name("raknid worker");
set_id( ({ "worker","raknid","rshovel" }) );
set_short("A raknid worker");
set_long("This is a fairly small raknid. He has no rippling muscles or any"
        " type of facial features. You feel this is an easy prey.");
set("aggressive",35);
set_subclass("monk");
set_level(69);
set_skill("attack",100);
set_skill("blade",300);
set_race("raknid");
set_body_type("raknid");
set_gender("male");
new(WEP "shovel")->move(this_object());
force_me("wield shovel");
}
