//Valleyman

#include <std.h>
#include <farm.h>
inherit MONSTER;

void create() {
    ::create();

    set_name("Goodwife");
    set_id( ({"goodwife", "wife"}) );
    set_heart_beat(1);
    set_short("Goodwife");
    set_long("The Goodwife bustles about her business humming a happy tune");
    set_race("human");
    set_gender("female");
    set_body_type("human");
    set_level(15);
    new(WEP"pan.c")->move(this_object());
    command("wield pan");
}
