#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("male");
   set_name("dragon turtle");
   set_id( ({ "dragon","turtle","dragon turtle"}) );
   set_short("A dragon turtle");
   set_long("It's has a snout and heas like a dragon and a body of a turtle. This creature is very large.");
   set_level(60);
   set_body_type("snake");
   set_alignment(200);
   set_race("snake");
   set_class("fighter");
   set_skill("attack",200);
   }
