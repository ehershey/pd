#include <std.h>
#include <arlon.h>
inherit MONSTER;
void create() {
::create();
set_name("Abomination");
set_short("Monstrous Abomination");
set_long("This towering pile of flesh is a mockery of life itself. Sinewy muscles wrap around its tremendous form, leathery wings sprout from its back, its huge hands end in cruel claws, large bony structures sprout from its back and shoulders, and its fangs protrude from its mouth.");
set_id(({"abomination", "monster", "guardian"}));
set_level(50);
set_race("abomination");
set_body_type("imp");
set_gender("male");
    set_emotes(2,
        ({"%^CYAN%^The Abomination attempts to gouge your eyes out!",
        }),
        0);
new(ARM"fpsa.c")->move(this_object());
command("wear armour");
}
