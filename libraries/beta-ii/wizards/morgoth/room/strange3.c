#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_short("A Strange Path");
   set_long("%^BOLD%^%^RED%^A Strange Path\n"
     "%^BOLD%^%^BLUE%^You have come to the conclusion that there is no"
     "%^BOLD%^%^BLUE%^end to this path, and it simply serves as a scenic"
     "%^BOLD%^%^BLUE%^route between the more important areas of this"
     "%^BOLD%^%^BLUE%^strange, twisted, world.");
   set_exits(([
     "north" : "/wizards/morgoth/room/house1.c",
   ]));
}
