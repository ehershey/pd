//      /bin/daemon/fingerd.c
//      Nightmare Mudlib finger daemon
//      based on finger daemon from the TMI mudlib coded by
//      Sulam, Jubal, Brian, and Buddha (12.8.91 - 3.8.92)
//      written by Descartes of Borg 22 November 1992
 
#include <objects.h>
#include <dirs.h>
#include <daemons.h>
#include <config.h>
 
inherit OB_USER;

 
string alig_str(string what, int x);
string query_title();
string query_last_on();
string query_hah(object ob, int verbose);
 
void create() {
    seteuid(getuid());
}
 
static void complete_variables() {
    /*if(!true_name) true_name = "";*/
    if(!real_name) real_name = "???";
    if(!player_class) player_class = "child";
    if(!last_on) last_on = "no record";
   if(!ip) ip = "nowhere";
     if(!level) level = -1;
    if(!race) race = "Unborn";
    if(!player_age) player_age = 0;
}
 
string general_finger_display() {
    string finger;
    object *who;
    int i;
   string level;
  
    finger =
"                  Members of the "+mud_name()+" Reality\n";
    finger +=
"  "+mud_name()+" has been up since PDT "+ctime(time()-uptime())+"\n";
    finger +=
"   "+mud_name()+" runs "+version()+" driver with "+mudlib()+"\n";
    finger += alig_str("Player", 15);
    finger += alig_str("Real Name", 30);
    finger += alig_str("Class", 10);
    finger += alig_str("Level", 7);
    finger +=alig_str("Idle", 5);
    finger += "\n";
     who = users();
    for(i=0; i<sizeof(who); i++) {
	if(who[i]->query_invis()) continue;
	if(!who[i]->query_name()) continue;
	finger += alig_str((string)who[i]->query_cap_name(), 15);
	finger += alig_str((string)who[i]->query_rname(), 30);
	if(!who[i]->query_class()) finger += alig_str("child", 10);
	else finger += alig_str((string)who[i]->query_class(), 10);
	if(wizardp(who[i]))   // provide some distinction by Val June 1, 1993
	  level = "im";
	else
	  level = "" + (int)who[i]->query_level() + "";
	finger += alig_str(level, 7);
	finger += alig_str(query_idle_string(who[i], 0), 5);
	finger += "\n";
    }
    return finger;
}
 
