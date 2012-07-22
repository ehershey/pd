#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The ball of Cain");
    set_long("%^CYAN%^%^BOLD%^The light of the Goddess shines forth. "
	"In the shattered skull of the Goddess statue, the goddess he"
	"rself lies dying. ");


    set_items(([
	"statue" : "The head has been smashed open into a resting place for the goddess.",	          	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
	"no attack" : 1,
    ]));



    set_exits(([
	"down" : ROOMS "cainball4e3.c",
       ]));
}


void init() {
 ::init();
   add_action("quest", "forfeit");
}

int quest(string str) {
   if (!str || str != "quest") return notify_fail("Forfeit what?\n");
   write("You kneel to Terra and are suddenly consumed in a bright light.");
   this_player()->move_player( "/d/standard/library.c");
   return 1;
}


void reset() {
  ::reset();
    if(!present("goddess")) 
      new(MOB "goddess")->move(this_object());
}

