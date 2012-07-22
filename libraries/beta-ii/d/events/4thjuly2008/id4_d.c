
#include <std.h>
#include <id4.h>

#define SQUARE_LOC "/d/nopk/tirun/square"

#define OPEN_TIME 1215251700-time()

#define CLOSE_TIME 1215331589-time()

#define COLORS ({ "white", "blue", "red" })

inherit DAEMON;

int done = 0;

void start_quest();
void end_quest();
void close_quest();

void create() {
  ::create();
}

int register_event() {
  event("start_quest", OPEN_TIME);
  event("end_quest", CLOSE_TIME);
  return event_pending(this_object());
}

void add_done() { done++; if (done == 3) close_quest(); }

void start_quest() {
  object dragon;
  foreach (string color in COLORS) {
    object room;
    object entrance = load_object(ROOMS+"/"+color+"_entrance");
    if (!entrance) continue;
    room = load_object(entrance->query_property("entrance_room"));
    if (!room) continue;
    room->set_no_clean(1);
    room->add_exit(ROOMS+"/"+color+"_entrance", "enter");
    room->set_long(room->query_long(0)+"\n"+
      "%^BOLD%^%^WHITE%^There is a tunnel entrance here.%^RESET%^"
    );
  }
  /*
  dragon = new(MOBS+"start_dragon");
  dragon->move(SQUARE_LOC);
  */
  find_object(SQUARE_LOC)->set_no_clean(1);
}
void open_white() {
  object entrance = load_object(ROOMS+"/white_entrance");
  object room;
  if (!entrance) return;
  room = entrance->query_property("entrance_room");
  if (!room) return;
  room->set_no_clean(1);
  room->add_exit(ROOMS+"/white_entrance", "enter");
  room->set_long(room->query_long(0)+"\n%^BOLD%^%^WHITE%^There is a tunnel entrance here.%^RESET%^");
}

void end_quest() {
  object dragon;
  dragon = present("id4_dragon", load_object(SQUARE_LOC));
  if (dragon)
    dragon->force_me("say I wish we'd found all my friends...");
  close_quest();
}

void close_quest() {
  object dragon;
  foreach (string color in COLORS) {
    object room;
    object entrance = load_object(ROOMS+color+"_entrance");
    if (!entrance) continue;
    room = load_object(entrance->query_property("entrance_room"));
    if (!room) continue;
    room->set_no_clean(0);
    room->reset();
  }
  find_object(SQUARE_LOC)->set_no_clean(0);
  dragon = present("id4_dragon", load_object(SQUARE_LOC));
  if (!dragon) return;
  dragon->force_me("say Thank you all so much!");
  dragon->force_me("emote flies away.");
  if (dragon) dragon->remove();
}
