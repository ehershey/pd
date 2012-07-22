#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
   ::create();
     set_short("Illuminati Equipment Supply Room");
     set_long("The Illuminati Equipment Supply Room. Get outta here biatch!");
     set_exits((["west" : ROOMS"illuminati/new/itemshop.c"]));
     new(ROOMS"illuminati/new/sphere.c")->move(this_object());
     new(ROOMS"illuminati/new/sphere.c")->move(this_object());
     new(ROOMS"illuminati/new/sphere.c")->move(this_object());
     new(ROOMS"illuminati/obj/black_hole.c")->move(this_object());
     new(ROOMS"illuminati/obj/black_hole.c")->move(this_object());
}
