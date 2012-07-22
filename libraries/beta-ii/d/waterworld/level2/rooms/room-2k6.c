/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_smell("default","There is a distinct acrid scent in the air.");
  set_long("Several variations of the phylum 'porifera' are anchored to the reef in this area."
   " This type of animal is commonly known as a 'sponge'."
   " Sponges form structures called spicules."
   " Most sponges give off bio-toxins that are poisonous to a large range of lifeforms."
   " A large strange looking anemone is here."
  );

  set_exits(([
    "enter anemone":ROOMS2"secret-4.c",
    "northeast":ROOMS2"room-2l5.c",
    "northwest":ROOMS2"room-2j5.c",
    "southwest":ROOMS2"room-2j7.c"
   ]));
  add_invis_exit("enter anemone");
  set_items(([
    "anemone":"This anemone seems to be of magical origin. Perhaps you can enter it??",
    "spicules":"These are the columns that the sponges form. They are usually made out of calcium carbonate or silicon dioxide.",
    "sponges":"Most sponges eat by filtering out bacteria from the water. They have very few predators. It seems that a blue sponge is getting attacked in the corner however.",
    "blue sponge":"A nudibranch is nibbling on the sponges here. These critters are one of few animals that are immune to the sponges' toxins."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
