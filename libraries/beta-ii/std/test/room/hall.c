#include <teststd.h>
#include <council.h>
#include <daemons.h>
#include <rooms.h>

inherit ROOM;

string previous_title(object tp);
int get_cost(string which, int lev);
void set_type(string clas);

string this_class;

void create() {
  ::create();
  set_property("no attack", 1);
  set_property("no castle", 1);
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no magic", 1);
  set_property("no attack", 1);
  set_property("no teleport", 1);
  set_property("no bump", 1);
}

void init() {
    ::init();
    add_action("cmd_start", "start");
    add_action("roll","roll");
    add_action("train", "train");
    add_action("improve", "improve");
    add_action("advance","advance");
    add_action("list","list");
}

void set_type(string clas) {this_class = clas;}

int roll(string str) {
    if(str != "stats") return 0;
    ROOM_SETTER->do_rolls();
    return 1;
}

int advance() { return (int)ADVANCE_D->advance(); }

int train(string str) {
    string which, which_tmp;
    int amount;
    if(!str) {
        notify_fail("Correct syntax: <train skill amount>\n");
        return 0;
    }
    if(sscanf(str, "%s %s %d", which, which_tmp, amount) == 3) which = which+ " "+ which_tmp;
    else if(sscanf(str, "%s %d", which, amount) !=2) {
        notify_fail("Correct syntax: <train skill amount>\n");
        return 0;
    }
    which = lower_case(which);
    if(!this_player()->skill_exists(which)) {
        notify_fail("No such skill.\n");
        return 0;
    }
    return (int)ADVANCE_D->train_player(this_player(), which, amount);
}

int improve(string str) {
    string *stats;
    string adj;
    int stat_cost;
    if (this_class && this_player()->query_class() != this_class)
      return notify_fail("You may not do that here.\n");
    if (!str)
      {
       notify_fail("Improve what?\n");
       return 0;
      }
    stats = ({ "strength", "intelligence", "wisdom", "dexterity", "constitution", "charisma" });
    str = lower_case(str);
    if(member_array(str, stats) == -1) {
        notify_fail("You have no such stat.\n");
        return 0;
    }
    stat_cost = get_cost(str, (int)this_player()->query_base_stats(str)+1);
    if( (int)this_player()->query_exp()-stat_cost < 0 ) {
        notify_fail("You are not experienced enough to improve yourself in that way.\n");
        return 0;
    }
    this_player()->set_stats(str, (int)this_player()->query_base_stats(str) + 1);
    this_player()->add_exp(-stat_cost);
    adj = (str == "strength" ? "stronger" : (str == "intelligence" ? "more intelligent" :
      (str == "wisdom" ? "wiser" : (str == "dexterity" ? "more nimble" :
      (str == "constitution" ? "sturdier" : "more attractive")))));
    message("my_action", sprintf("You look %s.", adj), this_player());
    message("other_action", sprintf("%s looks much %s",
      (string)this_player()->query_cap_name(), adj), environment(this_player()),
      ({ this_player() }));
    return 1;
}

int get_cost(string stat, int lev) {
    switch(this_class) {
    case "fighter":
        switch(stat) {
            case "strength": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            case "constitution": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            case "dexterity": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            default: return (int)ADVANCE_D->get_stat_cost(2, lev,stat); break;
        } break;
    case "mage":
        switch(stat) {
            case "intelligence": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            case "constitution": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            case "wisdom": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            default: return (int)ADVANCE_D->get_stat_cost(2, lev, stat); break;
        } break;
    case "rogue":
        switch(stat) {
            case "intelligence": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            case "dexterity": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            case "charisma": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            default: return (int)ADVANCE_D->get_stat_cost(2, lev,stat); break;
        } break;
    case "clergy":
        switch(stat) {
            case "intelligence": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            case "wisdom": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            case "strength": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            default: return (int)ADVANCE_D->get_stat_cost(2, lev,stat); break;
        } break;
    case "wanderer":
        switch(stat) {
            case "charisma": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            case "dexterity": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            case "constitution": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            default: return (int)ADVANCE_D->get_stat_cost(2, lev,stat); break;
        } break;
    case "dragon":
        switch(stat) {
            case "strength": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            case "constitution": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            case "intelligence": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            case "wisdom": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
            default: return (int)ADVANCE_D->get_stat_cost(2, lev,stat); break;
        } break;
    case "vampire":
      switch (stat) {
        case "constitution":
        case "strength":
        case "intelligence":
          return (int)ADVANCE_D->get_stat_cost(1, lev, stat); break;
        default:
          return (int)ADVANCE_D->get_stat_cost(2, lev, stat); break;
      } break;
    default: return (int)ADVANCE_D->get_stat_cost(2, lev, stat); break;
    }
}

int list(string str) {
  int x;
  
  if(!str) "/d/nopk/standard/quest_room"->list_quests(this_player(), 0);
  else {
    if(sscanf(str, "%d", x) != 1) {
    notify_fail("You must give the number of the quest you want listed.\n");
  return 0;
  }
  if(x<1) {
    notify_fail("No such quest.\n");
  return 0;
  }
"/d/nopk/standard/quest_room"->list_quests(this_player(), x);
  }
  return 1;
}

int cmd_start(string str)
{
 if (!str || str=="")
   {
    notify_fail("Start where?\n");
    return 0;
   }
 if (str!="here")
   {
    notify_fail("You cant start there.\n");
    return 0;
   }
 this_player()->set_primary_start(base_name(this_object()));
 write("You are now set to start here.");
 return 1;
}
