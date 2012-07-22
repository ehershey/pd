#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("building",1);
    set_short("A Mental Insitution");
    set_long(
      "%^BOLD%^%^WHITE%^A sound proof, padded room, all white of course. "
           );
    set_items(([
        "walls" : "Padded so no one can hurt themselves",
        "room" : "It is for those who are mentally challenged.",
        "pad" : "They absorb hits so one dosn't hurt themselves.",
    ]));
    set_listen("default", "Complete silence fills the air");
    set_exits( ([
"south" : UMI "hosp3",
    ]) );
}
void init()
{
 ::init();
 add_action("open", "open");
}
int open(string str)
{
 if (str!="door") return notify_fail("A guard comes out and says tsk tsk\n");
 if (this_player()->query_class()!="cleric")
   {
    write("A guard comes out and says tsk tsk");
    return 1;
    }
 write("%^CYAN%^The gaurd comes out and escorts you in!");
 this_player()->move_player(UMI "clhall", "with the guard.");
return 1;
}
