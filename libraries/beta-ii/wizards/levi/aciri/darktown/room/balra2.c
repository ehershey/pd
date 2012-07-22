#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("A room of silver.");
    set_long("%^RED%^Blood is everywhere!  "
              "%^RED%^%^BOLD%^This room looks like the inside of a heart!  The walls are beating and blood spurts out of tubes that hang from the ceiling.  Single drops of the darkest blood you've ever seen drip in through the hole.  These must be from the blood that that man on the ceiling dripped.  There is nothing more in here than pure blood, bubbling and splashing around.  A couple of steel drains on the walls circulate the blood and purify it to achieve it's greatest potential. ");
       
    
    set_items(([
          "blood" : "Blood bubbles and splashes around the room, eventually going into the drains and back out, purified.",
          "walls" : "This would appear to be the inside of a heart...",
          "drains" : "The drains draw blood in, clean it and spurt it back out.",
          "hole" : "Single drops of almost black blood drip through the hole.",
      
              
                
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
        "no teleport" : 1,
        "no steal" : 1,
    ]));
    set_exits((["down" : ROOMS "balra3.c", 
           ]));
    add_invis_exit("down");
    
}

void init() {
 ::init();
   add_action("out", "climb");
}

int out(string str) {
   if (!str || str != "out") return notify_fail("Say what!?\n");
   write("You crawl back out of this beating pool and wipe yourself off.");
   this_player()->move_player( ROOMS  "balra1.c");
   return 1;
}

void reset() {
  ::reset();
    if(!present("death")) 
      new(MOB "death")->move(this_object());
}

