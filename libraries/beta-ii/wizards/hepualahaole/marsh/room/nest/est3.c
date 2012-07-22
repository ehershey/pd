#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The tunnels connect here, creating a giant circle.  "
      "There is a hole in the floor that leads down to the "
      "level below."
         
    );
    set_items(([
        "tunnels" : "They lead back to the heart of the nest.",
        "hole" : "It is wide enough for you to jump through.",
        "floor" : "There is a hole cut into it.",
        "below" : "Another level can be seen.",
        "nest" : "Raknids built it.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"north" : NEST "est7",
"west" : NEST "est2",
    ])  );
}
void init() {
   ::init();
   add_action("jump","jump");
}
int jump(string str) {
   if(str != "hole"){
     notify_fail("Nothing happens.\n"); return 0; }
   write("As you approach the hole, a queasy feeling sets in\n");
   this_player()->move(HIVE "hive27");
   tell_object(this_player(), "%^BOLD%^RED%^You hit the ground hard%^RESET%^\n");
   this_player()->add_hp(-30);
   return 1;
}
void reset() {
 ::reset();
    if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
 
    }
}
