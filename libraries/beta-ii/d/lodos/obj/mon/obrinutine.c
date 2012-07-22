#include <std.h>
#include <lodos.h>
inherit MONSTER;

static int counting = 0;
static int time = 0;
int query_time();
void start_timer();
void stop_timer();

int query_time() { return time; }

void start_timer() {
   time = 0;
   counting = 1;
}

void stop_timer() {
   time = 0;
   counting = 0;
}

void heart_beat() {
 ::heart_beat();
   if (counting) {
     if (time > 999) { time = 999; counting = 0; }
     time++;
   }
}

void create() {
 ::create();
   set_name("obrinutine");
   set_short("a tall dark man");
   set_long("The tall, dark mediteranian man stands here, never really "
     "moving. He wears a long, grey cloak and a top hat. He leans on an "
     "antique wooden cane. The tall man has jet black hair and soft brown "
     "eyes. His face is kind, though generally bored. He holds a stop "
     "watch in one hand. The man's name is Obrinutine. You can ask him to "
     "<explain rules> for the obstacle course.");
   set_id(({ "man", "oby", "obby", "obrinutine", "tall man", "dark man" }));
   set_level(1);
   set_race("human");
   set_body_type("human");
   set_gender("male");
   set_heart_beat(1);
}
