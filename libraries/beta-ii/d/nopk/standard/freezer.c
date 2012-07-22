#include <std.h>
#include <config.h>
#include <rooms.h>
#include <sindarii.h>

inherit ROOM;

static private object *old;

void create() {
    ::create();
    set_properties( ([ "no teleport":1,
                       "no attack":1,
                       "no steal":1,
                       "no magic":1 ]));
    set("short", "The freezer");
    set("long", "The local freezer.");
    set_exits((["square" : ROOMS "square"]));
    set_no_clean(1);
    call_out("clean_room", 60);
}

static void clean_room() {
    object *inv;
    int i;

    if(time() < 1063202733) return;

    i=sizeof(inv = all_inventory(this_object()));

    while(i--) {
     if(!inv[i]->query_net_die_time()) continue;
     if(time() - inv[i]->query_net_die_time() > 14400) {
         inv[i]->force_me("quit");
      }
    }
    call_out("clean_room", 60);
}

