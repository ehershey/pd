#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_short("%^BOLD%^%^RED%^A Strange Path");
   set_long(
      "%^BOLD%^%^YELLOW%^A Sandy Beach\n"
      "%^BOLD%^%^GREEN%^The sun is shining on the sea, doing it's very best to make"
      " the billows smooth and bright. "
      "%^BOLD%^%^GREEN%^This is odd, because is is the middle of the night.");
   set_exits(([
     "west" : "/wizards/morgoth/room/strange1.c",
     "south" : "/wizards/morgoth/room/beach2.c"]));
   }

void reset(){
   ::reset();
   new("/wizards/morgoth/mob/walrus.c")->move(this_object());
   }
