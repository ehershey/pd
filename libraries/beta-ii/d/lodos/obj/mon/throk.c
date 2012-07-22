#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi, count;

void create() {
 ::create();
   set_short("an orc fighter");
   set_id(({ "throk", "orc" }));
   set_name("throk");
   set_level(22);
   set_long("Throk the orc has trained himself with the help of a "
      "gang of fighters as a mixture of a berserker and a warrior. "
      "His strange training leaves Throk with both the training of "
      "a warrior and the fury of a berserker.");
   set_body_type("ogre");
   set_race("orc");
   set_gender("male");
   set_heart_beat(1);
   make(ARM"loin");
   set_emotes(4, ({ "Throk mumbles something about an escaped llama." }),
      0);
}

int llama_give(string str) {
   if (!str || str != "llama to throk")
     return notify_fail("Trade what to whom?\n");
   if (this_player()->set_mini_quest("llama", 9000, "You returned an escaped "
     "llama to the rightful owners.")) {
      write("You trade the llama to Throk.");
      write("You feel more experienced.");
      tell_room(environment(this_player()), this_player()->query_cap_name()+
         " looks more experienced.", ({ this_player() }));
      say(this_player()->query_cap_name()+" trades the llama to the fighters.", this_player());
      add_money("gold", 5000);
      force_me("give 5000 gold coins to "+this_player()->query_name());
      present("llama", environment(this_object()))->remove();
      this_object()->remove();
      return 1;
   }
   force_me("say But you already gave Throk llama!");
   return 1;
}

void init() {
 ::init();
   add_action("llama_give", "trade");
}

void heart_beat() {
 ::heart_beat();
   if(!this_object()) return;
   if (!oi) {
     force_me("wear loincloth");
     oi = 1;
   }
   if (count >= 5) count = 0;
   if (environment(this_object()))
   if (present("llama", environment(this_object()) ) ) {
      if (count == 2) {
       force_me("say Hey! Throk want trade monies for llama! "
         "Throk want llama back, Throk train llama.");
      }
   }
   count++;
}
