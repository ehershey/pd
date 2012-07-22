//      /cmds/mortal/_bid.c
//      Nightshade 12-13-01

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_bid(string str) {
  return load_object("/cmds/mortal/_auction")->do_bid(str);
}

void help() {
    write("Syntax: <bid [amount] [currency]>\nPlaces a bid on whatever is up for auction.\n"
          "See also: auction");
}
