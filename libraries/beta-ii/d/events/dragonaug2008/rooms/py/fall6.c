#include <std.h>
#include <dragonevent.h>
#include <move.h>

#define SAY(x) message("info", x, this_object())
#define INSTANCE_D "/d/events/dragonaug2008/rooms/instance_d.c"

inherit DRAG_ROOMS"py/logbase";

int do_look(string);

int count;

void create() {
  ::create();
  set_long("The western edge of the inside of a large, hollowed log. The center of the log leads to the east. The inside of the log is just wide enough to fit you comfortably. Outside of the log to the west, there are large trees that stretch towards the sky. Far below, a small circular dirt clearing is visible on the ground.");
  set_items( ([
    "log" : "You are standing within it.",
    "center" : "The center of the log lies to the east.",
    ({"below","ground"}) : "Far below you, you can see a small circular dirt clearing, nestled within the forest.",
    "sky" : "The log above and the canopy of trees beyond that obscure your view of the sky.",
    "dirt" : "The clearing below is covered with it.",
    "clearing" : "Far below you, the trees and shrubbery are pounded away into a small dirt clearing.",
    "shrubbery" : "It is scattered about the ground and the trees.",
    ({"trees", "vines", "object", "vine"}) : (: do_look :),
  ]) );
  set_exits( ([
    "east" : DRAG_ROOMS"py/fall5",
  ]) );
  count = 0;
}

void init() {
  ::init();
  add_action("do_jump", "jump");
  add_action("use_stone", ({"use", "release"}));
  add_action("throw_item_at_vine", "throw");
}

void heart_beat() {
  ::heart_beat();
  if(!player || !present(player)) return;

  count ++;

  if(count >= 1+random(4)) {
    int i = DRAG_D->query_data("cavelogsway:"+player->query_name());
    i -= 1+random(2);
    DRAG_D->set_data("cavelogsway:"+player->query_name(), i);
    SAY("%^ORANGE%^Your weight pushes the log down slightly.");
    set_print_status(1);
    count = 0;
  }

  if (query_print_status())
    print_status();
}

int do_jump(string str) {
  if(!str) {
    write("Jump where?");
    return 1;
  }
  if(str != "out" && str != "west" && str != "down" && str != "towards clearing" && str != "into clearing" && str != "clearing" && str != "to clearing") return 0;

  write("You leap into the air!");
  this_player()->move(DRAG_ROOMS"py/fall8", "out of the log");
  return 1;
}

int do_look(string str) {
  int i = DRAG_D->query_data("cavelogramp:"+player->query_name());
  message("info", this_player()->query_cap_name()+" attempts to look at "+str+".", this_object(), this_player());
  if(str == "trees") {
    SAY("The vine-covered trees surround the outside of the log. They reach towards the sky.");
  }
  else if(str == "vines") {
    SAY("The vines cover the tree. "+(i?"":"They appear to be holding some sort of long object to the tree."));
  }
  else if(!i) {
    if(str == "object") {
      SAY("It appears to be loosely secured to a tree near you by a long vine that wraps around it. It is very close, but out of your reach.");
    }
    else if(str == "vine") {
      SAY("It appears to be very frail. It holds some sort of object in place.");
    }
  }
  return 1;
}

int use_stone(string str) {
  object stone;
  string stoneName;
  if(str == "stone") return notify_fail("You need a target for that.\n");
  if(sscanf(str, "%s on %s", stoneName, str) != 2) return 0;
  stone = present(stoneName, this_player());
  if(!stone) return notify_fail("What "+stoneName+"?\n");
  if(file_name(stone)[0..sizeof(DRAG_ITEMS"caveob")-1] != DRAG_ITEMS"caveob")
    return notify_fail(query_verb()+"ing a "+stoneName+" would do no good.\n");
  if(str != "object" && str != "vines" && str != "vine")
    return notify_fail(query_verb()+"ing the stone on "+str+" would not help.\n");

  DRAG_D->set_data("cavestage:"+this_player()->query_name(), 5);
  message("info", "%^YELLOW%^A bright light shoots forth from the stone, obliterating the tree, as well as the log you were standing in!", this_object());
  message("info", "You fall out of the tree!", this_object());
  this_player()->move(DRAG_ROOMS"py/fall8");
  all_inventory(this_object())->move(environment(this_player()));
  return 1;
}

int throw_item_at_vine(string str) {
  string item;
  object itemOb;
  if(sscanf(str, "%s at vine", item) != 1 && sscanf(str, "%s at object", item) != 1)
    return 0;
  if(!(itemOb = present(item, this_player())))
    return notify_fail("You do not have "+item+".\n");
  if(DRAG_D->query_data("cavelogramp:"+this_player()->query_name()))
    return notify_fail("That is not here.\n");
  if(itemOb->move( INSTANCE_D->get_instance_room(this_player()->query_name(), DRAG_ROOMS"py/3", query_instance_group_id()) ) != MOVE_OK) {
    write("You cannot throw that.");
    return 1;
  }
  message("info", this_player()->query_cap_name()+" throws an "+item+" out of the log.", this_object(), this_player());
  message("info", "The "+item+" strikes the vine and knocks the object lose!", this_object());
  DRAG_D->set_data("cavelogramp:"+this_player()->query_name(), 1);

  SAY("The object strikes the side of the log, knocking it to the east.");
  DRAG_D->set_data("cavelogsway:"+player->query_name(), DRAG_D->query_data("cavelogsway:"+player->query_name())+16);
  set_print_status(1);
  return 1;
}
