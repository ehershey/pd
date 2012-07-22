#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_short("%^BOLD%^%^RED%^A Strange Path");
   set_long(
      "%^BOLD%^RED%^A Strange Path\n"
      "%^BOLD%^%^BLUE%^You are standing on a dusty path, it winds"
      " on for as far as you can see.\n"
      "%^BOLD%^%^BLUE%^The sound of laughter and merriment can be"
      " heard in the distance. Odd\n"
      "%^BOLD%^%^BLUE%^tracings are all about you on the path and"
      " trees, even the air seems to\n"
      "%^BOLD%^%^BLUE%^have a tale to tell. Memories of rhymes"
      " long forgotten flicker at the edges\n"
      "%^BOLD%^%^BLUE%^edges of your mind.\n");
   set_items((["tracings" : "These tracings look very old, and have probably been here for years"]));
   set_exits(([
     "east" : "/wizards/morgoth/room/beach1.c",
     "west" : "/wizards/morgoth/room/strange2.c",
   ]));
    }
