#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("female");
   set_name("fish");
   set_id( ({ "ahi","fish"}) );
   set_short("ahi");
   set_long("A large silver fish.");
   set_level(20);
   set_body_type("fish");
   set_alignment(10);
   set_race("fish");
   set_class("fighter");

      }
