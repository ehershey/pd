#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
    set_short("Illuminati Tower");
    set_long("The Illuminati Weapon Supply Room. Get outta here biatch!");
    set_exits((["out" : ILROOM"weapshop.c"]));
    new(ILWEAPON"shortstaff.c")->move(this_object());
    new(ILWEAPON"shortstaff.c")->move(this_object());
    new(ILWEAPON"kratak.c")->move(this_object());
    new(ILWEAPON"kratak.c")->move(this_object());
    new(ILWEAPON"divine.c")->move(this_object());
    new(ILWEAPON"divine.c")->move(this_object());
}
