//Aziraphale


inherit ROOM;
object oi;
void create()  {
   ::create();
     set_properties(([ "light" : 2, "sky" : 1, "no teleport" : 1]));
     set_short("Azira's Room");
     set_long("This is the room of Amarael. Bathe ye all in the pleasure of my general proximity.");
     set_exits(([ 
                ]));
     set_items(([
                "rug"           : "The rug has been woven into an intricate pattern that seems to shift and rearrange itself while you are not looking. This truely must be a treasure.",
                "maps"          : "The maps have been woven from an extremely fine material and look very lifelike. They show the lands of Tirun, Tenebrae, Lodos, Arlon, Roston, Merkkerri, Helgrath, Dunsinane, Purgatory and Rhondale.",
        ]));
oi = new("/std/bboard");
oi->set_name("Area Board");
oi->set_id( ({ "board" }) );
oi->set_board_id("Area_Board");
oi->set_max_posts(20);
oi->set_edit_ok(({ "amarael", "stormbringer" }));
oi->set_location("/wizards/amarael/workroom.c");
oi->set("short", "%^BOLD%^GREEN%^HOLY FREAKING PUPIKACHU%^RESET%^");
oi->set("long", "info on areas I am making dot com\n");
}

void init() {
     object pra, tp;
   ::init();
     tp = this_player();
     if(tp->query_name() != "amarael" && wizardp(tp)) {
       if(pra = find_living("amarael"))
         tell_object(pra, "\n%^BOLD%^CYAN%^"+tp->query_cap_name()+" has entered your room.%^RESET%^\n");
     }
}

void reset() {
    ::reset();
    if (!present("box"))
        new("/wizards/seeker/box")->move(this_object());
  if (!present("portal"))
      new("/wizards/stormbringer/portal")->move(this_object());
}
