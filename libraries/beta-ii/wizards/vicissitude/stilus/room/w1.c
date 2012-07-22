
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
     "After travelling for a while you arrive in "
     "a strange glade, thick with %^CYAN%^fog%^RESET%^ "
     "and damp earth. The %^GREEN%^trees%^RESET%^ "
     "appear to be %^MAGENTA%^warped%^RESET%^ and "
     "%^ORANGE%^frighteningly%^RESET%^ disfigured "
     "by the presence of some unknown power. "
     "You cannot help but wonder if you are being watched. "
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



