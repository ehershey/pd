// Seeker's new spell system

#include <daemons.h>

inherit DAEMON;

int min_mp, min_sp, min_level, no_combat, min_align, max_align, spell_delay;
mapping min_skills, fail_messages;
string *target_properties, *p_class, *subclass;

void set_spell_delay(int x);
void set_min_align(int x);
void set_max_align(int x);
void set_min_sp(int x);
void set_min_mp(int x);
void set_min_level(int x);
void set_class(string *st);
void set_subclass(string *st);
void set_skills(mapping sk);
void set_fail_messages(mapping fl);
void set_no_combat(int x);
int  target_ok(object ob);
int  ok_to_cast(object ob);
void set_target_properties(string *str);
void set_class(string *st)
{
 p_class = st;
}
void set_subclass(string *st)
{
 subclass = st;
}
void set_spell_delay(int x)
{
 spell_delay = x;
}
void set_min_align(int x)
{
 min_align = x;
}
void set_max_align(int x)
{
 max_align = x;
}
int sizeof_target()
{
 return sizeof(target_properties);
}
void set_target_properties(string *str)
{
 target_properties = str;
}

string query_spell_name()
{
 string st;
 
 sscanf( base_name(this_object()), "_%s.c", st);
 if (st) return st; else return "";

}
int target_ok(object ob)
{
 int i;
  
 if (!ob) return notify_fail("You do not see that anywhere.\n");
 if (userp(ob) && !interactive(ob)) return notify_fail("You may not target link-dead players.\n");
 if (!i = sizeof(target_properties)) return notify_fail("ERROR: No target properties notify a creator\n");
 while(i--)
  { 
   switch(target_properties[i])
    {
     case "living":
      if (!ob->is_living()) return notify_fail("You can only target living things.\n");
      break; 
     case "user":
      if (!userp(ob)) return notify_fail("You can only target players.\n"); 
      break;
     case "alive":
      if (ob->query_ghost()) return notify_fail("You can only target things that are alive.\n");
      break;
     case "ghost":
      if (!ob->query_ghost()) return notify_fail("You can only target dead people.\n");
      break;
     case "present":
      if (!present(ob, environment(this_player()))) return notify_fail("You dont see that anywhere.\n");
      break;
     case "inventory":
      if (!present(ob, this_player())) return notify_fail("You are not carrying that.\n");
      break;
     case "armour": 
      if (!ob->is_armour()) return notify_fail("You can only use this on armour.\n");
      break;
     case "weapon":
      if (!ob->is_weapon()) return notify_fail("You can only use this on weapons.\n");
      break;
     case "enemy":
      if (member_array(ob, this_player()->query_attackers())==-1)
        if (member_array(ob, this_player()->query_hunters())==-1)
          return notify_fail("You are not attacking that.\n");
      break;
    case "attack": break;
    case "default": return notify_fail("You may not attack that.\n");
     break;
    }
  if (ob->query_property("no "+query_spell_name()))
    return notify_fail("That is immune to such magic.\n");
  
  if ("attack"==target_properties[i])
    if (member_array(ob, this_player()->query_attackers())==-1)
      this_player()->kill_ob(ob, 0);
  }
 return 1;
}
 
void set_no_combat(int x)
{
 no_combat = x;
}
void set_min_sp(int x)
{
 min_sp = x;
}

void set_min_mp(int x)
{
 min_mp = x;
}

void set_min_level(int x)
{
 min_level = x;
} 

void set_skills(mapping sk)
{
 min_skills = sk;
} 

void set_fail_messages(mapping fl)
{
 fail_messages = fl;
}

int ok_to_cast(object ob)
{
 int i;
 string *str;
 
 if (!ob) return 0;
 if (!this_object()->spell())
   return notify_fail("You are not able to cast such spell.\n");
 if (member_array(this_player()->query_class(), p_class)==-1 ||
     member_array(this_player()->query_subclass(), subclass)==-1)
   return notify_fail("You are not able to cast that spell.\n");
 str = keys(min_skills);
 i = sizeof(str);
 while(i--)
  {
    if (min_skills[str[i]] > this_player()->query_skill(str[i]) )
      return notify_fail("You do not have the skill to cast this spell.\n");
  }
 if (min_level > this_player()->query_level())
   return notify_fail("You're magicial powers are not experienced enough to cast that.\n");
 if (!alignment_ok(this_player()))
   return notify_fail("You have betrayed the source of your powers.\n");
 if (this_player()->query_alignment() > max_align)
   return notify_fail("You too much with the light to cast this spell.\n");
 if (this_player()->query_alignment() < min_align)
   return notify_fail("There is too much darkness in your soul to cast this.\n");
 if (this_player()->query_magic_round())
    return notify_fail("You are already in the middle of another spell.\n");
 
 if (this_player()->query_sp() < min_sp)
   return notify_fail("You lack the stamina to cast this spell.\n");
 if (this_player()->query_mp() < min_mp)
   return notify_fail("You lack the magical power to cast this spell.\n");
if (this_player()->query_current_attacker() ||
    this_player()->query_hunters())    
 if (this_player()->query_current_attacker() ||
     (member_array(ob, this_player()->query_hunters()!=-1 &&
      present(ob, environment(this_player())) )) && no_combat)
   return notify_fail("You can not cast this spell while in combat.\n");
  if (!target_ok(ob)) return 0;

 return 1;
}


void create()
{
 ::create();
 min_level = 1;
 min_sp = -500;
 min_mp = -500;
 min_align = -1500;
 max_align = 1500;
 p_class = ({"child"});
 subclass = ({"none"});
}
