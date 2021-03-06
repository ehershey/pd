#include <std.h>
inherit MONSTER;

static int talk = 0;

void create() {
 ::create();
   set_name("girl");
   set_short("a little girl");
   set_long("Her face glows with holy light and her hair, despite her young age, "
     "is white. The girl's eyes are a brilliant yellow. She is very pretty.");
   set_id(({ "girl", "angel" }));
   set_level(1);
   set_race("angel");
   set_body_type("faerie");
   set_heart_beat(1);
}

int query_talking() { return talk; }
void start_talk() { talk = 1; }
void stop_talk()  { talk = 0; }

void heart_beat() {
 object *all;
 string *quests;
 int i, q;
 ::heart_beat();
   if (!talk) return;
   switch (talk) {
     case 1:
       say("%^BOLD%^A pretty little girl floats upwards until she comes face to "
         "face with you.", this_object());
       break;
     case 3:
       say("%^BOLD%^A realization comes to you, this was the girl you just died "
         "trying to save! Had she perished as well? Were your efforts in vain?",
         this_object());
       break;
     case 4:
       say("%^YELLOW%^A sweet voice sounds in your mind.", this_object());
       force_me("say You lived a life like many others.");
       break;
     case 6:
       force_me("say You journeyed on a quest, The Quest of the Archangel. You "
         "saw me and being brave of heart and true of spirit, you tried to save "
         "me from certain death.");
       break;
     case 8:
       force_me("say I thank you.");
       force_me("smile");
       break;
     case 9:
       all = all_inventory(environment(this_object()));
       i = sizeof(all);
       while (i--) {
         if (all[i] == this_object()) continue;
         if (!all[i]->is_player()) continue;
         quests = all[i]->query_quests();
         q = sizeof(quests);
         while (q--) {
           if (quests[q] == "The Quest of the Archangel") {
             this_object()->force_me("say You have already completed this "
               "quest, why come you again? Go back to whence you came.");
            all[i]->move_player("/d/nopk/tirun/square", "out");
             return;
           }
         }
         all[i]->add_exp(3000000);
         all[i]->set_stats("wisdom", (all[i]->query_stats("wisdom") + 3));
         all[i]->set_stats("charisma", (all[i]->query_stats("charisma") + 3));
         all[i]->set_stats("constitution", (all[i]->query_stats("constitution") + 3));
         all[i]->set_manual_quest("The Quest of the Archangel", 21);
      if (member_array(all[i]->query_subclass(), ({ "antipaladin", "kataan", "necromancer" }) ) != -1) {
        this_object()->force_me("say I only wish that you had chosen a more noble path in life, "
           "so that you could ascend into the heavens. Please accept this small gift, my friend.");
        talk = 0;
        return;
      }

         if (all[i]->query_subclass() == "paladin" || all[i]->query_subclass() ==
             "cleric" || all[i]->query_subclass() == "monk")
          this_object()->force_me("say "+all[i]->query_cap_name()+", you have "
             "discovered the true Quest of the Archangel. You need but ascend "
             "to become one of the blessed warriors of purity.");

         this_object()->force_me("say Accept this gift, my friend, then ascend "
             "to leave.");
         message("quest", "You feel more experienced from the completion of "
           "The Quest of the Archangel", all[i]);
         talk = 0;
         return;
       }
   }
   talk++;
}
