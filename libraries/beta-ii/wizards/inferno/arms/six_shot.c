#include <std.h>
inherit WEAPON;

static int now;
static mapping loaded = ([ "0" : 0, "1" : 0, "2" : 0, "3" : 0,
                           "4" : 0, "5" : 0 ]);

void create() {
 ::create();
   set_name("revolver");
   set_short("a six-shot revolver");
   set_long("A small, six-shot pistol in the old western fasion. It can "
     "hold six bullets at a time. The power this revolver has is "
     "amazing.");
   set_id(({ "revolver", "gun", "six-shot", "pistol" }));
   set_type("blunt");
   set_wc(0);
}

int load(string str) {
   int x;
   if (!str || str != "revolver") return notify_fail("Load what\n");
   write("You load a single bullet into the revolver and spin the "
     "barrel.");
   loaded = ([ "0" : 0, "1" : 0, "2" : 0, "3" : 0, "4" : 0, "5" : 0 ]);
   say(this_player()->query_cap_name()+" loads a single bullet into "
     "a revolver and spins the barrel.", this_player());
   x = random(5);
   loaded[x] = 1;
   now = 0;
   return 1;
}

int spin(string str) {
   int x;
   if (!str || str != "revolver") return notify_fail("Spin what?\n");
   x = random(5);
   now = x;
   write("You spin the chamber on the revolver.");
   say(this_player()->query_cap_name()+" spins the chamber on a revolver.",
     this_player());
   return 1;
}

int fire(string str) {
   if (!str || str != "revolver") return notify_fail("Fire what?\n");
   write("%^YELLOW%^You hold the revolver to your head and pull the trigger!");
   say("%^YELLOW%^"+this_player()->query_cap_name()+" holds a revolver to "
     +this_player()->query_title_gender()+" and pulls the trigger!",
     this_player());
   if (loaded[now] == 1) {
     tell_object(environment(this_player()), "%^BOLD%^%^RED%^BANG!!!");
     this_player()->die();
     loaded[now] = 0;
     now = 0;
     return 1;
   }
   tell_object(environment(this_player()), "%^BOLD%^> Click. <");
   now++;
   return 1;
}

void init() {
 ::init();
   add_action("load",  "load");
   add_action("fire",  "fire");
   add_action("spin", "spin");
}
