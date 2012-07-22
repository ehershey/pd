#include <std.h>
#include <illuminati.h>
#include <helgrath.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light":3, "indoors":1, "no scry":1]));
     set_name("Illuminati Helgrath Subhall");
     set_short("Illuminati Helgrath Subhall");
     set_long("%^ORANGE%^This is the Illuminati subhall of Helgrath, an outpost of the Tower of Light. Members come here to get away from the extreme cold of the frozen lands. Large chairs make a perfect spot to %^BOLD%^WHITE%^<relax>%^RESET%^ORANGE%^.%^RESET%^"); 
     set_exits(([
		"southeast"    : ROOMS"wilndursquare_wt.c"
		]));
     set_items(([
		"chairs"     : "The chairs are placed in a half circle facing inwards to a roaring fire. It would be great to %^CYAN%^<relax>%^RESET%^ in one."
]));
}

void reset() {
   ::reset();
     if(!present("portal"))
       new(ILOBJ"portal.c")->move(this_object());
}

void init() {
   ::init();
     add_action("sit", "relax");
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
}

int sit(string str) {
       write("You sit down in the comfy chair and relax in the warmth.");
       this_player()->set_hp(this_player()->query_max_hp());
       this_player()->set_sp(this_player()->query_max_sp());
       this_player()->set_mp(this_player()->query_max_mp());
       this_player()->set_paralyzed(3, "Ohhhhhh that feels good.");
       return 1;
}
