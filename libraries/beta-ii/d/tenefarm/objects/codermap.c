#include <std.h>
#include <wildfire.h>
inherit OBJECT;
void create() {
  ::create();
  set_name("coder map");
  set_short("area detail map");
  set_long("Wildfire's area map.\n"
   "                   The map reads:\n"
   "  ------------------------------------------------\n"
   "  |     `~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~       |\n"
   "  |        BARN             house-> 21   /       |\n"
   "  |         |                      /    /        |\n"
   "  |         11                   20    /         |\n"
   "  |         |                   /     /          |\n"
   "  |         10    13 -14       19 ___/   26 WMILL|\n"
   "  |        /     /     \\      |   |_     |       |\n"
   "~1+~2-~7-~8-~9-12       15    18   | 24-25       |\n"
   "  |   |                   \\    |   |/            |\n"
   "  |   ~3-~6                16 -17-22-23          |\n"
   "  |   | X |  <-Pasture              |   \\         |\n"
   "  |   ~4-~5                        |    27       |\n"
   "  |                                |    |        |\n"
   "  |                                |    28       |\n"
   "  |                                \\    |        |\n"
   "  |                                 |   30       |\n"
   "  |__________________________________\\___________|\n"
   "   BARN                  HOUSE             WMILL  \n"
   "    33                  34-35-36          37+38+39\n"
   "    |                enter-^        enter-^       \n"
   "    32-31 <-enter                                 \n"
  );
  set_id(({ "map", "old" }));
}
