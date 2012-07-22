
#include <std.h>

inherit "/wizards/nulvect/std/armour";
inherit BAG;

void create() {
  armour::create();
  bag_logic::create();
}

string query_long_more() {
  string ret="";
  string *longs = ({
    "query_long_worn",
    "query_long_closed",
    "query_long_contents",
    "query_long_full",
  });
  
  foreach (string func in longs) {
    string tmp;
    tmp = call_other(this_object(), func);
    if (strlen(tmp))
      ret += tmp+"\n";
  }

  return ret;
}

string query_short_more() {
  string ret="";
  string *shorts = ({
    "query_short_worn",
  });

  foreach (string func in shorts) {
    string tmp;
    tmp = call_other(this_object(), func);
    if (strlen(tmp))
      ret += " "+tmp;
  }

  return ret;
}

