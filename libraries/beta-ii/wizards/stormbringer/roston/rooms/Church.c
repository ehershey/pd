#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();                       

set_name("Roston Church");
set_items((["bible" : "This is a holy book ",
            "water" : "This is very holy water ",
            "robes" : "These robes are of a holy monk "]));
set_properties((["light":2 , "night light":3, "no bump":1]));
set_short("The Roston Church");
set_long("This is a very holy place, the walls are covered "
         "with big and colorfull pictures.The floor is made "
         "of white tile. The priest will happily answer any "
         "questions you might have.");

set_exits( ([ "out" : ROOMS"roston22" ]));
}                                                               
void reset() {
  ::reset();

     if(!present("priest"))
       {
        new(MOB "Priest")->move(this_object());
       }

}
