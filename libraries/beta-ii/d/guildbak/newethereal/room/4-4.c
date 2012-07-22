#include <guild.h>
#include "ether.h"
inherit ETHERSTD;

void create() {
  ::create();
    set_short("Endbringer's Room");
    set_long( "%^BOLD%^%^RED%^Endbringer's Room%^RESET%^\n"
              "This is the room of the great %^BOLD%^%^BLACK%^S%^WHITE%^h%^BLACK%^a%^WHITE%^d%^BLACK%^o%^WHITE%^w %^BLACK%^L%^WHITE%^o%^BLACK%^r%^WHITE%^d %^RED%^E%^BLACK%^n%^RED%^d%^BLACK%^b%^RED%^r%^BLACK%^i%^RED%^n%^BLACK%^g%^RED%^e%^BLACK%^r%^RESET%^ and his beautiful wife, A%^BOLD%^%^WHITE%^k%^BLACK%^i%^RESET%^s%^BOLD%^%^WHITE%^h%^BLACK%^i%^RESET%^. On one wall is the painting of a female ferrel and on the other, hangs a set of staves and daggers. In the left corner of the room rests a large bed, with %^BOLD%^%^MAGENTA%^purplish%^BLACK%^ black%^RESET%^ sheets neatly covering the resting place of the two lovebirds. Standing before the painting is a desk made of solid oak, which has an undorderly and messy look." );
    set_items(([
        "staves" : "These newly carved staves lean against the wall, resting with older ones that looked used. They were hand made by Akishi, the truly added detail show her interest and love for the hobby.",
        "desk" : "Magic scrolls, leather bound books, letters from the past & present, and parchments on necromancy rest messily upon the desk.  A human skull is being used as a paperweight, and it stares down on the papers with a blank look.",
        "painting" : "This is a painting of Endbringer's first wife, %^BOLD%^%^CYAN%^S%^BLACK%^u%^CYAN%^r%^BLACK%^i%^RESET%^. She had been wandering Lodos one day and mysteriously disappeared.",
        "daggers" : "Many worn out daggers line the wall, giving off an eerie feel. They showed their loyalty and use to Endbringer during use.",
    ]) );
    set_smell("default", "The soft scent of roses hovers in the air.");
    set_listen("default", "There is a calming silence here.");
    set_exits( ([
        "west" :  ROOMS "4-1.c",
    ]) );

}

