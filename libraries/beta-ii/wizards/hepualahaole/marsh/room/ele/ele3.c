#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("The leader's hideout");
    set_day_long(
      "The leader of the hyena is rather spiritual.  He often needs "
      "guidence of his ancestors and will come here for that peace."
    );
    set_night_long(
       "The leader of the hyena is rather spiritual. He often needs "
      "guidence of his ancestors and will come here for that peace."
    );
    set_items(([
        "hideout" : "Smoothed out rocks serve as an altar of meditation.",
        "den" : "There are no bones or blood in this spiritual place.",
    ]));
    set_smell("default", "It smells like incense.");
    set_listen("default", "Sounds of soothing nature's harmony");
    set_exits( ([
"up" : ELE "ele",
    ]) );
}
void reset() {
 ::reset();
   if (!present("hyena")) {
      new(MOB"mahyena")->move(this_object());
 
    }
}
