#include <guild.h>
#include "ether.h"
inherit ETHERSTD;

void create() {
  ::create();
    set_short( "Kumi's Room" );
    set_long( "%^BOLD%^%^WHITE%^Kumi's Room%^RESET%^\n"
              "This tiny %^CYAN%^light blue%^RESET%^ room seems to be a secret workroom of some sort. Tiny %^BOLD%^%^CYAN%^blue orbs%^RESET%^ dance around, shedding light to the room. A tall flute of %^BOLD%^%^GREEN%^Mountain%^RED%^ Dew%^RESET%^ sits on a desk next to strange mechanical machines of some sort. A small picture frame stands on the other side of the desk." );
    set_items(([
        "room" : "%^BOLD%^Read the main description, dork!%^RESET%^",
        "orbs" : "%^BOLD%^%^CYAN%^Tiny blue orbs floating around the room.%^RESET%^",
        "flute" : "A tall frosted glass flute filled to the top with cool %^BOLD%^%^GREEN%^Mountain%^RED%^ Dew%^RESET%^.",
        "dew" : "Delicious dew from the mountains of Tirun.",
        "desk" : "An ornate %^ORANGE%^rosewood%^RESET%^ desk, standing low to the ground.",
        "machine" : "A c64 w/64k of ram, 12\" screen, 5.25\" floppy drive, an Atari joystick, and Commodore 300 modem.",
        "machines" : "A c64 w/64k of ram, 12\" screen, 5.25\" floppy drive, an Atari joystick, and Commodore 300 modem.",
        "picture" : "%^BOLD%^%^WHITE%^A silver picture frame with a picture of Kumi's late grandfather in it. There is an inscription on the bottom of the frame.%^RESET%^",
        "frame" : "%^BOLD%^%^WHITE%^A silver picture frame with a picture of Kumi's late grandfather in it. There is an inscription on the bottom of the frame.%^RESET%^",
        "inscription" : "An inscription on the bottom of the picture frame. Perhaps you should try to read it."
        
    ]) );
    set_smell("default", "Smells like post-teen spirit!");
    set_listen("default", "http://radio.djkumi.net:7777/listen.pls");
    set_exits( ([
        "passage" :  ROOMS "4-2.c",
    ]) );

}
