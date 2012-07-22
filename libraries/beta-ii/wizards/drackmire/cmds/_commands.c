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


int cmd_commands(string str)
{
    string *list, *array;
    string name, output;
    int i, a;

    foreach (string dir in directories) {

      list = get_dir(dir+"_*.c");
      if (!(sizeof(list))) continue;

      foreach (string file in list) {
          sscanf(file, "_%s.c", name);
        array += ({ name });
      }

    }
    
    
    for(i=0;i<sizeof(output);i++){
        output += arrange_string(output[i],13);
        }

    message("no_wrap", "+=+=( Commands )"
        "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
        "+=+=+=+=\n",
      this_player());
      
    message("output", output, this_player());
      
    return 1;
}

void help() {
  write( @EndText
Syntax: commands
Lists commands available to all mortals.
EndText
  );

}
