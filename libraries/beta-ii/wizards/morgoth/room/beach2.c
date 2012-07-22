#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_short("%^BOLD%^%^RED%^A Strange Path");
   set_long(
      "%^BOLD%^%^YELLOW%^A Sandy Beach\n"
      "%^BOLD%^%^GREEN%^The sea is wet as wet could be, the sand "
      "is dry as dry.\n"
      "%^BOLD%^%^GREEN%^You can not see a cloud, because no cloud is in the sky."
      " No birds are flying overhead, there are no birds to fly.");
   set_exits((["north" : "/wizards/morgoth/room/beach1.c"]));
   }

void reset(){
   ::reset();
   new("/wizards/morgoth/mob/carpenter.c")->move(this_object());
   }
