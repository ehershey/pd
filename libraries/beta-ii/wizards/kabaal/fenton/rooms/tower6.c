#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_property("building",1);
    set_short("inside a large tower");
    set_long(
      "The warm, inviting air drifts in here from all directions.  A large "
      "fireplace rests on the eastern wall.  A pair of chairs sits around "
      "the fireplace.  This room looks like it hasn't been used in years. "
    );
    set_items(([
	"fireplace" : "It is very elegant, but hasn't been used in a while. ",
	"chairs" : "Old, wooden chairs.",
    ]));
   set_exits( ([ 
        "west" : ROOMS"tower5.c",
        "north" : ROOMS"tower7.c",
    ]) );
}void reset() {
::reset();
    if(!present("guardian.c"))
      new(MOB"guardian.c")->move(this_object());
}
int east() {
if (!present("emerald", this_player())) {
  if(present("guardian")){
    write("The Guardian steps infront of you.");
    return 0;
    }
  }
  else {
    write("You show your emerald to the gate guard and continue your journey.");
    return 1;
  }
}
