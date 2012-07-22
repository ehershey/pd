#include <std.h>
#include <lodos.h>
inherit ROOM;
void init() {
  ::init();
add_action("peer", "peer");
add_action("survey", "survey");
}
void create() {
::create();
set_short("");
set_long("       %^B_WHITE%^                                               %^RESET%^       \n"
         "    %^B_WHITE%^                                                     %^RESET%^    \n"
         "  %^B_WHITE%^                                                         %^RESET%^  \n"
         "%^B_WHITE%^                                                             %^RESET%^\n"
         "  %^B_WHITE%^                                                         %^RESET%^  \n"
         "    %^B_WHITE%^                                                     %^RESET%^    \n"
         "       %^B_WHITE%^                                               %^RESET%^       \n"
);
set_properties((["light" : 2, "indoors" : 1, "no teleport":1]));
set_exits(([
"west": AMAZE "a_115.c",
"east": AMAZE "a_117.c",
]));
set_items(([
"walls": "Cloudy mists",
]));
}
void reset() {
::reset();
}
int survey(string what) {
write("Your mind is unable to focus.");
    return 1;
}
int peer(string what) {
write("Your mind is unable to focus.");
    return 1;
}
