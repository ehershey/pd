#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("River Bed");
    set_day_long(
      "On the floor, of what used to be a rushing river.  The banks "
      "on ether side, towers over-head almost vertical, making the "
      "thought of climbing out vanish.  To the south, there is a "
      "broken fence."
     );
    set_night_long(
      "The water that once ran through this river bed, has dried up many "
      "moons ago.  By the light of fire-flies, the dark and creepy banks "
      "towers high above the river floor.  An outline of a broken fence "
      "can be seen."
    );
    set_items(([
        "floor" : "It's not even muddy, the river dried up ages ago.",
        "river" : "Dried up years ago",
        "bed" : "A river once went through here.",
        "banks" : "It towers high above you.",
        "land" : "Steap because of the cliffs.",
        "flies" : "Unique, there is an actual flame for the body.",
        "fence" : "You could easily climb over it.",
    ]));
    set_exits( ([
"climb" : TOWN "town25",
"north" : BA "ba3",
    ]) );
    add_invis_exit("climb");
}
void init()
{
 ::init();
 add_action("Fclimb", "climb");
}
int Fclimb()
{
 write("%^CYAN%^You walk up to the fence and step over.%^RESET%^");
 return 0;
}
void reset() {
 ::reset();
   if (!present("fishskel")) {
      new(MOB"fishskel")->move(this_object());
  if (!present("wasp"))
     new(MOB"wasp")->move(this_object());
 
    }
}
