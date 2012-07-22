//      /bin/daemon/fingerd.c
//      Nightmare Mudlib finger daemon
//      based on finger daemon from the TMI mudlib coded by
//      Sulam, Jubal, Brian, and Buddha (12.8.91 - 3.8.92)
//      written by Descartes of Borg 22 November 1992
//      Descarte's crappy coding redone bye Nightshade
#include <guild.h>
#include <objects.h>
#include <dirs.h>
#include <daemons.h>
#include <config.h>
inherit OB_USER;
string alig_str(string what, int x);
string query_last_on();
string query_hah(object ob, int verbose);
string query_title();
string oth_fing();
void create() {
    ::create();
}
string general_finger_display() {
    string finger, hidden;
    object *who;
    int i;
    string level;
    finger =
    "               %^RESET%^%^BLUE%^-=%^CYAN%^Members of the "+mud_name()+" Reality%^BLUE%^=-%^RESET%^\n";
    finger +=
    "     %^RESET%^"+mud_name()+" has been up since PDT "+ctime(time()-uptime())+"\n";
    finger +=
    "      "+mud_name()+" runs "+version()+" driver with "+mudlib()+"\n%^RESET%^";
    finger += "%^RESET%^%^BLUE%^-----------------------------------------------------------------------------\n";
    finger += arrange_string("%^RESET%^%^BLUE%^|   %^CYAN%^  Player", 16);
    finger += arrange_string("%^BLUE%^|    %^CYAN%^   Real Name", 24);
    finger += arrange_string("%^BLUE%^|%^CYAN%^   Class", 12);
    finger += arrange_string("%^BLUE%^|%^CYAN%^   Position", 15);
    finger += "%^BLUE%^|%^CYAN%^  Idle%^BLUE%^  |%^RESET%^\n";
    finger += "%^RESET%^%^BLUE%^|---------------|-----------------------|-----------|--------------|--------|\n";
    who = users();
    for(i=0; i<sizeof(who); i++) {
        if(who[i]->query_invis()) continue;
        if(!who[i]->query_name()) continue;
        finger += arrange_string("%^RESET%^%^BLUE%^|%^RESET%^"+(string)who[i]->query_cap_name(), 16);
        hidden = (string)who[i]->query_rname();
        if(hidden[0] == '*')
            finger += arrange_string("%^RESET%^%^BLUE%^|%^RESET%^"+capitalize(hidden[1..strlen(hidden)]), 24);
        else
            finger += arrange_string("%^RESET%^%^BLUE%^|%^RESET%^-Private-", 24);
        if(!who[i]->query_class()) finger += arrange_string("%^RESET%^%^BLUE%^|%^RESET%^Child", 12);
        else finger += arrange_string("%^RESET%^%^BLUE%^|%^RESET%^"+capitalize((string)who[i]->query_class()), 12);
        level = who[i]->query_position();
        if(level == "high mortal")
            level = "player";
        finger += arrange_string("%^RESET%^%^BLUE%^|%^RESET%^"+level, 15);
        finger += arrange_string("%^RESET%^%^BLUE%^|%^RESET%^"+query_idle_string(who[i], 0), 9);
        finger += "%^RESET%^%^BLUE%^|%^RESET%^\n";
    }
    finger += "%^RESET%^%^BLUE%^-----------------------------------------------------------------------------\n";
    return finger;
}
string user_finger_display(string who) {
    mapping mail_stat;
    string tmp,a;
    string pos;
    string uh_oh;
    string finger;
    string tmp9;
    string ip;
    int age, birth;
    if(!who) return "You must specify whom you wish to finger.\n";
    tmp = lower_case(who);
    who = sprintf("%s/%s/%s", DIR_USERS, tmp[0..0], tmp);
    if(file_size(who + ".o") < 0) 
        return "No such person in this reality.\n";
    restore_object(who);
    mail_stat = (mapping)LOCALPOST_D->mail_status(tmp);
    finger = "\n%^RESET%^%^CYAN%^[%^WHITE%^*%^CYAN%^]%^BLUE%^------%^BOLD%^(%^WHITE%^Finger%^BLUE%^)%^RESET%^%^BLUE%^--------------------------------------------------%^CYAN%^[%^WHITE%^*%^CYAN%^]%^RESET%^\n";
    finger += "    %^RESET%^";
    finger += query_title();
    finger += "\n";
    finger += "%^RESET%^%^CYAN%^[%^WHITE%^*%^CYAN%^]%^BLUE%^----------------------------------------------------------------%^CYAN%^[%^WHITE%^*%^CYAN%^]%^RESET%^\n";
    finger += "    %^RESET%^%^CYAN%^Name: %^RESET%^";
    finger += alig_str((query_true_name() == "ashadow"?"A shadow":capitalize(query_true_name())),24);
    finger += "%^RESET%^%^MAGENTA%^Position: %^RESET%^(";
    if(query_position() == "high mortal")
        finger += "player)";
    else
        finger += query_position()+")";
   if(this_player())
    if(wizardp(this_player()))
        finger += " lev: "+query_level();
    finger += "\n    %^CYAN%^Race: %^RESET%^";
    uh_oh = capitalize(query_gender()) + " ";
    if (query_race()=="dragon") {
        uh_oh += capitalize(query_subclass())+ " ";
        uh_oh += capitalize(query_class()) + " ";
        pos = "Dragonkin";
    }
    else {
        if(!query_race() || (query_race() == ""))
            uh_oh += "Unborn ";
        else
            uh_oh += capitalize(query_race()) + " ";
        if(!query_class() || (query_class() == ""))
            pos = "Adventurer ";
        else
            pos = capitalize(query_class()) + " ";
        if(!query_subclass() || (query_subclass() == ""))
            pos += "(%^BOLD%^None%^RESET%^) ";
        else
            pos += " (%^BOLD%^"+capitalize(query_subclass())+"%^RESET%^) ";
    }
    finger += arrange_string(uh_oh, 25);
    age = time() - query_birthday();
    finger += "%^RESET%^%^MAGENTA%^Age:%^RESET%^ "+(18 + (age/4320000));
    if(query_race()!="vampire") {
      finger += "\n    %^CYAN%^Class: %^RESET%^"+arrange_string(pos,24)+"%^RESET%^%^MAGENTA%^Married: %^RESET%^";
      if (!query_married())
          finger += "Single\n";
      else
          finger += capitalize(query_married())+"\n";
      finger += "%^RESET%^%^CYAN%^    Guild:%^RESET%^ ";
     if(member_array(query_name(), MASTER) != -1) finger += arrange_string("Primal Council", 24); else
      if(stringp(tmp9=query_guild()) && tmp9 != "assassin")
          finger += arrange_string(capitalize(tmp9), 24);
      else
          finger += arrange_string("None", 24);
//      finger += "%^RESET%^%^MAGENTA%^Kingdom: %^RESET%^"+(query_kingdom()?query_kingdom():"Adventurer");
    } else {
      finger += "\n%^RESET%^%^CYAN%^    Guild:%^RESET%^ ";
     if(member_array(query_name(), MASTER) != -1) finger += arrange_string("Primal Council", 24); else
      if(stringp(tmp9=query_guild()) && tmp9 != "assassin")
          finger += arrange_string(capitalize(tmp9), 24);
      else
          finger += arrange_string("None", 24);
      finger += "%^RESET%^%^MAGENTA%^Married: %^RESET%^";
      if (!query_married())
          finger += "Single";
      else
          finger += capitalize(query_married())+"";
    }
    birth = query_birthday();
    finger += "\n    %^RESET%^%^CYAN%^Birthday:%^RESET%^ "+capitalize(month(birth))+" "+date(birth)+", "+
    ((year(birth) - 18 < 0?(1000-(18-year(birth))):(1000+(year(birth)-18))))+" BN\n";
    if(query_invis() || !find_player(tmp))
        finger += "%^CYAN%^    Last on:%^RESET%^ "+query_last_on();
    else if(find_player(tmp) && !interactive(find_player(tmp))) 
        finger += "%^CYAN%^    On since:%^RESET%^ Link-Dead";
    else {
        uh_oh = query_hah(find_player(tmp), 1);
        if(uh_oh != "") 
           finger += "    %^BOLD%^"+uh_oh + "%^RESET%^\n";
        finger += "%^CYAN%^    On since:%^RESET%^ "+query_last_on();
    } if(find_player(tmp) && interactive(find_player(tmp)))
    finger += "\n"; else finger += "\n";
    finger += "%^RESET%^%^CYAN%^[%^WHITE%^*%^CYAN%^]%^BLUE%^----------------------------------------------------------------%^CYAN%^[%^WHITE%^*%^CYAN%^]%^RESET%^\n";
    uh_oh = query_rname();
    if((this_player() && archp(this_player())) || (uh_oh[0] == '*')) {
        if(uh_oh[0] == '*')
            uh_oh = uh_oh[1..strlen(uh_oh)];
        finger += "%^RESET%^%^CYAN%^    I R L:%^RESET%^ "+uh_oh+"\n";
    }
    if (sscanf(query_email(), "*%s", a) != 1) {
        if(this_player() && archp(this_player()))
            if((uh_oh = query_email()) != "")
                finger += "%^CYAN%^    Email:%^RESET%^ " + uh_oh + "\n";     
    } else finger += "%^CYAN%^    Email:%^RESET%^ "+a+"\n";

    if (getenv("HOMEPAGE") && sscanf(getenv("HOMEPAGE"), "*%s", a) == 1) 
      finger += "%^CYAN%^    Homepage:%^RESET%^ "+a+"\n";

    age = 0;
    uh_oh = "";
    if(query_env("MSN") && query_env("MSN") != "") {
        uh_oh += arrange_string("    %^RESET%^%^CYAN%^MSN: %^RESET%^"+query_env("MSN"), 35);
        age++;
    }
    if(query_env("AIM") && query_env("AIM") != "") {
        if(age == 0) uh_oh += "    ";
        uh_oh += arrange_string("%^RESET%^%^CYAN%^AIM: %^RESET%^"+query_env("AIM"), 31);
        age++;
    }
    if(query_env("ICQ") && query_env("ICQ") != "") {
        if(age == 2) uh_oh += "\n    ";
        if(age == 0) uh_oh += "    ";
        uh_oh += arrange_string("%^RESET%^%^CYAN%^ICQ: %^RESET%^"+query_env("ICQ"), 31);
        age++;
    }
    if(query_env("YAHOO") && query_env("YAHOO") != "") {
        if(age == 2) uh_oh += "\n    ";
        if(age == 0) uh_oh += "    ";
        uh_oh += arrange_string("%^RESET%^%^CYAN%^Yahoo: %^RESET%^"+query_env("YAHOO"), 31);
    }

    if(uh_oh != "")
      finger += uh_oh+"\n";

    finger += "%^BOLD%^    " + capitalize(query_true_name()) + " has ";
    if(!mail_stat["unread"]) 
        finger += "no unread mail.%^RESET%^\n";
    else if(mail_stat["unread"] == 1) 
        finger += "1 unread piece of mail.%^RESET%^\n";
    else 
        finger += mail_stat["unread"] + " unread pieces of mail.%^RESET%^\n";
    if(query_env("LFINGER") && query_env("LFINGER") != "") {
        finger += "%^RESET%^%^CYAN%^[%^WHITE%^*%^CYAN%^]%^BLUE%^----------------------------------------------------------------%^CYAN%^[%^WHITE%^*%^CYAN%^]%^RESET%^\n";
        finger += query_env("LFINGER") + "\n";
    }
    tmp = user_path(tmp);
    if((file_size(tmp + ".project") >= 0) || (file_size(tmp+".plan") >= 0)) 
    finger += "%^RESET%^%^CYAN%^[%^WHITE%^*%^CYAN%^]%^BLUE%^----------------------------------------------------------------%^CYAN%^[%^WHITE%^*%^CYAN%^]%^RESET%^\n";
    if(file_size(tmp + ".project") >= 0) 
        finger += "%^BOLD%^%^BLUE%^    Project:%^RESET%^ "+read_file(tmp+".project");
    if(file_size(tmp+".plan") >= 0) 
        finger += "%^BOLD%^%^BLUE%^    Plan:%^RESET%^\n"+read_file(tmp+".plan");
    finger += "%^RESET%^%^CYAN%^[%^WHITE%^*%^CYAN%^]%^BLUE%^----------------------------------------------------------------%^CYAN%^[%^WHITE%^*%^CYAN%^]%^RESET%^\n";
    if(wizardp(this_player())) {
      if(find_player(query_name()) && interactive(find_player(query_name())))
        ip=query_ip_number(find_player(query_name())); else
        ip=MULTI_D->get_user_ip(query_name())+".*";
      finger += "    ADMIN INFO\n";
      finger += "      IP: "+
        arrange_string((find_player(query_name()) && interactive(find_player(query_name()))?query_ip_number(find_player(query_name())):"Offline ("+ip+")"), 25);
      finger += "LAN: "+(LAN_D->valid_lan(ip)?"%^BOLD%^%^GREEN%^Yes%^RESET%^":"%^BOLD%^%^RED%^No%^RESET%^")+"\n";
      finger += "      IP Range: "+arrange_string(MULTI_D->get_user_ip(query_name())+".*", 19);
      finger += "Verified: "+(AUTH_D->verified(query_name())?"Yes":"No")+"\n";
      finger += "      Banished: "+(BANISH_D->query_banished_ip(ip)?"Yes":"NO ")+"                ";
      if(ip)
      ip=implode(explode(ip, ".")[0..2], ".");
      if( ip != MULTI_D->get_user_ip(query_name())) {
        finger += "Creation-Now IP Match: %^BOLD%^%^RED%^No%^RESET%^\n";
        if(BANISH_D->query_banished_ip(ip))
          finger += center("WARNING! Check for second-party character")+"\n"+center("creation for banned character.")+"\n"+
            center("Use <compare> to compare current ip to existing users.");
      } else
      finger += "Creation-Now IP Match: %^BOLD%^%^GREEN%^Yes%^RESET%^\n";
      finger += "\n%^RESET%^%^CYAN%^[%^WHITE%^*%^CYAN%^]%^BLUE%^----------------------------------------------------------------%^CYAN%^[%^WHITE%^*%^CYAN%^]%^RESET%^\n";
    }
    return finger;
}
string query_hah(object ob, int verbose) {
    int time, tmp;
    string line;
    if(!ob) return 0;
    if(!interactive(ob)) {
        if(verbose) return "Disconnected.";
        else return "disconnected";
    }
   if(ob->query_noidle()) return "";
    line = "";
    time = query_idle(ob);
    if(time < 60) return line;
    tmp = time / 86400;
    if(tmp) {   
        if(!verbose) return tmp + " d";
        else line += tmp + " day" + (tmp>1 ? "s " : " ");
    }
    tmp = (time%86400)/3600;
    if(tmp) {   
        if(!verbose) {
            if(tmp>9) return tmp+" h";
            else line += tmp+":";
        }
        else line += tmp + " hour"+(tmp>1 ? "s " : " ");
    }
    tmp = (time%3600)/60;
    if(tmp) {   
        if(!verbose) {  
            if(strlen(line)>0 && tmp < 10) line += "0";
            line += (string)tmp;
        }
        else line += tmp+ " minute"+(tmp>1 ? "s " : " ");
    }
    if(verbose) line += "idle time";
    else line += "idle";
    return line;
}
string query_last_on() { return last_on; }
string query_title() {
    string pre, post;
    if(!getenv("TITLE")) return capitalize(query_true_name());
    if(sscanf(getenv("TITLE"), "%s $N %s", pre, post) != 2) {
        if(sscanf(getenv("TITLE"), "$N %s", post) != 1) return
capitalize(query_true_name());
        else return capitalize(query_true_name())+" "+post;
    }
    return pre+" "+capitalize(query_true_name())+" "+post;
}

string alig_str(string what, int x) {
    int y;
    string out;
    out = "";
    if(!what) return 0;
    y = strlen(what);
    out += what;
    if(y>x) {
        out = what[0..x-1] + " ";
        return out;
    }
    x = x-y;
    if(x<1) return out;
    for(y=0; y<=x; y++) out += " ";
    return out;
}
