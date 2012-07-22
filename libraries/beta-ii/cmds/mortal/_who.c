//      /bin/mortal/_who.c
//      from the Nightmare Mudlib
//      lists users() in an interesting format and sorting order
//      created by Descartes of Borg 03 july 1993
//      redesigned by Kalinash 12 Jan 94
//      redesigned again by Seeker Feb 2000
//      and again by Nightshade Nov 2001
#include <std.h>
#include <daemons.h>

#define DEFAULT_SORT "p";

inherit DAEMON;

#define SUBCLASSES ({"berserker","paladin","ranger","warrior", \
                     "necromancer","pyromancer","sorceror","wizard", \
                     "cleric","druid","kataan","monk", \
                     "assassin","scout","thief","thug", \
                     "bard","gypsy","jester","swashbuckler" })
#define CLASSES ({ "fighter", "mage", "clergy", "rogue", "wanderer" })
#define GUILDS ({ "forsaken", "unholy", "darksoul", "knightsofvalor", })
#define IS_SUBCLASS(a) (member_array(a, SUBCLASSES) == -1?0:1)
#define IS_CLASS(a) (member_array(a, CLASSES) ==-1?0:1)
#define IS_RACE(a) (member_array(a, RACE_D->query_races()) == -1?0:1)
#define IS_GUILD(a) (member_array(a, GUILDS) == -1?0:1)
#define IS_USER(a) (member_array(a, users()->query_name()) == -1?0:1)

#define GR "%^RESET%^%^CYAN%^"
#define BO "%^RESET%^%^CYAN%^%^BOLD%^"
string list_users(string *races, string order);

int cmd_who(string str) {
    string *args, *races;
    string order;
    int i, x;

    races = ({});
    order = DEFAULT_SORT;
    if(str) {
	i = sizeof(args = explode(str, " "));
	while(i--) {
            x=sizeof(args[i])-1;
/*
            if(!IS_USER(args[i]) && args[i][0..0] != "-" && args[i][x..x] == "s") 
              args[i][x..x] = "";
*/

            if (replace_string(args[i],"s","") == "dragonwarrior") args[i] = "dw";
	    if(args[i][0..0] == "-" && strlen(args[i]) > 1) order = args[i][1..1]; else
            if(IS_SUBCLASS(lower_case(args[i]))) { order = "subclass"; races += ({args[i]}); } else
            if(IS_CLASS(lower_case(args[i]))) { order = "class"; races += ({ args[i] }); } else
            if(IS_RACE(lower_case(args[i]))) { order = "race"; races += ({ args[i] }); } else
            if(IS_GUILD(lower_case(args[i]))) { order = "original_guild"; races += ({ args[i] }); } else
            if(IS_USER(lower_case(args[i]))) { order = "name"; races += ({args[i]}); }  else {
            order=""; races += ({"sd"});}
	}
    }
    this_player()->more(explode(list_users(races, order), "\n"));
    return 1;
}

