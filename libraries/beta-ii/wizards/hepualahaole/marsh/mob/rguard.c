#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
::create();
set_name("raknid guard");
set_short("A raknid guard");
set_id( ({ "guard","raknid","r_guard","raknid guard" }) );
set_long("He sitting around admiring his new weapon.  He "
        "doesn't know that you entered the area.");
set_subclass("monk");
set_level(60);
set_skill("attack",100);
set_skill("axe",300);
set_race("raknid");
set_body_type("raknid");
set_gender("male");
new(WEP "axe")->move(this_object());
force_me("wield axe");
}
