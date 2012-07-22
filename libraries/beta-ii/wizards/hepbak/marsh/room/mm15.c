#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
    set_server(SERVER);
    ::create();
    set_long("this is a standard
sentence"+this_object()->query_night_long()+".");
    set_exits( ([
        "south" : ROOMS "m15",
      ]) );
}
string query_long() { 
  if(query_night()) 
      return ::query_long() + "This goes on the end of night sentances."; 
  else 
      return ::query_long() + "This goes on the end of day sentances."; 
} 
