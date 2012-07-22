/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

int book;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_listen("default","The faint sound of a voice can be heard...");

  set_listen("conch shell",
    "Your mind is filled with a thunderous voice...\n\n"
	"Beware all who worship evil!\n\n"
	"I am Lord Poseidon, king and master of Atlantis!\n\n"
	"Let this ship serve as a reminder to evil and a message to all "
	"who would walk that path. If you attempt to enslave those I hold dear, "
	"you will feel the might of my armies and navies!\n"
  );
  set_long(
   "The cabin is covered in anemones, sea urchins, sponges, and sea creatures of every shape and form."
   " An extremely decayed desk rests up against what remains of the cabin wall."
   " There is a wardrobe against the far wall and the rusted frame of a bed in the center."
   " A pearl encrusted conch shell hangs from its strap on the wall."
  );

  add_invis_exit("wardrobe");
  set_exits(([
    "wardrobe":ROOMS2"secret-6b.c",
    "out":ROOMS2"room-2c6.c"
   ]));
  set_items(([
    "desk":"This is an extremely decayed metal desk. The drawers still seem to be intact.",
    "drawers":"They appear to actually be shielded against the water by magic. You may be able to pry one open.",
    "conch shell":"It seems to be playing a message of some kind.",
    "wardrobe":"It seems large enough to walk inside."
   ]));
  new(PEARLS"rose_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
  book=0;
}
void init() 
{
  ::init();
  add_action("secret_ledger","pry");
}
int secret_ledger(string str)
{
  if(!str || str != "drawer") return notify_fail("Pry what?\n");
  else if(book !=1) {
    message("info","The drawer slides open and a ledger falls to the floor.\n",this_player());
    new(ITEMS2"ledger.c")->move(this_object());
    book=1;
    message("info",this_player()->query_cap_name()+" prys a drawer open.\n"
	  "A ledger falls to the ground.\n", environment(this_player()), this_player());
    return 1;
  }
  else if(book >=1) {
    message("info","The drawer slides open. It is empty.\n",this_player());
    message("info",this_player()->query_cap_name()+" prys a drawer open.\n",
	  environment(this_player()),this_player());
    return 1;
  }
}
