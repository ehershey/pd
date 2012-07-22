// Aziraphale
#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_properties((["light":3, "indoors":1, "no scry":1, "no steal":1, "no
bump":1]));
set_name("Illuminati Hall");
set_short("Illuminati Hall");
set_long("%^RESET%^%^ORANGE%^The Hall of Ages, the main hall of the Illuminati. The room "
"%^RESET%^%^ORANGE%^takes up the entire first floor of the Tower of Light. "
"%^RESET%^%^ORANGE%^Pillars support the tower and windows line the walls."); 
set_exits(([
"hall" : ROOMS"meeting",
"up"            : ROOMS"illuminati/new/floor2",
"north"          : ROOMS"illuminati/new/entrance"
]));
set_items(([
"windows"       : "Large stained glass windows, each one portrays an image of a
holy warrior.",
"pillar"        : "A large marble pillar, it is very strong and very thick."
]));
}

void init()
{
::init();
add_action("newstuff", "request");
add_action("listamon", "read");
}

int newstuff(string str) {
    object tp;
    tp = this_player();
    if (!str || str == "") {
       write("\nYou must specify a request.");
       return 1;
       }
//    if (str == "ring") {
//       if (!present("ilring", tp)) {
//          new(GUILDARMOUR"ilring.c")->move(tp);
//          write("\nYou have received your new Illuminati Ring.");
//          return 1;
//          }
//       write("\nYou already have an Illuminati Ring!");
//       return 1;
//       }
    write("\nYour request could not be completed. For a list of things you may request, type %^BOLD%^%^CYAN%^<read list>%^RESET%^.");
    return 1;
}

int listamon(string str) {
    if (str == "list") {
       write("When new unique items are added you may request them.");
       return 1;
       }
    write("You can only %^BOLD%^%^CYAN%^<read list>%^RESET%^ here.");
    return 1;
}

void reset() {

::reset();
if (!present("silver chest"))
   new(ROOMS"illuminati/new/chest")->move(this_object());
}
