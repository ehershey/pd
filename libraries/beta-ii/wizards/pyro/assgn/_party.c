//      /bin/user/_party.c
//      handles all party commands
//     created 111192 by Descartes of Borg
#include <std.h>
#include <party.h>
#include <daemons.h>
inherit DAEMON;
int form(string str);
int leave();
int join_party(string str);
int add_member(string str);
int sub(string str);
int leader(string str);
int list();
int party_line(string str);
void help();
static string
parse_time(int t)
{
   string str;
   str=(t%60)+" s";
   t /= 60;
   if(t%60>0)
      str=t%60+" m "+str;
   t /= 60;
   if(t%24>0)
      str=t%24+" h "+str;
   t /= 24;
   if(t>0)
      str=t+" d "+str;
   return str;
}
int cmd_party(string str) {
    string com, extra;
/*    if(wizardp(this_player())) return 0;  */
    if(!str) {
        help();
        return 1;
    }
    if(sscanf(str, "%s %s", com, extra) == 2) {
        switch(com) {
            case "form": return form(extra); break;
            case "leave": return leave(); break;
            case "join": return join_party(extra); break;
            case "add": return add_member(extra); break;
            case "remove": return sub(extra); break;
            case "leader": return leader(extra); break;
            case "list": return list(); break;
            case "line": return party_line(extra); break;
            default: help(); return 1; break;
        }
    }
    else {
        if(str == "leave") return leave();
        else if(str == "list") return list();
        else {
            help();
            return 1;
        }
    }
}
int form(string str) {
    string *tmp;
    int x;
    tmp = (string *)PARTY_OB->query_parties();
    if(!tmp) tmp = ({});
    if(member_array(str, tmp) != -1) {
        notify_fail("A party by that name already exists.\n");
        return 0;
    }
    x = (int)PARTY_OB->add_member(this_player(), str);
    if(x==ALREADY_MEMBER) {
        notify_fail("You are already a member of another party.\n");
        return 0;
    }
    write("You form the party "+str+".\nYou are the leader.\n");
    return 1;
}
int leave() {
    int x;
    string partay;
    partay = this_player()->query_party();
    x = (int)PARTY_OB->remove_member(this_player());
    if(x==NOT_MEMBER) {
        notify_fail("You are not a member of any party!\n");
        return 0;
    }
    PARTY_OB->notify_party(partay, (string)this_player()->query_cap_name()+" has left the party.\n");
    write("You leave your party.\n");
    return 1;
}
int add_member(string str) {
    object ob;
    string party;
//    int x;
    int j;
    object *who;
    int highest, lowest;
    ob = find_player(str);
    if(!ob) {
        notify_fail("No player by that name on the mud.\n");
        return 0;
    }
    if(wizardp(ob) && !archp(ob)) { 
        notify_fail("Immortals may not join.\n");
        return 0;
    }
    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You must be the leader of a party to add any members!\n");
        return 0;
    }
    if(this_player() != (object)PARTY_OB->query_leader(party)) {
        notify_fail("You must be the leader of your party to add any members!\n");
        return 0;
    }
    if((int)this_player()->query_level() > (int)ob->query_level()+5 ||
      (int)this_player()->query_level() < (int)ob->query_level() - 5)
        return notify_fail("Too great a level difference for that person "
        "to join this party.\n");
    if(this_player() != (object)PARTY_OB->query_leader(party)) {
        notify_fail("You must be the leader of your party to add any members!\n");
        return 0;
    }
    for(j=0;j<sizeof(who=PARTY_OB->query_party_members(party));j++) {
      if(!j) {
        lowest=who[0]->query_level();
        highest=who[0]->query_level();
        continue;
      }
      if(who[j]->query_level() < lowest) lowest=who[j]->query_level();
      if(who[j]->query_level() > highest) highest=who[j]->query_level();
    }
    if(ob->query_level() < highest-5) return notify_fail("That player is too low a level to join this party.\n");
    if(ob->query_level() > lowest+5) return notify_fail("That player is too experianced for your party.\n");
    PARTY_OB->add_invited(ob, party);
    PARTY_OB->notify_party(party, (string)ob->query_cap_name()+" has been invited to join the party.");
    tell_object(ob, this_player()->query_cap_name()+" invites you to join the party \""+party+"\".\nYou have 60 seconds to type <party join "+party+">.\n");
    return 1;
}
int sub(string str) {
    object ob;
    string party;
    int i;
    ob = find_player(str);
    if(!ob) {
        notify_fail("That player is not on the mud.\n");
        return 0;
    }
    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You must be the leader of a party to remove a member.\n");
        return 0;
    }
    if(this_player() != (object)PARTY_OB->query_leader(party)) {
        notify_fail("You must be the leader of the party to remove a member.\n");
        return 0;
    }
    i = (int)PARTY_OB->remove_member(ob);
    if(i==NOT_MEMBER) {
        notify_fail(ob->query_cap_name()+" is not a member of your group.\n");
        return 0;
    }
    PARTY_OB->notify_party(party, (string)ob->query_cap_name()+" is no longer in the group.");
    return 1;
}
int leader(string str) {
    object ob;
    string party;
    int x;
    ob = find_player(str);
    if(!ob) {
        notify_fail("That player is not on line.\n");
        return 0;
    }
    if(ob == this_player()) {
        notify_fail("You are already the leader!\n");
        return 0;
    }
    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You must lead a group before you may change its leader.\n");
        return 0;
    }
    if(this_player() != (object)PARTY_OB->query_leader(party)) {
        notify_fail("You must be the leader of a group in order to change the leadership.\n");
        return 0;
    }
    if((string)ob->query_party() != party) {
        notify_fail(ob->query_cap_name()+" is not in your party!\n");
        return 0;
    }
    x = (int)PARTY_OB->change_leader(ob);
    if(x != OK) {
        notify_fail("Leadership change failed.\n");
        return 0;
    }
    write("You are no longer the leader.\n");
    PARTY_OB->notify_party(party, (string)ob->query_cap_name()+" is now the party leader.");
    return 1;
}
int list() {
    object *who;
    int i, v;
    int partyExpRate = 0;
    string party;
    string tmp;
    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You are not a member of any party.\n");
        return 0;
    }
    who = (object *)PARTY_OB->query_party_members(party);
    if(!sizeof(who)) {
        notify_fail("You are no longer in a party.\n");
        return 0;
    }
    write("The following are members of the party "+party+":\n");
