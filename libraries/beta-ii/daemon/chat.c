#define TO "builders"
#define FROM "Primal Darkness-II"
#define NNETWORK_D "/wizards/whit/network"

#include <fnetwork.h>
#include <guild.h>
#include <udp.h>
#include <daemons.h>
#include <objects.h>
#define MAGENTA "%^MAGENTA%^"
#define B_CYAN    "%^BOLD%^%^CYAN%^"
#define B_RED     "%^BOLD%^%^RED%^"
#define RESET "%^RESET%^"

#define CHANNELS_BASIC ({\
  "newbie", "gossip", "OOC",\
  "auction", "trivia", "colosseum",\
})
#define CHANNELS_CLASS ({ \
  "fighter", "rogue", "mage",\
  "clergy", "wanderer", "dragon",\
})
#define CHANNELS_SUBCLASS ({ \
  "warrior", "ranger", "berserker", "paladin", "antipaladin",\
  "assassin", "thief", "thug", "scout",\
  "necromancer", "pyromancer", "sorceror", "wizard",\
  "cleric", "kataan", "druid", "monk",\
  "bard", "gypsy", "jester", "swashbuckler",\
  "red", "blue", "white", "black",\
})
#define CHANNELS_RACE ({ \
  "angel", "demon", "lich", "vampire",\
})
#define CHANNELS_LEVEL ({ \
  "hm", "elite", "legend", \
})
#define CHANNELS_STAFF ({\
  "cre", "intercre", "pd", "staff",\
  "system", "driver", "network",\
})
#define CHANNELS_MISC ({ \
  "council", "guild", \
})
#define CHANNELS_WIZ \
  CHANNELS_BASIC + CHANNELS_STAFF + \
  CHANNELS_CLASS + CHANNELS_SUBCLASS + \
  CHANNELS_LEVEL + CHANNELS_RACE + \
  CHANNELS_MISC + VALID_GUILDS


#define HMA_LINE ({ \
  "wiz", "kumi", "faust", "wildflower", \
  "staver", "yakko", "kalohe", "noa", \
  "hepulahaole", "akamai", "baitzi", "sulphur", \
  "taz", "seeker", "stormbringer", "nightshade", \
  "blind", "whit", \
})

#define NO_SUBCLASS_CHANNELS


static private mapping channels;

int list_channel(string str);
void do_auction_line(string arg);
void do_colosseum_line(string arg);
void do_buddylist_line(string who, string arg);
void do_enemylist_line(string who, string arg);
void do_info_line(string arg);
int do_raw_chat(string line, string arg);
int do_chat(string verb, string str);
object *query_listeners(string chan);
int query_listening(object who, string chan);
string *query_channels(object who);
varargs void add_user(string *chans, object ob);
varargs void remove_user(string *chans, object ob);
void register_channels(object who);
void do_line(string line, string arg);
string *intermudchannels();
void inter_channels(string who, string verb, string str, int emote);
string time_stamp();

void create() {
    seteuid(getuid());
    channels = ([]);
    foreach (object who in users())
      register_channels(who);
}

object *query_listeners(string chan) {
  return copy(channels[chan]);
}
int query_listening(object who, string chan) {
  return member_array(who, query_listeners(chan)) != -1;
}
string *query_channels(object who) {
  string *chans = ({});
  foreach (string ch, object *listening in channels)
    if (member_array(who, listening) != -1)
      chans += ({ ch });
  return chans;
}

