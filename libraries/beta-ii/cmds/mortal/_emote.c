/*
// Author unknown (??)
// Help added by Brian (1/28/92)
*/

#include <std.h>
#include <daemons.h>

inherit DAEMON;

#define SZ 75

void add_group_say(string msg, object *all, object tp) {
    int i;
    //   object ob;
    i = sizeof(all);
    while (i--) {
	if (all[i] == tp) continue;
	if (!all[i]->is_player()) continue;
	LAST_D->add_say(all[i]->query_name(), msg);
    }
}

int cmd_emote(string str) {
    string tail,insert;
    object *inv;

    inv = all_inventory(environment(this_player()));
    inv = filter_array(inv, "ignoring", this_object());
    if(this_player()->query_ghost()) {
	notify_fail("A ghost has no feelings.\n");
	return 0;
    }
    if(!str) {
	message("emote", "You look emotional.", this_player() );
	message("emote", this_player()->query_cap_name() + " looks emotional.",
          environment(this_player()), this_player() );
	LAST_D->add_say(this_player()->query_name(), "You look emotional.");
	add_group_say(this_player()->query_cap_name()+" looks emotional.",
	  inv, this_player());
	return 1;
    }
    if (sscanf(str," %s",tail)==1) insert = "";
    else if (sscanf(str,"'%s",tail) == 1) insert = "";
    else insert = " ";
    if((int)this_player()->query_mp() <0 && (int)this_player()->query_level() < 20) {
	write("You are low on magic points.");
	return 1;
    }
    if((int)this_player()->query_level() < 20) this_player()->add_mp(-7);
  str = CENSOR_D->censor(this_player(), "emote", str);
    message("emote", sprintf("%-="+SZ+"s",
      "You emote: "+this_player()->query_cap_name()+insert+str),
      this_player() );
    message("emote", sprintf("%-="+SZ+"s",
	this_player()->query_cap_name() + insert + str), inv, ({this_player()}));
    LAST_D->add_say(this_player()->query_name(), "You emote: "+
      this_player()->query_cap_name()+insert+str);
    "/cmds/system/_intercept"->global("emote", this_player()->query_name()+" emotes: "+
      this_player()->query_cap_name()+insert+str);
    add_group_say(this_player()->query_cap_name()+insert+str,
      all_inventory(environment(this_player())), this_player());
    return 1;
}

int ignoring(object o) {
    if(o->query_ignoring(this_player()->query_name())) return 0;
    return 1;
}

int help() {
    write("Syntax: <emote [string]>\n"+
      "Whatever string you type in will be given to every one in the room\n"+
      "with you following your name.  Thus the command:\n"+
      "emote sits down and relaxes.      will do:\n"+
      "Brian sits down and relaxes.\n"+
      "(With your name substituted for Brian)\n");
    write("Cost for players under level 20: 7 mp\n"+
      "For immortals and high mortals: free\n");

    write("See also: say, whisper, yell\n");
    return 1;
}
/* EOF */
