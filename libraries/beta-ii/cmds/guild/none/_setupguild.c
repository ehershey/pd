//  Guild System Version 4
//  Created by Whit

#include <daemons.h>
#include <guild.h>
#define SYNTAX notify_fail("Syntax: <setupguild [guild name] [leader]>\n")
string *member, *council, *leader, *squire;

int cmd_setupguild(string la) {
    string debug = "";
    int warn, er;
    string str, lead, *type;

    if(!wizardp(this_player())) return 0;
   if(!GUILD_D->valid_master(this_player()->query_name())) return
	notify_fail("You may not do that.\n");

    if(sscanf(la, "%s %s", str, lead) != 2) {
	er = 1;
	return SYNTAX;
    }

    if(!str) return SYNTAX;
    str = lower_case(str);
    if(member_array(str, VALID_GUILDS) != -1) return 
	notify_fail(str+" already exists.\n");
    debug += "Checking for guild directory... ";
    if(file_size("/d/guilds/"+str)!=-2) {
	debug += "Cannot find directory: /d/guilds/"+str+"\n";
	er = 1;
    } else
	debug += "Ok.\nChecking for object(hall.c)... ";

    if(!er) if(file_size("/d/guilds/"+str+"/hall.c")==-1) {
	    debug += "Error: Cannot find hall.c\n";
	    er = 1;
	} else
	    debug += "Ok.\nChecking for object(treasury.c)... ";
    if(!er) if(file_size("/d/guilds/"+str+"/treasury.c")==-1) {
	    debug += "Warning: Cannot find treasury.c\n";
	    warn++;
	} else
	    debug += "Ok.\nChecking for object(entrance.c)... ";
    if(!er) if(file_size("/d/guilds/"+str+"/entrance.c")==-1) {
	    debug += "Warning: Cannot find entrance.c\n";
	    warn++;
	} else
	    debug += "Ok.\nChecking for object files: \n     news... ";
    if(!er) if(!file_exists("/d/guilds/news/"+str)) {
	    cp("/d/guilds/temp/data/news", "/d/guilds/data/news/"+str);
	}
    debug += "Ok.\n     Member Object... ";
    if(!er) if(file_exists("/d/guilds/save/"+str+".o")) {
	    debug += "Warning: File already exists.\n";
	    type += ({ "member" });
	    warn++;
	} else {
	    write_file("/d/guilds/save/"+str+".o", "leader ({\""+lead+"\",})");
	    debug += "Ok.\n";
	}
    debug += "     Treasury Data... ";
    if(!er) if(file_exists("/d/guilds/data/treasury/"+str+".o")) {
	    debug += "Warning:  File already exists.\n";
	    warn++;
	}
    if(!er) if(file_exists("/d/guilds/data/vote/"+str+".o")) {
	    debug += "Warning:  File already exists.\n";
	    warn ++;
	} else debug += "Ok.\nAdding Leader... ";
    if(!er) {
     if(!find_player(lead)) { er = 1; debug += "Unable to find player.\n"; }
	    if(find_player(lead)->query_guild()) { er = 1; debug += "User has a guild.\n"; }
	    find_player(lead)->set_guild(str);
	    debug += "Leader "+lead+" added.\n";
	}
	if(er) {
	    write(debug+"\nCannot complete request.  Cleaning up installation.\n");
	    if(member_array(type, "member") == -1) rm("/d/guilds/save/"+str+".o");
     rm("/d/guilds/data/news/"+str);
	    return 1;
	}

	write(debug+"\n\n");
	if(!warn) write("Request complete.  You may now start using the guild.\n");
	else write("Warnings: "+warn+"\nRequest complete.  You may now start using the guild.\n");
	return 1;
    }

