#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "This part of the tunnel is very dark, nothing can be seen "
      "up ahead. The only thing can be seen is an outline round "
      "boulder."
    );
    set_items(([
        "tunnel" : "It's dark in here.",
        "boulder" : "It's is perfectly round, try rolling it.",
        "outline" : "Light seems to trickle out around the sides.",
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"northeast" : HIVE "hive12",
"southwest" : HIVE "hive",
    ])  );
}
void init() {
   ::init();
   add_action("roll","roll");
}
int roll(string str) {
   if(str != "boulder"){
     notify_fail("Nothing happens.\n"); return 0; }
   write("You push on the boulder it starts to move.\n");
   this_player()->move(HIVE "hive11");
   tell_object(this_player(), "You quickly dart inside before it rolls back.\n");
   this_player()->add_hp(-10);
   return 1;
}
