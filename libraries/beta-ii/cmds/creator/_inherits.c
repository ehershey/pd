
// Command written by Ironman
//      From Ironman's libraries

#include <std.h>

inherit DAEMON;

int cmd_inherits(string input) {
    string str,temp,POINTER;
    string* storage;
    object file;
    int counter;

    if(!input) return notify_fail("Search what object?\n");

    sscanf(input,"%s %s",str,temp);
    if(!temp) {
	if(!(file=get_object(input))) return notify_fail("Cannot find: "+input+"\n");
	storage=sort_array(deep_inherit_list(file),-1);
	counter=sizeof(storage);
	message("info","The object "+input+" inherits the following files:",this_player());
	while(counter--) {
	    message("info",storage[counter],this_player());
	}
	return 1;
    }
    if(!(file=get_object(temp))) return notify_fail("Cannot find: "+input+"\n");
    if(function_exists(str,file)) {
	POINTER=function_exists(str,file);
	message("info","Function "+str+"() in object "+temp+" defined in: "+POINTER+".c",this_player());
	return 1;
    }
    else {
	message("info","Function "+str+"() not defined in object "+temp+".",this_player());
	return 1;
    }
}
void help() {

  message("help",
    "Syntax: inherits <function> <object>\n"
    "        inherits <object>\n\n"
    "When given two arguments, this command finds which inherited file defined a function.\n"
    "With one argument, it prints all files inherited by the given object.",
    this_player() );
}
