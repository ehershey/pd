#include <std.h>
#include <wildfire.h>
inherit OBJECT;
void create() {
  ::create();
  set_name("flower");
  switch (random(5)) {
  case 1:
    set_short("%^RESET%^%^GREEN%^----<-%^MAGENTA%^@");
    set_long("%^MAGENTA%^A beautiful purple flower.");
    break;
  case 2:
    set_short("%^RESET%^%^GREEN%^--<-%^YELLOW%^@");
    set_long("%^YELLOW%^A beautiful yellow flower.");
    break;
  case 3:
    set_short("%^RESET%^%^GREEN%^-<-<-%^BLUE%^@");
    set_long("%^BLUE%^A beautiful blue flower.");
    break;
  case 4:
    set_short("%^RESET%^%^GREEN%^---|-%^RED%^@");
    set_long("%^RED%^A beautiful red flower.");
    break;
  default:
    set_short("%^RESET%^%^ORANGE%^-|--<-@");
    set_long("%^ORANGE%^Aww... The flower is dead...");
    break;
  }
  set_id(({ "flower" }));
  set_smell("default", "It smells wonderful.");
}
int query_auto_load() {return 1;}
