#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("female");
   set_short("spider");
   set_long("It's so big, it can barely fit into the cave.");
   set_level(50);
   set_body_type("arachnid");
   set_alignment(0);
   set_race("giant");
   set_class("fighter");

      }
