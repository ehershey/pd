#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
     object oi;
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1, "no attack" :1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
     set_name("Rhondale South");
     set_short("Rhondale Square");
     set_day_long("%^RESET%^CYAN%^Rhondale Village Square%^RESET%^\nThe town square at day is filled with commoners and merchants going about their daily business. Amongst all the hustle and bustle stands a single fountain, with a few people idly standing around it to pass the time.");
     set_night_long("%^RESET%^CYAN%^Rhondale Village Square%^RESET%^\nThe square is all but empty during the night. A few lamps keep the place well lit, and every now and then a guard passes through. A few people are standing around a beautiful fountain.");
     set_exits(([
                "north"         : KEEPROOM"zvillage/insqnorth.c",
                "south"         : KEEPROOM"zvillage/insqsouth.c",
                "east"          : KEEPROOM"zvillage/insqeast.c",
                "west"          : KEEPROOM"zvillage/insqwest.c"
                ]));
oi = new("/std/bboard");
oi->set_name("Rhondale Board");
oi->set_id( ({ "board" }) );
oi->set_board_id("Rhondale_Board");
oi->set_max_posts(99);
oi->set_edit_ok(({ "amarael", "stormbringer" }));
oi->set_location(KEEPROOM"zvillage/[].c");
oi->set("short", "Rhondale board of hunters");
oi->set("long", "The board has been placed up by the fountain for travelers to post important information. \n");
}

void init() {
   ::init();
     add_action("starter", "start");
}

int starter(string str) {
    if (str != "here") {
       notify_fail("You may only start here.\n");
       return 0;
       }
    write("You are now set to start on the village of Rhondale.");
    this_player()->set_primary_start(KEEPROOM"zvillage/[].c");
    return 1;
}

void reset() {
   ::reset();
     if (!present("fountain"))
        new(KEEPARMOUR"zvillage/sqfountain.c")->move(this_object());
     if (!present("guard")) {
        new(KEEPMOB"zvillage/townguard.c")->move(this_object());
        }
}
