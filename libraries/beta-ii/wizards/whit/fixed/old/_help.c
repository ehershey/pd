//      /bin/user/_help.c
//      from the Nightmare mudlib
//      the help command
//      based on the help created by Wayfarer and Mrx
//      written by Descartes of Borg
#include <std.h>
#include <daemons.h>
#include <dirs.h>
inherit DAEMON;
string alig_str(string str, int x);
int list_cmds(string str);
void write_banner(string group, string topic) {
    write("%^BOLD%^%^MAGENTA%^Help Topic:%^RESET%^ "+topic+"%^BOLD%^%^MAGENTA%^    "
      "Category:%^RESET%^ "+group);
}
int call_help (string path, string topic) {
  string group, file;
  object ob;
//added by PETER
  string truncated1, truncated2;
  truncated1=topic;
  if (strlen(truncated1)>13) truncated1=truncated1[0..13];
  truncated2=topic;
  if (strlen(truncated2)>13) truncated2=truncated2[0..13];
  file = path+"/_"+truncated1;
  if ((ob = find_object(file)) || (file_size(file+".c") >= 0 ) ||
    (file_size(path + "/" + truncated2) >=0)) {
      switch (path)
        {
        case DIR_USER_HELP :
          group = "General";
          write_banner(group, topic);
                   this_player()->more(path+"/"+topic, "help");
//                message("info", read_file(path+"/"+topic)+"\n",
//this_player());
          return 1;
          break;
        case DIR_CREATOR_HELP :
          group = "Developer";
          write_banner(group, topic);
          this_player()->more(path+"/"+topic, "help");
//          message("info", read_file(path+"/"+topic)+"\n",
// this_player());
          return 1;
          break;
        case DIR_MORTAL_CMDS :
          group = "Player";
          break;
        case DIR_HM_CMDS:
           group = "High Mortal";
            break;
        case DIR_CREATOR_CMDS :
          group = "Developer";
          break;
        case DIR_SYSTEM_CMDS :
          group = "System";
          break;
        case DIR_CLASS_CMDS:
          group = "Command";
          break;
        case DIR_GUILD_CMDS:
          group = "Guild";
          break;
        case DIR_RACE_CMDS:
          group = "Race Command";
          break;
        case DIR_UNDEAD_CMDS:
          group = "Ghost";
          break;
        case DIR_ILLUSION_CLASS_CMDS:
          group = "Command";
        case DIR_AMBASSADOR_CMDS :
          group = "Ambassador";
          break;
        default:
//        group = path;
          group = "Other";
          break;
        }
      write("%^BOLD%^%^MAGENTA%^Help Topic:%^RESET%^ "+topic+"%^BOLD%^%^MAGENTA%^    "
        "Category:%^RESET%^ "+group);
      if (!ob)
        ob = find_object_or_load (file);
      if (!ob)
        {
          message("help", "That command is not loading properly, please "
            "report it using the \"bug\" command.", this_player());
          return 1;
        }
      if (function_exists("help",ob))
        {
          call_other(file,"help");
          return 1;
        }
      else
        {
          message("help", "That command exists, but has no help.  "
            "Please use the bug command to report it.", this_player());
          return 1;
        }
    }
  else
    return 0;
}
int cmd_help(string topic) {
  string *search_path;
  int i;
  object ob, act_ob;
  act_ob = previous_object();
    seteuid(getuid(previous_object()));
  if (!topic)
    {
     topic = "help";
    }
  if(topic != "I")   /* patch to allow "help I"  by Valodin Jan 93 */
    topic = lower_case (topic);

    if(topic == "commands" || topic == "feelings") {
    return list_cmds(topic);
  }

  if (call_help(DIR_USER_HELP, topic)) return 1;
  if (wizardp(act_ob))
      if (call_help(DIR_CREATOR_HELP, topic)) return 1;
  search_path = (string *)act_ob->query_search_path();
  if (search_path) {
      for (i = 0; i<sizeof(search_path); i++)
              if (call_help(search_path[i],topic)) return 1;
  }
  if((ob = present(topic,act_ob)) || (ob = present(topic,environment(act_ob))))    {
      if(function_exists("help",ob))
        {
        write("%^BOLD%^%^MAGENTA%^Help Topic:%^RESET%^ "+topic+"%^BOLD%^%^MAGENTA%^ -  "
          "Category:%^RESET%^ Special");
          ob->help();
          return 1;
        }
    }
  message("help", "There is no help available for that topic.", this_player());
  return 1;
}
int list_cmds(string str) {
    string borg;
    string *comms, *paths;
    int i;
    borg = "\n";
    if(str == "feelings") comms = (string *)SOUL_D->query_feelings();
    else {
        comms = ({});
        paths = (string *)this_player()->query_search_path();
        paths = paths - ({ "/cmds/skills" });
        i = sizeof(paths);
             
        while(i--) comms += (string *)CMD_D->query_commands(paths[i]);
    }
    comms = sort_array(comms, "alpha", this_object());
    for(i=0; i <sizeof(comms); i+=5) {
        borg += alig_str(comms[i], 13);
        if(i+1<sizeof(comms)) borg += alig_str(comms[i+1], 13);
        if(i+2<sizeof(comms)) borg += alig_str(comms[i+2], 13);
        if(i+3<sizeof(comms)) borg += alig_str(comms[i+3], 13);
        if(i+4<sizeof(comms)) borg += alig_str(comms[i+4], 13);
        borg += "\n";
    }
    this_player()->more(explode(borg, "\n"), "help");
    return 1;
}
string alig_str(string str, int x) {
    string reg;
    int i, y;
    if(!str) str = "";
    y = strlen(str);
    x -= y;
    if(x < 1) return str;
    for(i=0; i<= x; i++) {
        str += " ";
    }
    return str;
}
void help() {
    write("Syntax: <help [topic]>\n\n"+
        "Gives you help ony any subject for which help is available.\n"+
        "Help exists for all commands.  For a list of what topics are\n"+
        "available, type <help topics>.\n"
        "Other information providing commands: faq, date\n"
    );
}
int alpha(string a, string b) { return strcmp(a, b); }
