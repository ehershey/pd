#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("town",1);
    set_short("Uwagi Town");
    set_day_long(
      "The vines, for no apparent reason, has come this far.  A broken "
      "down fence crosses the path, it can be easily climbed over to "
      "get to the other side.  Not that a passer-by would want to.  "
      "Who ever said * The grass is always greener on the other side "
      "of the fence * , has never visited this fence.  On the other "
      "side, is just miles of tunnels, or better yet, a maze of dirt."
          );
    set_night_long(
      "Under a light of fire-flies, an outline of a broken fence is "
      "up ahead.  Strange, the vines are no longer present up ahead."
    );
    set_items(([
        "vines" : "It's not here, but looking back towards town, there are "
                  "hordes of vines.",
        "fence" : "Right in the middle of the fence, it is low enough for "
                  "anyone to climb over to get to the other side.",
        "path" : "It is a dirt path, finally you can see your feet again.",
        "tunnels" : "It looks like a dried up river-bed.",
        "maze" : "It's not really a maze, it looks like a dried up river "
                 "bed.",
        "dirt" : "Normal dirt, nothing special about it.",
        "flies" : "Unique, they have an actual flame for a body.",
    ]));
    set_exits( ([
"south" : TOWN "town24",
"climb" : BA "ba",
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
