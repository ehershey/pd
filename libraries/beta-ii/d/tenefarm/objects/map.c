#include <std.h>
#include <wildfire.h>
inherit OBJECT;
void create() {
  ::create();
  set_name("map");
  set_short("A faded old map");
  set_long("This is a very old faded map. The symbols are barely legible.\n"
   "                   The map reads:\n"
   "  %^ORANGE%^-----------------------------------------------\n"
   "  %^ORANGE%^|     %^BLUE%^`~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^       %^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|        %^RED%^BARN%^RESET%^             house-> []  %^BLUE%^/       %^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|%^RESET%^         |                      /   %^BLUE%^/%^RESET%^        %^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|%^RESET%^         []                   []   %^BLUE%^/%^RESET%^         %^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|%^RESET%^         |                   /    %^BLUE%^/%^RESET%^          %^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|%^RESET%^         []    []-[]       []   %^BLUE%^_/%^RESET%^   [] WMILL%^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|%^RESET%^        /     /     \\      |   %^BLUE%^|%^RESET%^     |       %^ORANGE%^|%^RESET%^\n"
   "[]%^ORANGE%^+%^RESET%^[]-[]-[]-[]-[]       []    []  %^BLUE%^|%^RESET%^ []-[]       %^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|%^RESET%^   |                   \\   |   %^BLUE%^|%^RESET%^/            %^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|%^RESET%^  %^GREEN%^ []-[]%^RESET%^                []-[]-%^BLUE%^[]%^RESET%^-[]          %^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|%^RESET%^   %^GREEN%^ |X|  <-Pasture             %^BLUE%^|%^RESET%^   \\         %^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|   %^GREEN%^[]-[]                       %^BLUE%^|%^RESET%^    []       %^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|%^RESET%^                               %^BLUE%^|%^RESET%^    |        %^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|%^RESET%^                               %^BLUE%^|%^RESET%^    []       %^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|%^RESET%^                               %^BLUE%^\\%^RESET%^    |        %^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|%^RESET%^                                %^BLUE%^|%^RESET%^   []       %^ORANGE%^|%^RESET%^\n"
   "  %^ORANGE%^|_________________________________%^BLUE%^\\%^ORANGE%^___________|%^RESET%^\n"
  );
  set_id(({ "map", "old map" }));
}
