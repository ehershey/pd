#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("female");
   set_name("hyena");
   set_id( ({ "hyena","laughing hyena"}) );
   set_short("A laughing hyena");
   set_long("Smaller than a dog, but twice as strong.");
   set_level(30);
   set_body_type("canine");
   set_alignment(10);
   set_race("canine");
   set_class("fighter");
   set_skill("attack",100);

      }
