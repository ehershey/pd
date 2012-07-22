// There is a known issue with the mimic. The corpse 
// of the mimic monster remains around for one round 
// after it dies; this is because if the call_out
// function in the broken chest is set to 0, instantly,
// the corpse hasn't appeared yet and thusly isn't
// removed at all.

#include <std.h>
#include <sakura.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("mimic");
    set_short("A Chest-Like Mimic");
    set_id(({"mimic"}));
    set_level(15);
    set_race("Mimic");
    set_body_type("");
    set_gender("neuter");
    set_long("This very ornately decorated and expensive chest has no visible locking mechanism of any sort. In fact, the chest's lid is wide open, probably busy devouring you.");
    set_die( (: call_other, this_object(), "death_func":) );

    call_out("no_chest",0);

}

int death_func() {

    message("say", "The chest shatters into chunks of wood, blood leaking out through the cracks.", environment(this_object()));
    new(OBJ"broken_chest.c")->move(environment(this_object()));
    this_object()->move("/d/nopk/standard/void.c");
    return 1;
}

int no_chest() {

    if(present("chest"))
    {
	present("chest")->remove();
    }

}
