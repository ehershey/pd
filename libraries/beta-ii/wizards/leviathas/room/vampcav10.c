#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("The Vampires Cave");
    set_long(
      "%^MAGENTA%^This is the Lair of the Vampires.  %^RESET%^%^BOLD%^Down a beautiful "
      "staircase there is a large area with tables full of %^RED%^red wine%^RESET%^%^BOLD%^. "
      "%^CYAN%^Chandeliers%^RESET%^%^BOLD%^ hang from the ceiling and cast a dim light across a "
      "beautiful marbel floor that has a %^BLACK%^black and %^RESET%^%^MAGENTA%^purple%^RESET%^%^BOLD%^ carpet covering "
      "most of it.  There are many pale figures dressed in vampiric garb "
      "dancing to the sound of an organ.  There is a %^YELLOW%^golden %^RESET%^%^BOLD%^statue down "
      "the steps and far to the north and there is an old, crumbling silver "
      "statue to the east.",);
 
    set_items(([
        "staircase" : "The staircase is massive and made of gold. ", 
        "tables" : "They hold many chalices and goblets of red wine.",
        "chalices" : "They are made of gold with rubies studded around the "
              "rims.",
        "goblets" : "Golden goblets with sapphires and emeralds studded all "
              "round.",
        "chandeliers" : "Huge, beautiful crystal lights hanging from the ceiling.",
        "floor" : "White marbel tiles all ligned up perfectly.  There must be "
              "thousands of them.",
        "carpet" : "From the top of the stairs the entire carpet can be seen.  "
              "On it are sewn many shadows with golden threads all feasting on "
              "one silver woman.",
        "figures" : "These are the vampires.  Though normally hideous, each have "
              "seductive powers.  All their energy in one room is breathtaking "
              "and they appear the most beautiful creatures in the universe.",
        "garb" : "The clothing of the vampires, most likely stolen from the corpses "
              "of rich people who became the prey of the vampires.",
        "organ" : "The organ is at the western end of the hall being played by an "
              "old man.",
        "man" : "The old man is pale and looks dead.",
        "statue" : "Which statue?  The golden statue or the silver statue?",
        "golden statue" : "It lies to the north.  It is one of the most "
              "amazing sculptures of an ancient god, the god of the vampires.",
        "silver statue" : "Unlike the golden statue, this was poorly made, probably "
              "in mockery of someone that was hated by the vampires.  It is hard to "
              "see much detail from here, however judging by the long, flowing hair "
              "it is probably a female.", 
       
        ]));
    
    set_exits( (["stairs" : ROOMS "vamplair1.c", ]) );
    
        
}
