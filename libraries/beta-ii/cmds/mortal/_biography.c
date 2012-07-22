//      /bin/user/_biography.c
//      from the Nightmare mudlib
//      gives a player's biography
//      created by Descartes of Borg 30 march 1993

#include <daemons.h>

#include <std.h>

inherit DAEMON;

int cmd_biography(string str) {
    int *pk;
    int birth, byear, i, max;
    string *kills, *quests, *mquests;
    mixed *deaths, *oh;
    string borg, tmp;
    mapping minis;

write("%^BLUE%^+=+=%^BOLD%^( %^WHITE%^Biography %^BLUE%^)%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
    borg = (string)this_player()->query_short();
    byear = year(birth = (int)this_player()->query_birthday()) - 18;
    borg += "\nYou were born "+day(birth)+", "+date(birth)+" "+month(birth)+
      " "+(byear ? (byear<0 ? (-byear)+" BN.\n" : byear+" NM.\n") : " of the null year.\n");
    if(!(oh = (mixed *)this_player()->query_current_marriage()))
      borg += "You are currently single.\n";
    else if(sizeof(oh) == 0)
      borg += "You are currently single.\n";
    else if(!oh[1]) 
      borg += "You married "+capitalize(oh[0])+" on a forgotten date.\n\n";
    else 
      borg += "You married "+capitalize(oh[0])+" on "+month(oh[1])+" "+
        date(oh[1])+", "+year(oh[1])+".\n";

    quests = this_player()->query_quests();
    if (!quests) borg += "%^BLUE%^%^BOLD%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^\nYou have not solved any quests.\n";
      else {
       i = sizeof(quests);
       if (i) borg += "%^BLUE%^%^BOLD%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^\nYou have solved the following quests:\n%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^\n";
       
       while(i--) {
        borg += quests[i] + "\n";
       }
      borg += "\n";
     }
    if(!sizeof(minis = (mapping)this_player()->query_mini_quest_map()))
      borg += "%^BLUE%^%^BOLD%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^\nYou have no meaningful accomplishments.\n";
    else {
      borg += "%^BLUE%^%^BOLD%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^\nYou have been rewarded for these great deeds:\n%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^";
      i = sizeof(mquests = keys(minis));
      while(i--) {    
        borg += "\n"+date(minis[mquests[i]][0])+" "+month(minis[mquests[i]][0])+
          " "+year(minis[mquests[i]][0])+" NM:\n"+minis[mquests[i]][1];
        }
        borg += "\n";
    }
    if(!(deaths=(mixed *)this_player()->query_deaths()) ||
      !(max = sizeof(deaths)))
        borg += "%^BLUE%^%^BOLD%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^\nYou have never experienced the pain of death.\n%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^\n";
    else {
        borg += "%^BLUE%^%^BOLD%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^\nYou have been brought into the grasp of death by:\n%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^\n"+
          arrange_string("Enemy", 15)+arrange_string("Date", 20)+
          arrange_string("Enemy", 15)+"Date\n";
        for(i=0; i<max; i+=2) {
            borg += arrange_string(capitalize(deaths[i][0]), 15);
            tmp = date(deaths[i][1])+" "+month(deaths[i][1])+
              " "+year(deaths[i][1])+" NM.";
            borg += arrange_string(tmp, 20);
            if(i+1 < max) {
                borg += arrange_string(capitalize(deaths[i+1][0]), 15);
                  tmp = date(deaths[i+1][1])+" "+month(deaths[i+1][1])+
                  " "+year(deaths[i+1][1])+" NM.";
                borg += tmp;
            }
            borg += "\n";
        }
    }
    if(!(pk = (int *)this_player()->query_kills()) || !sizeof(pk))
      borg += "\nNo kills.\n";
    else {
        for(i=0, kills = ({}), max = sizeof(pk); i<max; i++) {
            if(pk[i] < 0) continue;
            kills += ({ (string)PLAYER_D->query_monster(pk[i]) });
        }
        borg += "%^BLUE%^%^BOLD%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^\nYou have brought doom to these beings:\n%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^\n";
        borg += format_page(kills, 3);
        borg += "%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^";
    }

    this_player()->more(explode(borg, "\n"));
    return 1;
}

int help()
{
  write( @EndText
Syntax: biography
Effect: gives some details of your character's life.
See also: score
EndText
  );
  return 1;
}
