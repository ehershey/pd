#include <std.h>
inherit ROOM;
#include <guild.h>
void create() {
    ::create();
    set_short("Illuminati Weapon Supply Room");
    set_long("The Illuminati Weapon Supply Room. Get outta here biatch!");
    set_exits((["east" : ROOMS"illuminati/new/weapshop.c"]));
    new(ROOMS"illuminati/weapon/divine.c")->move(this_object());
    new(ROOMS"illuminati/weapon/divine.c")->move(this_object());
    new(ROOMS"illuminati/weapon/divine.c")->move(this_object());
    new(ROOMS"illuminati/weapon/divine.c")->move(this_object());
    new(ROOMS"illuminati/weapon/avenger.c")->move(this_object());
    new(ROOMS"illuminati/weapon/avenger.c")->move(this_object());
    new(ROOMS"illuminati/weapon/avenger.c")->move(this_object());
    new(ROOMS"illuminati/weapon/avenger.c")->move(this_object());
}
