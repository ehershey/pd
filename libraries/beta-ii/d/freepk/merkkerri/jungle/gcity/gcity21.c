#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^The courtyard within the palace gates%^RESET%^");
set_day_long("%^YELLOW%^You stand within an incredible courtyard that houses some of the most amazing flora and wildlife you have ever seen.  The exotic plants here draw magnificent birds and insects here creating quite a landscape.  The path leads west to the entrance of the main palace.  An intersecting path running north and south will take you to the guard towers of the palace.%^RESET%^");
set_night_long("%^YELLOW%^You stand within an incredible courtyard that houses some of the most amazing flora and wildlife you have ever seen.  The exotic plants here draw magnificent birds and insects here creating quite a landscape.  The path leads west to the entrance of the main palace.  An intersecting path running north and south will take you to the guard towers of the palace.%^RESET%^");
set_items(([
(({"flora", "plants"})) : "The plantlife is breathtaking.  Vibrant flowers and sculpted bushes speckle the courtyard.",
(({"wildlife" , "birds", "insects"})) : "The wildlife in the courtyard is even more diverse than the surrounding jungle!",
"paths" : "The north south path leads to the guard towers while the west path leads to the main entrance of the palace.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"east": GCITY "gcity16.c",
"west": GCITY "gcity33.c",
"north": GCITY "gcity34.c",
"south" : GCITY "gcity35.c",
]));
}

void reset() {
 ::reset();
}
