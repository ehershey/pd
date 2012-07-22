#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Den");
    set_day_long(
      "Corpses dragged to this spot is half hanging on the bone. "
      "This gruesome sight of elephants either wishing to survive, or "
      "wishing their death would come sooner then expected."
    );
    set_night_long(
      "Corpses dragged to this spot is half hanging on the bone. "
      "This gruesome sight of elephants either wishing to survive, or "
      "wishing their death would come sooner then expected."
    );
    set_items(([
        "corpse" : "The meant is barely haning on to the bone.",
        "den" : "The messier part of the den is here.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Sounds of hyenas dragging corpses");
    set_exits( ([
"northeast" : ELE "ele5",
"southeast" : ELE "ele",
    ]) );
}
void reset() {
 ::reset();
   if (!present("mhyena")) {
      new(MOB"mhyena")->move(this_object());
      new(MOB"mhyena")->move(this_object());
      new(MOB"mhyena")->move(this_object());
  if (!present("fhyena"))
     new(MOB"fhyena")->move(this_object());
     new(MOB"fhyena")->move(this_object());
  if (!present("trele"))
     new(MOB"trele")->move(this_object());
    }
}
