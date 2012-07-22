//  Guild System 3
//  Whit
//  This is the wizards command to set up a guild.
#define DIR "/d/guilds/"

static int error;
string *member, *council, *leader;
int cmd_setup(string guild) {
    string name, leader2;
    if(!guild) return notify_fail("Syntax: <setup [name] [leader]>\n");
    if(sscanf(guild, "%s %s", name, leader2) != 2) return notify_fail(
	  "Syntax: <setup [name] [leader]>\n");
    write("Checking requirments:\n");
    if(file_size(DIR+name) != -1) {
	write("Warning:  The guild files needs to be in /d/guilds/\"guild\""
	  " (No such directory)\n");
	error = 1;
    }
    if(!file_exists(DIR+name+"/hall.c")) {
	write("Warning:  hall.c not found.  Guild Meeting room will not work "
	  "properly.\n");
	error = 1;
    }
    if(!file_exists(DIR+name+"/hall.c")) {
	write("Warning:  treasury.c not found.  Guilds must have a treasury."
	  "\n");
	error = 1;
    }
    if(file_exists("/d/guilds/save/"+name+".o") && error != 1) {
	write("Warning:  Skipping object file creation. (File already exists)"
	  "\n");
	error = 1;
    }
    if(error != 1) {
	write("Creating object file:");
	member = ({}); 
	council = ({});
	leader = ({ leader2 });
	save_object(DIR"save/"+guild);
    }
    if(error == 1) {
	write("Unable to create object file (Errors in guild)\n");
    }
    return 1;
}
