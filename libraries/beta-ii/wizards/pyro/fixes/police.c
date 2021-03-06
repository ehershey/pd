#include <std.h>
inherit MONSTER;

static int drug;
void add_enforce(string str);
void heart_beat();

void add_enforce(string str) {
   if (str == "drug" || str == "drugs") drug = 1;
}

void create() {
 ::create();
   set_heart_beat(1);
}

void die(object thing) {
  object ob;
  ob = this_object()->query_current_attacker();
  if(ob->is_player()) {
    ob->add_outlaw("other1", 1);
  }
  ::die(thing);
}

void heart_beat() {
   object *all, to, tr, blank;
   string *strp;
   mapping trig;
   int i;

   ::heart_beat();

   trig = ([ ]);
if (!this_object() ||!environment(this_object())) return;
   all = all_inventory(environment(this_object()));
   i = sizeof(all);
   while (i--) {
     if (!all[i]->is_player()) continue;
     if (all[i]->query_recent_outlaw() && !wizardp(all[i]))
                 trig[all[i]->query_name()] = 1;
   }
   if (trig == ([ ])) return;
   strp = keys(trig);
   i = sizeof(strp);
   while (i--) {
     to = find_player(strp[i]);
     if (to == blank) continue;
     tr = new("/d/nopk/tirun/lawless/prep");
     this_object()->force_me("say "+to->query_cap_name()+", you are "
        "wanted by the high government of the land!");
     say(to->query_cap_name()+" is taken off to the High Court of Tirun, "
        "where "+to->query_subjective()+" will be brought to justice.", to);
     to->move(tr);
     tr->start_sequence(to);
   }
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("say Killing a defender of the law is punishable by jail or even death!");
    return 0;
}