string list_users(string *races, string order) {
    object *who, *ims, *pls, *adm, shadow;
    string tmp, borg;
    int i, max, x;
    ims = ({});
    pls = ({});
    who = filter_array(users(), "which_users", this_object(), races, order);
    for(x=0;x<sizeof(who);x++) {
	if (who[x]->query_name() == "ashadow") shadow = who[x]; else
	if (archp(who[x])) {
	    if (!adm) adm = ({ who[x] }); 
	    else adm += ({ who[x] });
	}
	else if(wizardp(who[x]))
	    if (!ims) ims = ({ who[x] }); else ims += ({ who[x] });
	else 
	if(!pls) pls = ({who[x]}); else pls += ({ who[x] });
    }
    switch(order) {
    case "a":
	pls = sort_array(pls, "sort_by_name", this_object());
	break;
    case "b":
	pls = sort_array(pls, "sort_by_birth", this_object());
	break;
    case "d":
	pls = sort_array(pls, "sort_by_deaths", this_object());
	break;
    case "k":
	pls = sort_array(pls, "sort_by_kills", this_object());
	break;
    case "p":
	pls = sort_array(pls, "sort_by_playing_time", this_object());
	break;
    case "q":
	pls = sort_array(pls, "sort_by_quests", this_object());
	break;
    case "t":
	pls = sort_array(pls, "sort_by_login_time", this_object());
	break;
    default:
	pls = sort_array(pls, "sort_by_name", this_object());
	break;
    }
    borg =  "%^BLUE%^";
    borg += "+=+=+=+=+=+=+=+=+=+=+=+=+=+=+";
    borg += "%^BOLD%^(%^WHITE%^ ";
    borg += "Primal Darkness";
    borg += " %^BLUE%^)%^RESET%^%^BLUE%^";
    borg += "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n";
    if(shadow && shadow->is_player() && interactive(shadow) && !shadow->query_invis()) {
      tmp = "[Shadow] "+shadow->query_title();
      borg += "%^RED%^%^BOLD%^"+tmp+"%^RESET%^\n";
    }
    max = sizeof(adm);
    if(max)
	for(i=0; i<max; i++) {
	    tmp = "%^RESET%^%^BLUE%^[%^BOLD%^Admin%^RESET%^%^BLUE%^ ]%^BOLD%^ ";

	    if((string)adm[i]->query_title())
		tmp+= (string)adm[i]->query_title();
	    else
		tmp += "("+capitalize((string)adm[i]->query_name())+")";
	    tmp = arrange_string(tmp, 55);
	    borg += "%^BLUE%^%^BOLD%^"+tmp;
	    tmp = capitalize((string)adm[i]->query_position());
	    tmp = arrange_string(tmp, 13);
	    tmp += "\n";
	    borg += "%^RESET%^%^BOLD%^"+tmp;
	}
    max = sizeof(ims);
    if(max)
	for(i=0; i<max; i++) {
	    tmp = "[%^BOLD%^Immrtl%^RESET%^%^MAGENTA%^] ";
	    if((string)ims[i]->query_title()) 
		tmp+= (string)ims[i]->query_title();
	    else
		tmp += "("+capitalize((string)ims[i]->query_name())+")";

	    tmp = arrange_string(tmp, 55);
	    borg += "%^RESET%^%^MAGENTA%^"+tmp;
	    tmp = capitalize((string)ims[i]->query_position());
	    tmp = arrange_string(tmp, 13);
	    tmp += "\n";
	    borg += "%^RESET%^%^WHITE%^"+tmp;
	}
    max = sizeof(pls);
    if(max)
	for(i=0; i<max; i++) {
	    tmp = GR+"["+BO+"Player"+GR+"]%^RESET%^%^CYAN%^";
	    tmp = arrange_string(tmp, 9);
	    borg += tmp;
	    if((string)pls[i]->query_title()) {
		tmp = (string)pls[i]->query_title();
		tmp = arrange_string(tmp, 45);
	    }
	    else {
		tmp = "("+(string)pls[i]->query_cap_name()+")";
		tmp = arrange_string(tmp, 45);
	    }
	    borg += tmp;
	    tmp=" %^RESET%^%^BOLD%^";
	    if ((pls[i]->query_race() == "") || (!pls[i]->query_race()))
		tmp += "Unborn";
	    else if (pls[i]->query_race() == "dragon")
		tmp += capitalize((string)pls[i]->query_subclass());
	    else
		tmp += capitalize((string)pls[i]->query_race());
	    tmp = arrange_string(tmp+" %^CYAN%^", 12);
	    if ((pls[i]->query_class() == "") || (!pls[i]->query_class()))
		tmp += "Child";
	    else if (pls[i]->query_race() == "dragon")
		tmp += capitalize((string)pls[i]->query_race());
	    else
		tmp += capitalize((string)pls[i]->query_class());
	    tmp = arrange_string(tmp, 25);
	    borg += tmp+"%^RESET%^\n";
  //if (this_player() && this_player()->query_name() == "nulvect") write("width="+strlen(strip_color(borg))+"\n");
	}
    if (find_living("sigma") && environment(find_living("sigma")))
	borg += GR+"["+BO+"Mascot"+GR+"]%^RESET%^%^MAGENTA%^   Mascot Sigma the friendly bird                Dodo Bird\n";
    if (find_living("sigmatt") && environment(find_living("sigmatt")))
	borg += GR+"["+BO+"Mascot"+GR+"]%^RESET%^%^MAGENTA%^   Mascot Sigma the trick or treater            Dodo Bird\n";
    borg += "%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n";
   return copy(borg);
}

