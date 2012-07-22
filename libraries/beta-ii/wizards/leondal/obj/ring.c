/****************************************
 *
 * ring.c
 *
 * Leondal - 09/2009
 *
 * This ring allows me to make and
 * use custom commands that I'm used
 * to from other muds. It will also
 * eventually let me test player
 * commands.
 *
 ****************************************/

#include <std.h>

inherit ARMOUR;

#define PATH "/wizards/leondal/cmds/"

int query_auto_load() { return 1; }

void create() {

  ::create();
  set_name("glowing ring");
  set_id( ({ "ring", "glowing ring", "leondal's ring" }) );
  set_short("A Glowing, Evil Ring");
  set_limbs(({ "first hand" }));
  set_weight(1);
  set_type("ring");

}

void init() {

  ::init();
  add_action("filter","",1);

}

int drop() {

  message("help","You cannot drop your evil ring.",this_player());
  return 1;

}

mixed filter(mixed arg){

  string FILE;
  object ofile;

  if(query_verb() == "dest") return 0;
  
  FILE=PATH+query_verb()+".c";
  ofile=load_object(FILE);

  if(file_size(FILE)>=0 && ofile) {
    (object)FILE->load();
    return call_other((object)FILE,"main",(string)arg);
  }
  return 0;
}
