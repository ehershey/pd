//  Created by Whit
// 2
#include <std.h>
#include "/wizards/whit/quest/christmas/quest.h"

inherit ROOM;

void create() {
    ::create();
    set_short("Unknown land");
   set_long("A violent snow storm rages on.  There is hardly any "
     "visibility.  You seem to lose all sense of direction.");

    set_exits(([ 
	"north": ROOMS"maze/1",
	"south": ROOMS"maze/2",
	"west": ROOMS"maze/3",
	"east": ROOMS"maze/1",
      ]));
}
void init() {
   ::init();
   if(this_player())
   message("", "The storm continues to rage on!", this_player());
   if(this_player())
   if(wizardp(this_player()))
   message("", "%^BOLD%^%^RED%^Wiz:%^RESET%^ Go west.", this_player());

}


