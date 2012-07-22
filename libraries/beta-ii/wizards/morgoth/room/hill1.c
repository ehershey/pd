#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_short("The Bottom Of The Hill");
   set_long(
     "%^BOLD%^%^MAGENTA%^The bottom of a hill\n"
      "%^BOLD%^%^CYAN%^You are standing at the bottom of a hill. you start to feel as if you have been here before, but when? Oh well must be your imagination, which seems to run wild around here.");
   set_exits(([
     "down" : "/wizards/morgoth/room/strange2.c",
     "up" : "/wizards/morgoth/room/hill2.c",
   ]));
}
