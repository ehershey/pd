#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("male");
   set_name("worm");
   set_id( ({ "worm"}) );
   set_short("worm");
   set_level(50);
   set_long("A large sand worm.");
   set_body_type("worm");
   set_alignment(0);
   set_race("worm");
   set_class("fighter");

      }
