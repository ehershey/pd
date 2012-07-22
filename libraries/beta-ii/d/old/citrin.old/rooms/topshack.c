// Coding by Whit
// Coded for Primal Darkness

#include <std.h>
#include <citrin.h>
inherit ROOM;

int down(string str);
int leap(string str);
void init() {
::init();
add_action("down","down");
add_action("leap","leap");
}
int leap(string str);

void create() {
::create();
    set_short("The top of an old shack");
    set_day_long("The shack roof is very sturdy comparing it to the inside "
                 "of it.  The roof creaks though every so often still knowing "
                 "that at anytime it could cave in.  The roof gives a good "
                 "view of the rest of the forest.  The woods come alive "
                 "with the dawning of the new sun.  There is a large hole in "
                 "which the ladder comes out of.");
    set_night_long("The shack roof is very sturdy comparing it to the inside "
                 "of it.  The roof creaks though every so often still knowing "
                 "that at anytime it could cave in.  The roof gives a good "
                 "view of the rest of the forest.  The woods come alive "
                 "with the dawning of the new sun.  There is a large hole in "
                 "which the ladder comes out of.");
    set_items(([
        "roof" : "It may be a good idea to find another way around the hole."
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 0,
        "forest" : 1,
    ]));
    set_exits(([
        "down" : ROOMS+"shack.c",
    ]));
}

int down(string str) {
object igor, env1, env2, *all;
int i;
if (query_exit("down") == "/d/standard/void") return 0;

write("As you try to leave down the hole caves in making it imposible "
      "to leave.");
say(this_player()->query_cap_name()+" tries to leave down but the hole "
                                    "caves in..");
igor = new("/wizards/inferno/igor");
igor->move(ROOMS"shack");
env1 = environment(igor);
igor->move(ROOMS"treetop4");
env2 = environment(igor);
igor->remove();
tell_room(env1, "Whoosh! The ceiling collapses inwards, "
      "throwing you out the door!", ({ }));
tell_room(env2, "With a sudden crash, the ceiling of the shack "
      "collapses, completely destroying it!", ({ }));
env2->set_inf(1);
all = all_inventory(env1);
i = sizeof(all);
while (i--) {
   if (!all[i]->is_player()) continue;
   all[i]->move(ROOMS"treetop4");
   say(env2, all[i]->query_cap_name()+" is thrown into the room!", 
       all[i]);
}
remove_exit("down");
return 1;
}

int leap(string str) {
write("You leap off the roof to the walkway below.");
say(this_player()->query_cap_name()+" leaps off the shack.");
this_player()->move_player(ROOMS"treetop4");
return 1;
}
