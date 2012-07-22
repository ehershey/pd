#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Den");
    set_day_long(
      "This is a hyena den.  Bloody bones everywhere, and stenches of rotting
fl
esh "
      "is quite strong here."
    );
    set_night_long(
      "This is a hyena den.  Bloody bones everywhere, and stenches of rotting
fl
esh "
      "is quite strong here."
    );
    set_items(([
        "den" : "A hyena's palace.  Bloody bones and rotting flesh
everywhere.",
        "graveyard" : "There are bones scattered everywhere.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Loud gnawing sounds");
    set_exits( ([
"southeast" : ELE "ele4",
"southwest" : ELE "ele2",
"north" : ELE "tunnel",
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
   }
}
