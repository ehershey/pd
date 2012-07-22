#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_short("Illuminati Equipment Supply Room");
     set_long("The Illuminati Equipment Supply Room. Get outta here biatch!");
     set_exits((["out" : ILROOM"itemshop.c"]));
     new(ILOBJ"bpack.c")->move(this_object());
     new(ILOBJ"sphere.c")->move(this_object());
     new(ILOBJ"sphere.c")->move(this_object());
     new(ILOBJ"sphere.c")->move(this_object());
     new(ILOBJ"ilseal.c")->move(this_object());
     new(ILOBJ"ilseal.c")->move(this_object());
     new(ILOBJ"ilseal.c")->move(this_object());
     new(ILOBJ"blackhole.c")->move(this_object());
     new(ILOBJ"blackhole.c")->move(this_object());
     new(ILOBJ"blackhole.c")->move(this_object());
}
