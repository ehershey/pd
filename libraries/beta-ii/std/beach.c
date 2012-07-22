#include <daemons.h>
inherit PIER;

static string letter;

void set_letter(string str) { letter = str; }

int *query_coords() { return OCEAN_D->query_coord_from_letter(letter); }

void create() {
  ::create();
  set_no_clean(1);
}
