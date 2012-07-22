#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Den");
    set_day_long(
      "This part of the den is a little less messy.  It is where the "
      "cubs mature and learn to be a great hunter."
    );
    set_night_long(
     "This part of the den is a little less messy.  It is where the "
      "cubs mature and learn to be a great hunter."
    );
    set_items(([
        "bones" : "They are of all different sizes from mostly elephants.",
        "graveyard" : "There are bones scattered everywhere.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Sounds cubs playfully fighting for food");
    set_exits( ([
"northwest" : ELE "ele5",
"southwest" : ELE "ele",
    ]) );
}
void reset() {
 ::reset();
   if (!present("mchyena")) {
      new(MOB"mchyena")->move(this_object());
      new(MOB"mchyena")->move(this_object());
      new(MOB"mchyena")->move(this_object());   
  if (!present("fhyena"))
     new(MOB"fchyena")->move(this_object());
     new(MOB"fchyena")->move(this_object());
     new(MOB"fchyena")->move(this_object());
   }
}
