#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light":3, "indoors":1, "no scry":1]));
     set_name("Illuminati Tower");
     set_short("Illuminati Tower");
     set_long("%^ORANGE%^The fifth floor of the Illuminati's Tower of Light holds the various training areas for each of the five adventuring types known throughout the realms: Fighter, Clergy, Mage, Rogue, Wanderer.%^RESET%^");
     set_exits(([
                "down"          : ILROOM"floor4.c",
                "up"            : ILROOM"roof.c",
                "northeast"     : ILROOM"neturret5.c",
                "northwest"     : ILROOM"nwturret5.c",
                "west"		: ILROOM"fighterh.c",
                "southwest"	: ILROOM"clergyh.c",
                "south"		: ILROOM"mageh.c",
                "southeast"	: ILROOM"rogueh.c",
                "east"		: ILROOM"wandererh.c"
                ]));
}

void init() {
   ::init();
     add_action("lookin", "peer");
     add_action("enterin", ({ "south", "southwest", "southeast", "east", "west"}));
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
}

int enterin(string str) {
    string hall, classn;
    if(str && str != "")
      return 0;
    hall = query_verb();
    switch(hall) {
      case "west" 	: classn = "fighter"; break;
      case "southwest" 	: classn = "clergy"; break;
      case "south" 	: classn = "mage"; break;
      case "southeast" 	: classn = "rogue"; break;
      case "east" 	: classn = "wanderer"; break;
      default		: classn = "fail"; break;
      }
    if(classn != this_player()->query_class() && !wizardp(this_player())) {
      message("info", "As a "+this_player()->query_class()+" you may not enter a hall of the "+classn+".", this_player(), );
      return 1;
      }
    else {
      message("info", "You are admitted into the Illuminati hall of the "+classn+".\n", this_player(), );
      return 0;
      }
    message("bug", "ERROR: This shouldn't happen!", this_player(), );
    return 1;
}

int lookin(string str) {
    string *disallow;
    disallow = ({ "south", "southwest", "southeast", "east", "west", "s", "sw", "se", "e", "w" });
    if(member_array(str, disallow) == -1)
      return 0;
    else {
      message("info", "The halls are closed off from view.", this_player(), );
      return 1;
      }
    message("bug", "ERROR: This shouldn't happen!", this_player(), );
    return 1;
}
