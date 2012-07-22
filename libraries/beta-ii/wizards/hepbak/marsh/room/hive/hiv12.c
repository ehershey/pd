#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":1, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "Welcome to %^BOLD%^YELLOW%^The Local Bar%^RESET%^.  "
      "There are barstools lined up along side the bar.  "
      "At the far wall, some guards are gathered around a "
      "door, murmuring excitedly.  There seems to be no "
      "barkeeper present."
     
    );
    set_items(([
        "bar" : "It has stools lined up along side of it.",
        "barstools" : "It is something to sit on.",
        "stool" : "You are suppose to sit on it.",
        "wall" : "There is a sign posted on the wall.",
        "guards" : "They look very excited about something "
                   "that is posted on the wall.",
        "barkeep" : "There isn't one present.",
  
    ]));
    set_listen("default", "Guards murmuring and high fiving.");
    set_exits( ([
"southeast" : HIVE "hiv9",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")){ 
    new(MOB"r_guard")->move(this_object());
    new(MOB"r_guard")->move(this_object());
    new(MOB"r_guard")->move(this_object());
    new(MOB"r_guard")->move(this_object());
    new(MOB"r_guard")->move(this_object());
    }
}
