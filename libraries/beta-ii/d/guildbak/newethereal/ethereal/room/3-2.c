#include <guild.h>
#include <ether.h>
inherit LOCKER;

void create() {   
  set_path("/adm/save/votes/etherealstorage"); 
  ::create();
    set_short("Locker");
    set_long(
      "%^BOLD%^%^GREEN%^Ethereal Storage Shop%^RESET%^\n"
      "%^RESET%^%^GREEN%^Large crates are stacked neatly behind a counter."
      " All the crates are numbered and have hinged doors on the front."
      " This shop charges for storing items."
      " Use the command %^BOLD%^<store>%^RESET%^%^GREEN%^ to leave an item for storage, and %^BOLD%^<reclaim>%^RESET%^%^GREEN%^ to retrieve a stored item."
      " Only one item may be stored per player.%^RESET%^"
    );
    set_items(([
        "crates" : "%^RESET%^%^ORANGE%^Large crates that are used to store things.%^RESET%^",
    ]) );
    set_smell("default", "The scent of aromatic blossoms waft in the air, bringing peace to the room.");
    set_listen("default", "Faint gaelic chanting drifts through the marble halls.");
    set_exits( ([
        "south" : ROOMS "3-1.c",
    ]) );

}
