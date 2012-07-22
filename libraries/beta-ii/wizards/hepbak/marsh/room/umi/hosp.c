#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("building",1);
    set_short("A Mental Insitution");
    set_long(
      "%^BOLD%^%^WHITE%^The hallway ends here, the door to the east has a sign on it. "
           );
    set_items(([
        "walls" : "No pitures on them, they are a solid white.",
        "hallway" : "It's a long hallway with doors on either side of it.",
        "door" : "The door has a sign on it.",
        "sign" : "%^BOLD%^%^RED%^ EMPLOYEES ONLY",
    ]));
    set_listen("default", "Complete silence fills the air");
    set_smell("default", "Smells of chlorine stings at your nose");
    set_exits( ([
"west" : UMI "hosp13",
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
