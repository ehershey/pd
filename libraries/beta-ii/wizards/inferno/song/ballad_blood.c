#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
     "Tempest rages, lightning strikes and thunder roars,",
     "An army heads into the storm, they go to war;",
     "Led by courage, blessed by sages,",
     "Naught is hope, solely fury,",
     "Soldiers fight with vengance deadly",
     "Fallen buried, fighting now for what was taken,",
     "Oh! sweeping death, we are ready!"
   }));
   set_type("other");
   set_song_name("ballad of blood");
}

int check_sing(object o) {
   if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 76)
     return 1;
}

void finish_song() {
   object tp, *all = ({ }), *att = ({ });
   int atk, i, total, time, j, k;

   tp = this_object()->query_caster();
   all = all_inventory(environment(tp));
   atk = tp->query_skill("euphony")/5;
   time = tp->query_level()/2;
   i = sizeof(all);
   total = 1;
   while (i--) {
     if (!all[i]->is_living()) continue;
     if (all[i] == tp) continue;
     if (wizardp(all[i]) && !wizardp(tp)) continue;
     att = tp->query_attackers();
     j = sizeof(att);
     k = 0;
     while (j--) {
	if (all[i] == att[j]) k = 1;
     }
     if (k) {
	message("info", "As your enemies gather courage, you nervously "
	  "back down a little.", all[i]);
	say(all[i]->query_cap_name()+" looks a little more cowardly.",
	  all[i]);
	if (all[i]->query_skill_bonus("melee") > -((atk*2) - 10))
	  all[i]->add_skill_bonus("melee", -(atk), time);
	if (all[i]->query_skill_bonus("defense") > -((atk*2) - 10))
	  all[i]->add_skill_bonus("defense", -(atk), time);
	continue;
     }
     if (tp->query_party() && tp->query_party() == all[i]->query_party()) {
	message("info", "You gather up your wits and go to battle.", all[i]);
	say(all[i]->query_cap_Name()+" looks a little more courageous.",
	  all[i]);
	if (all[i]->query_skill_bonus("melee") < ((atk*2) + 10))
	  all[i]->add_skill_bonus("melee", atk, time);
	if (all[i]->query_skill_bonus("attack") < ((atk*2) + 10))
	  all[i]->add_skill_bonus("attack", atk, time);
	continue;
     }
   }
   message("info", "You gather up your wits and go to battle.", tp);
   say(tp->query_cap_Name()+" looks a little more courageous.", tp);
   if (tp->query_skill_bonus("melee") < ((atk*2) + 10))
     tp->add_skill_bonus("melee", atk, time);
   if (tp->query_skill_bonus("attack") < ((atk*2) + 10))
     tp->add_skill_bonus("attack", atk, time);

   message("info", "You strike fear into the hearts of your enemies "
     "and inspire your alies.", tp);
}
