#include <std.h>
#include <marsha.h>
inherit ROOM;

void create() {
::create();
    set_short("The Temple of Change");
    set_long("The temple is warm and the walls seem to move as wind hits them from outside.  The ground is very smooth and hard, possibly marble.  "
	"This is a long hall, extremely featureless, with many side halls which would be invisible if not for the tiny lights shining out of them.  "
	"The lights bounce all over the walls, as if by the a wavering flame.  To the north, there is a rather large object of some sort and to the "
	"south there is an opening leading outside.");
    
    set_items(([
          "floor" : "The floor shines barely at the entrance and appears to be some sort of marbly substance.",
	  "pillars" : "Mighty looking pillars, in cone shapes, Brace the doorway open.  They allow a person of any concievable size to enter the structure.",    
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "tob10.c",
	"out" : ROOMS "tob8.c",
    ]));
}

