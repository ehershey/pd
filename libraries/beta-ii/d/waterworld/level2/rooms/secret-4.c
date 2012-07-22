/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

int statue_routine();
int notices();

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long("This is one of the many outposts of the mer-people."
   " Posted on the walls are several pictures of their military in full uniform and armor."
   " Some of their equipment seems to be stored here as well, encased in extremely strong magic."
   " There is a large scroll in the center of the north wall. In fact it takes up the entire north wall."
   " A statue of the mer-king stands in the corner."
  );

  set_exits(([
    "out":ROOMS2"room-2k6.c"
   ]));
  set_items(([
    "pictures":"These are photos of mermen and mermaids in fine platinum armour and full battle gear. It seems the mer-military is very formidable indeed judging by these pictures.",
    "equipment":"These pieces of armour and weapons are entomed in jade and protected by a very potent holding spell. The holding spell on the jade case seems so powerful, it gives the impression of pulsating to the rhythm of a magical heartbeat.",
    "statue": (: statue_routine :),
    ////               
    ////  The history of the reef and Atlantis' origins in this realmn.
    // __________________________________________________________________
    "scroll":"There are several plates on the scroll, plate-1 to plate-11.",

    "plate-1":"4235 Anres (Mer-Year)"
    "\n\n A dracolich by the name of Trydryill attempts a global spell of enslavement." 
    " Trydryill's spell of enslavement proves too powerful for him to control." 
    " Instead of the spell enslaving the minds of the people, it goes wild and opens a gate to another world."
    " This accident would cause two cataclysms in the years to come."
    " The first being upon an unfortunate city named 'Atlantis'. The second would be upon Trydryill at the hands of the mighty king of Atlantis."
    "\n     The first cataclysm is that the other end of the gate spell formed directly under the city of Atlantis!"
    " This caused the city to quite literally fall out of one world and settle on the ocean floor of another."
    " Fortunately the magic and technology of the Atlantian people were able to adapt quickly to an aquatic life.",

    "plate-2":"4236 Anres\n\n"
    " A short time after Atlantis fell into Tirun's bay, the king of Atlantis forced all his magical energies into a spell of transformation."
    " This spell changed the Atlantians' bodies to resemble the local aquatic life."
    " This transformation gave them the ability to breathe both with gills and with lungs."
    " The glorious mer-kingdom of Atlantis and the race to become known as mer-people were born."
    "\n\n After expending nearly all of his mana to help his people, the mer-king Poseidon rested to recharge his magical reserves.",

    "plate-3":"4238 Anres"
    "\n\n Once Poseidon's massive reserves of magical energies were restored, the mer-king noticed a depleted state of mana in the world around him."
    " Poseidon decided to create the 'Pearls of Atlantis' to aid the world to recover its mana reserves. He spread them across the ocean's floor.",

    "plate-4":"4241 Anres"
    "\n\n Poseidon determines his people are now adapted to their new home."
    " He summons the general of his armies, the colossal Kracken, and the admiral of his navies, the Man-o-War."
    " Together the trio set out on their quest to discover what brought their people to this world.",

    "plate-5":"4243 Anres"
    "\n\n Poseidon learns of Trydryill's attempts to enslave this world and drain its mana for himself."
    " Unfortunately for both Trydryill and the rest of this world, Poseidon learned that it was this spell that caused his people to endure such hardships."
    " Kraken returns to Atlantis to summon the Atlantian armed forces.",

    "plate-6":"4244 Anres"
    "\n\n Kraken and the Atlantian armed forces surface near Tirun to join Man-o-war and Poseidon."
    " Poseidon instructs his forces to teach the locals how to defend themselves against Trydryill's forces."
    " They learn their ways of swordsmanship, projectiles, hand-to-hand, archery, even the alchemy of the 'Pearls of Atlantis'."
    "\n\n Poseidon himself teaches the people the arts of Atlantian sorcery.",

    "plate-7":"4249 Anres"
    "\n\n Trydryill's forces attempt to invade Tirun."
    " Man-o-war, a jellyfish the size of a small Island, was in the harbor to greet them with open tentacles."
    " Due to his tentacles being the size of large oak trees, the conflict was extremely swift and utterly brutal."
    " Only one of Trydryill's ships escaped on the Man-o-war's orders."
    "\n\n    This attack was a mortal mistake for Trydryill for soon Poseidon would learn of his location.",

    "plate-8":"4250 Anres"
    "\n\n Poseidon's forces take as many people out of harm's way as would follow them."
    " Quite a few of the natives dismissed their tales about the power that Poseidon would be releasing upon Trydryill and the world."
    " Fortunately, some followed them and found shelter high in the mountains, behind magical barriers or under the waves in Atlantis."
    " The ones that remained perished quite savagely in the tsunamis and hurricanes that were to come.",

    "plate-9":"4251 Anres"
    "\n\n Poseidon, Kraken and Man-o-war arrive in the bay at the foot of Trydryill's stronghold."
    " Trydryill's stronghold had withstood all assaults of both magic and force of arms before this day."
    " Unfortunately for Trydryill's stronghold, this trio was more like an embodiment of the will of nature itself."
    "\n\n Trydryill's forces numbered in the hundreds of thousands but were woefully undermatched against these colossal warriors of the deep."
    " In a repeat of the naval attack on Tirun, Man-o-war annihilated everything within a tentacle's reach of the sea."
    " Kraken, an ancient aquatic dragon, marched onto land and attacked the dracolich's armies."
    " Nothing the armies had could pierce Kraken's incredibly thick hide."
    " As a result, everything that carried Trydryill's mark was turned into a walking buffet by the Kraken."
    "\n\n This left the stronghold and the smug dracolich Trydryill for Poseidon to confront."
    "\n\n Trydryill heckled Poseidon as the mer-king stood upon the waves of the bay below."
    "\n\n Poseidon began his enchantments and his trident began to dance with lightning and flames."
    " The waters of this world awakened to Poseidon's call to arms."
    " The mer-king lowered his trident into the water at his feet."
    " Immediately the waters forged great walls of living matter and rushed towards the stronghold in massive tsunami after tsunami."
    " The stronghold fell under such an onslaught and was pulled into the sea at Poseidon's feet.",

    "plate-10":"4251 Anres"
    "\n\n Trydryill proved too powerful for Poseidon to destroy after expending such massive amounts of mana."
    " This lead to Poseidon's decision to entomb the dracolich in amber."
    " The amber prison was entrusted to a race of monks that were visiting Atlantis when it was pulled into this world.",

    "plate-11":"4258 Anres\n\n"
    "(This plate seems to be too worn to be readable)"
   ]));
  // __________________________________________________________________
  ////

  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}

int statue_routine() {
  object dart=new(TRIVIA"probe.c");
  object TP=this_player();
  object prize;
  string pname=TP->query_name();
  int index=175;
  //
  //   Index is to be set to 125 upon movement to the player-port.
  //        It is set at 2 only for testing purposes.

  int score;


  load_object(ROOMS2"secret-5.c");
  dart->move(ROOMS2"secret-5.c");

  score=(environment(dart)->score_check(pname));
  dart->remove();

  if(score<index) {
    message("info","This is an immaculate statue of the Mer-king, Poseidon.",TP);
    return 1;
  }

  else if(score >= index) {
    message("say","\n\nA voice resonates from the statue stating: Quessalaz has informed me that you have done well with his questions. You may have the Atlantian Coat-of-Arms as a gift from me, King Poseidon.\n\n",TP);

    message("info","The statue hands you a suit of armour.", TP);
    message("info","The statue comes to life and hands a suit of armour to "+TP->query_cap_name()+".", environment(TP),TP);
    prize = new(PRIZES"coat-of-arms.c");
    if (prize->move(TP)) prize->move(environment(TP));
    TP->set_property("coat-of-arms",1);
    TP->force_me("save");
    return 1;
  }

}
