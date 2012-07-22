// Coding by Whit
// Coded for Primal Darkness

#include <std.h>
#include <citrin.h>
inherit ROOM;

static int inferno;
int rt;
void set_inf(int x);
int go_enter(string str);

void create() {
::create();
    set_short("Amoung the Tree Tops");
    set_day_long("The boarded pathway ends abruptly to a large rundown "
                 "shack.  Afer many years of abuse from the harsh weather "
                 "it looks at any moment that it will far apart.  The door "
                 "has been half way knocked off its hinges.  The are small "
                 "spots of blood across the boardwalk.");
    set_night_long("The boarded pathway ends abruptly to a large rundown "
                 "shack.  Afer many years of abuse from the harsh weather "
                 "it looks at any moment that it will far apart.  The door "
                 "has been half way knocked off its hinges.  The are small "
                 "spots of blood across the boardwalk.");
    set_items(([
        "shack" : "The shack is old and has fell into disrepair.",
        "blood" : "Who knows where that came from.",
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 0,
        "forest" : 1,
    ]));
    set_exits(([
        "west" : ROOMS+"treetop3.c",
        "enter" : ROOMS+"shack.c",
    ]));
    inferno = 0;
}

void set_inf(int x) { inferno = x; }

int go_enter(string str) {
   if (inferno) {
      write("The entrance to the shack has collapsed, "
        "preventing entrance to it.");
      return 1;
   }
   return 0;
}

void init() {
 ::init();
   add_action("go_enter", "enter");
   add_action("search", "search");
}

int search(string str) {
if(!inferno) return 0;
if(str == "house") {
if(rt==1) return notify_fail("You find nothing.");
write("You find some old planks from the house.");
rt=1;
new("/d/citrin/objects/planks")->move(this_player());
return 1;
}
return 0;
}