string user_finger_display(string who) {
    mapping mail_stat;
    string tmp;
    string pos;   /* caller's position used to show email for high level 
		     callers.  Added by Valodin, June 8, 1993 */
    object ob;
    string uh_oh;
    string finger;
    string level, tmp9;
    
    if(!who) return "You must specify whom you wish to finger.\n";
    
    ob = find_player(lower_case(who));
    tmp = lower_case(who);
    who = sprintf("%s/%s/%s", DIR_USERS, tmp[0..0], tmp);
    if(file_size(who + ".o") < 0) 
	return "No such member of the Primal Darkness Reality.\n";
    restore_object(who,1);
    mail_stat = (mapping)LOCALPOST_D->mail_status(tmp);
    if(ob) {
	finger = query_title()+"\n";
	uh_oh = capitalize((string)ob->query_gender()) + " ";
	uh_oh += (string)ob->query("race") + " ";
	uh_oh += (string)ob->query_class() + " ";
        if(stringp(tmp9=(string)ob->query_guild()) && tmp9 != "assassin")
          uh_oh += "of the "+pluralize(tmp9);
	finger += alig_str(uh_oh, 45);
	if(wizardp(ob))
	  level = "Immortal";
	else
	  level = "" + (int)ob->query_level() + "";
	finger += "Level: "+level+"\n";
	finger += "In real life: ";
	finger += alig_str((string)ob->query_rname(), 31);
	if(!ob->query_married()) 
	    finger += "Single\n";
	else 
	    finger += "Married to " + capitalize((string)ob->query_married()) +
		      "\n";
	birth = (int)ob->query_birthday();
	finger += "Birthday: "+capitalize(month(birth))+" "+date(birth)+", "+
	   ((year(birth)-18))+" BN\n";
	if(this_player() && archp(this_player()))
		if((uh_oh = (string)ob->query_email()) != "")
		    finger += "Email: " + uh_oh + "\n";     
	if(ob->query_invis()) 
	    finger += "Last on: ";
	else {
	    uh_oh = query_hah(ob, 1);
	    if(uh_oh != "") 
		finger += uh_oh + "\n";
	    finger += "On since: ";
	}
	finger += query_last_on() + " from ";
// privacy for where blockers added by Valodin July 1, 1993
	if(ob->query_property("where block") ) 
	  if(this_player() && archp(this_player()))
	     finger += (string)ob->query_ip() + "\n";
	  else
	     finger += "Anonymous\n";
	else
	  finger += (string)ob->query_ip() + "\n";
	finger += query_cap_name() + " has ";
	if(!mail_stat["unread"]) 
	    finger += "no unread mail.\n";
	else if(mail_stat["unread"] == 1) 
	    finger += "1 unread piece of mail.\n";
	else 
	   finger += mail_stat["unread"] + " unread pieces of mail.\n";
 	tmp = user_path(tmp);
	if(file_size(tmp + ".project") >= 0) 
	    finger += "Project: "+read_file(tmp+".project");
	if(file_size(tmp+".plan") >= 0) 
	   finger += "Plan:\n"+read_file(tmp+".plan");
 	else 
	    finger += "No plan.\n";
    }
    else {
	    complete_variables();
	    finger = query_title()+ "\n";
	    if(query_description())
		finger += capitalize(query_true_name()) + " " + 
			  query_description() + "\n";
	    uh_oh = capitalize(query_gender());
	    uh_oh += " " + query_race() + " ";
	    uh_oh += query_class();
            if(query_guild() && query_guild() != "assassin")
	  uh_oh += " of the "+pluralize(query_guild());
	    finger += alig_str(uh_oh, 45);
            if(member_array(query_position(), MORTAL_POSITIONS)==-1) // Kalinash
		finger += "Level: Immortal\n";   // 1 nov 93 for offline
	    else finger += "Level: "+query_level()+"\n"; // wizzes
	    finger += "In real life: ";
	    finger += alig_str(query_rname(), 31);
	    if(query_married()) 
		finger += "Married to "+capitalize(query_married())+"\n";
	    else 
		finger += "Single\n";
	    finger += "Birthday: "+capitalize(month(birth))+" "+date(birth)+", "+
	      ((year(birth)-18))+" BN\n";
	    if(this_player() && archp(this_player()))
		    if((uh_oh = query_email()) != "")
			finger += "Email: " + uh_oh + "\n";         
	    if(this_player() && archp(this_player()))
	   finger += "Last on: " + query_last_on() + " from "+query_ip()+"\n";
 	    else finger += "Last on: "+query_last_on()+" from "+
	      (query_property("where block") ? "Anonymous" : query_ip())+"\n";
	    finger += query_cap_name() + " has ";
	    if(!mail_stat["unread"]) 
		finger += "no unread mail.\n";
	    else if(mail_stat["unread"] == 1) 
		finger += "1 unread piece of mail.\n";
	    else 
		finger += mail_stat["unread"]+" unread pieces of mail.\n";
	    tmp = user_path(tmp);
	    if(file_size(tmp+".project") >= 0)
		finger += "Project: "+read_file(tmp+".project");
	    if(file_size(tmp+".plan") >= 0) 
		finger += "Plan:\n" + read_file(tmp + ".plan");
	    else 
		finger += "No plan.\n";
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
	    line += tmp;
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

    if(!getenv("TITLE")) return query_cap_name();
    if(sscanf(getenv("TITLE"), "%s $N %s", pre, post) != 2) {
	if(sscanf(getenv("TITLE"), "$N %s", post) != 1) return capitalize(query_true_name());
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
 
string query_cap_name() { return capitalize(query_true_name()); }
