#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("female");
   set_name("dragonfly");
   set_id( ({ "bug","dragonfly"}) );
   set_short("A dragonfly");
   set_long("The dragonfly has a long thin body with four wings.");
   set_level(25);
   set_body_type("insctwgd");
   set_alignment(20);
   set_race("insect");
   set_class("fighter");
   set_skill("attack",100);

      }
