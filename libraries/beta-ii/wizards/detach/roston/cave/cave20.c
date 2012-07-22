#include <std.h>

inherit ROOM;
void init() {
    ::init();

add_action("jump_rock" , "jump");
}
void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "cracks" : "A huge hole in the ground",
               "vapors" : "A wired looking mist",
               "rock" : "This giant Rock seems to be covering somthin",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("The walls of the cave seem to be caved in here you "
            "can only see piles of rocks and boulders, there seems "
            "one giant rock blocking the passage way.");

   set_exits( (["north"  : "/wizards/detach/roston/cave/cave1"])); 

}

 void reset() {
::reset();

     if(!present("bear"))
         {
       new("/wizards/detach/roston/cave/e_bear")->move(this_object());
       }

}                                  
int jump_rock(string what) {
  if (what != "rock") return 0;
this_player()->move_player("/wizards/detach/darkmouth/enter", "into the
huge
gap and vanishes without a trace.");
    return 1;
}