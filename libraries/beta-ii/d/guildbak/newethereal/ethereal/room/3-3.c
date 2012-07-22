#include <daemons.h>
#include <guild.h>
#include "ether.h"
inherit TREASURY;

void create() {
  ::create();
    set_guild("ethereal");
    set_short("Treasury");
    set_long(
      "%^BOLD%^%^GREEN%^Ethereal Treasury%^RESET%^\n"
      "%^RESET%^%^GREEN%^This large room is shroud in nobility."
      " Several paintings adorn the wall."
      " Here is where you donate money to the guild by using %^BOLD%^<donate amount>%^RESET%^%^GREEN%^ - i.e: donate 1 gold."
      " Please donate in the form of gold, only."
      " If you would like to view all past transactions, use %^BOLD%^<read scroll>%^RESET%^%^GREEN%^."
      " To view the current balance use %^BOLD%^<balance>%^RESET%^%^GREEN%^.%^RESET%^"
    );
    set_items(([
        "paintings" : "Gold framed paintings of Ethereal's Leaders.",
    ]) );
    set_smell("default", "The scent of aromatic blossoms waft in the air, bringing peace to the room.");
    set_listen("default", "Faint gaelic chanting drifts through the marble halls.");
    set_exits( ([
        "north" : ROOMS "3-1.c",
    ]) );

}
