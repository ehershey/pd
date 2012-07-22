#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Umi's Dumpster");
    set_long(
      "Here is Umi's Dumpster, all of the garden's waste ends up here to "
      "rot and decay, which then goes back to the garden as fertilizer."
    );
    set_items(([
        "dumpster" : "There are high piles of waste here, even so, the shadows
are strange.",
        "waste" : "Dead plants left to rot.",
        "garden" : "The garden is to the north of here.",
        "shadows" : "Where the piles are high, shadows small, and vice versa.",
    ]));
    set_exits( ([
"north" : GAR "gar2",
    ]) );
}
void init()
{
 ::init();
 add_action("search", "search");
}
int search(string str)
{
 if (str!="shadows") return notify_fail("You find nothing odd.\n");
 if (this_player()->query_class()!="kataan")
   {
    write("You find nothing odd.");
    return 1;
    }
 write("%^CYAN%^The shadows come alive and drags you away!");
 this_player()->move_player(GAR "kahall", "gets taken by the shadows.");
}
