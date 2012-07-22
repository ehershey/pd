#include <std.h>

inherit ARMOUR;

int initarg;
string shortdesc;
string longdesc;

void set_short(string s) {
  string *ids;
  ids=explode(s, " ")+({"clothing"});
  set_id(ids);
  shortdesc=s;
  ::set_short(s);
}

void set_long(string l) {
  longdesc=l;
  ::set_long(l);
}

void create() {
  ::create();
  if (initarg != 1) {
    set_name("");
    set_id( ({"clothing"}) );
    set_short( "" );
    set_long( "" );
    set_type("");
    set_limbs(({""}));
  }
  set_mass(1);
  set_value(0);
  set_ac(0);
}             

mixed *query_auto_load() {
  return ({base_name(this_object()),
   ({ query_name(), shortdesc, longdesc,
   query_type(), query_limbs(),
   query_type() == "gloves" ? query_fingers() : 0 }) });
}

void init_arg(mixed *arg) {
  if (arg[0]) {
    set_name(copy(arg[0]));
    set_short(copy(arg[1]));
    set_long(copy(arg[2]));
    set_type(copy(arg[3]));
    set_limbs(copy(arg[4]));
    if (arg[5])
      set_fingers(copy(arg[5]));
    initarg=1;
  }
}
