#include <std.h>
inherit ROOM;
#include <guild.h>
void create() {
    ::create();
    set_short("Illuminati Armour Supply Room");
    set_long("The Illuminati Armour Supply Room. Get outta here biatch!");
    set_exits((["west" : ROOMS"illuminati/new/armshop.c"]));
    new(ROOMS"illuminati/new/faithwings.c")->move(this_object());
    new(ROOMS"illuminati/new/frostring.c")->move(this_object());
    new(ROOMS"illuminati/new/frostring.c")->move(this_object());
    new(ROOMS"illuminati/armour/ilband.c")->move(this_object());
}

