#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 1]) );
    set_property("building",1);
    set_short("Odori's Hut");
    set_long(
      "Here is Odori's Hut, he only caters to those ogres suffering the same "
      "ordeal that he is. All others must go to the shop to the north.  Inside
"
      "this hut you see shelves and shelves of little trinkets, and every day "
      "stuff.  Looking ahead, there is a desk and a trash can.  The floor "
      "looks to be recently swept.  This hut has a rustic feel to it.",
    );
    set_items(([
        "hut" : "It is a shop for only Ogres suffering the same fate that Odori
is.",
        "trash can" : "There is a lid on the can.",
        "can" : "There is a lid on the can.",
        "shelves" : "Full of trinkets and everyday stuff.",
        "trinkets" : "Things that will cheer up a depressed ogre.",
        "floor" : "It's been recently swept, it is an all wooden floor.",
        "desk" : "It is a small desk, it holds a cash register.",
    ]));
    set_exits( ([
"out" : HAM "ham3",
    ]) );
}
void init()
{
 ::init();
 add_action("lift", "lift");
}
int lift(string str)
{
 if (str!="lid") return notify_fail("You lift the lid and look inside and  you
see nothing!\n");
 if (this_player()->query_class()!="rogue")
   {
    write("You lift the lid and look inside and you see nothing!");
    return 1;
    }
 write("%^BOLD%^%^BLACK%^Shadows reach out and pulls you into the trash can!");
 this_player()->move_player(HAM "rohall", "into nothing");
return 1;
}
