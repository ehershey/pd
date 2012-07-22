#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("building",1);
    set_short("Uwagi Town Bank");
    set_long(
      "The building here seems to be the least important to the "
      "Lizard-people.  It looks as though it will be a bank.  There "
      "is a vault here with the standard four walls, but no roof."
          );
    set_items(([
        "vault" : "It is sitting here wide open, but nothing is "
                  "inside it yet.",
        "walls" : "Just your basic wood, but without paint.",
        "roof" : "Nope no roof.",
        "bank" : "Nothing here but a vault.",
    ]));
    set_exits( ([
"out" : TOWN "town11",
"enter" : TOWN "vault",
    ]) );
}
void reset() {
 ::reset();
   if (!present("vault", this_object()))
     new( ITEMS "avault.c" )->move(this_object());
}
