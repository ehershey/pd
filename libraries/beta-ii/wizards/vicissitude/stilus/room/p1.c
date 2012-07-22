
#include <std.h>
#include <defs.h>
inherit ROOM;

void create() {
   ::create();
   set_properties( ([ 
     "indoors" : 1,
     "light" : 1
   ]) );
   set_short("Lost in the woods");
   set_long(
     "You are on an almost unidentifiable %^ORANGE%^path%^RESET%^ "
     "of %^CYAN%^soggy%^GREEN%^ vines%^RESET%^ and "
     "%^ORANGE%^damp soil%^RESET%^. The %^GREEN%^trees%^RESET%^ "
     "are tightly clustered and look %^MAGENTA%^warped%^RESET%^"
     " from some unknown force. The air is charged with "
     "a %^RED%^strange energy%^RESET%^. "
     "The %^CYAN%^fog%^RESET%^ rolls thick in the air and it is "
     "difficult to tell which way you are going."
   );
   set_items( ([
     "nothing" : "just that it says"
   ]) );
   set_smell(
     "default","The air is thick and dank."
   );
   set_listen(
     "default","There is a myriad of low tones here."
   );
   set_exits( ([
     "north" : "/wizards/vicissitude/stilus/room/start.c",
     "northeast" : "/wizards/vicissitude/stilus/room/start.c",
     "east" : "/wizards/vicissitude/stilus/room/start.c",
     "southeast" : "/wizards/vicissitude/stilus/room/start.c",
     "south" : "/wizards/vicissitude/stilus/room/start.c",
     "southwest" : "/wizards/vicissitude/stilus/room/start.c",
     "west" : "/wizards/vicissitude/stilus/room/start.c",
     "northwest" : "/wizards/vicissitude/stilus/room/start.c"
   ]) );

}


void init() {
   ::init();
   add_action("fpeer","peer");
   add_action("flisten","listen");
}

int fpeer(string str)
{ write("The fog and trees are too dense to see much.");
return 1;

}




int flisten(string str)
{write("The laughter has quieted.");
return 1;
}



