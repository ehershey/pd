#include <std.h>
#include <daemons.h>
#define COL "%^BLUE%^"
#define RES "%^RESET%^"
inherit OBJECT;

object owner;
string feature;

void setup(object tp);
void next_round(int i);
int catch_it(string str);
int do_dart();
void remove();

int get() { return 0; }

int do_dart() {
  object tgt=this_player();
  int def, cost;

  cost = owner->query_skill("agility")/10 + owner->query_stats("dexterity")/6;
  
  if (owner->query_sp() < cost) {
    message("info","You are too tired to dart out of the way!",owner);
    return 0;
  }

  if (owner->query_stats("dexterity") <
      tgt->query_stats("dexterity")*3/4 +
      random(tgt->query_stats("dexterity")*2/5)) {
    
        message("info",tgt->query_cap_name()+ "'s attack is too fast "
                       "for you to dart away!",
                       owner);
        message("info",owner->query_cap_name()+" tries to dart away, "
                       "but you are too fast for "+owner->query_objective()+".",
                       tgt);
        owner->add_sp(-random(15));
        return 0;
  }
  
  owner->add_sp(-(cost+random(10)));

  message("info",tgt->query_cap_name()+ " tries to attack, "
                 "but you "+COL+"dart behind "+
                 indefinite_article(feature)+RES+" and "+
                 COL+"avoid"+RES+" "+tgt->query_objective()+"!",
                 owner);
  message("info","You try to attack, but "+owner->query_cap_name()+
                 " "+COL+"darts"+RES+" behind "+indefinite_article(feature)+
                 " and "+COL+"avoids"+RES+" the blow completely!",
                 tgt);
  message("info",tgt->query_cap_name()+" tries to attack, but "+
                 owner->query_cap_name()+" "+COL+"darts behind "+
                 indefinite_article(feature)+RES+" and "+
                 COL+"avoids"+RES+" the blow completely!",
                 environment(tgt), ({tgt, owner}) );

  tgt->add_skill_bonus("attack", -(owner->query_skill("defense")), 1);
  
  return 1;


}

int catch_it(string str) {
  string verb=query_verb();
  object cmd, ab;
  int i;

  if (find_call_out("remove") != -1)
    return 0;

  if (!owner || !present(owner, environment())) {
    remove_call_out("next_round");
    call_out("remove",1);
    return 0;
  }

  if (this_player() == owner)
    return 0;

  if (file_size("/cmds/skills/_"+verb+".c") >= 1) {
    cmd=load_object("/cmds/skills/_"+verb+".c");
    if (cmd) {
      if (function_exists("abil",cmd) != 0) {
        if (cmd->abil()) {
          if (cmd->type() == "attack") {
            i=do_dart();
            remove_call_out("next_round");
            call_out("remove",1);
            return i;
          }
        }
      }
    }
  }
  return 0;
}

void init() {
  ::init();
  add_action("catch_it", "", 1);
}

void create() {
  ::create();
  set_id(({"dart_abil_ob"}));
  set_weight(0);
}

void setup(object tp, string feat) {
  if (!tp) return;
  owner=tp;
  feature = feat;
  next_round(4+(owner->query_skill("agility")/50));
}

void next_round(int i) {
  if (!this_object())
    return;
  
  if (living(environment()) || !owner ||
      !present(owner,environment()) ||
      !sizeof(owner->query_attackers())) {
    remove();
    return;
  }

  i--;
  if (i<1) {
    message("info","You relax and stop trying to dart away.", owner);
    remove();
    return;
  }
  
  call_out("next_round",2,i);
}

void remove() {
  ::remove();
}
