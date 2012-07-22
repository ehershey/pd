
// Command written by Ironman
//      From Ironman's libraries

#include <std.h>

inherit DAEMON;

int cmd_sonar(string input) {
    string str,temp,POINTER;
   string* storage;
    object file;
      int counter;

    if(!input) return notify_fail("

 I realize you want to look for a function but WHAT
function?? Inside of what object??

");

   sscanf(input,"%s %s",str,temp);
    if(!temp) {
   if(!(file=get_object(input))) return notify_fail("

I can not seem to locate the object you
wish to search...

");
         storage=sort_array(deep_inherit_list(file),-1);
         counter=sizeof(storage);
         message("info","The object "+input+" inherits the following files ;
",this_player());
         while(counter--) {
         message("info",storage[counter]+"
",this_player());
                          }
        return 1;
    }
   if(!(file=get_object(temp))) return notify_fail("

I can not seem to locate the object you wish
to search...

");
    if(function_exists(str,file)) {
        POINTER=function_exists(str,file);
        message("info","

The function "+str+"() inside of the object, "+temp+", is defined in the file
"+POINTER+".c .

",this_player());
       message("info","Use the command grep to scan "+POINTER+".c for the lines containing
"+str+".

",this_player());
        return 1;
    }
    else {
        message("info","

The function "+str+"() does not exist inside of the
object.

",this_player());
        return 1;
    }
}
int help() {

    write("Command name: sonar");
    write("
Command syntax: sonar <function> <object>");
   write("
Command syntax: sonar <object>");
    write("
This command will scan the given object for the named function and return what file has
the function's definition in it.");
    write("If only the object is named, sonar will scan it and return a listing of all inherited
files.");
    return 1;
}
