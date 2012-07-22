#include <std.h>
#include <illuminati.h>
#include <tirun.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light":3, "indoors":1, "no scry":1]));
     set_name("Illuminati Tirun Subhall");
     set_short("Illuminati Tirun Subhall");
     set_long("%^ORANGE%^This is the Illuminati subhall of Tirun, an outpost of the Tower of Light. Members come here to get away from the crowds of city. Large chairs make a perfect spot to %^BOLD%^WHITE%^<relax>%^RESET%^ORANGE%^.%^RESET%^"); 
     set_exits(([
		"north"    : ROOMS"clergy/cleric/cleric_old.c"
		]));
     set_items(([
		"chairs"     : "The chairs are placed in a circle facing inwards around the center of the room. It would be great to sit in one."
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
       write("You sit down in the comfy chair and relax in the quiet.");
       this_player()->set_hp(this_player()->query_max_hp());
       this_player()->set_sp(this_player()->query_max_sp());
       this_player()->set_mp(this_player()->query_max_mp());
       this_player()->set_paralyzed(3, "Ohhhhhh that feels good.");
       return 1;
}
