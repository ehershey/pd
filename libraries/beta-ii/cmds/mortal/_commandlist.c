//  Drackmire, 4/20/10
//  based on the command spells by
//  seeker 06/02/2000
//  Fixed by Whit - 12:02:18 AM 01/04/02
//   simplified by Nulvect 2006-08-29

#include <std.h>
#include <daemons.h>
inherit DAEMON;
string *directories = 
({
  "/cmds/mortal/",
});


int cmd_commandlist(string str)
{
    string *list;
    mapping commands  = ([ "commands" : ({ }) ]);
    string name, output;
    int i, a;

    output = "";
    foreach (string dir in directories) {

	list = get_dir(dir+"_*.c");
	if (!(sizeof(list))) continue;

	foreach (string file in list) {
	    sscanf(file, "_%s.c", name);
	    commands["commands"] += ({ name });
	}

    }


    for(i=0;i<sizeof(commands["commands"]);i++){
	output += arrange_string(commands["commands"][i],13);
    }

     message("no_wrap", "%^BLUE%^+=+=%^BOLD%^(%^RESET%^ Commands %^BOLD%^BLUE%^)%^RESET%^BLUE%^"
      "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
      "+=+=+=+=\n%^RESET%^",
      this_player());

    message("output", output, this_player());
    message("output", "\n\nTo learn more about any of these commands, type %^CYAN%^'help (command)'%^RESET%^", this_player());

    return 1;
}

void help() {
    write( @EndText
Syntax: commandlist
Lists commands available to all mortals.
EndText
    );

}
