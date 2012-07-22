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
      "thought of climbing out vanish. "
     );
    set_night_long(
      "The water that once ran through this river bed, has dried up many "
      "moons ago.  By the light of fire-flies, the dark and creepy banks "
      "towers high above the river floor. "
    );
    set_items(([
        "floor" : "It's not even muddy, the river dried up ages ago.",
        "river" : "Dried up years ago",
        "bed" : "A river once went through here.",
        "banks" : "It towers high above you.",
        "land" : "Steep because of the cliffs.",
        "flies" : "Unique, there is an actual flame for the body.",
    ]));
    set_exits( ([
"north" : BA "ba5",
"northwest" : BA "ba4",
    ]) );
}
void init()
{
 ::init();
 add_action("Fclimb", "climb");
}
int Fclimb()
{
 write("%^RED%^The dirt loosens up and you cut yourself up as you slide down.%^RESET%^");
 this_player()->add_hp(-10); 
 return 1;
}
void reset() {
 ::reset();
   if (!present("mudbug")) {
      new(MOB"mudbug")->move(this_object());
  if (!present("crawfish"))
     new(MOB"crawfish")->move(this_object());
 
    }
}
