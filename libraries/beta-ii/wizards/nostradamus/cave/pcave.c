#include <std.h>
#include <cave.h>
 
inherit ROOM;
 
void create(){
::create();
   set_short("mountain");
   set_day_long("The tall mountains have cast a shadow on you.  The"
    " deep shadows are darker than the butt of a dragon.");
   set_night_long("The wolves are howling on their night hunt in the"
    " distance.  You can barely see your hand it is so dark.");
   set_items(([
     ({"shadows", "shadow", "deep shadows"}):
    "The shadows are dark and creepy, who would want to go in there?",
    "ground" : "The ground is dry and untraveled.",]));
   set_properties(([
    "light" : 2,
    "night light" : 1,
    ]));
   set_exits(([
    ]));
   add_enter("shadows", CAVE "cave_e.c");
}
