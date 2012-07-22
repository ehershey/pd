#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "cracks" : "A huge hole in the ground",
               "vapors" : "A wired looking mist",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("The Cave to the east seems to be fadeing away. "
            "There are many cracks in the ground, vapors seems "
            "to be flowing out of the cracks.");

   set_exits( (["south"  : "/wizards/detach/roston/roston52"]));
}
    void reset() {  
::reset();

     if(!present("fox"))
       {
       new("/wizards/detach/roston/fox")->move(this_object());
       }

}           
