#include <std.h>
inherit MONSTER;

static int oi = 0;

void create() {
 ::create();
   set_name("amgis");
   set_short("Amgis, the scavenger");
   set_moving(1);
   set_speed(4);
   set_long(@ENDTEXT
  _       _              _
_(v)_    (v)     ('>    ( )
 /-\    //-\\    /V\   // \\
(\_/)   (\_/)   <(_)   (\=/)
 ^ ^     ^ ^      ~~    ~ ~
            -[Amgis]-
  _       _       _      _      _
 <`)     <`)     <`)    (v)    (v)
 /V\     /V\     /V\   //-\\  //-\\
\(_)>  \<\_)>  \< _/>  (u_/)  (\_u)
 ~~      ~~      ~~       ^    ^
Amgis, Sigma's elder cousin couldn't find any better job than as a scavenger, 
seeing as Sigma already took the position as a mascot. There aren't many job
openings for Dodo Birds. Amgis wanders around, picking up anything that looks
like it may be of value.. In other words everything it can lift.
%^YELLOW%^[Note]:%^RESET%^ Please do not attack Amgis
ENDTEXT);
   set_level(1);
   set_property("no attack", 1);
   set_race("Dodo Bird");
   set_id(({"amgis", "bird", "garbage man", "garbageman", "scavenger" }));
   set_body_type("fowl");
   set_hp(30000000);
}

int move_player(object str, string where) {
   int i;
   object *all, ob, env;

   ::move_player(str, where);
   env = environment(this_object());
   all = all_inventory(env);
   i = sizeof(all);
   while (i--) {
     ob = all[i];
     if (ob->is_living()) continue;
     if (ob->query_id()[0] == "boat") continue;
     tell_object(env, "%^YELLOW%^Amgis takes %^RESET%^%^ORANGE%^"
       +ob->query_short()+"%^BOLD%^ and swallows it.");
     ob->remove();
   }
   this_object()->add_hp(30000000);
   return 1;
}

int die() {
   "/wizards/powerman/room/patha"->ok_to_amgis();
   ::die(this_object());
}
