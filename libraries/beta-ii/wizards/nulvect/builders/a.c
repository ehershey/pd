#include <std.h>

inherit OBJECT;

string stuff;

void create() {
  ::create();
  stuff = "default";
}
void set_stuff(string s) { stuff = s; }
string query_stuff() { return stuff; }
