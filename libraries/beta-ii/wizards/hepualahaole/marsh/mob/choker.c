#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("choker");
   set_id( ({ "choker"}) );
   set_short("choker");
   set_long("A rather strange looking creature.");
   set_level(50);
   set_body_type("human");
   set_alignment(0);
   set_race("choker");
   set_class("fighter");

      }
