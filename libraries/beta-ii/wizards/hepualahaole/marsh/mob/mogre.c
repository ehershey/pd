#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("male");
   set_name("ogre");
   set_id( ({ "ogre"}) );
   set_short("ogre");
   set_long("It looks very sad being chained up and forced to work.");
   set_level(60);
   set_body_type("human");
   set_alignment(-300);
   set_race("ogre");
   set_class("fighter");

      }