int which_users(object who, string *races, string f) {
    string my_race, func;
    int i;
    func = "query_"+f;
    if(!who->query_name()) return 0;
    if(who->query_invis() && !archp(this_player())) return 0;
    if(!i=sizeof(races)) return 1;
    my_race = (string)call_other(who, func);
    while(i--) if(races[i]== my_race) return 1;
    return 0;
}

int sort_by_birth(object alpha, object beta) {
    int a, b;

    a = (int)alpha->query_birthday();
    b = (int)beta->query_birthday();
    if(a == b) return strcmp((string)alpha->query_name(),
	  (string)beta->query_name());
    else if(a > b) return 1;
    else return -1;
}

int sort_by_name(object alpha, object beta) {
    return strcmp((string)alpha->query_name(), (string)beta->query_name());
}

int sort_by_playing_time(object alpha, object beta) {
    int a, b;

    a = (int)alpha->query_age();
    b = (int)beta->query_age();
    if(a==b) return strcmp((string)alpha->query_name(),
	  (string)beta->query_name());
    else if(a > b) return -1;
    else return 1;
}

int sort_by_login_time(object alpha, object beta) {
    int a, b;

    a = (int)alpha->query_login_time();
    b = (int)beta->query_login_time();
    if(a==b) return strcmp((string)alpha->query_name(),
	  (string)beta->query_name());
    else if(a>b) return 1;
    else return -1;
}
int sort_by_kills(object alpha, object beta) {
    int a, b;

    if((a=sizeof((string *)alpha->query_kills())) > (b=sizeof((string*)beta->query_kills())))
	return -1;
    else if(a < b) return 1;
    else return strcmp((string)alpha->query_name(), (string)beta->query_name());

}

int sort_by_deaths(object alpha, object beta) {
    int a, b;

    a = sizeof((mixed *)alpha->query_deaths());
    b = sizeof((mixed *)beta->query_deaths());
    if(a>b) return -1;
    else if(a<b) return 1;
    else return strcmp((string)alpha->query_name(), (string)beta->query_name());

}

int sort_by_quests(object alpha, object beta) {
    int a, b;

    if((a=(int)alpha->query_quest_points()) >
      (b=(int)beta->query_quest_points()))
	return -1;
    else if(a < b) return 1;
    else return strcmp((string)alpha->query_name(), (string)beta->query_name());

}

void help() {
    write(
      "Syntax: <who [-][abdkpqt] [race1 race2 ... raceN]>\n\n"+
      "Lists all players online or all players of the race(s) given.\n"+
      "If no arguments are given, it simply lists all players sorted by\n"
      "name.\n\n"
      "Options: \na - Alphabetically\nb - Age\nd - Number of Deaths\n"
      "k - Number of Kills\np - Amount of Playing Time\nq - Number of"
      " Quests\nt - Amount of login time\n");
}

private string convert_to_table(mapping w, string color);

