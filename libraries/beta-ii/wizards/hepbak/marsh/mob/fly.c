#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
   ::create();
   set_gender("female");
   set_name("fly");
   set_id( ({ "fly"}) );
   set_short("fly");
   set_long("The buzzing noise is irritating");
   set_level(40);
   set_body_type("insctwgd");
   set_alignment(15);
   set_race("insect");
      }
