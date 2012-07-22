#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Den");
    set_day_long(
      "This part of the den is the sleeping quarters.  It is deep enough "
      "inside that any intruders would wake up the sleeping hyena in time "
      "to defend their home.  There are bones scattered around here in small "
      "piles, seems like the hyenas like a late-night snack every now and
then."
    );
    set_night_long(
      "This part of the den is the sleeping quarters.  It is deep enough "
      "inside that any intruders would wake up the sleeping hyena in time "
      "to defend their home.  There are bones scattered around here in small "
      "piles, seems like the hyenas like a late-night snack every now and
then."
    );
    set_items(([
        "den" : "This is the sleeping quarters.",
     "bones" : "The bones look like they can be moved.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Sounds of elephants begging for mercy");
    set_exits( ([
"northeast" : ELE "ele4",
"northwest" : ELE "ele2",
    ]) );
}
void init(){
    ::init();
  add_action("move", "move");
}
int move(string str) {
     write("You move the bones and discover a hole!");
      add_exit(ELE "ele3" , "hole");
    return 1;
}
void reset() {
 ::reset();
   if (!present("mhyena")) {
      new(MOB"mhyena")->move(this_object());
      new(MOB"mhyena")->move(this_object());
   if (!present("fhyena"))
     new(MOB"fhyena")->move(this_object());
     new(MOB"fhyena")->move(this_object());
   }
}