varargs void add_user(string *chans, object ob) {
  if (!ob) {
    ob = previous_object();
    if (base_name(ob) != OB_USER) return;
  }

  foreach (string ch in chans) {
    if (undefinedp(channels[ch]) || !sizeof(channels[ch]))
      channels[ch] = ({ });
    if (member_array(ob, channels[ch]) == -1)
      channels[ch] += ({ ob });
  }

}
varargs void remove_user(string *chans, object ob) {
  if (!ob) {
    ob = previous_object();
    if (base_name(ob) != OB_USER) return;
  }
  
  foreach (string ch in chans) {
    if (member_array(ch, keys(channels)) != -1)
      channels[ch] -= ({ ob });
    if (undefinedp(channels[ch]) || !sizeof(channels[ch]))
      map_delete(channels, ch);
  }

}
void register_channels(object who) {
    string name;
    mixed ip;
    string *chans;
    int mat;
    
    if (!who) return;

    name = who->query_name();
    ip = who->query_ip();
    mat = (int)who->query_property("mature channel");

    if (wizardp(who)) {
      chans = CHANNELS_WIZ;
      if (archp(who)) chans += ({ "admin" });
      if (member_group(name, "rootuser")) chans += ({ "root" });
    }
    else {
      int lvl = who->query_level();
      string guild = GUILD_D->query_guild(who->query_name());
      string pos = who->query_guild_position();
      string cl = who->query_class();
      string subcl = who->query_subclass();
      string race = who->query_race();

      chans = CHANNELS_BASIC;
      if (cl) chans += ({ cl });
      if (subcl) chans += ({ subcl });

      if (lvl > 19) chans += ({ "hm" });
      if (lvl > 49) chans += ({ "elite" });
      if (lvl > 99) chans += ({ "legend" });

      switch (race) {
        case "archangel" : chans += ({ "angel" }); break;
        default:
          if (member_array(race, CHANNELS_RACE) != -1) chans += ({ race });
      }

      switch (guild) {
        case "none": case 0: case "": break;
        case "lastsaints": chans += ({ guild, "illuminati" }); break;
        case "illuminati": chans += ({ guild, "lastsaints" }); break;
        default: chans += ({ lower_case(guild) });
      }

      if (pos == "leader" || pos == "main") chans += ({ "guild" });
      if (leaderp(who)) chans += ({ "council" });

    }

    if (mat) chans += ({ "mature" });

    if (ip)
      if (member_array(name, HMA_LINE) != -1 ||
          strsrch(ip, ".hnllhi1.dsl-verizon.net") != -1 ||
          strsrch(ip, ".hawaii.rr.com") != -1)
            chans += ({ "hma" });

//    if (who->query_kingdom()) chans += ({ KINGDOM_D->query_line(query_kingdom()) });

#ifdef NO_SUBCLASS_CHANNELS
    chans -= CHANNELS_SUBCLASS;
#endif

    add_user(chans, who);

}

void do_line(string line, string arg) {
  object *ppl;
  
  if (!line) return;
  
  if (!sizeof(ppl = query_listeners(line))) return;

  if (strsrch(arg, "<"+line+">") == -1)
    arg = "<"+line+"> " + arg;
  
  message(line+" line", arg, ppl);

  LAST_D->add_last(line, arg);
}

void do_auction_line(string arg) { do_line("auction", arg); }
void do_colosseum_line(string arg) { do_line("colosseum", arg); }
void do_info_line(string arg) { do_line("mudinfo", arg); }

/*
void do_buddylist_line(string who, string arg) { do_line("buddylist", arg); }
void do_enemylist_line(string who, string arg) { do_line("enemylist", arg); }
*/

void do_buddylist_line(string who, string arg) {
    string msg;
    object *ob;
    ob = filter(users(), (: $1->query_buddy($(who)) :) );
    if (!sizeof(ob)) return;
    msg = "<buddylist> "+arg;
    message("buddylist line", msg, ob);
    foreach (object p in ob)
      LAST_D->add_buddylist(p->query_name(), msg);
}
void do_enemylist_line(string who, string arg) {
    string msg;
    object *ob;
    ob = filter(users(), (: $1->query_enemy($(who)) :) );
    if (!sizeof(ob)) return;
    msg = "<enemylist> "+arg;
    message("enemylist line", msg, ob);
    foreach (object p in ob)
      LAST_D->add_enemylist(p->query_name(), msg);
}

int do_raw_chat(string line, string arg) {
  string msg;
  string bef,it,aft;
  object *ppl;

  if (!sizeof(ppl = query_listeners(line))) return 0;

  msg = arg;

  message(line+" line", msg, ppl);
  
  LAST_D->add_last(line, arg);
  return 1;
}

