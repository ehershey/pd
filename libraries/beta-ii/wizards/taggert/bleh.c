#include <std.h>

inherit ROOM;
static int count;

void create() {
 ::create();
   set_name("blah");
   set_long("bleh");
   set_smell("default", "I can't belive it's not butter.");
   count = 0;
   set_heart_beat(0);
}

void heart_beat() {
   count++;
}

int PullString(string str) {
   if (!str || str == "") return 0;
   if (str != "string") return 0;
   set_heart_beat(1);
   count = 0;
   write("You tug on the string.");
   return 1;
}

void init() {
 ::init();
   add_action("PullString", "pull");
}
