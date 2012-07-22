#include <std.h>
#include <waterworld.h>

inherit DAEMON;

int count;
int critter;
int x;

void execute_selection_lvl1(int max, object rm)
{
count=(1+random(max));

       if(!present("monster", rm)) {
             for(x = 0;x<count;x++)
                  {
                     critter=(1+random(14));
                     if(critter == 1)
                         {new(MOB1"cod.c")->move(rm); }
                     if(critter == 2)
                         {new(MOB1"crab.c")->move(rm); }
                     if(critter == 3)
                         {new(MOB1"eel.c")->move(rm) ; }
                     if(critter == 4)
                         {new(MOB1"shedder.c")->move(rm) ; }
                     if(critter == 5)
                         {new(MOB1"shrimp.c")->move(rm); }
                     if(critter == 6)
                       {new(MOB1"stripper_bass.c")->move(rm);  }
                     if(critter == 7)
                         {new(MOB1"sunfish.c")->move(rm); }
                     if(critter == 8)
                            {new(MOB1"starfish.c")->move(rm); }
                     if(critter == 9)
                            {new(MOB1"pelican.c")->move(rm); }
                     if(critter == 10)
                           {new(MOB1"barnacle.c")->move(rm); }
                     if(critter == 11)
                           {new(MOB1"flounder.c")->move(rm); }
                    if(critter == 12)
                          {new(MOB1"seal.c")->move(rm); }
                    if(critter == 13)
                          {new(MOB1"snail.c")->move(rm); }
                    if(critter == 14)
                          {new(MOB1"seagull.c")->move(rm); }

                              }
                   }
}
