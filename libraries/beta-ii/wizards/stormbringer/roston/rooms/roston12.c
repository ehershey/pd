#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();          

set_name("east of town square");
set_items((["snow"  : "A deep white snow",
            "dirt"  : "A light brown mixture"]));
set_properties((["light":2 , "night light":3]));
set_short("A dirt path");
set_long("You are on the east side of town, to the "
         "east you can see a large Church. The snow "
         "gathers on the side of the path. ");

set_exits( ([ "east" : ROOMS "roston21",
              "west" : ROOMS "roston" ]));
}                                                                  

void reset() {

     if(!present("man"))
       {
        new(MOB "t_man")->move(this_object());
       }

}
                                   
