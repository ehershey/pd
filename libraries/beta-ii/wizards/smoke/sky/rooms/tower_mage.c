#include <std.h>
#include <cp.h>
inherit ROOM;
void init() {
    ::init();
    add_action("read", "read");
    add_action("read2", "read");
    add_action("read3", "read");
    add_action("read4", "read");
}
void create() {
 ::create();
   set_properties( ([ "light" : 3, "indoors" : 1, "night light" : 3,
                "no teleport" : 1]) );
   set_short("High atop a mage tower");
   set_long(
            "%^BOLD%^%^CYAN%^A blinding blue light shines from a "
            "%^YELLOW%^ma%^WHITE%^g%^CYAN%^a%^WHITE%^c%^YELLOW%^al o%^CYAN%^r%^WHITE%^b%^CYAN%^ "
            "floating above a cluttered table. Two bookshelves line the "
            "northern wall and are full of books. A %^WHITE%^white bear "
	    "skin %^CYAN%^rug covers the majority of the stone floor. A "
	    "faded painting hangs in between the two bookshelves. An "
	    "open doorway leads south to the spiraling staircase.%^RESET%^");
   set_items(([
            "staircase" : "A spiraling staircase leads to the bottom "
                        "of the tower. It is south of here.",
            "walls" : "Dark stone walls round off and form a domed "
                 "ceiling.",
           "orb" : "%^BOLD%^%^CYAN%^The magical orb emits an almost "
                 "blinding light if you stare at it for more than "
                 "a few seconds. It just floats above the table and "
		 "only seems to be a light source.%^RESET%^",
            "bookshelves" : "The wooden bookshelves are both filled "
                 "with many old books. They dominate the north wall "
		 "and are seperated by an old, faded painting.",
            "books" : "There are so many books on the shelves it's "
                 "hard to imagine any one person has read them all. "
		 "The books are almost all very faded except for a "
		 "%^BOLD%^%^RED%^red book,%^GREEN%^ green book, %^CYAN%^blue book, "
		 "%^RESET%^and a %^YELLOW%^yellow book.%^RESET%^",
	    "red book" : "%^BOLD%^%^RED%^This book is bound in a "
		 "red leather cover. Sewn into the face of the book "
		 "is the title:\n%^BOLD%^%^BLACK%^     Runes - Vol. IV\n"
		 "     Runes of Damage%^RESET%^",
	    "yellow book" : "%^YELLOW%^This book is bound in a "
		 "red leather cover. Sewn into the face of the book "
		 "is the title:\n%^BOLD%^%^BLACK%^        Runes - Vol. I\n"
		 "     Runes of Regeneration%^RESET%^",
	    "blue book" : "%^BOLD%^%^CYAN%^This book is bound in a "
		 "blue leather cover. Sewn into the face of the book "
		 "is the title:\n%^BOLD%^%^BLACK%^      Runes - Vol. III\n"
		 "     Runes of Knowledge%^RESET%^",
	    "green book" : "%^BOLD%^%^GREEN%^This book is bound in a "
		 "green leather cover. Sewn into the face of the book "
		 "is the title:\n%^BOLD%^%^BLACK%^       Runes - Vol. II\n"
		 "     Runes of Physicality%^RESET%^",
	    "table" : "A cluttered table sits against the wall. Floating "
		 "almost a foot above it is a %^YELLOW%^ma%^WHITE%^g%^CYAN%^a%^WHITE%^c%^YELLOW%^al o%^CYAN%^r%^WHITE%^b%^RESET%^.",
	    "rug" : "An enormous bear skin rug covers most of the "
		 "cold stone floor.",
	    "painting" : "A very important looking painting hangs between "
		 "the two bookshelves on the northern wall. It depicts a "
		 "demon and a dwarf in front of a burning village, each "
		 "wearing a malicious grin. A black dragon is shackled "
		 "and bound in the center of the village as lightning "
		 "strikes all around her.",
   ]));
   set_smell("default", "It almost smells like burnt hair.");
   set_listen("default", "The crackling of energy is strong here.");
   set_exits( ([ 
        "south" :  ROOMS "tower7_1"]));
}
void reset() {
::reset();
    if(!present("andorf")) new(MOB"andorf.c")->move(this_object());
}
int read(string str) {
    if(!str) {
        return notify_fail("Read what?\n");
    }
    if(str != "red book") {
        return notify_fail("You may <read [color] book>\n");
    }
    message("info", "\n                       Runes - Vol. IV\n"
	"                       Runes of Damage%^RESET%^",this_player());
    message("Ninfo",
      "\n\nThe Runes of Damage are rumored to be the oldest gifts from the "
      "gods since life itself. Many adventurers from all walks of life "
      "and all paths of study have lost their lives searching for these "
      "runes. Many have also given up, lost sanity, or been plagued with "
      "endless nightmares so frightening as to take their own life in "
      "search of the Damage runes.\n\n"
      "By far, the most efficient way to harness the power of the Runes "
      "of Damage is to have it magically infused to a weapon. Each rune "
      "contains its own element. The easiest way to spot a Damage rune, "
      "if by chance you are fortunate enough to encounter one, is by its "
      "red symbol. The red indicates that the rune is of the damage variety."
      " There are four known Runes of Damage: the Ansuz, Sowelu, Laguz, and "
      "the Isa Rune.\n\n"
      "Ansuz-\nThe Ansuz Rune contains the element of wind. The symbol of "
      "the Ansuz looks like the letter F with the two horizontal lines at "
      "a slant.\n"
      "Sowelu-\nThe Sowelu Rune contains the element of fire. The symbol "
      "of the Sowelu looks like the letter S with sharp curves and a long "
      "body.\n"
      "Laguz-\nThe Laguz Rune contains the element of water. The symbol of "
      "the Laguz looks like a straight vertical line with a slanted line "
      "extending downward on the right side.\n"
      "Isa-\nThe Isa Rune contains the element of ice. The symbol of the "
      "Isa is simply a vertical line.\n\n"
      "To maximize the potential of the Runes of Damage, it is best to "
      "infuse the rune into the weapon early.\n", this_player());
    return 1;
}
int read2(string str) {
    if(!str) {
        return notify_fail("Read what?\n");
    }
    if(str != "blue book") {
        return notify_fail("You may <read [color] book>\n");
    }
    message("info", "\n                            Runes - Vol. III\n"
	"                          Runes of Knowledge%^RESET%^",this_player());
    message("Ninfo",
      "\n\nThe Runes of Knowledge are as rare as any other type of rune. "
      "They are rumored to have been gifts of the demons, handed out "
      "to their followers to aid them in battle. Angles later handed them "
      "out to various righteous warriors, clergymen and others to help "
      "counter against the demon gifts.\n\n"
      "By far, the most efficient way to harness the power of the Runes "
      "of Knowledge is to have it magically infused to a weapon. Each rune "
      "contains its own area of knowledge. The easiest way to spot a Knowledge "
      "rune, if by chance you are fortunate enough to encounter one, is by its "
      "blue symbol. The blue indicates that the rune is of the knowledge variety."
      " There are five known Runes of Knowledge: the Thurisaz, Teiwaz, Othila, "
      "Inguz, and the Algiz Rune.\n\n"
      "Thurisaz-\nThe Thurisaz Rune contains the knowledge of armed combat. "
      "The symbol of the Thurisaz looks like a pointed D with the vertical "
      "line running longer than that of a D.\n"
      "Teiwaz-\nThe Teiwaz Rune contains the knowledge of attack. The symbol "
      "of the Teiwaz looks like an upward arrow that doesn't fully come "
      "to a point.\n"
      "Othila-\nThe Othila Rune contains the knowledge of attack magic. The "
      "symbol of the Othila looks like a ribbon, or perhaps a fish standing "
      "upright on its tail fin.\n"
      "Inguz-\nThe Inguz Rune contains the knowledge of healing. The symbol of the "
      "Inguz appears to be one X another another.\n"
      "Algiz-\nThe Algiz Rune contains the knowledge of faith. The symbol of the "
      "Algiz is a vertical line with two upward extensions near the top, "
      "one in each direction.\n\n"
      "To maximize the potential of the Runes of Knowledge, it is best to "
      "infuse the rune into the weapon early.\n", this_player());
    return 1;
}
int read3(string str) {
    if(!str) {
        return notify_fail("Read what?\n");
    }
    if(str != "green book") {
        return notify_fail("You may <read [color] book>\n");
    }
    message("info", "\n                           Runes - Vol. II\n"
	"                        Runes of Physicality%^RESET%^",this_player());
    message("Ninfo",
      "\n\nThe Runes of Physicality are believed to be gifts from "
      "the earth, given to those only she deems worthy. It is unknown "
      "how she chooses whom she gives these priceless runes to, as "
      "the most vile necromancers and holiest paladins alike have "
      "been known to possess these runes.\n\n"
      "By far, the most efficient way to harness the power of the Runes "
      "of Physicality is to have it magically infused to a weapon. Each rune"
      " contains its own attribute. The easiest way to spot a Physicality "
      "rune, if by chance you are fortunate enough to encounter one, is by its "
      "green symbol. The green indicates that the rune is of the physical "
      "variety. There are four known Runes of Physicality: the Uruz, Kenaz, "
      "Eihwaz, and the Berkana Rune.\n\n"
      "Uruz-\nThe Uruz Rune contains the strength attribute. The symbol of "
      "the Uruz is a straight vertical line with a long downward slanted "
      "extension.\n"
      "Kenaz-\nThe Kenaz Rune contains the wisdom attribute. The symbol "
      "of the Kenaz looks just like a pointy C.\n"
      "Eihwaz-\nThe Eihwaz Rune contains the dexterity attribute. The symbol of "
      "the Eihwaz looks just like an M.\n"
      "Berkana-\nThe Berkana Rune contains the intelligence attribute. The symbol "
      "of the Berkana is a pointy B.\n\n"
      "To maximize the potential of the Runes of Physicality, it is best to "
      "infuse the rune into the weapon early.\n", this_player());
    return 1;
}
int read4(string str) {
    if(!str) {
        return notify_fail("Read what?\n");
    }
    if(str != "yellow book") {
        return notify_fail("You may <read [color] book>\n");
    }
    message("info", "\n                             Runes - Vol. I\n"
	"                          Runes of Regeneration%^RESET%^",this_player());
    message("Ninfo",
      "\n\nThe Runes of Regeneration are believed to the very essence "
      "of life itself. It is completely unknown about the origin of "
      "these powerful runes. Some cultures refuse to speculate "
      "on where they came from, and others worship them. It is said "
      "that he holds a Regeneration rune is a dozen steps closer to "
      "immortality than he who does not.\n\n"
      "By far, the most efficient way to harness the power of the Runes "
      "of Regeneration is to have it magically infused to a weapon. Each rune"
      " contains its own healing ability. The easiest way to spot a Regeneration "
      "rune, if by chance you are fortunate enough to encounter one, is by its "
      "yellow symbol. The yellow indicates that the rune is of the regeneration "
      "variety. There are three known Runes of Regeneration: the Fehu, Jera, "
      "and the Nauthiz Rune.\n\n"
      "Fehu-\nThe Fehu Rune contains regeneration power of the mind. The "
      "symbol of the Fehu looks like a backwards Y with an extra extension.\n"
      "Jera-\nThe Jera Rune contains regeneration power of energy. The symbol "
      "of the Jera looks just like a pointy C with a backwards pointy C.\n"
      "Nauthiz-\nThe Nauthiz Rune contains regeneration power of health. "
      "The symbol of the Nauthiz looks like a cross except the horizontal "
      "line slants down rather than running straight.\n\n"
      "To maximize the potential of the Runes of Regeneration, it is best to "
      "infuse the rune into the weapon early.\n", this_player());
    return 1;
}
