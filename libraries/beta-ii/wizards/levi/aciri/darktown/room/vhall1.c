#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("Deathless hall");
    set_day_long("This is a short but massive hall.  Beautiful paintings and statues line either side of it and a tiny door is closed at the end. "
        "The walls, floor and ceiling are made of ivory and there are no noticable lines, as if the whole hall was carved out of a giant chunk of it. "
        "Massive pillars rocket up and brace the awesome weight of the ceiling.");
    
    set_night_long("This is a short but massive hall.  Beautiful paintings and statues line either side of it and a tiny door is closed at the end. "
        "The walls, floor and ceiling are made of ivory and there are no noticable lines, as if the whole hall was carved out of a giant chunk of it. "
        "Massive pillars rocket up and brace the awesome weight of the ceiling.");
    
    set_items(([
          "hall" : "It is empty and silent...",
          "paintings" : "The eyes in the paintings would appear to be watching you walk by.",
          "statues" : "Elegantly clad lords and ladies seem to be frozen in the middle of a dance..",
          "ivory" : "The ivory is quite white and bright.",
          "pillars" : "They hold the ceiling up, Sherlok.",
                        
                
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "vhall2.c",
       ]));
}

void init() {
 ::init();
   add_action("mansion", "leave");
}

int mansion(string str) {
   if (!str || str != "mansion") return notify_fail("Leave what?\n");
   write("The glass doors open.  You step outside.");
   this_player()->move_player( ROOMS  "dtownmp3.c");
   return 1;
}
