#include <std.h>
inherit OBJECT;

static object *ob=({ });
static int sitting=0;
int sit();

int sit(string str) {
   if (str != "on chair") return 0;
   if (sitting) {
      write("Someone is already sitting on it.");
      return 1;
   }
   write("You sit down on the comfortable, fluffy, chair.");
   say(this_player()->query_cap_name()+" sits down on the couch and smiles in comfort.", this_player());
   sitting++;
   if (!sitting) ob[0] = this_player();
   else ob += ({ this_player() });
   return 1;
}

int stand() {
   int i;
   i = sizeof(ob);
   while(i--) {
      if (ob[i] == this_player()) {
         ob -=  ({ this_player() });
         write("You stand up, off the couch.");
         tell_room(environment(this_object()), this_player()->query_cap_name()+
           " stands up, off the couch.", ({ this_player() }));
         return 1;
      }
   }
   return 0;
}

void init() {
 ::init();
   add_action("sit", "sit");
   add_action("stand", "stand");
}

void create() {
 ::create();
   set_name("couch");
   set_short("%^RESET%^%^ORANGE%^a big, fluffy couch%^RESET%^");
   set_long("It has nice, fluffy pillows along it, and large armrests. "
      "This is the type of couch that reclines. It has three cusions on "
      "it for people to sit on.");
   set_weight(200);
   set_value(9000);
   set_heart_beat(1);
}

int get() { return 0; }

void heart_beat() {
   int i, x;
   if (!sizeof(ob)) return 0;
   i = sizeof(ob);
   while(i--) {
      if (!present(ob[i]), environment(this_object())) {
         ob -= ({ ob[i] });
         if (!sizeof(ob)) return;
         continue;
      }
      ob[i]->heal(10);
   }
}
