#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("goblin security");
    set_short("A Goblin %^%^BLUE%^%^Se%^%^BLUE%^%^c%^%^RESET%^%^u%^%^BLUE%^%^r%^%^RESET%^%^i%^%^BLUE%^%^t%^%^RESET%^%^y Guard");
    set_long("The goblin has 'MAXWELL' tatooed on his arm.");
    set_id(({"security", "goblin", "guard", "monster"}));
    set_level(19);
    set_race("goblin");
    set_body_type("goblin");
    set_gender("male");
    set_emotes(10,
        ({"Maxwell eyes you suspiciously",
        }),
        0);           // 0 means outof battle, 1 means in battle
new("/wizards/marduk/mine_shaft/nightstick.c")->move(this_object());
this_object()->force_me("wield stick");
}
