#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("bandit");
    set_short("A sly Bandit");
    set_long("The Bandit is after valuables!");
    set_id(({"bandit", "sly bandit", "monster"}));
    set_level(12);
    set_race("troll");
    set_body_type("troll");
    set_gender("male");

new("/wizards/marduk/mine_shaft/cloak.c")->move(this_object());
this_object()->force_me("wear cloak");
new("/wizards/marduk/mine_shaft/knife.c")->move(this_object());
this_object()->force_me("wield knife");
}
