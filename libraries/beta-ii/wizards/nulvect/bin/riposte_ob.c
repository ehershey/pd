#include <std.h>
#include <daemons.h>
inherit OBJECT;

object owner;

void setup(object tp);
void next_round(int i);
int catch_it(string str);
int do_riposte();
void remove();

int do_riposte() {
  object tgt=environment();
  int att, cost;

  cost = owner->query_skill("blade")/8 + owner->query_stats("dexterity")/5;
  
  if (owner->query_sp() < cost) {
    message("info","You see an opening, but you're too tired to riposte.",owner);
    return 0;
  }

  if (owner->query_stats("dexterity") <
      tgt->query_stats("dexterity")*3/4 + random(tgt->query_stats("dexterity")*2/5)) {
    
        message("info","%^BOLD%^You see an opening as "+tgt->query_cap_name()+
                       " tries to attack!%^RESET%^\n"
                       "You try to dodge, but "+tgt->query_subjective()+
                       " is too fast!",
                       owner);
        message("info",owner->query_cap_name()+" tries to dodge your attack, "
                       "but you are too fast for "+owner->query_objective()+".",
                       tgt);
        message("info",owner->query_cap_name()+" tries to dodge "+
                       tgt->query_cap_name()+"'s attack, but "+
                       tgt->query_cap_name()+" is too fast!",
                       environment(tgt), ({tgt, owner}) );
        owner->add_sp(-random(15));
        return 0;
  }
  
  owner->add_sp(-(cost+random(10)));

  message("info","%^BOLD%^You see an opening as "+tgt->query_cap_name()+
                 " tries to attack!%^RESET%^\n"
                 "You quickly dodge and lunge at "+tgt->query_cap_name()+
                 ", driving your blade into "+tgt->query_objective()+"!",
                 owner);
  message("info","As you try to attack, "+owner->query_cap_name()+
                 " dodges and lunges at you with "+owner->query_possessive()+
                 " blade!", tgt);
  message("info",tgt->query_cap_name()+" tries to attack, but "+
                 owner->query_cap_name()+" dodges and lunges with "+
                 owner->query_possessive()+" blade!",
                 environment(tgt), ({tgt, owner}) );

  tgt->add_skill_bonus("defense", owner->query_skill("attack"), 1);
  
  att = BALANCE2_D->get_Pdamage(owner, tgt, 2,
      ({ "attack", "blade", "entertainment" }),
      ({ "strength", "dexterity" }), ({ "dexterity" }) );
  att *= 1.8;

  tgt->do_damage(tgt->return_target_limb(), att+random(20));

  return 1;

}

int catch_it(string str) {
  string verb=query_verb();
  object cmd, ab;
  int i;

  if (find_call_out("remove") != -1)
    return;
  if (!owner) {
    remove_call_out("next_round");
    call_out("remove",1);
    return 0;
  }
  if (!present(owner, environment(environment()))) {
    remove_call_out("next_round");
    call_out("remove",1);
    return 0;
  }
  if (file_size("/cmds/skills/_"+verb+".c") >= 1) {
    cmd=load_object("/cmds/skills/_"+verb+".c");
    if (cmd) {
      if (function_exists("abil",cmd) != 0) {
        if (cmd->abil()) {
          ab=load_object("/cmds/mortal/_abilities.c");
          if (ab) {
            if (ab->query_spell_class(verb) == "attack") {
              i=do_riposte();
              remove_call_out("next_round");
              call_out("remove",1);
              return i;
            }
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
  set_id(({"riposte_ob"}));
  set_mass(0);
}

void setup(object tp) {
  if (!tp) return;
  owner=tp;
  owner->set("riposte", 1);
  next_round(3+(owner->query_skill("perception")/40));
}

void next_round(int i) {
  if (!this_object())
    return;
  
  if (!living(environment()) || !owner ||
      !present(owner,environment(environment())) ||
      member_array(environment(),owner->query_attackers()) == -1) {
    remove();
    return;
  }

  i--;
  if (i<1) {
    message("info","You couldn't find an opportunity to riposte "+
                   environment()->query_cap_name()+".", owner);
    remove();
    return;
  }
  
  call_out("next_round",2,i);
}

void remove() {
  if (owner)
    owner->set("riposte",0);
  ::remove();
}
