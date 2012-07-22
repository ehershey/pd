#include <std.h>
#include <venenum.h>
inherit BAG;

void create() {
    ::create();
    set_name("dead body");
    set_id( ({ "body", "corpse"}) );
    set_short("A corpse");
    set_long("This human corpse met a grisly end here in this dungeon. His body appears to have been run through with large spikes of some description, leading to his current demise. The force of the spikes is so great that it slashed right through the unfortunate person's armour, destroying it in the process. The force behind such damage is unbelievable.");
    set_mass(100);
    set_value(50);
    set_prevent_get("It is very disrespectful to move the bodies of the fallen.");

    new(WEP"greed.c")->move(this_object());
    new(ITEM"journal.c")->move(this_object());
    new(WEP"dagger.c")->move(this_object());
    new(WEP"dagger.c")->move(this_object());
    new("/std/obj/oil.c")->move(this_object());
    new("/std/obj/oil.c")->move(this_object());
    new("/std/obj/oil.c")->move(this_object());
}
