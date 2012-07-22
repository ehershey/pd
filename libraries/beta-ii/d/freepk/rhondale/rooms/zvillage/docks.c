#include <std.h>
#include <aziraphale.h>
inherit DOCKS;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 1, "town" : 1]));
     set_name("Rhondale");
     set_short("Rhondale");
     set_day_long("The Rhondale docks go out over deep ocean. Here larger boats made for sailing rough seas can dock. If you have a boat you can board it here. If the boat is not here then %^RESET%^CYAN%^<recall boat>%^RESET%^. Once it is docked you may %^RESET%^CYAN%^<board (name)>%^RESET%^.");
     set_night_long("The Rhondale docks go out over deep ocean. Here larger boats made for sailing rough seas can dock. If you have a boat you can board it here. If the boat is not here then %^RESET%^CYAN%^<recall boat>%^RESET%^. Once it is docked you may %^RESET%^CYAN%^<board (name)>%^RESET%^");
     set_exits(([
		"east"			: KEEPROOM"zvillage/dockroad2.c"
                ]));
     set_listen("default", "The creaking of strained wood is everpresent.");
 set_letter("C");
}
