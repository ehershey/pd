#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("spider");
   set_id( ({ "wolfspider"}) );
   set_short("wolfspider");
   set_long("A large deadly spider. It is brown and hairy.");
   set_level(50);
   set_body_type("arachnid");
   set_alignment(0);
   set_race("wolfspider");
   set_class("fighter");

      }
