//  Coded by Whit
//  Treasury for guilds
#include <std.h>
#include <guild.h>
#include <daemons.h>
#include <illuminati.h>

inherit TREASURY;

void create() {
   ::create();
     set_guild("illuminati");
     set_name("Illuminati Tower");
     set_long("%^ORANGE%^The treasury for the Illuminati, this is where the guilds "
       "gold is stored. The room is bare white everywhere except for a "
       "small inscription on the opposite wall. A large steel door leads "
       "north into the hall.  For a list of commands please "
       "%^BOLD%^WHITE%^<read sign>%^RESET%^");
     set_properties((["light":1, "night light":1, "indoors":1, "no scry" : 1]));
     set_items(([ "inscription" : "It's a sign you can read."]));
     set_short("Illuminati Tower");
     set_exits(([
		"north" : ILROOM"floor2",
                "up"    : ILROOM"ilbank.c",
      ]));
}

void init() {
   ::init();
      if(this_player()->query_guild() != "illuminati" && !wizardp(this_player())) 
       ILOBJ"ejection"->eject(this_player());
}
