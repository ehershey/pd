#include <std.h>
#include <mjungle.h>
#include <gcity.h>

inherit BARKEEP;

create() {
    ::create();
   set_property("no bump", 1);
set_name("bartender");
set_id(({"bartender", "merkkirri bartender", "gnoll"}));
set_short("Merkkirri Bartender");
   set("aggressive", 0);
set_level(30);
    set_long("He tends bar and he listens.\n");
   set_gender("male");
set_alignment(-100);
set("race", "gnoll");
   add_money("gold", random(200));
set_body_type("gnoll");
    set_currency("gold");
    set_menu(
     ({
     "firebreather", "special", "ale"
     }),
     ({ "alcoholic", "alcoholic", "alcoholic" }),
     ({ 25, 15, 3 })
    );
    set_my_mess(
     ({
     "The firebreather burns your throat!",
    "Wow! That bartender sure knew how to make drinks when he invented that!",
     "You down some ale."
     })
    );
    set_your_mess(
     ({
     "screams from the burning of a drink of a firebreather.",
     "drinks a special of the house.",
     "drinks some ale."
     })
    );
    set_menu_short(
     ({
     "A firebreather",
     "A special of the house",
     "A pale ale"
     })
    );
    set_menu_long(
     ({
    "A firebreather from the Silvermane Bar.",
     "A classic special of the house from the Silvermane Bar.",
     "A pale ale brewed from strange jungle roots."
     })
    );
}
