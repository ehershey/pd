#define SAVE "/d/guilds/data/vote/"+guildname
#include <std.h>
#include <daemons.h>

inherit ROOM;

static string guildname;
mapping vote, votecountyes, votecountno;

void set_guild(string what) { guildname = what; }

void init() {
    ::init();
    add_action("add_name", "add");
    add_action("remove_name", "remove");
    add_action("vote", "vote");
    add_action("check", "check");
    add_action("setup", "setup");
    add_action("list", "list");
    add_action("read", "read");
}

void create() {
    ::create();
    vote = ([]);
    votecountyes = ([]);
    votecountno = ([]);
    restore_object(SAVE);
}

int read(string str) {
    restore_object(SAVE);
    if(!str && str != "sign") return notify_fail("Read what?\n");
    write("Here are the following commands:\n");
    write("<vote [name] [yes/no]>:  This will make you vote yes/no "
      "for [name].");
    write("<list>:  Will show a list of people wanting to join.");
    write("<add [name]>: (gm or councilor) Will add [name] to the list.");
    write("<remove [name]: (gm or councilor) Will remove [name] from the "
      "list.>");
    write("<check [name]>: (gm or councilor) Will check the votes for "
      "[name]\n");
    return 1;
}

int list() {
    int i;
    string *out, *list;
    restore_object(SAVE);
    list = keys(vote);
    restore_object(SAVE);
    write("The following people whould like to join:\n");
    if(sizeof(list) <= 0) write("There is currently no one wanting to "
	  "join.");
    i = sizeof(list);
    out = ({});
    while(i--) {
	if(!vote[list[i]]);
	else {
	    if(member_array(this_player()->query_name(), vote[list[i]]) != -1)
		out += ({ "*"+list[i] });
	    else out += ({ list[i] });
	}
    }

    write(format_page(out));
    write("* indicates that you have already voted for that player.\n");
    return 1;
}



int setup() {
    if(!wizardp(this_player())) return 0;
    votecountyes = ([]);
    votecountno = ([]);
    vote = ([]);
    write("Vote setup complete.\n");
    save_object(SAVE);
    return 1;
}


int check(string who) {
    restore_object(SAVE);
   if(!GUILD_D->check_rights(this_player()->query_name(), guildname,
	({"council", "leader"}) ) ) 
	return notify_fail("You are not authorized to view the votes.");
    if(!who) return notify_fail("Syntax: <check [who]>\n");
    if(!vote[who]) return notify_fail("No such name.\n");
    write(votecountyes[who]+" votes for yes.  "+votecountno[who]+" votes "
      "for no.\n");
    return 1;
}

int vote(string str) {
    string who, what;
    restore_object(SAVE);
    if(!str) return notify_fail("Syntax: <vote [who] [yes/no]>\n");
    if(sscanf(str, "%s %s", who, what) != 2) return notify_fail("Syntax: "
	  "<vote [who] [yes/no]>\n");
    who = lower_case(who);
    if(!vote[who]) return notify_fail("No such name.\n");
    if(member_array(this_player()->query_name(), vote[who]) != -1) return
	notify_fail("You have already voted for the person.\n");
    if(member_array(who, keys(vote)) == -1) return notify_fail("No "
	  "such name.\n");
    if(what != "yes" && what != "no") return notify_fail("Yes or No only.\n");
    vote[who] += ({ this_player()->query_name() });
    if(what == "yes") {
	votecountyes[who]=votecountyes[who]+1;
	write("Vote counted.\n");
	save_object(SAVE);
    }
    if(what == "no") {
	votecountno[who]=votecountno[who]+1;
	write("Vote counted.\n");
	save_object(SAVE);
    }
    return 1;
}

int add_name(string who) {
    restore_object(SAVE);
    if(!guildname) return notify_fail("Invalid guild name.\n");
    if(!GUILD_D->check_rights(this_player()->query_name(), guildname,
	({"council", "leader"}) ) ) return notify_fail("You are not "
	  "allowed to do that.\n");
    if(!who) return notify_fail("Add who?\n");
    restore_object(SAVE);
    who = lower_case(who);
    if(vote[who]) return notify_fail("That name is "
	  "already on the list.\n");
    vote[who]=({});
    votecountyes[who]=0;
    votecountno[who]=0;
    write("Name added.\n");
    save_object(SAVE);
    return 1;
}

int remove_name(string who) {
    restore_object(SAVE);
    if(!guildname) return notify_fail("Invalid guild name.\n");
    if(!GUILD_D->check_rights(this_player()->query_name(), guildname,
	({"council", "leader"}) ) ) return notify_fail("You are not "
	  "allowed to do that.\n");
    if(!who) return notify_fail("Remove who?\n");
    restore_object(SAVE);
    who = lower_case(who);
    if(member_array(who, keys(vote)) == -1) return notify_fail("No "
	  "such name.\n");
    map_delete(vote, who);
    write("Final count: "+votecountyes[who]+" votes for "
      "yes. "+votecountno[who]+" votes for no.\n");
    map_delete(votecountno, who);
    map_delete(votecountyes, who);
    write("Name removed.\n");
    save_object(SAVE);
    return 1;
}

