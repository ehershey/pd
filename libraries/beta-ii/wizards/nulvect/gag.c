#include <std.h>
#include <daemons.h>
inherit OBJECT;
int silencer(string str);
void create() {
    ::create();
    set_short("gag");
    set_name("gag");
    set_long("You do not see that here.");
    set_id(({ "gagger12345" }));
    set("no store", 1);
}
void init() {
    ::init();

    add_action("destgag","destgag");
    add_action("remove_me", "remove");
    add_action("silencer","");
    call_out("init",2);


}
int remove_me(string str) {
    if(!str) {
	notify_fail("Remove what?\n");
	return 0;

    }
    if(str != "gag") {
	notify_fail("Use: remove gag.\n");
	return 0;
    }
    if(!wizardp(this_player())) return 0;
    write("You have been ungagged!\n");
    this_object()->remove();
    return 1;
}
int destgag(string str) {
  if (wizardp(this_player())) {
    this_object()->remove();
    message("action","You dest your gag.",this_player());
    return 1;
  }
  return 0;
}
int query_auto_load() { return 1; }
int give() { 
    if (wizardp(this_player())) return 0;
    return 1; }
int reclaim() { 
    if (wizardp(this_player())) return 0;
    return 1; }
int store() { 
    if (wizardp(this_player())) return 0;
    return 1; }
int put() { 
    if (wizardp(this_player())) return 0;
    return 1; }
int drop() {
    if (wizardp(this_player())) return 0;
    return 1;
}
int bury() {
    if (wizardp(this_player())) return 0;
    return 1;
}
int dest() {
    if (wizardp(this_player())) return 0;
    return 1;
}
int silencer(string str) {
    string inf;
    if (!str) return 0;
    if (this_player()->query_name() == "stormbringer") return 0;
   if (this_player()->query_name() == "whit") return 0;
    if (this_player()->query_name() == "seeker") return 0;
    if (this_player()->query_name() == "nightshade") return 0;
    inf = query_verb();

    if (inf == "remove") return remove_me(str);
    if (inf == "destgag") return 0;

    if (member_array(inf,this_player()->query_channels()) != -1 ||
        member_array(replace_string(inf,":",""),this_player()->query_channels()) != -1 ||
        member_array(replace_string(inf,"emote",""),this_player()->query_channels()) != -1) {
      message("system","You have been gagged.",this_player());
      return 1;
    }

    switch(inf) {
      case "rub": if (str == "oil" || str == "stone") return 0; else return 1;
      case "sing":
        return 0;
      case "say":
      case "store":
      case "reclaim":
      case "store $*":
      case "reclaim $*":
      case "yell":
      case "mail":
      case "post":
      case "whisper":
      case "shout":
      case "tell":
      case "emoteto":
      case "emote":
      case "party line":
      case "speak":
      case "reply":
      case "message":
      case "title":
      case "pretitle":
	write("You have been gagged.");
	return 1;

    default:
/*
      foreach (string dir in this_player()->query_search_path()) {
        if (file_size(dir+"/_"+inf+".c") != -1) return 0;
      }
      foreach (mixed *cmd in this_player()->local_commands()) {
        if (cmd[0] == inf) return 0;
      }
*/
      if (CMD_D->find_cmd(inf, this_player()->query_search_path())) return 0;
      if ((int)sizeof(load_object(SOUL_D)->query_atmos(inf)) >= 1) {
        message("system","You have been gagged.",this_player());
        return 1;
      }
    }
    return 0;
}

