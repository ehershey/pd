#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("A room of silver.");
    set_day_long("%^BOLD%^This room is made completely of silver.  %^RESET%^%^ORANGE%^Gargoyles %^RESET%^%^BOLD%^and %^RESET%^%^MAGENTA%^vampires%^RESET%^%^BOLD%^ have been carved out of the walls and %^RESET%^%^RED%^b%^BOLD%^l%^RESET%^oo%^RED%^d%^RESET%^%^BOLD%^ trickles out of their mouthes like a fountain.  There is a throne in the centre of the room on an elevated pentagram.  A rim forms around the room but in between it and the pentagram, %^RED%^b%^BOLD%^l%^RESET%^o%^RED%^%^BOLD%^o%^RESET%^%^RED%^d %^RESET%^%^BOLD%^flows %^RED%^cri%^RESET%^%^RED%^m%^BOLD%^son%^RESET%^%^BOLD%^.  Suspended from the ceiling is a man made of some %^BLACK%^sh%^RESET%^%^BOLD%^im%^RESET%^me%^BOLD%^r%^BLACK%^ing%^RESET%^%^BOLD%^ rock that seems less silver but more beautiful. %^RESET%^%^RED%^B%^BOLD%^l%^RESET%^o%^BOLD%^%^RED%^o%^RESET%^%^RED%^d%^RESET%^%^BOLD%^ pours out of it's mouth and into a small, cylindrical hole in the centre of the pentagram, a couple of inches away from the base of the th%^RED%^ro%^RESET%^%^BOLD%^ne. "); 
    set_night_long("%^BOLD%^This room is made completely of silver.  %^RESET%^%^ORANGE%^Gargoyles %^RESET%^%^BOLD%^and %^RESET%^%^MAGENTA%^vampires%^RESET%^%^BOLD%^ have been carved out of the walls and %^RESET%^%^RED%^b%^BOLD%^l%^RESET%^oo%^RED%^d%^RESET%^%^BOLD%^ trickles out of their mouthes like a fountain.  There is a throne in the centre of the room on an elevated pentagram.  A rim forms around the room but in between it and the pentagram, %^RED%^b%^BOLD%^l%^RESET%^o%^RED%^%^BOLD%^o%^RESET%^%^RED%^d %^RESET%^%^BOLD%^flows %^RED%^cri%^RESET%^%^RED%^m%^BOLD%^son%^RESET%^%^BOLD%^.  Suspended from the ceiling is a man made of some %^BLACK%^sh%^RESET%^%^BOLD%^im%^RESET%^me%^BOLD%^r%^BLACK%^ing%^RESET%^%^BOLD%^ rock that seems less silver but more beautiful. %^RESET%^%^RED%^B%^BOLD%^l%^RESET%^o%^BOLD%^%^RED%^o%^RESET%^%^RED%^d%^RESET%^%^BOLD%^ pours out of it's mouth and into a small, cylindrical hole in the centre of the pentagram, a couple of inches away from the base of the th%^RED%^ro%^RESET%^%^BOLD%^ne. "); 
    set_items(([
          "grargoyles" : "The gargoyles all seem to grin as blood slowly trickles out of their mouthes ",
          "vampires" : "They're only stone... ",
          "throne" : "This is the throne of a powerful vampire indeed. It is jet black, the only thing that doesn't seem silver in this room, with a plush, crimson backing to it.  The top of the throne is shaped like fire.",
          "pentagram" : "All the blood from the ceiling gathers and pours down a hole in the centre of it ",
          "rim" : "A place to stand on so you don't fall into the swirling blood. ",
          "man" : "He eyes are widened and it looks like the blood is being sucked down his throat. ",
          "blood" : "It is everywhere, but in a very orderly, seductively beautiful way. ",
          "hole" : "The blood from the ceiling makes it's way into this. ",
      
              
                
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([ "out" : ROOMS "vtower4.c",
                  ]));
    add_invis_exit("");
}

void init() {
 ::init();
   add_action("hole", "enter");
}

int hole(string str) {
   if (!str || str != "hole") return notify_fail("Enter what?\n");
   write("You attempt to enter the hole but fall in!!!                                                                                %^RED%^SPLASH!!!%^RESET%^.");
   this_player()->move_player( ROOMS  "balra2.c");
   return 1;
}

