#include <std.h>
#include <corinthor.h>

inherit ROOM;

void reset() {
   ::reset();
     if(random(3) == 1 || present("monster"))
       return;
     new(ELFMOB"rndmob.c")->move(this_object());
     if(random(3) == 1)
       new(ELFMOB"rndmob.c")->move(this_object());
     if(random(4) == 1)
       new(ELFMOB"rndmob.c")->move(this_object());
     if(random(5) == 1)
       new(ELFMOB"rndmob.c")->move(this_object());
}
