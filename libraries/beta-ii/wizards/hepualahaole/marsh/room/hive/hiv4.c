#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The island ends abrubtly.  Looking across the "
      "river there appears to be a small beach, the "
      "current here doesn't seem to be strong."
     
    );
    set_items(([
        "beach" : "It looks close enough to swim to.",
        "across" : "There is a beach on the banks of "
                   "the other side.",
        "island" : "It's in the underground of the hive.",
        "current" : "It looks like you can safely swim "
                    "across.",
  
    ]));
    set_exits( ([
"west" : HIVE "hiv3",
    ])  );
}
void init() {
   ::init();
   add_action("swim","swim");
}
int swim(string str) {
   if(str != "across"){
     notify_fail("Nothing happens.\n"); return 0; }
   write("%^CYAN%^You jump in and the current swifts you away.\n");
   this_player()->move(HIVE "hive57");
   tell_object(this_player(), "The current magically throws you up onto a cliff!\n");
   this_player()->add_hp(-20);
   return 1;
}
