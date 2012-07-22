inherit VAULT;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",1);
  set("short","Palace");
  set("long","This is the bedroom of the King and Queen of Tenebrae.  There "
    "are lots of different pieces of furniture about.  Sofas, chairs, tables are "
    "about the room.  There is a large mirror embedded in the east wall.  "
    "A large, curtained bed fills the room, and looks soft and inviting."
    "  Small candles line the walls, and seem to be always lit, creating a "
    "somewhat dreamy atmosphere.  There is a servant here cleaning up.");
  set_smell("default","The smell of insense and flowers fills the air.");
  set_listen("default","It is fairly quiet here.");
  set_items((["candles":"They haven't melted a bit...  must be lit with magic.",
    "bed":"The enormous bed is covered with many soft blankets and fluffy pillows.",
    "mirror":"The mirror seems to be a large mirror built into the wall from afar, but"
    "upon closer inspection, you realize that your image is not reflected in it!"
    "  You touch the mirror, but no fingerprint is left.  This could only be magic.",
    "furniture":"The furniture is nice and cozy."]));
  set_door("door", ROOMS "palace25.c", "out", "bedroom key");
  set_open("door", 1);
  set_exits((["out":ROOMS "palace25.c"]));
}

void init() {
  ::init();
  add_action("catch_tell","say");
}

void reset() {

  object mon, key;

  ::reset();

  if(!present("servant")) {
    mon = new(MOB "fservant");
    mon->move(this_object());
    key = new(OBJ "key");
    key->move(mon);
  }
}

int catch_tell(string str) {
    object tp;
    string a, b, c;

    if(sscanf(str, "%sower of darkness, come consume me%s", a, b) == 2) {
        if(this_player()->query("teneking")!=1){
          write("You mutter an incantation, but nothing happens.");
          return 1;}
        else{
         if(present("bauble", this_player())){
write("You mutter the incantation.../nThe mirror s%^BOLD%^h%^RESET%^i%^BOLD%^m%^RESET%^m%^BOLD%^e%^RESET%^r%^BOLD%^s%^RESET%^ and a burst of air sucks you into the mirror!");
            this_player()->move_player(ROOMS "palace40.c", "into the mirror");
            return 1;}
          else{
            write("You mutter the incantation and the mirror begins to shimmer.  But it does not last long, as if it needs something to sustain it's power...");
            return 1;
            }
          }
    }
}
