//Coded by Whit

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Some Bushes");
    set_properties( (["light" : 3, "night light" : 2]) );
set_long("The path is covered with %^BOLD%^%^GREEN%^green %^RESET%^"
"bushes.  The slight breeze rustles the leaves of the bushes.  Large bugs "
"live here making this a very bugy place.");
set_exits(([
"south" : ROOMS+"bushes4",
"north" : ROOMS+"bushes2.c",
              ]) );
}
