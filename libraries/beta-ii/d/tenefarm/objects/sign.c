#include <std.h>
#include <wildfire.h>

inherit OBJECT;

int noMap;

void create() {
  ::create();
  set_name("sign");
  set_short("A sign");
  set_long("This sign has a map attatched to it. Maybe you should read it.");
  set_id(({ "sign", "board" }));
  set_prevent_get("The sign is magically held in place.");
  set_mass(18);
  set_read("default", "Due to the amount of people knocking on my door asking me how to get home I had a wizard magically attach a magically regenerating supply of maps to this sign. Simply <receive map> to obtain one.");
  noMap = 0;
}

void init() {
  ::init();
  add_action("receive_map", "receive");
}

int receive_map(string str) {
  if(str != "map") return notify_fail("Recieve what?\n");
  if(noMap) return notify_fail("Somebody just took a map. Give the sign a minute to prepare another one for you.\n");
  new(OBJ"map.c")->move(this_player());
  write("As you greedily snatch the map off the sign another one materializes where it used to be. How strange.");
  if(wizardp(this_player())) {
    new(OBJ"codermap.c")->move(this_player());
    write("As you look over the map you notice a second map to notify coders of the room names. simply add farm in front of the number.");
  }
  noMap = 1;
  call_out("refresh_sign", 3);
  return 1;
}

int refresh_sign() {
  noMap = 0;
}
