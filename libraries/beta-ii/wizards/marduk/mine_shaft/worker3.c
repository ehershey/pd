#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("mine worker");
    set_short("A Mine Worker");
    set_long("The goblin worker looks exhausted.");
    set_id(({"worker", "goblin", "monster"}));
    set_level(10);
    set_race("goblin");
    set_body_type("goblin");
    set_gender("male"); 

new("/wizards/marduk/mine_shaft/pickaxe.c")->move(this_object());
this_object()->force_me("wield pickaxe");
new("/wizards/marduk/mine_shaft/helmet.c")->move(this_object());
this_object()->force_me("wear helmet");
}