write( "%^BOLD%^%^MAGENTA%^   Party Member     Idle       hp      sp      mp       exp earned\n"
"%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+%^RESET%^");
// write("   "+(string)who[i]->query_cap_name());
    for(i=0; i<sizeof(who); i++) {
      partyExpRate += who[i]->get_exp_per_hour();
tmp = "     "+arrange_string(who[i]->query_cap_name(), 15);
tmp += arrange_string(parse_time(query_idle(who[i])), 11);
v = percent(who[i]->query_hp(), who[i]->query_max_hp());
  if (v <= 30) tmp += "%^RED%^";
    else
  if (v <= 60) tmp += "%^YELLOW%^";
    else tmp += "%^GREEN%^";
tmp += arrange_string(who[i]->query_hp()+" ", 8)+"%^RESET%^"; 
v = percent(who[i]->query_sp(), who[i]->query_max_sp());
  if (v <= 30) tmp += "%^RED%^";
    else
  if (v <= 60) tmp += "%^YELLOW%^";
    else tmp += "%^GREEN%^";
tmp += arrange_string(who[i]->query_sp()+" ", 8)+"%^RESET%^";
v = percent(who[i]->query_mp(), who[i]->query_max_mp());
  if (v <= 30) tmp += "%^RED%^";
    else
  if (v <= 60) tmp += "%^YELLOW%^";
    else tmp += "%^GREEN%^";
tmp += arrange_string(who[i]->query_mp()+" ", 9)+"%^RESET%^";
tmp += add_commas(PARTY_OB->query_party_exp(who[i]));
write(tmp);
    }
    write("Party Efficiency: "+partyExpRate+" exp/hour");
    return 1;
}
int join_party(string str) {
    int x;
    int highest, lowest;
    if(!str) return 0;
    if (!sizeof(PARTY_OB->query_party_members(str)))
      return notify_fail("That party seems to have disappeared.\n");
    if(!PARTY_OB->invited_now(this_player(), str) && !wizardp(this_player())) {
        notify_fail("You must be invited into a party in order to join.\n");
        return 0;
    }
    highest=0;
    lowest=1000000;
    foreach (object member in PARTY_OB->query_party_members(str)) {
      if (member->query_level() > highest) highest=member->query_level();
      if (member->query_level() < lowest) lowest=member->query_level();
    }
    if (this_player()->query_level() > lowest+5 ||
        this_player()->query_level() < highest-5)
          return notify_fail("Your level is out of range for that party.\n");
    x = (int)PARTY_OB->add_member(this_player(), str);
    if(x==ALREADY_MEMBER) {
        notify_fail("You are already in another party!\n");
        return 0;
    }
    PARTY_OB->notify_party(str, (string)this_player()->query_cap_name()+" has joined the party.\n");
    return 1;
}
void help() {
    write("Command: party\n"+
        "Syntax: <party form [name]>\n"+
        "        <party add [player]>\n"+
        "        <party join [name]>\n"+
        "        <party remove [player]>\n"+
        "        <party leave>\n"+
        "        <party list>\n"+
        "        <party line [message]>\n"+
        "        <party leader [player]>\n"+
        "        <partyrange>\n"+
        "        <last partyline>\n\n"+
        "This command accesses the various party enabling functions.\n"+
        "The person who forms any party is automatically the leader of\n"+
        "the party.  Only that player may add or remove players.  The\n"+
        "level range within a party is limited to a maximum of 5.  That\n"+
        "player may also designate another player as the party leader.\n"+
        "Any party member may leave the party at any time through the\n"+
        "\"leave\" function.  A list of all current party members is\n"+
        "given by the \"list\" function.  Experience is awarded based\n"+
        "on the individual's level with respect to the rest of the party.\n"+
        "Once you have been invited to join the party, you must type\n"+
        "<party join [name]> (where name is the name of the party).\n"+
        "<partyrange> will allow you to see what other players can join\n"+
        "your party. <last partyline> will let you check last messages\n"+
        "on the party line.\n"+
 "See also: follow, kill\n"
  );
}
int party_line(string str) {
    string party, pl_name;
    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You are not a member of a party.\n");
        return 0;
    }
    pl_name = capitalize((string)this_player()->query_name());
    PARTY_OB->notify_party(party, pl_name+" <"+party+">: "+str);
    "/cmds/system/_intercept"->global("tell", "%^RESET%^"+pl_name+" <"+party+">: "+str);
    return 1;
}
