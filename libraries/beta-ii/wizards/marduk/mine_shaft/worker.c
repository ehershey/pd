#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("mine worker");
    set_short("A Mine Worker");
    set_long("The goblin worker looks exhausted.");
    set_id(({"worker", "goblin", "monster"}));
    set_level(12);
    set_race("goblin");
    set_body_type("goblin");
    set_gender("male"); 
    set_emotes(10,     // He will emote this line once every 20 heart beats
        ({"The Goblin says: Be carefull!",
          "The Goblin says: Watch your step!",
        }),
        0);           // 0 means outof battle, 1 means in battle

new("/wizards/marduk/mine_shaft/pickaxe.c")->move(this_object());
this_object()->force_me("wield pickaxe");
new("/wizards/marduk/mine_shaft/helmet.c")->move(this_object());
this_object()->force_me("wear helmet");
}
