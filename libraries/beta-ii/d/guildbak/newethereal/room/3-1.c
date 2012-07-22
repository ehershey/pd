#include <guild.h>
#include "ether.h"
inherit ETHERSTD;

void create() {
  ::create();
    set_short("Level 3");
    set_long(
      "%^BOLD%^%^GREEN%^Ethereal Tower: Level 3%^RESET%^\n"
      "%^RESET%^%^GREEN%^The walls are inlaid with malachite, jade and emerald stones."
      " The floor is made from a smooth cold stone, which has swirls of sparkling green particles in it."
      " A large sign with the word \"%^BOLD%^Locker%^RESET%^%^GREEN%^\" hangs just above the door to the north of the room."
      " To the south of the room, is a doorway with a sign above it which reads, \"%^BOLD%^Treasury%^RESET%^%^GREEN%^\".%^RESET%^"
    );
    set_items(([
        "malachite" : "%^RESET%^%^GREEN%^Precious green stones that adorn the walls.%^RESET%^",
        "jade" : "%^RESET%^%^GREEN%^Precious green stones that adorn the walls.%^RESET%^",
        "emerald" : "%^RESET%^%^GREEN%^Precious green stones that adorn the walls.%^RESET%^",
        "stones" : "%^RESET%^%^GREEN%^Precious green stones that adorn the walls.%^RESET%^",
        "floor" : "%^RESET%^%^GREEN%^Softened granite with swirls of sparkling green specks in it.%^RESET%^",
    ]) );
    set_smell("default", "The scent of aromatic blossoms waft in the air, bringing peace to the room.");
    set_listen("default", "Faint gaelic chanting drifts through the marble halls.");
    set_exits( ([
        "north" :  ROOMS "3-2.c", "south" : ROOMS "3-3.c", "up" : ROOMS "4-1.c", "down" : ROOMS "2-1.c",
    ]) );

}
 
