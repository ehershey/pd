#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("male");
   set_name("fish");
   set_id( ({ "shark"}) );
   set_short("shark");
   set_long("A carnivorous fish that attacks anything in sight.");
   set_level(60);
   set_body_type("fish");
   set_alignment(10);
   set_race("fish");
   set_class("fighter");
set("aggressive",200);

      }