// this is the function called from the command hook in living.c
int do_chat(string verb, string str) {
    object tp = this_player();
    object *ppl;
    string msg;
    string name;
    int emote;

    if (!tp) return;
    
    if (member_array(verb, keys(channels)) == -1) {
        if (sscanf(verb, "%s:", verb) || sscanf(verb, "%semote", verb))
          emote = 1;
        else
          return 0;
    }

    if (member_array(verb, keys(channels)) == -1 || !query_listening(tp, verb)) return 0;
    
    if (!str) {
      tp->set_blocked(verb);
      return 1;
    }

    if (tp->query_blocked(verb)) {
      if (tp->query_blocked("all")) {
        message("info", "You cannot chat while totally blocked.", tp);
        return 1;
      }
      tp->set_blocked(verb);
    }

    switch (verb) {
      case "pd": case "staff":
        NNETWORK_D->send(
          "$|"+verb+"||"+tp->query_cap_name()+"||"+FROM+"||"+TO+"|||"+str,
          TO
        );
      break;

      case "auction": case "network": case "mudinfo":
        message("info", capitalize(verb)+" line is read-only.", tp);
        return 1;
      break;
    
      case "intermud":
        SER->intercre("$|"+tp->query_cap_name()+"||"+mud_name()+"|||"+MUD_ID+"||||"+str);
      break;

      case "OOC":
        NETWORK->send_chat(tp, str);
      break;

      case "newbie":
        str = TERMINAL_D->no_colours(str);
      break;
    }

    // imms can be "A shadow" on the lines, but not players
    if (wizardp(tp))
      name = tp->query_cap_name();
    else
      name = capitalize(tp->query_name());
    
    str = CENSOR_D->censor(tp, verb, str);

    ppl = query_listeners(verb);

    if (emote)
      msg = "<"+verb+"> "+name+" "+str;
    else {
      msg = name+" <"+verb+"> "+str;
      // add guild position to front of guild lines
      if (member_array(verb, VALID_GUILDS) != -1) {
        string pos;

        pos = GUILD_D->query_position(tp->query_name());
        if (!pos) pos = "";
        switch (lower_case(pos)) {
          case "none": pos = "Master"; break;
          case "main": pos = "Leader"; break;
        }
        pos = capitalize(pos);
        msg = "<"+pos+"> "+msg;
      }
    }

    message(verb+" line", msg, ppl);

    LAST_D->add_last(verb, msg);

    if (verb != "admin") {
        seteuid("LineLog");
        write_file("/log/lines/"+verb, time_stamp()+""+msg+"\n");
        seteuid(getuid());
    }
    
    if (member_array(verb, INTERMUD_CHANNELS) != -1) {
      SERVICES_D->send_gwizmsg(str, emote, verb);
    }

    return 1;
}
string *intermudchannels() { return INTERMUD_CHANNELS; }
void inter_channels(string who, string verb, string str, int emote) {
    string msg;
    string colour;
    object *ob;
    int i;
    ob = channels[verb];
    i = sizeof(ob);
    while(i--)
    {
        if (!ob[i]) continue;
        if (ob[i])
            colour = ob[i]->query_line_color(verb);
        if (!colour || colour=="")
            colour = "%^MAGENTA%^";
        if(!channels[verb] || base_name(previous_object()) != SERVICES_D) 
            return;
        if(emote)
            msg = sprintf("%s<%s>%s %s %s", colour, verb, RESET, who, str);
        else msg = sprintf("%s %s<%s>%s %s", who, colour, verb, RESET,str);
        if (msg)
            message("inter", msg, ob[i]);
    }
    LAST_D->add_last(verb, msg);
}
int list_channel(string str) {
    string list;
    int i;
    if(!str) return notify_fail("Syntax: <list [channel]>\n");
    if(!channels[str]) return notify_fail("Invalid Line.\n");
    if(member_array(this_player(), channels[str]) == -1) return 0;
    list = "";
    list = "Online: ";
    i =sizeof(channels[str]);
    while(i--) {
        if(!channels[str][i]) continue;
        if(hiddenp(channels[str][i]) || (int)channels[str][i]->query_invis() ||
          (int)channels[str][i]->query_blocked(str)) continue;
        list += " "+channels[str][i]->query_cap_name();
    }
    message("info", list, this_player());
    return 1;
}
string time_stamp() {
    string d,mo;
    mixed h,m,s,y,date;
    sscanf(ctime(time()), "%s %s %d %d:%d:%d %d", d,mo,date,h,m,s,y);
    y=(string)""+y;
    return "["+mo+" "+date+"-"+y[2..]+" "+h+":"+m+":"+s+"]";
}

