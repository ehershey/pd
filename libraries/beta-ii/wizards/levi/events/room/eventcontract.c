#include <std.h>
#include <sp.h>

inherit ROOM;

void create()
{
 ::create();
 set_short("Event Contract");
 set_long("By using the 'Agree' exit, you knowingly accept the following conditions:"
          "1.) You may not attack, kill, or otherwise directly harm another player "
          "during this event.  2.) As a further extension of condition 1, you may "
          "not steal from another player.  This includes any use of a steal-like "
          "ability, or looting their corpse without permission.  3.) You must "
          "observe the regular set of rules provided by 'help rules' during this "
          "event. 4.) Following the violation of any of these rules, you accept an "
          "arbitrary punishment from the Event Staff without reprieve from the "
          "Administration. ");
 set_listen("default", "The thrill of adventure calls you on.");
 set_exits( ([ "agree" : ROOMS "seekpal1.c",
               "disagree" : "/d/nopk/arlon/room/plains6" ]) );
}

