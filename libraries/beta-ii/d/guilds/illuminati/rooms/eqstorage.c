#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_short("Illuminati Equipment Supply Room");
     set_long("The Illuminati Equipment Supply Room. Get outta here biatch!");
     set_exits((["out" : ILROOM"itemshop.c"]));
}
void reset() {
   :: reset();

}
