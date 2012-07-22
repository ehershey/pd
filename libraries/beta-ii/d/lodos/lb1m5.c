#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
    ::create();
    set_short("Beneath the center of a temple");
    set_long("In place of a ceiling is a huge hole, as if the entire top "
      "of this room had been violently torn off. Looking straight up, the "
      "top of the central tower of the temple can be seen, a glowing yellow "
      "mass of energy. Roatating in the center of the room is a multi "
      "colored box. Inscribed on the side of the box is a riddle.");
    set_items(([
	"ceiling" : "Ceiling?? What ceiling, can't you read?",
	"tower"   : "You can see straight up from here.",
	"box"     : "The ancient riddle box of the temple to the archangel. "
	"If you think you know the answer, simply <answer [guess]>",
	({ "riddle", "inscription" }) : "I am a story brought to art, \n"
	"I am the life within, \n"
	"I can brighten your spirits, \n"
	"Or bring you to your knees. \n"
      ]));
    set_properties(([ "no teleport" : 1, "light" : 2, "night light" : 2, "indoors" : 1 ]));
    set_exits(([
	"up" : ROOMS"l1m5"
      ]));
}

int guess(string str) {

    if (!str) return 0;
    if (str != "song" && str != "a song") return 0;
    if (this_player()->query_level() < 50) return notify_fail("A strange force repels 

you.\n");
   write("You feel a slight tingling sensation as your body is transported from this 

place.");
   this_player()->move_player(AMAZE"a_44.c", "riddle box");
   return 1;
}

void init() {
 ::init();
   add_action("guess", "answer");
}
