#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Marsh");
    set_day_long(
      "This is a very narrow ledge, the wall pushes you to the edge. "
    );
    set_night_long(
      "This is a very narrow ledge, the wall pushes you to the edge."
    );
    set_items(([
        "ledge" : "Very narrow, and full of squished bones.",
        "bones" : "Something big fell on them.",
        "wall" : "It's actually a boulder wedged into the cliff",
        "boulder" : "What you think a boulder is?? It is a big rock!",
       ]));
    set_smell("default", "It smells rotting flesh.");
    set_listen("default", "Sounds of rolling thunder is heared here.");
    set_exits( ([
"up" : ELE "ele8",
"west" : ELE "cliff",
    ]) );
}
void init()
{
 ::init();
 add_action("roll", "roll");
}
int roll(string str)
{
 if (str!="boulder") return notify_fail("Roll what?\n");
 if (this_player()->query_class()!="fighter")
   {
    write("You try to push the boulder, but it wont budge.");
    return 1;
    }
 write("You push the boulder out of the way.");
 this_player()->move_player(ELE "fihall", "pushes the boulder out of the way
a
nd goes into the hole.");
return 1;
}
