/*
// Author: Descartes
*/

/* patched by Valodin jan 15,  1993
   ob is forced to look around
   and trash strings are  filtered a little better
*/

#include <move.h>
#include <std.h>

inherit DAEMON;

int help();

int
cmd_trans(string str) {
  object      ob;

  if((string)this_player()->query_position() == "ambassador") return 0;
  if(!str) {
    return help();
  }
  if( ob=find_living(lower_case(str)) )
  {
    if(environment(ob)==environment(this_player()))
    {
      write("You twitch.\n");
      if (!this_player()->query_invis())
          say(this_player()->query_cap_name()+" twitches.\n");
      return 1;
    }

    tell_object(ob, "%^BOLD%^%^WHITE%^You are magically teleported somewhere!%^RESET%^\n");
    ob->move_player(environment(this_player()));
    return 1;
  }
  else return help();
}

int
help()
{
  write("Command: trans\nSyntax: trans <player>\n"+
        "If the name of an active player is passed then this\n"+
        "command teleports that player to you.\n"+
        "See also: move\n"+
        "");
  return 1;
}
