#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("male");
   set_name("ooze");
   set_id( ({ "ooze"}) );
   set_short("ooze");
   set_long("Looks like a puddle of water.");
   set_level(40);
   set_body_type("blob");
   set_alignment(0);
   set_race("ooze");
   set_class("fighter");

      }
