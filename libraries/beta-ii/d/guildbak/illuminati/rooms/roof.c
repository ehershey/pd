#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light":3, "sky": 1, "no scry":1]));
     set_name("Illuminati Roof");
     set_short("Illuminati Roof");
     set_day_long("%^YELLOW%^The highest point of the Tower of Light is here upon the battlements. The roof gives a completely open view to the horizon in all directions, showing nothing but the endless ocean all around. The daytime sky is perfectly clear and filled with fluffly clouds.%^RESET%^");
     set_night_long("%^BOLD%^BLUE%^The highest point of the Tower of Light is here upon the battlements. The roof gives a completely open view to the horizon in all directions, showing nothing but the endless ocean all around. The night sky perfeclty clear and dazzling to behold.%^RESET%^");
     set_exits(([
		"down"          : ILROOM"floor5.c"
		]));
     set_items(([
		"clouds"        : "%^BOLD%^WHITE%^The clouds float above and all around you. Moving your hand through them you can feel that they are insubstantial. As the wind blows you feel as though you are flying.%^RESET%^", 
		"surroundings"  : "%^BOLD%^BLUE%^The ocean stretches out around you on all sides. Looking down you can see the base of the tower on a small island. Nothing else can be seen as far as the horizon.%^RESET%^"
		]));
}

void init() {
   ::init();
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
}
