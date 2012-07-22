#include <std.h>
inherit DAEMON;

int spell();

string type() { return "other"; }

int cmd_morph(string str) {
  int i;
  object *weps, ob, tp, mOb;

  if(!spell()) return 0;

  tp = this_player();  

  if(str)
  {   


    if(tp->query("bear") || tp->query("lion") || tp->query("wolf"))
      return notify_fail("You have already morphed!");

    if(tp->query_current_attacker())
      return notify_fail("You are in combat!\n");

    if(tp->query_ghost())
      return notify_fail("You need a physical form to morph.\n");

    if(tp->query_mp() < 500)
      return notify_fail("You do not have enough mana to morph at this time!\n");

    if(str == "into lion" || str == "lion")
    {
      message("room",tp->query_cap_name()+" morphs into the shape of a lion.", environment(tp), tp);     
      tp->add_stat_bonus("strength", tp->query_base_stats("wisdom")/8);
      tp->add_stat_bonus("dexterity", tp->query_base_stats("wisdom")/4);
      tp->add_skill_bonus("attack", tp->query_base_skill("nature")/8);
      tp->add_skill_bonus("melee", tp->query_base_skill("nature")/8);		    
      write("Your body morphs and forms the shape of a large lion.");
      tp->set("lion",1);
    }
    else if(str == "into wolf" || str == "wolf")
    {
      message("room",tp->query_cap_name()+" morphs into the shape of a wolf.", environment(tp), tp);     
      tp->add_stat_bonus("strength", tp->query_base_stats("wisdom")/6);
      tp->add_stat_bonus("constitution", tp->query_base_stats("wisdom")/6);
      tp->add_stat_bonus("dexterity", tp->query_base_stats("wisdom")/6);
      tp->add_skill_bonus("attack", tp->query_base_skill("nature")/7);
      tp->add_skill_bonus("melee", tp->query_base_skill("nature")/7);		    
      write("Your body morphs and forms the shape of a large wolf.");
      tp->set("wolf",1);
    }
    else if(str == "into bear" || str == "bear")
    {
      message("room",tp->query_cap_name()+" morphs into the shape of a bear.", environment(tp), tp);     
      tp->add_stat_bonus("strength", tp->query_base_stats("wisdom")/4);
      tp->add_stat_bonus("constitution", tp->query_base_stats("wisdom")/4);
      tp->add_skill_bonus("attack", tp->query_base_skill("nature")/6);
      tp->add_skill_bonus("melee", tp->query_base_skill("nature")/6);		    
      write("Your body morphs and forms the shape of a large bear");
      tp->set("bear",1);
    }
    else
      return notify_fail("Syntax: morph into [(type}]\n");

    weps = this_player()->query_wielded();
    i = sizeof(weps);
    while(i--)
      tp->force_me("unwield "+weps[i]->query_id()[0]);

    tp->force_me("remove all");
    tp->add_mp(-500);
    new("/cmds/skills/obj/morph_object.c")->move(tp);
  }
  else
  {
    if(!tp->query("bear") && !tp->query("wolf") && !tp->query("lion"))
      return notify_fail("You must select a form to morph in to.\n");

    mOb = present("morph_object_1x3", tp);

    if(tp->query("bear"))
    {
      tp->set("bear", 0);
      message("room","A bear morphs into the shape of "+tp->query_cap_name()+"!", environment(tp), tp);     
      tp->add_stat_bonus("strength", -(tp->query_base_stats("wisdom")/4));
      tp->add_stat_bonus("constitution", -(tp->query_base_stats("wisdom")/4));
      tp->add_skill_bonus("attack", -(tp->query_base_skill("nature")/6));
      tp->add_skill_bonus("melee", -(tp->query_base_skill("nature")/6));		    
      write("Your body morphs into its old form.");
    }	
    if(tp->query("wolf"))
    {	
      tp->set("wolf",0);
      message("room","A wolf morphs into the shape of "+tp->query_cap_name()+"!", environment(tp), tp);     
      tp->add_stat_bonus("strength", -(tp->query_base_stats("wisdom")/6));
      tp->add_stat_bonus("constitution", -(tp->query_base_stats("wisdom")/6));
      tp->add_stat_bonus("dexterity", -(tp->query_base_stats("wisdom")/6));
      tp->add_skill_bonus("attack", -(tp->query_base_skill("nature")/7));
      tp->add_skill_bonus("melee", -(tp->query_base_skill("nature")/7));		    
      write("Your body morphs into its old form.");
    } 	
    if(tp->query("lion"))
    {
      tp->set("lion",0);
      message("room","A lion morphs into the shape of "+tp->query_cap_name()+"!", environment(tp), tp);     
      tp->add_stat_bonus("strength", -(tp->query_base_stats("wisdom")/8));
      tp->add_stat_bonus("dexterity", -(tp->query_base_stats("wisdom")/4));
      tp->add_skill_bonus("attack", -(tp->query_base_skill("nature")/8));
      tp->add_skill_bonus("melee", -(tp->query_base_skill("nature")/8));		    
      write("Your body morphs into its old form.");
    }	

    tp->fix_vital_bonus();
    if (mOb) mOb->object_gone();
  }
  return 1;
}

void help() {
  write("Syntax <morph into [(living)]>\n"
   "Powerful druids can alter their form to either a "
   "bear, a lion, or a wolf. Each shape has its own "
   "advantages.\n");
}

int spell() {
  object tp;
  tp = this_player();
  if(tp->query_subclass() != "druid") return 0;
  if(tp->query_level() < 50) return 0;
  return 1;
}
