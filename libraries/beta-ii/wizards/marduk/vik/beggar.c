#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("human");
    set_short("A poor beggar");
    set_long("The beggar sits here all day hoping for someone to "
	"take pity upon him.");
    set_id(({"human", "poor beggar", "beggar"}));
    set_level(24);
    set_race("human");
    set_body_type("human");
    set_gender("male");
    set_emotes(1005,
	({"The beggar holds out his hand for some money.",
	  "The beggar looks at you with pleading eyes.",
	}),
	0);

new("/wizards/marduk/vik/vest.c")->move(this_object());
this_object()->force_me("wear vest");
}
