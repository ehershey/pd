#include <std.h>
#include <illuminati.h>
#include <guild.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light":3, "indoors":1, "no scry":1]));
     set_no_clean(1);
     set_name("Illuminati Hall");
     set_short("Illuminati Hall");
     set_long("%^BOLD%^WHITE%^The Hall of Ages\n%^RESET%^ORANGE%^The main hall of the Illuminati, the room takes up the entire first floor of the Tower of Light. Pillars support the tower and windows line the walls. A portal leads to the meeting place of the guilds.%^RESET%^"); 
     set_exits(([
                "portal"       : ROOMS"meeting",
                "up"           : ILROOM"floor2",
                "north"        : ILROOM"entrance"
                ]));
     set_items(([
                "windows"       : "Large stained glass windows, each one portrays an image of a holy warrior.",
                "pillar"        : "A large marble pillar, it is very strong and very thick."
                ]));
}

void init() {
   ::init();
     add_action("dropin", "drop");
     add_action("startin", "start");
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
}

void reset() {
   ::reset();
     if(!present("silver chest"))
       new(ILOBJ"chest.c")->move(this_object());
}

int dropin(string str) {
    this_player()->force_me("put "+str+" in chest");
    return 1;
}


int startin(string str) {
    if(!str || str=="")
      return notify_fail("Start where?\n");
    if(str!="here")
      return notify_fail("You cannot start there.\n");
    this_player()->set_primary_start(ILROOM"newhall.c");
    write("You are now set to start here.");
    return 1;
}
