//	/std/party.c
//	party daemon for the Nightmare mudlib
//	created by Descartes of Borg 10 Nov 1992
#include <party.h>
#include <ansi.h>
#include <daemons.h>
mapping party;
mapping invited;
mapping experience;
string party_member(object ob);
void manage_party(string group);
void remove_party(string group);
void remove_invitation(mixed *bing);
int invited_now(object ob, string str);
int same_party(object p1, object p2);
void create() {
  party = ([]);
  invited = ([]);
  experience = ([]);
  call_out("manage_all_parties", 300);
}
int add_member(object ob, string group) {
  if(!party) party = ([]);
  if(party_member(ob)) return ALREADY_MEMBER;
  if(!party[group]) {
    tell_object(ob, "You are the leader of party "+group+".\n");
    party[group] = ({});
  }
  party[group] += ({ ob });
  if(invited) if(invited[group]) if(member_array(ob, invited[group]) != -1) {
        remove_invitation( ({ ob, group, 1 }) );
      }
  ob->set_party(group);
  manage_party(group);
  return OK;
}
int remove_member(object ob) {
  string group;
  if(!party) return NOT_MEMBER;
  group = party_member(ob);
  if(!group) return NOT_MEMBER;
  party[group] -= ({ ob });
  map_delete(experience, ob);
  tell_object(ob, "You are no longer in the party "+group+".\n");
  ob->set_party(0);
  manage_party(group);
  return OK;
}
string party_member(object ob) {
  string *groups;
  int i;
  if(!party) return 0;
  groups = keys(party);
  for(i=0; i<sizeof(groups); i++) {
    if(member_array(ob, party[groups[i]]) != -1) return groups[i];
  }
  return 0;
}
int change_leader(object ob) {
  string group;
  object *this_party;
  int x;
  if(!party) return NOT_MEMBER;
  group = party_member(ob);
  if(!group) return NOT_MEMBER;
  manage_party(group);
  this_party = party[group];
  x = member_array(ob, this_party);
  if(!x) return ALREADY_LEADER;
  this_party[x] = this_party[0];
  this_party[0] = ob;
  tell_object(ob, "You are now the leader of party "+group+".\n");
  party[group] = this_party;
  manage_party(group);
  return OK;
}
void manage_party(string group) {
  object *tmp;
  object *who;
  object ob;
  int i, j;
  tmp = ({});
  if(!party) return;
  if(!party[group]) return;
  if(!sizeof(party[group])) {
    remove_party(group);
    return;
  }
  ob = party[group][0];
  who = party[group];
  for(i=0; i<sizeof(who); i++) {
    if(!who[i]) continue;
    if(!living(who[i]) || !interactive(who[i])) {
      who[i]->set_party(0);
      continue;
    }
    tmp += ({ who[i] });
  }
  if(!sizeof(tmp)) {
    remove_party(group);
    return;
  }
  if(tmp[0] != ob) tell_object(tmp[0], "You are now the leader of the party "+group+".\n");
  party[group] = tmp;
  return;
  tmp = ({});
  for(i=0; i<sizeof(party[group]); i++) {
    if((who = party[group][i]->query_attackers())) {
      for(j=0; j<sizeof(who); j++) {
        if(member_array(who[j], tmp) == -1) tmp += ({ who[j] });
      }
    }
  }
  for(i=0; i < sizeof(party[group]); i++) party[group][i]->set_attackers(tmp);
}
void remove_party(string group) {
  if(!party) return;
  if(undefinedp(party[group])) return;
  map_delete(party, group);
}
void calculate_exp(string group, int exp, object tmp) {
  int tot, x, i;
  if(!party) {
    //        experience[ previous_object() ] += exp;
    previous_object()->fix_exp(exp, tmp);
    return;
  }
  if(!party[group]) {
    previous_object()->fix_exp(exp, tmp);
    return;
  }
  /*
  if(sizeof(party[group]) == 1) {
    experience[ previous_object() ] += exp;
    previous_object()->fix_exp(exp, tmp);
    return 0;
  }
  manage_party(group);
  for(i=0; i<sizeof(party[group]); i++)
  {
    exp = exp / 1.25;	
  }
  */
  manage_party(group);
  for (i = 1; i < sizeof(party[group]); i++) {
    exp = exp * 4 / 5;
  }
  for(i=0; i<sizeof(party[group]); i++) {
    experience[ party[group][i] ] += exp;
    party[group][i]->fix_exp( exp, tmp);
  }
}
int query_party_exp(object ob)
{
  return experience[ob];
}
string *query_parties() {
  if(!party) return 0;
  return keys(party);
}
object *query_party_members(string group) {
  if(!party) return 0;
  if(!party[group]) return 0;
  manage_party(group);
  return party[group];
}
object query_leader(string str) {
  if(!party) return 0;
  if(!party[str]) return 0;
  manage_party(str);
  return party[str][0];
}
void notify_party(string str, string what) {
  int i, sz;
  if(!party) return;
  if(!party[str]) return;
  manage_party(str);
  sz = sizeof(party[str]);
  for(i=0; i<sz; i++) {
    if(party[str][i]->query_ansi()) {  
      LAST_D->add_partyline(party[str][i]->query_name(), HIB+""+NOR+what+""); 
      message("party", HIB+" "+NOR+what+"\n", party[str][i]);
    }
    else 
      LAST_D->add_partyline(party[str][i]->query_name(), " "+what+"");
    message("party", " "+what+"\n", party[str][i]);
  }
}
void add_invited(object ob, string str) {
  if(!invited) return;
  if(!invited[str]) invited[str] = ({});
  invited[str] += ({ ob });
  call_out("remove_invitation", 60, ({ ob, str, 0 }));
}
object *query_invited(string str) {
  if(!invited) return 0;
  if(!invited[str]) return 0;
  return invited[str];
}
int invited_now(object ob, string str) {
  if(!invited) return 0;
  if(!invited[str]) return 0;
  if(member_array(ob, invited[str]) == -1) return 0;
  return 1;
}
void remove_invitation(mixed *bing) {
  if(!invited) return;
  if(!invited[bing[1]]) return;
  if(member_array(bing[0], invited[bing[1]]) == -1) return;
  invited[bing[1]] -= ({ bing[0] });
  if(!bing[2] && bing[0]) tell_object(bing[0], "You are no longer invited to be a member of the party.\n");
}
void manage_all_parties() {
  string *grps;
  int i;
  if(i = sizeof(grps = keys(party)))
    while(i--) manage_party(grps[i]);
  call_out("manage_all_parties", 300);
}
int same_party(object p1, object p2) {
  string party1 = party_member(p1);
  string party2 = party_member(p2);
  if (party1 && party2 && party1 == party2) return 1;
  return 0;
}
