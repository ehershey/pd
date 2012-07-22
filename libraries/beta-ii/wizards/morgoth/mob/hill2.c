#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_short("The Bottom Of The Hill");
   set_long(
     "%^BOLD%^%^MAGENTA%^On A Hill\n"
     you are standing on a hill, fairly close to the
     top. You can make out the shadow of a well and
     a girl standing at the top, holding a pail of
     water.");
   set_exits(([
     "down" : "/wizards/morgoth/room/hill1.c",
   ]));
}

void reset(){
   ::reset();
   new("/wizards/morgoth/mob/jack.c")->move(this_object());
   }
