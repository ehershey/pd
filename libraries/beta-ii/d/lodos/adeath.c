#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("The lining within every cloud");
   set_long("You find yourself in a place of happiness and joy. This is truely "
     "the lining within every cloud. You have wandered into heaven, and for one "
     "reason or another you do not seem to be dead. Bright light shines down, "
     "bathing your body in warmth. The air seems to have a silver tint to it. "
     "This place is always well lit, despite day or night.");
   set_items(([
     "air"   : "Silvery air and light from every direction.",
     "light" : "Light shines on you from every direction, though it does not "
               "hurt your eyes.",
     "cloud" : "This is the silvery lining of the clouds, heaven."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1,
     "no bump" : 1, "no attack" : 1, "no magic" : 1, "no teleport" : 1,
     "no steal" : 1 ]));
   set_exits(([
   ]));
}

int filter(string str) {
   if (query_verb() == "ascend") {
     if (present("girl", this_object())->query_talking())
       return notify_fail("You should listen to the girl finish talking first.\n");
     write("%^YELLOW%^Your body begins to float, and with a blinding flash of "
       "light, you find yourself in a different place.");
   if (this_player()->query_subclass() == "antipaladin" ||
       this_player()->query_subclass() == "kataan" ||
       this_player()->query_subclass() == "necromancer")
      this_player()->move_player("/d/nopk/tirun/square", "light");
     else
       this_player()->move_player(ROOMS"become", "light");
     return 1;
   }
   if (wizardp(this_player()) || this_player()->is_monster()) return 0;
   write("The dead are incapable of such acts.");
   return 1;
}

void init() {
 ::init();
   add_action("filter", "");
   present("girl", this_object())->start_talk();
}

void reset() {
 ::reset();
   if (!present("girl"))
     make(MOB"girl");
}
