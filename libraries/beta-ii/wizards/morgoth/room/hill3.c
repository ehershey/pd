#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_short("The Top Of The Hill");
     "%^BOLD%^%^MAGENTA%^At The Top Of A Hill\n"
     "%^BOLD%^%^MAGENTA%^You have finally made it to the top of the
	hill, and have decided to rest for a minute. As you look around you,
	you notice a well, and there is a small girl, about the age of seven
	here with a pail, getting water out of the well.");
   set_exits(([
     "down" : "/wizards/morgoth/room/hill2.c",
   ]));
}

void reset(){
   ::reset();
   new("/wizards/morgoth/mob/jill.c")->move(this_object());
   new("/wizards/morgoth/object/well.c")->move(this_object());
   }
