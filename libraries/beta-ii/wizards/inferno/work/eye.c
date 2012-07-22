#include <std.h>
inherit MONSTER;

static private object snoopee;

void create() {
 ::create();
   set_name("eye");
   set_short("the blind eye of truth");
   set_long("The eye is hazy and the glass is foggy. A single green "
      "sphere rests within the hazy crystal eye.");
//   set_weight(70);
//   set_value(0);
   set_level(1);
   set_race("human");
   set_body_type("human");
}

int spy(string str) {
   if (!wizardp(this_player())) return 0;
  if(!str) {
    if(snoop(this_object()))
        write("Ok.\n");
    else write("Couldn't stop snoop\n");
  }
  else if(!(snoopee=find_player(str=lower_case(str))))
    write(str+": no such player.\n");
  else
    write(snoop(this_object(), snoopee)?"The green sphere within the eye "
      "begins to spin very quickly.\n":"Could not spy on "+str+".\n");
   return 1;
}

void catch_tell(string str) {
   string st;
   object env;
   if (!snoopee) return;
   if (!sscanf(str, "%%%s", st)) return;
   env = environment(this_object());
   tell_object(env, "%^BOLD%^%^GREEN%^%%^RESET%^"+str);
}
/*
int get() {
   if (wizardp(this_player())) return 1;
   return 0;
}
*/
// int is_player() { return 1; }
void init() {
 ::init();
   add_action("spy", "spy");
}
