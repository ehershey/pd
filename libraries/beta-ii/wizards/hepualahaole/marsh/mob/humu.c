#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("male");
   set_name("fish");
   set_id( ({ "humuhumunukunukuapua'a","fish"}) );
   set_short("A humuhumunukunukuapua'a %^BLACK%^");
   set_long("Why does a small fish has such a great big name?");
   set_level(20);
   set_body_type("fish");
   set_alignment(10);
   set_race("fish");
   set_class("fighter");

      }
