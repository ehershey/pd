#include <std.h>
inherit DAEMON;
#define SNOWBALL "/wizards/vian/rainbowsnowball.c"
int cmd_throwsnowball() {
    foreach (object player in users()) {
        new(SNOWBALL)->move(player);
        message("info", "%^BOLD%^Vian's laughter echos in your ears as a %^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^i%^BLUE%^n%^GREEN%^b%^MAGENTA%^o%^CYAN%^w %^WHITE%^infused snowball pelts you in the back of the head.",
player);
}     
 return 1;
}  
