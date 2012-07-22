#include <std.h>
#include <illuminati.h>
inherit ROOM;

void create() {
  ::create();
    set_short("Illuminati Tower");
    set_long("The Illuminati Armour Supply Room. Get outta here biatch!");
    set_exits((["out" : ILROOM"armshop.c"]));
    new(ILOBJ"crestspawn.c")->move(this_object());
    new(ILOBJ"ilbandspawn.c")->move(this_object());
    new(ILARMOUR"lwingbracer.c")->move(this_object());
    new(ILARMOUR"rwingbracer.c")->move(this_object());
    new(ILARMOUR"faithwings.c")->move(this_object());
    new(ILARMOUR"frostring.c")->move(this_object());
    new(ILARMOUR"frostring.c")->move(this_object());
}
