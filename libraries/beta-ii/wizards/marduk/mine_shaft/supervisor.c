#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("Arnold");
    set_short("A goblin supervisor");
    set_long("The supervisor feels big and mighty, with power over the workers.");
    set_id(({"supervisor", "goblin", "arnold"}));
    set_level(16);
    set_race("goblin");
    set_body_type("goblin");
    set_gender("male");
    set_emotes(30,
        ({"Arnold barks: Get to work scum!",
        }),
        0);

new("/wizards/marduk/mine_shaft/clipboard.c")->move(this_object());
}
