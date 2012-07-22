#include <std.h>
#include <illuminati.h>

inherit ROOM;

void init() {
   ::init();
     add_action("startin", "start");
     add_action("peerin", "peer");
     add_action("downme", ({ "down", "d" }));
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
}

int startin(string str) {
    if(!str || str=="")
      return notify_fail("Start where?\n");
    if(str!="here")
      return notify_fail("You cannot start there.\n");
    this_player()->set_primary_start(ILROOM+this_player()->query_name()+".c");
    write("You are now set to start here.");
    return 1;
}

int peerin(string str) {
    if(str != "d" && str != "down")
      return 0;
    message("info", "The view of the hall is blocked.", this_player(), );
    return 1;
}

int downme() {
    this_player()->move_player(ILROOM+this_player()->query_class()+"h", "down");
    return 1;
}
