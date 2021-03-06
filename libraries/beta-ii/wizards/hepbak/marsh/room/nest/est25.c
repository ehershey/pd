#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":1, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "A single torch mounted on the wall, lights up the intersection "
      "of tunnels."
         
    );
    set_items(([
        "tunnels" : "Four tunnels forming an intersection.",
        "intersection" : "Four tunnels joining together.",
        "wall" : "There is a torch mounted on a wall.",
        "light" : "It's not very bright, just enough to light the "
                  "intersection."
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"east" : NEST "est26",
"west" : NEST "est24",
"north" : NEST "est33",
    ])  );
}
void reset() {
 ::reset();
   if (!present("torch", this_object()))
     new( ITEMS "torch.c" )->move(this_object());
}
