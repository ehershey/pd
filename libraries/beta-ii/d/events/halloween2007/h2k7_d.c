
#include <std.h>
#include <h2k7.h>

#define ENTRANCE_ROOM "/d/nopk/forest/forest76"
#define PATCH_ROOM1 H2K7ROOMS+"room6_18"
#define QUEST_ROOM H2K7ROOMS+"room1_0"
// about 3:30pm PST Oct 31st
#define OPEN_TIME 1193862285-time()
// about 5pm PST Oct 31st
#define QUEST_TIME 1193868375-time()
// about 4am PST Nov 1st
#define CLOSE_TIME 1193908187-time()

inherit DAEMON;

void create() {
  ::create();
}

string query_entrance() { return ENTRANCE_ROOM; }

int register_event() {
  event("open_patch", OPEN_TIME);
  return event_pending(this_object());
}

void do_more() {
  event("start_quest", QUEST_TIME);
  event("close_patch", CLOSE_TIME);
}
void open_patch() {
  object room = load_object(ENTRANCE_ROOM);
  if (!room) return;
  new(H2K7ITEMS"pumpkin")->move(room);
  room->add_exit(PATCH_ROOM1, "patch");
  room->set_long(room->query_long()+"\n"+
    "%^ORANGE%^There seems to be a pumpkin patch near here.%^RESET%^");
  // this makes sure a reset() won't undo this stuff
  room->set_no_clean(1);
  message("broadcast",
    "%^ORANGE%^Pumpkins have been spotted in Tirun Orchard!%^RESET%^",
    users() );
  /*
  event("start_quest", QUEST_TIME);
  event("close_patch", CLOSE_TIME);
  */
}

void close_patch() {
  object room = load_object(ENTRANCE_ROOM);
  if (!room) return;
  room->set_no_clean(0);
  room->reset();
  message("broadcast",
    "%^ORANGE%^The pumpkin patch has mysteriously vanished.%^RESET%^",
    users() );
}

void start_quest() {
  object room = load_object(QUEST_ROOM);
  if (!room) return;
  room->set_no_clean(1);
  new(H2K7MOBS"shade")->move(room);
  new(H2K7MOBS"trappedspirit")->move(room);
  message("broadcast",
    "%^BOLD%^%^BLUE%^A cold chill descends over the pumpkin patch.%^RESET%^",
    users() );
  call_out("check_shade", 60, room );
}

void check_shade(object room) {
  if (!room || present("halloween shade", room))
    message("broadcast",
      "%^BOLD%^%^BLUE%^Fiendish laughter echoes from the north of the "
      "pumpkin patch.%^RESET%^", users() );
}

void place_random(object ob) {
  string *files;
  string f;
  object room;
  if (!ob) return;
  files = get_dir(H2K7ROOMS+"room*.c");
  f = files[random(sizeof(files))];
  if (!(room = load_object(H2K7ROOMS+f))) return;
  ob->move(room);
}

void do_reminder() {
  message("broadcast", "%^ORANGE%^"
    "A voice calls out faintly from the pumpkin patch:%^RESET%^ "
    "Please let me out...", users() );
  call_out("do_reminder", 60*30);
}
void stop_reminder() { remove_call_out("do_reminder"); }

