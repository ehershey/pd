#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
    set_server(SERVER);
    ::create();
    set_long("this is a standard
sentence"+this_object()->query_day_long()+".");
    set_exits( ([
        "south" : ROOMS "m15",
      ]) );
}
