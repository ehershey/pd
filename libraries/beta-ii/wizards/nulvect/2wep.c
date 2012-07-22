#include <std.h>

inherit WEAPON;

void create() {
  ::create();
  set_name("multipurpose weapon");
  set_id(({"weapon","testwep","wep","knife","proj",
           "spear","blade","sword","axe","flail",
           "blunt"}));
  set_short("a multipurpose weapon");
  set_long("It does everything.");
  set_weight(10);
  set_wc(8);
  set_type("blade");
  set_hands(2);
}

int query_auto_load() { return 1; }

string query_long() {
  return "Type: "+query_type()+"  WC: "+query_wc();
}

void init() {
  ::init();
  add_action("change_type","type");
  add_action("change_wc","WC");
  add_action("max","max");
  add_action("mob","mob");
}

int change_type(string str) {
  set_type(str);
  if (present("testwep 2",environment()))
    return notify_fail("Changed types to "+str+".\n");
  message("info","Changed type to "+str+".",this_player());
  return 1;
}

int change_wc(string str) {
  set_wc(to_int(str));
  if (present("testwep 2",environment()))
    return notify_fail("Changed WCs to "+str+".\n");
  message("info","Changed WC to "+str+".",this_player());
  return 1;
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

int mob(string str) {
  this_player()->force_me("clone /wizards/nulvect/testmon.c");
  return 1;
}

