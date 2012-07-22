#include <std.h>
#include <waterworld.h>

inherit DAEMON;

int count;
int critter;
int x;

void execute_selection_lvl2(int max, object rm)
{
  count=(1+random(max));
  if(!present("monster",rm)) {

    for(x = 0;x<count;x++)
    {
      critter=(1+random(14));
      switch (critter) {
      case 1:
	new(MOB2"bluefish.c")->move(rm);
	break;
      case 2:
	new(MOB2"coral.c")->move(rm);
	break;
      case 3:
	new(MOB2"lobster.c")->move(rm);
	break;
      case 4:
	new(MOB2"moray_eel.c")->move(rm);
	break;
      case 5:
	new(MOB2"octopus.c")->move(rm);
	break;
      case 6:
	new(MOB2"seahorse.c")->move(rm);
	break;
      case 7:
	new(MOB2"squid.c")->move(rm);
	break;
      case 8:
	new(MOB2"tuna.c")->move(rm);
	break;
      case 9:
	new(MOB2"clownfish.c")->move(rm);
	break;
      case 10:
	new(MOB2"nudibranch.c")->move(rm);
	break;
      case 11:
	new(ITEMS2"angler_lure.c")->move(rm);
	break;
      case 12:
	new(MOB2"nautilus.c")->move(rm);
	break;
      case 13:
	new(MOB2"large_seahorse.c")->move(rm);
	break;
      case 14:
	new(ITEMS2"stone_lure.c")->move(rm);
	break;
      }
    }
  }
}
