#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "Inside a secret passage.  There is a boulder "
      "blocking the way out.  A tunnel leads the way "
      "north."
         
    );
    set_items(([
        "tunnel" : "One of many in this place.",
        "boulder" : "It is perfectly round, try "
                    "rolling it.",
        "passage" : "Shh! Tell no one about it.",
  
    ]));
    set_exits( ([
"north" : HIVE "hive20",
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
   this_player()->move(HIVE "hive7");
   tell_object(this_player(), "You quickly dart out before it rolls back.\n");
   this_player()->add_hp(-10);
   return 1;
}
void reset() {
 ::reset();
     if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
    }
}
