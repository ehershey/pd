#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_name("Rhondale East Road");
     set_short("Rhondale East Road");
     set_long("This road connects the eastern parts of the inner and outer circles of Rhondale to each other. To either side of the road can be seen the houses of merchants. This road usually empty during the day with every one out making a living.");
     set_exits(([
                "east"          : KEEPROOM"zvillage/outer0300.c",
                "west"          : KEEPROOM"zvillage/inner03.c",
                ]));
}
