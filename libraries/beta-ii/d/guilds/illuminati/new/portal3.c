#include <std.h>
#include <guild.h>
inherit OBJECT;
void create()
{
::create();
set_id(({"portal", "arch", "golden arch", "archway", "golden archway", "ilarchgate"}));
set_name("Illuminati archway");
set_long("%^BOLD%^%^WHITE%^The %^YELLOW%^Illuminati%^WHITE%^ archway. It links all the halls of the %^YELLOW%^Illuminati "
"%^WHITE%^together.\n\nYou may <travel to [helgrath or tirun]>%^RESET%^");
set_short("%^BOLD%^%^YELLOW%^Golden %^WHITE%^archway%^RESET%^");
set_weight(0);
set_prevent_get("%^BOLD%^%^WHITE%^The arch is ethereal and cannot be touched, only passed through.%^RESET%^");
}

void init() {
::init();
add_action("travel", "travel");
}

int travel(string str) {
    if (this_player()->query_guild() != "illuminati") {
       this_player()->move_player("/d/tirun/square.c");
       write("%^BOLD%^%^BLACK%^The portal rejects you from the halls of the Illuminati!%^RESET%^");
       }
    if (!str) {
       write("%^BOLD%^%^BLACK%^You must specify a destination before passing through the arch.%^RESET%^");
       return 1;
       }
    if (str == "to helgrath") {
       write("%^BOLD%^%^WHITE%^Stepping through the arch find yourself in the subhall of Helgrath.%^RESET%^");
       this_player()->move_player(ROOMS"illuminati/new/helhall.c");
       return 1;
       }
   if (str == "to tirun") {
       write("%^BOLD%^%^WHITE%^Stepping through the arch find yourself in the Tirun subhall.%^RESET%^");
       this_player()->move_player(ROOMS"illuminati/new/tirunhall.c");
       return 1;
       }
    write("%^BOLD%^%^BLACK%^You step through the arch but nothing happens.%^RESET%^");
    return 1;
}
