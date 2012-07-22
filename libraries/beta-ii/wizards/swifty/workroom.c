#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("just plain lost");
   
    set_long("This is the study of a hard working young wizard."
                 "The legendary Swifty sits at a huge desk with his"
                 "hands folded and head bowed. He seems deep in thought"
                 "and you think it would be unwise to disturb him..so stfu."
                 "The only real sound comes from a large clock in the corner");

    set_items(([
        "wizard" : "This is the great Swifty at work, you cant help but swoon.",
        "clock"  : "This is a large clock that serves to remind you that time"
                " is wasting while you stand here...so GET OUT!" ]));
set_properties(([
        "light" : 2,
        "night light" : 2
    ]));
    set_exits(([
        "out" : "/d/standard/square.c"
    ]));
}
