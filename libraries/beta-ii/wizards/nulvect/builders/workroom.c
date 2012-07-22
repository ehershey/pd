#include <std.h>
#include <daemons.h>
#include <dirs.h>
inherit ROOM;

int max(string str);
int show_stuff(string str);
int do_nothing(string str);

void init() {
  ::init();
  if (this_player()->query_name() == "rull")
  {
    add_action("show_stuff","stuff");
  }
  if (this_player()->query_name() != "rull")
  {
    add_action("do_nothing",({"kill","call"}));
  }
}
int do_nothing(string str) {
  return 1;
}





void create() {
  ::create();
  set_properties((["light" : 2, "indoors" : 1]));
  set_short("a cardboard box");
  set_long("This is a very large cardboard box. It's about tall enough "
    "for a person to stand up in. The bottom is a bit damp and dirty, "
    "but the rest of it is a shiny new cardboard-brown. A couple milk crates "
    "serve as seats, and a plank on the ground seems to be a bed.");
  set_smell("default","Wet cardboard.");
  set_listen("default","Wind whistles through the flaps.");
  set_exits(([ "square" : "/d/nopk/tirun/square" ]));
}

int max(string str) {

  int i, max, l=0;
  mapping s;
  string what, w;
  object who;

  if (str) sscanf(str,"%d %s",l,w);
  if (!w) who=this_player();  
  else who=find_player(w);

  if (!who) {
    message("info","No one around by that name.",this_player());
    return 1;
  }

  s=who->query_skills();

  for (i=0; i<sizeof(s); i++) {
    what= keys(s)[i];
    if (!l) {
      max= s[what]["max"];
      max= max*who->query_level();
      max= max/2;
    }
    else max=l;
    who->set_skill(what,max);
  }

  message("info","Skills maxed.",this_player());

  return 1;

}

int show_stuff(string str) {
  object tp=this_player();
  message("info","\n objective: "+tp->query_objective()+
                 "\n subjective: "+tp->query_subjective()+
                 "\n possessive: "+tp->query_possessive()+
"\n#include <daemons.h>; TERMINAL_D->no_colours(string);"+
"\n",tp);
  return 1;
}


