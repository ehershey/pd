//      /adm/daemon/advanced.c
//      from the Nightmare mudlib
//      the advancment daemon
//      created by Descartes of Borg 05 december 1992

#include <std.h>
#include <rooms.h>
#include <dirs.h>
#include <daemons.h>

#define MY_CLASS_HALL  "/d/standard/"+classs+"_hall"
#define RACE_COST      "/adm/db/races/cost/"
int get_exp(int lev);
int train_player(object tp, string which, int amount);
int get_stat_cost(int x, int lev, string stat);
string get_new_title(object tp);

void create() { seteuid(getuid()); }

int get_exp(int lev) {
    int val;

  val = (lev*lev*lev) * 63;
    return val;
}

int train_player(object tp, string which, int amount) {
    int exp, amt, boo;
 
    if(amount < 1) {
        notify_fail("You cannot train that amount.\n");
        return 0;
    }
    exp = (int)tp->query_exp();

    if(exp-amount < 0) {
        notify_fail("You do not have the experience to train that much.\n");
        return 0;
    }

    amt = ( ((int)tp->query_level()) * ((int)tp->query_max_skill(which)))/2;
     if(amt <= (int)(tp->query_skill(which) - tp->query_skill_bonus(which)))
    {
        notify_fail("You must advance your level to train more in that skill"+
                    ".\n");
        return 0;
    }
    boo = tp->add_skill_points(which, amount/4);
    tp->add_exp(-amount);

    write("You train in the skill of "+which+".");
    return 1;
}
int get_race_change(string race, string stat, int cost)
{
 float perc;
 int max, i, ra;
 string *lines;
 string loc, st, raise, tmp;

 
 loc = RACE_COST + race + "_stats";
 if (!(max=sizeof(lines=explode(read_file(loc), "\n")))) 
   return 0;
    for(i=0; i<max; i++) {
        if(!lines[i] || lines[i] == "" || lines[i][0] == '#') continue;
        if(sscanf(lines[i], "%s;%s", st, raise) != 2) {
            write("Error in reading RACE COST database in line"+(i+1)+".\n");
            return 0;
        }
     if (st==stat) break;
     if (i==max) return cost;
    }
   
   if (raise[0]!='-' && raise[0]!='+')
     return cost;
  raise = replace_string ( raise, "%", "");
    if (raise[0]=='+')
     {
       sscanf(raise, "+%s", tmp);
       perc = (to_float(tmp) / 100);
       ra = ( cost + ( perc * cost*7/2 ) );
      return ra;  
     }
   if (raise[0]=='-')
     {
       sscanf(raise, "-%s", tmp);
        perc = (to_float(tmp)/100);
        ra = ( cost - ( perc * (cost/2) ) );
        if (ra < 1000) ra = 1000;
       return ra;
     }
   
}
int get_stat_cost(int x, int lev, string stat) {
    int z;
/*
    if(x==1) z = (((lev/3)*(lev/3)*10000) + (lev/3)*1000) / 2;
    else z = (lev/2)*(lev/2)*(lev*900);
*/
    if (x==1) z = (lev*lev) * 700;
      else
        z = (lev*lev) * 1000;
       
   z = get_race_change(this_player()->query_race(), stat, z); 
   if (z < 1) z = 2147483647;
   return z;
   return z;
}

int advance() {
    int lev, exp;
    int cum, i;
    mapping skill;
    string *str, st, rnk;

    lev = (int)this_player()->query_level();
    exp = (int)this_player()->query_exp();
    if(get_exp(lev+1) > exp) {
        write("You are not experienced enough to advance to the next level.\n");
        return 1;
    }
    skill = this_player()->query_skills();
    i = sizeof(skill);
    str = keys(skill);
    while(i--) 
      {
       st = str[i]; 
       cum += skill[st]["level"];
      }

    if (cum < this_player()->query_level()*15 && this_player()->query_class() != "dragon")
     {
      write("You need to train your skills before leveling.");
      return 1; 
     }

    this_player()->add_exp(-get_exp(lev+1));
    this_player()->set_level(lev+1);
    if(lev == 99) {
      if (this_player()->query_race() == "demon" || this_player()->query_race() ==
        "lich") rnk = "Anti-"; else rnk = "";
      if (this_player()->query_gender() == "female") rnk += "Heroine";
      else rnk += "Hero";
      write("You have achieved the glorious power of the "+rnk+".");
      log_file("legend", this_player()->query_cap_name()+" became a "+rnk+":"+
        ctime(time())+"\n");
    }
    if(lev == 19) {
        this_player()->set_position("high mortal");
        this_player()->add_search_path(DIR_HM_CMDS);
        write("You have achieved the rank of High Mortal.");
        log_file("high_mortal", this_player()->query_name()+" became a high mortal: "+ctime(time())+"\n");
        this_player()->fix_vital_bonus(lev+1);
        this_player()->register_channels();
        return 1;
    }
    if(lev == 49) this_player()->register_channels();
     this_player()->fix_vital_bonus(lev+1);
    write("You advance to level "+(lev+1)+".\n");
    if (this_player()->query_class() == "vampire") VAMPIRE_D->check_vamp_sub(this_player());
    return 1;
}

void log_death(string str) { log_file("kills", str); }

string get_new_title(object tp) {
    string type;

    if (tp->query_class() == "vampire")
      type = tp->query_class();
    else
      type = tp->query_subclass();
    type = "$N the novice "+type;

    if(tp->query_subclass() == "none") {
        type = "Newbie $N the ";
        if(tp->query_gender() == "male")
            type += "boy";
        else if(tp->query_gender() == "female")
            type += "girl";
        else
            type += "neuter";
    }

    return type;
}

