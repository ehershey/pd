#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":1, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "There is a torch mounted on a wall, lighting up the "
      "intersection."
         
    );
    set_items(([
        "torch" : "Made of wood, not very valuable.",
        "wall" : "There is a torch mounted on the wall.",
        "intersection" : "Tunnels running north to south, east "
                         "to west.",
        "wood" : "Looks all beat up and weather-worn.",
        "tunnels" : "They look dark.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"west" : NEST "est62",
"east" : NEST "est64",
"north" : NEST "est68",
"south" : NEST "est58",
    ])  );
}
void reset() {
 ::reset();
   if (!present("torch", this_object()))
     new( ITEMS "torch" )->move(this_object());
    if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
 
    }
}
