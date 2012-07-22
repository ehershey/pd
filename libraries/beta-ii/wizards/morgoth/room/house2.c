#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_short("Stick House");
   set_long("%^BOLD%^%^MAGENTA%^A House Of Sticks\n"
     "%^BOLD%^%^MAGENTA%^Welcome to the little pig's house of sticks."
     "%^BOLD%^%^MAGENTA%^You had better hurry along before the wolf"
     "%^BOLD%^%^MAGENTA%^gets here.");
   set_exits(([
     "south" : "/wizards/morgoth/room/house1.c",
     "north" : "/wizards/morgoth/room/house3.c"
	]));
}
