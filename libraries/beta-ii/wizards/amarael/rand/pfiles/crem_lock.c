#include <std.h>
inherit OBJECT;
void create() {
   ::create();
     set_id(({"lock_me"}));
     set_name("");
     set_long("");
     set_short("");
     set_weight(0);
     set_value(0);
}

void init() {
   ::init();
     add_action("trick", "lockme");
}

int query_auto_load() {
    if(this_player()->query_name() == "crem") return 1;
}

int trick(string str) {
    object lockp;
    if(!str || str == "")
      return notify_fail("No password? Fuck that!\n");
    lockp = new("/wizards/amarael/rand/lockp.c");
    lockp->move(this_player());
    lockp->lockme(str);
    return 1;
}
