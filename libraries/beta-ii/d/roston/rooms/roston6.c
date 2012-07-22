#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();      
reset ();
set_name("two south of town square");
set_properties((["light":2, "night light":3]));
set_short("A dirt path");
set_long("The scent of leather has grown stronger. There "
         "is a thin a blanket of snow covering ground. On the side "
      "of the path patches of snow can be seen. ");
set_items((["blanket" : "A large red blanket ",
            "snow"    : "A deep white snow ",
            "dirt"    : "A light brown mixture"]));

set_exits( ([ "north" : ROOMS "roston3",
              "south" : ROOMS "roston7" ]));
}                                    

void reset() {

     if(!present("man"))
       {
        new(MOB"man")->move(this_object());
       }

}                                                             
