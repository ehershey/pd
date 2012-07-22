/*
// The new more command.
// Much more efficient, we hope.
*/

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_more(string str) {
  IMSTAT_D->add_stat(this_player()->query_name(), "more", time());
  return (int)this_player()->more(str);
}

int help()
{
  write( @EndText
Syntax: more <filename>
Effect: Uses the user's built in pager to list to your screen the
        contents of the file named <filename>
See also: less, cat, head, tail
EndText
  );
  return 1;
}
