//  Filtration System for fucking potty mouths.  Damn those sons of a bitches!
//   Whit

#include <daemons.h>

string time_stamp();
#define WORDS ({ "fuck", "blowjob", "pussy", "damn", "vagina", "nipple", \
                 "damnit", "shitty", "bitch", "fucker", "fuc", \
                 "cunt", "nigger", "niggar", "whore", "fck", "fag", "shit", \
                 "dick", "cock", "homo", "lesbian", "fuk", "piss", "fuuk", "kcuf", "kcf"\
                })

string *commands = ({
  "newbie",
  "hm",
  "elite",
  "guild",
  "council",
  "OOC",
  "gossip",
  "trivia",
  "colosseum",
  "vampire",
  "demon",
  "angel",
  "lich",
  "wanderer",
  "rogue",
  "mage",
  "fighter",
  "clergy",
  "dragon",
});

int filter(string cmd, string msg) {
    string *rep=({"@","!","#"});
    string *ex;
    string tmp;
    int i, x, t, cussed;
    if(wizardp(this_player())) return 0;
   if(!msg) return 0;
    msg = replace_string(msg, ".", "");
    msg = replace_string(msg, "-", "");
    msg = replace_string(msg, "/", "");
    msg = replace_string(msg, "|", "");
    msg = replace_string(msg, "(", "");
    msg = replace_string(msg, ")", "");
    msg = replace_string(msg, "_", "");
    msg = replace_string(msg, "*", "");
    msg = replace_string(msg, "0", "o");
    msg = replace_string(msg, "1", "i");

    ex=explode(msg, " ");
    i=sizeof(ex);
    if(member_array(cmd, commands)!=-1) {
        while(i--) {
            t=sizeof(WORDS);
            while(t--)
                if(strsrch(lower_case(ex[i]), WORDS[t])!=-1) {
		    CHAT_D->do_raw_chat("system", "Filter <system> Filtered: ["+this_player()->query_name()+"]-"+cmd+": "+msg);
                    return 1;
                }
            if(member_array(lower_case(ex[i]), WORDS)!=-1) {
                return 1;
            }
        }
        tmp = replace_string(msg, " ", "");
            t=sizeof(WORDS);
                while(t--)
                     if(strsrch(lower_case(tmp), WORDS[t])!=-1) {
                          return 1;
                     }
    }
    return 0;
}

string time_stamp() {
    string d,mo;
    mixed h,m,s,y,date;
    sscanf(ctime(time()), "%s %s %d %d:%d:%d %d", d,mo,date,h,m,s,y);
    y=(string)""+y;
    return "["+date+"-"+y[2..]+" "+h+":"+m+":"+s+"]";
}

