//Valleyman

#include <std.h>
#include <farm.h>
inherit MONSTER;

void create() {
    ::create();

    set_name("Goodman");
    set_id( ({"goodman", "man"}) );
    set_heart_beat(1);
    set_short("Goodman");
    set_long("The Goodman is standing in front of the fireplace stoking the fire.");
    set_race("human");
    set_gender("male");
    set_body_type("human");
    set_level(15);
    new(WEP"stoker.c")->move(this_object());
    command("wield stoker");
}
