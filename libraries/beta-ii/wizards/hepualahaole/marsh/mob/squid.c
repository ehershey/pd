#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
   ::create();
   set_gender("male");
   set_name("giant squid");
   set_id( ({ "giant", "squid", "giant squid",}) );
   set_short("giant squid");
   set_long("This squid is over 1,000 times bigger then an average squid.");
   set_level(50);
   set_alignment(-115);
   set_race("giant squid");
   set_class("fighter");
      }
