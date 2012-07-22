#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("male");
   set_name("beetle");
   set_id( ({ "beetle","fire beetle"}) );
   set_short("fire beetle");
   set_long("A luminous insect that lights up the area.  A large glowing globe is
centered upon his forhead.");
   set_level(30);
   set_body_type("insctwgd");
   set_alignment(0);
   set_race("beetle");
   set_class("fighter");
   set_subclass("warrior");
   set_skill("attack","200");


      }
