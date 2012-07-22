#include <std.h>
#include <durst.h>
inherit ROOM;
void create() {
   ::create();
	set_name("Rascij");
	set_short("Small Camp");
	set_properties(([
        "light"       : 2,        
        "night light" : 1,
        ]));
	set_day_long("A small tent has been set up here, it looks like it could hold around two people at most. An old bench has been placed near its entrance. It would appear that whomever has set up camp here plans to stay here for a while.");
	set_night_long("Not one sound can be heard, it sounds like a cemetary in all directions. Strange shadows appear everywhere, dancing around the campfire. Even the campfire is silent in this strange place.");
	set_items(([
            "tent"   : "A tattered old tent, it looks to be very old",
	]));
	set_exits( ([
	"northwest"  : ROOMS"rascij010.c",
	"east" : ROOMS"rascij012.c",
	"enter" : ROOMS"rascij023.c",
	]) );
}
void reset() {
   ::reset();
if (!present("camper", this_object()))
     new(MOB"camper.c")->move(this_object());
}
