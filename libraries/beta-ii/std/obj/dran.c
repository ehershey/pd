#include <std.h>
inherit OBJECT;
   static int vis;

void create() {
 ::create();
   set_weight(1);
   set_name("dran");
   set_short("a dark red dran");
   set_long("The source of all Drannoth's powers. It is a "
            "small, dark red orb.");
   set_id(({ "dran" }));
   set_value(0);
}

void init() {
 ::init();
   add_action("vision", "vision");
   add_action("hellwalk", "hellwalk");
}

int query_vis() { return vis; }

int vision(string str) {
   if (str != "on" && str != "off") {
      write("Syntax: <vision [on/off]>");
      return 0;
   }
   if (str == "on") {
      vis = 1;
      tell_room(environment(this_player()), this_player()->query_cap_name()+
                "'s eyes light up with a strange flame.", ({ this_player() }));

      write("You can now see.");
      this_player()->force_me("look");
      return 1;
   }
   if (str == "off") {
      vis = 0;
      tell_room(environment(this_player()), "The fire in "
                +this_player()->query_cap_name()+
                "'s eyes dim.", ({ this_player() }));
      write("The fire in your eyes dim.");
      this_player()->force_me("look");
      return 1;
   }
}

int hellwalk(string str) {
   write("Hellwalk is not yet implemented.");
   return 1;
}

int bury(string str) {
   if (str != "dran") return 0;
   write("You cannot bury this!");
   return 1;
}
int give(string str) {
   if (str != "dran") return 0;
   write("You cannot give the dran away!");
   return 1;
}
int drop(string str) {
   if (str != "dran") return 0;
   write("You cannot drop this!");
   return 1;
}
int put(string str) {
   if (str != "dran") return 0;
   write("You must always hold your dran!");
   return 1;
}
int query_auto_load() { return 1; }
