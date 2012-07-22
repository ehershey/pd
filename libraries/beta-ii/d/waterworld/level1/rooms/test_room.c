/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

object humpy,target,blueboy;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
     set_listen("","");
      set_smell("","");
      set_long("");

         set_exits(([
             "east":ROOMS1"test_room2.c"
                     ]));
         set_items(([
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
          humpy=new(MOB1"humpy.c");
          blueboy=new(MOB1"blue_boy.c");

           humpy->move(this_object());
           blueboy->move(this_object());
}

void monster_jump(string pname) {
       humpy->force_me("kill "+pname);
       blueboy->force_me("kill "+pname);
}