int update_online_who() {
    object *u, *a, *w, *p;
    int i;
    mapping t=([]);
    string out="", out2="";
    //  Seperate wizs, admins, and players.
    a=({}); w=({}); p=({});
    i=sizeof(u=users());
    while(i--) {
	if(u[i]->query_invis()) continue;
	if(archp(u[i])) { a += ({ u[i] }); continue; } else
	if(wizardp(u[i])) { w += ({ u[i] }); continue; } else
	if(u[i]->is_player())
	    p += ({ u[i] });
    }
	out2 += @END
<?php require_once("lib/pd.php"); ?>
				<br><br>
END;
	out2 += "There are currently "+ (sizeof(a) + sizeof(w) + sizeof(p) ) + " players online.";
	out2 += @END
				<br><br>
				<center>
				<table>
					<tr>
						<td width=75></td>
						<td width=100>Name</td>
						<td width=100>Race</td>
						<td width=100>Subclass</td>
						<td width=125>Guild</td>
						<td>Email &nbsp;</td>
						<td>Pic &nbsp;</td>
						<td>Char &nbsp;</td>
					</tr>
					<tr>
						<td colspan=10 align="center"><hr size=1 width="100%"></center></td>
					</tr>
END;
    a=sort_array(a, "sort_by_name");
    w=sort_array(w, "sort_by_name");
    p=sort_array(p, "sort_by_name");
    i=sizeof(a);
    while(i--) {
	t=([]);
	t["name"]=a[i]->query_name();
	t["class"]=a[i]->query_subclass();
	t["race"]=a[i]->query_race();
	t["guild"]=a[i]->query_guild();
	t["position"]=a[i]->query_position();
	t["email"]=a[i]->query_email();
        t["homepage"]=a[i]->getenv("HOMEPAGE");
	out += convert_to_table(t, "admin");
    }
    i=sizeof(w);
    while(i--) {
	t=([]);
	t["name"]=w[i]->query_name();
	t["class"]=w[i]->query_subclass();
	t["race"]=w[i]->query_race();
	t["guild"]=w[i]->query_guild();
	t["position"]=w[i]->query_position();
	t["email"]=w[i]->query_email();
        t["homepage"]=w[i]->getenv("HOMEPAGE");
	out += convert_to_table(t, "wizard");
    }
    i=sizeof(p);
    while(i--) {
	t=([]);
	t["name"]=p[i]->query_name();
	t["class"]=p[i]->query_subclass();
	t["race"]=p[i]->query_race();
	t["guild"]=p[i]->query_guild();
	t["position"]=p[i]->query_position();
	t["email"]=p[i]->query_email();
        t["homepage"]=p[i]->getenv("HOMEPAGE");
	out += convert_to_table(t, "player");
    }
    seteuid("WhoCmd");
    out = out2 + out + "</table></center><p><br><center><font size=1>&copy;Primal Darkness<br>Last updated "+ctime(time())+"</font></center>";
    write_file("/web/who.php", out, 1);
    seteuid(getuid());
    remove_call_out("update_online_who");
    call_out("update_online_who", 60);
    return 1;
}

private string convert_to_table(mapping w, string color) {
    mapping c, p;
    string out="", tmp;
    c=(["admin":"blue", "wizard":"magenta", "player":"cyan"]);
    p=(["admin":"Admin ", "wizard":"Immrtl", "player":"Player"]);

    out += "					<tr>\n";
	out += "						<td><font color="+c[color]+"> ["+p[color]+"]</font></td>\n";
	out += "						<td>"+capitalize(w["name"])+"</td>\n";

    if(!w["race"]) w["race"]="Unborn";
	    out += "						<td>"+capitalize(w["race"])+"</td>\n";
    if(!w["class"]) w["class"]="Classless";
	    out += "						<td>"+capitalize(w["class"])+"</td>\n";
    if(!w["guild"]) w["guild"]=" ";
	    out += "						<td>"+capitalize(w["guild"])+"</td>\n";
    if(w["email"] && w["email"][0..0] == "*" && sscanf(w["email"], "*%s@%s.%s", tmp, tmp, tmp)==3) {
		out += "						<td><a href='mailto:"+w["email"][1..]+"'>Yes</a>";
    } else out += "						<td></td>";

    out += "						<td>\n";
	out += "<?php";
	out += "	if(get_player_image(\""+w["name"]+"\")) echo(\"<a href='/players/pictures/"+lower_case(w["name"])+"/'>Pic</a>\");\n";
	out += "?>\n";
    out += "						</td>\n";
	out += "						<td>\n";
	out += "<?php\n";
	out += "	if(file_exists(\"/home/primal/public_html/players/illustrations/"+lower_case(w["name"])+".htm\")) echo(\"<a href='../players/illustrations/"+lower_case(w["name"])+".htm'>Char</a>\");\n";
	out += "?>\n";
	out += "						</td>\n";
//    if(w["homepage"] && (sscanf(w["homepage"], "http://%s", tmp) ==1 || sscanf(w["homepage"], "www.%s", tmp) == 1))
//    out += "						<td><a href=\""+w["homepage"]+"\" target=\"_New\">Yes</a></td>"; 
    out += "					</tr>";
    return out;
}

void create() {
   call_out("update_online_who", 1);
}
