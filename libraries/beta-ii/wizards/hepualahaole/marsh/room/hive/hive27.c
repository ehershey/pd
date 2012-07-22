#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "Deeper into the heart of the nest, more tunnels are "
      "winding it's way around the underground.  Another "
      "guard station is to the southeast.  Looking up, there "
      "is a hole."
         
    );
    set_items(([
        "nest" : "It's the home of the raknids.",
        "tunnels" : "They are everywhere in this nest.",
        "station" : "You must be getting closer to the "
                    "heart of the hive, this one looks "
                    "very busy.",
        "up" : "There is a hole up there.",
        "hole" : "Maybe if you jump up, you can pull "
                 "yourself up.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"southeast" : HIVE "hive24",
"southwest" : HIVE "hive22",
"north" : HIVE "hive37",
    ])  );
}
void init() {
   ::init();
   add_action("jump","jump");
}
int jump(string str) {
   if(str != "up"){
     notify_fail("Nothing happens.\n"); return 0; }
   write("You jump up and grab onto the ledge.\n");
   this_player()->move(NEST "est3");
   tell_object(this_player(), "%^BOLD%^RED%^Feeling your muscles burning, you made it
up!%^RESET%^\n");
   this_player()->add_hp(-10);
   return 1;
}
void reset() {
 ::reset();
     if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
    }
}
