
#include <teststd.h>
#include <dirs.h>
#include <daemons.h>
#include <security.h>

#define DIR_GMASTER_CMDS "/cmds/gmaster"

#define GAGGED ({\
  "say", "speak", "yell",\
  "shout", "emote", "whisper",\
  "tell", "emoteto", "converse",\
  "reply", "title", "message",\
  "pretitle", "post", "mail",\
  "store", "reclaim",\
})


static int forced;
static string *search_path;


void init_hook();
nomask static int cmd_hook(string cmd);
static void init_path();
string *query_search_path();
void add_search_path(string dir);
void delete_search_path(string dir);
int force_me(string cmd);
nomask int query_forced();


void create() {
  forced = 0;
  init_path();
// this doesn't work yet, since create() is called before enable_commands()
// the add_action will just do nothing since this_object isn't living yet
// we'll call init_hook from living.c or something
//  init_hook();
}

void init_hook() {
  add_action("cmd_hook", "", 1);
}

nomask static int cmd_hook(string cmd) {
  object tp = this_player();
  string verb = query_verb();
  string file;
  int flag = 0;

  if (present("logger", this_object())) {
    write_file("/wizards/whit/logs/"+this_object()->query_name(), "CMD: "+query_verb()+" "+cmd+"\n");
  }

  if (present("harass_logger", this_object())) {
    catch("/cmds/mortal/_harass"->add_harass(this_object()->query_name(), "CMD: "+verb+" "+cmd+"\n"));
  }

  if (verb != "quit" && tp->query_paralyzed()) {
    message("my_action", (string)this_player()->query_paralyze_message(), this_player());
    return 1;
  }

  file = CMD_D->find_cmd(verb, tp->query_search_path());

  if (tp->query_stupor()) {
    if (file && function_exists("spell", load_object(file)) != 0) {
       message("info", "Your thoughts are too scrambled.", tp);
       return 1;
    }
  }

  if (tp->query_property("gagged") || tp->query_property("torture")) {
    string stripped;
    if (sscanf(verb, "%s:%*s", stripped) != 2)
      if (sscanf(verb, "%semote%*s", stripped) != 2)
        stripped = verb;
    
    if ((userp(tp) && member_array(stripped, tp->query_channels()) != -1 && cmd) ||
        (sizeof((mapping)SOUL_D->query_atmos(verb)) && cmd && !file) ||
        member_array(verb, GAGGED) != -1 ||
        verb == "party" && cmd[0..3] == "line")

          flag = 1;
      
  }

  if (flag == 1) {
    if (tp->query_property("gagged")) {
      message("info", "You have been gagged.", tp);
      return 1;
    }
    if (tp->query_property("torture")) {
      object t = present("torture_ob", tp);
      if (t) t->punish();
    }
  }

  if (file)
    return (int)call_other(file, "cmd_"+verb, cmd);
  
  else if ((int)SOUL_D->do_cmd(verb, cmd)) 
    return 1;

  else if ((int)CHAT_D->do_chat(verb, cmd))
    return 1;

  return 0;
}


static void init_path() {
    string tmp;

    search_path = ({ DIR_MORTAL_CMDS, DIR_CLASS_CMDS });

    if (this_object()->query_race() == "vampire")
        search_path += ({ "/cmds/vamp" });

    // all the other tests are just for players, save time on mob loading
    if (!userp(this_object())) return;

    if (tmp = (string)this_object()->query_guild())
        search_path += ({ DIR_GUILD_CMDS+"/"+tmp, DIR_GUILD_CMDS });

    if(this_object()->query_name()=="whit") 
        search_path += ({ DIR_GMASTER_CMDS, DIR_GUILD_CMDS+"none" });

    if(ambassadorp(this_object()) || wizardp(this_object()))
        search_path += ({ DIR_AMBASSADOR_CMDS, DIR_SYSTEM_CMDS });

    if(high_mortalp(this_object()) || wizardp(this_object()))
        search_path += ({ DIR_HM_CMDS });

    if(wizardp(this_object())) {
        search_path += ({ DIR_CREATOR_CMDS });
        search_path += ({ DIR_GUILD_CMDS });
        if(file_size(user_path(this_object()->query_name()) + "bin") == -2)
            search_path += ({ user_path(this_object()->query_name())+"bin" });
        if(archp(this_object()))
            search_path += ({ DIR_ADMIN_CMDS });

    }
}

string *query_search_path() {
  if (previous_object() != this_object() &&
      geteuid(previous_object()) != UID_ROOT)
        return search_path + ({});

  else
    return search_path;
}

void add_search_path(string dir) {
  log_file("paths",
    this_object()->query_name()+": "+dir+" ("+ctime(time())+")\n");
  if (member_array(dir, search_path) == -1) search_path += ({ dir });
}

void delete_search_path(string dir) {
    if (getuid(previous_object()) != UID_ROOT) return;
    if (member_array(dir, search_path) != -1) search_path -= ({ dir });
}

int force_me(string cmd) {
    int res;

    forced = 1;
    res = command(cmd);
    forced = 0;
    return res;
}

nomask int query_forced() { return forced; }

