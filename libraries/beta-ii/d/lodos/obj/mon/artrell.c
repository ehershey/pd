#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
    ::create();
    set_short("a raknid");
    set_id(({ "artrell" }));
    set_name("raknid");
    set_level(25);
    set_long("The artrell is part of the gang of fighters. He is not very "
      "strong, but is insanely fast.");
    set_body_type("raknid");
    set_race("raknid");
    set_gender("male");
    set_heart_beat(1);
    set_alignment(-250);
    make(ARM"artgaunt");
    make(ARM"artbrace");
}

void heart_beat() {
    ::heart_beat();
    if (!oi) {
	force_me("wear gauntlets");
	force_me("wear bracers");
	oi = 1;
    }
}
