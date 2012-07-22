#include <std.h>
#include <corinthor.h>
inherit ROOM;

void create() {
     object oi;
   ::create();
     set_properties((["light": 2, "night light" : 1, "indoors" : 1, "no attack" :1, "no steal" : 1, "no bump" : 1]));
     set_name("Rhondale South");
     set_short("Rhondale Square");
     set_day_long("The heart of Corinthor is here, in the majestic hollowed hall of Orn'Atar. This is where the elven people gather for any public events, as well as to do their day to day business. In the middle of this massive hall is a statue, along with a noticeboard set at its base. There are four ways out, one at each point of the compass.");
     set_night_long("The heart of Corinthor is here, in the majestic hollowed hall of Orn'Atar. This is where the elven people gather for any public events, as well as to do their day to day business. In the middle of this massive hall is a statue, along with a noticeboard set at its base. There are four ways out, one at each point of the compass.");
     set_exits(([
                "north"         : ELFROOM"npath1.c",
                "south"         : ELFROOM"spath1.c",
                "east"          : ELFROOM"epath1.c",
                "west"          : ELFROOM"wpath1.c"
                ]));

oi = new("/std/bboard");
oi->set_name("Corinthor Board");
oi->set_id( ({ "board" }) );
oi->set_board_id("Corinthor_Board");
oi->set_max_posts(99);
oi->set_edit_ok(({ "amarael", "stormbringer" }));
oi->set_location(ELFROOM"square.c");
oi->set("short", "Corinthian board of the Elves");
oi->set("long", "A board has been placed here so that any who wish may post public notices. \n");
}

void init() {
   ::init();
     add_action("starter", "start");
}

int starter(string str) {
    if (str != "here") {
       notify_fail("You may only start 'here'.\n");
       return 0;
       }
    write("You are now set to start in Corinthor, city of the Elves.");
    this_player()->set_primary_start(ELFROOM"square.c");
    return 1;
}
