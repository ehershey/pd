#include <std.h>
#include <sakura.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("balzina");
    set_short("Balzina the Troll Butcher");
    set_id(({"balzina"}));
    set_level(random(5)+17);
    set_race("troll");
    set_body_type("human");
    set_gender("female");
    set_long("More then eight feet tall, towering over even her brother trolls, Balzina is a force to be wreckoned with. Her claws are sharpened to perfection, and her stench is almost unbearable. Despite the obvious joy she gains from combat, her real joy comes from the butchery and cooking of her victims.");
    set_die( (: call_other, this_object(), "death_func":) );

    swarm = 1;

    new(OBJ"claw.c")->move(this_object());

}

int death_func() {

    message("say", "Gasping at her open wounds, Balzina stumbles back. Hissing madly at you, she tries in vain to hold in her lifeblood before slumping back against the wall.", environment(this_object()));
    return 1;
}


