#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_short("Brick House");
   set_long("%^BOLD%^%^MAGENTA%^A House Of Brick\n"
     "%^BOLD%^%^MAGENTA%^Welcome to the little pig's house of brick."
     "%^BOLD%^%^MAGENTA%^LOOK OUT!!!, The wolf is here!");
   set_exits(([
     "north" : "/wizards/morgoth/room/house2.c"
	]));
}
