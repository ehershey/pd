
#include <std.h>
#include <lidelas.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("rutyo street");
        set_short("Rutyo street");
        set_long("A short street in the town of lidelas, it serves to connect some of the residential districts to the main parts of town. Rafore Street lies just off to the east, it is the largest street in town. Many large buildings line the street, each one seeming larger then the last. The buildings have many sculptures on them, most of them would seem to be of gargoyles. The gargoyles look down to the street, watching over all the people who walk by. The streets are made of a fine cobble stone, and looks to be well maintained. People pulling carts go by, the carts contain supplies brought from the docks. The people are most likely merchants off to sell goods to the townsfolk.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
        "gargoyles"    :  "They are not very large, and seem to be carved into
the building."
            ]));
            set_listen("default", "It is rather quiet in this part of town.");
            set_smell("default", "Sea salt fills the air.");
            set_exits(([
                        "west"          : ROOMS "lidelas037.c",
                        "east"          : ROOMS "lidelas003.c",
        ]));

}
