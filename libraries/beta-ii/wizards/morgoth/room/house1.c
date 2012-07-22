#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_short("Straw House");
   set_long("%^BOLD%^%^MAGENTA%^A House Of Straw\n"
     "%^BOLD%^%^MAGENTA%^Welcome to the little pig's house of straw."
     "%^BOLD%^%^MAGENTA%^You had better hurry along before the wolf"
     "%^BOLD%^%^MAGENTA%^gets here.");
   set_exits(([
     "south" : "/wizards/morgoth/room/strange3.c",
     "north" : "/wizards/morgoth/room/house2.c"
	]));
}
