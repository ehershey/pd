#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Within the Northeast guard tower%^RESET%^");
set_long("%^YELLOW%^The mighty tower continues far upwards but here on the second level is the sleeping quarters for guards who are forced to take shifts at odd hours.  Several cots have been set up and a clever vent system has been contructed to keep the soldiers warm from the fireplace below.%^RESET%^");
set_items(([
"stairs":"The stairs lead up into the higher levels of the tower or down to the ground level.",
"vent":"A iron tube runs up within the outside wall of the tower and opens to release the warm heat from the fire below.  Smoke is kept at bay by a strange magical energy field.",
"energy field": "The energy field appears to be a shield spell somehow enhanced with a permanent duration.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"down": GCITY "gcity37.c",
"up": GCITY "gcity57.c",
]));
}

void reset() {
 ::reset();
}
