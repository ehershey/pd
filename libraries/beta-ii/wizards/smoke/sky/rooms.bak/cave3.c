#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 1, "night light" : 0,
                "no teleport" : 1]) );
   set_short("White dragons den");
   set_long(
            "%^BOLD%^The cave is huge. It must be home to several large "
            "beasts. A large fire pit is in the middle of the room. A "
            "magnificant mural was once painted on the southern wall "
            "but has blurred and faded with time.%^RESET%^");
   set_items(([
            "cave" : "The cave is huge! It is built inside of the mountain "
                        "and is the home to a small dragon family.",
            "walls" : "The walls are really high and jagged. They've been cut "
                 "out of the mountain.",
            "south" : "A mural has been painted on the south wall. It is "
                 "very worn and faded, but still lively enough to get "
                 "an idea of what the painter was trying to portray.",
            "mural" : "A large mural painted long ago. It is broken down "
                 "into three sections, one on the left, one center, and "
                 "one on the right.",
            "pit" : "A large fire pit is in the center of the cave. "
                 "It hasn't been used too recently, only "
                 "ashes are in the pit.",
            "left" : "A golden dragon is painted in the center of "
                 "what appears to be a battlefield, totally surrounded "
                 "by tiny men. The dragons neck is arched back, as if "
                 "its getting ready to attack hundreds of men with his "
                 "breath.",
             "center" : "A gold dragon is painted soaring in the sky. Its "
                 "wings wide and face doesn't show the slightest glimpse "
                 "of anything except contentment. Below the dragon lies "
                 "an endless sea of trees.",
             "right" : "This painting depicts five dragons of seperate color."
                 " On the left of the picture shows a red and black dragon, "
                 "snarling with their fierce claws drawn and ready, facing "
                 "the right side of the picture. On the right side a white and"
                 " a blue dragon are seen, ready to engage in combat. In the "
                 "center of the painting, acting almost as a peacekeeper, "
                 "stands the gold dragon shown on the other paintings."
   ]));
   set_smell("default", "A poisonous stench lingers in the air..");
   set_exits( ([ 
        "out" :  ROOMS "11"]));
    if(!present("dragon")) new(MOB"f_white.c")->move(this_object());
    if(!present("dragon 2")) new(MOB"m_white2.c")->move(this_object());
    if(!present("dragon 3")) new(MOB"f_white2.c")->move(this_object());
}
