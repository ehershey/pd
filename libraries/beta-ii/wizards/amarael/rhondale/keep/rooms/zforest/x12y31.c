#include <std.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
     set_server(KEEPROOM"zforest/pathvserver.c");
   ::create();
     set_exits(([
  "southwest" : KEEPROOM"zforest/x13y30.c",
  "north" : KEEPROOM"zforest/x11y31.c",
      ]));
}

void reset() {
   ::reset();
     remove_exit("shadows");
}

void init() {
   ::init();
     add_action("kneelin", "kneel");
}

int kneelin() {
    message("info", "As you kneel to the ground a way opens up before you through the trees to the east.", this_player(), );
    message("info", this_player()->query_cap_name()+" kneels to the ground and suddenly a path appears through the trees to the east.", this_object(), this_player());
    add_exit(KEEPROOM"zforest/kratoan/entry.c", "east");
    call_out("rid_exit", 5);
    return 1;
}

void rid_exit() {
     message("info", "The trees close in again and the path is closed.", this_object(), );
     remove_exit("east");
}
