#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

static int flag = 0;

string check_ped() {
   if (flag) return "The stone pedistal near the southern wall has a bright red "
     "flag sitting atop it. Now you need just take it.";
  else return "It is an old stone pedistal. There is nothing on top of it.";
}

void create() {
 ::create();
   set_short("Obstacle Course: Room 6");
   set_long("%^RESET%^%^ORANGE%^"
     "You are within a rather small, closed off chamber. The walls are "
     "all made of stone. A doorway south is the only exit from this room. The "
     "air is musty and damp, as if this room hadn't been used for a very long "
     "time. Moss grows on the walls and on the floor as well. The steady "
     "dripping of water is caused by a thin crack in the ceiling. Only a single "
     "pedistal sits on the ground of the otherwise empty chamber.");
   set_items(([
     "pedistal": (: check_ped() :),
     "chamber" : "This empty chamber is cold and lonely.",
     "walls"   : "Thick walls close off this chamber to the rest of the outside "
                 "world.",
     "crack"   : "A very thin crack, just wide enough for the constant dripping "
                 "of water. There must be an underground stream just above the "
                 "ceiling",
     "ceiling" : "Other than the single crack, it is otherwise flawless.",
     "moss"    : "A rare strain of cave moss grows here.",
     "doorway" : "The sole exit from this dark and cold chamber."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "indoors" : 1,
     "no bump" : 1, "no attack" : 1, "no magic" : 1, "no teleport" : 1,
     "no steal" : 1 ]));
   set_exits(([
     "north" : ROOMS"o6"
   ]));
}

int take(string str) {
   if (!str || str != "flag") return 0;
   if (!flag) return notify_fail("You already took it!\n");
   write("You grab the flag from atop the pedistal and wait for something to "
     "happen.. When nothing does, you sigh in relief and prepare to return to "
     "the begining of the obstacle course.");
   new(OBJ"flag")->move(this_player());
   flag = 0;
   return 1;
}

void init() {
 ::init();
   flag = 1;
   add_action("take", "take");
}
