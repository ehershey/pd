//  Whit
#include <std.h>
#include <forgotten.h>
#undef OPEN

inherit ROOM;

static string *hold;
static object forsakened;
static int done;
int poison(object);
void create() {
    ::create();
    set_name("library entrance");
    set_short("Library Entrance");
    set_long("A large stone door stands to the south preventing "
      "any access to the rooms beyond.  The tunnels continue to the "
      "north further into the deep abyss.  On the door is three "
      "buttons.  A strange writing is upon the door.  Unlike "
      "the writings at the entrace, these are made of characters."
      "  The statue of a large dragon is to the left of the door.");
    set_items(([
	({"writing","strange writing"}):"The writing says: "
	"%^BOLD%^Unquale ana sanga man umin voronda ana kala.",
	({"buttons","button"}):"The buttons have three words on "
	"them.  The language being the same as the writing "
	"on the door.  The buttons are red, blue, and green.",
	"red button":"The red button's writing says: Nuru",
	"blue button":"The blue button's writing says: Losselie",
	"green button":"The green button's writing says: Vanima",
	"dragon":"The dragon is made from stone.",
      ]));
    //   "decode":"Death to those who are faithful to light.",
    /*
     * red = Death
     * green = Proper
     * blue = white people
     */
    set_exits(([
	"north":TUNNELS"159",
      ]));
    hold=({});
}

void init() {
    ::init();
    add_action("push", "push");
    add_action("forsake", "forsake");
    add_action("repeat", "repeat");
}

int push(string str) {
    string a, b, *co;
    co=({ "red","blue","green" });
    if(sscanf(str, "%s %s", a, b)!=2) return 0;
    if(b!="button") return 0;
    if(member_array(a, co) == -1) return 0;

    switch(a) {
    case "red":
	write("As you push the red button, a strange "
	  "warmth washes over your body.  It becomes so hot, "
	  "it singes your flesh off of your bones.");
	say(this_player()->query_cap_name()+" turns pale as "
	  +this_player()->query_possessive()+" skin falls "
	  "from "+this_player()->query_possessive()+" bones.\n");
#ifdef OPEN
	message("death", "%^BOLD%^%^RED%^The demons of the underworld "
	  "seize one of the creators children and drags "+
	  this_player()->query_objective()+" into the "
	  "black abyss of the underworld.\nA flash of "
	  "lightning marks the death of "+this_player()->query_cap_name()+
	  ".", users());
#else
	message("death", "%^BOLD%^%^RED%^The demons of the underworld "
	  "seize one of the creators children and drags "+
	  this_player()->query_objective()+" into the "
	  "black abyss of the underworld.\nA flash of "
	  "lightning marks the death of "+this_player()->query_cap_name()+
	  ".", this_player());
#endif
	write(read_file("/news/ghost")+"\n");
	this_player()->move("/d/nopk/standard/death/death_room");
	break;
    case "blue": 
	hold += ({ this_player()->query_name() });
	poison(this_player());
	break;
    case "green":
	if(!forsakened) return notify_fail("Nothing happens.\n");
	if(!present(forsakened, this_object())) return 
	    notify_fail("Nothing happens.\n");
	if(!present("green_pendant_event", forsakened)) return 
	    notify_fail("Nothing happens.\n");
	message("enironment", "A little crackling sound is heard.  "
	  "With some unseen force, the huge stone door opens.", 
	  this_object());
	this_object()->add_exit("south", LIBRARY"");
	break;
    default: return 0; break;
    }
    return 1;
}

void poison(object ob) {
    write("As you push the blue button, a strange feeling boils from "
      "the pit of your stomach.  You feel quesy and fall to your knees "
      "in suffering.");
    say(ob->query_cap_name()+" falls to "+ob->query_possessive()+" knees "
      "in suffering.");
    add_action("go_dir", ({"north", "south"}) );
    new("/wizards/whit/rooms/gag")->move(this_player());
    this_player()->add_poisoning(40);
    call_out("do_poison_2", 20);
}

void do_poison_2() {
    remove_action( "go_dir", "north");
    remove_action( "go_dir", "south");
    write("The poison subsides to a dull pain.\n");
    hold -= ({ this_player()->query_name() });
    if(present("gag", this_player())) present("gag", this_player())->remove();
}

int go_dir() {
    if(member_array(this_player()->query_name(), hold)==-1) return 0;
    write("The pain of the poison keeps you on the ground.\n");
    return 1;
}

void reset() {
    ::reset();
    if(!present("event_dragon", this_object())) 
	new(MON"dragon")->move(this_object());
}

int forsake(string str) {
    if(!str || str != "the light") return 0;
#ifdef OPEN
    if(!query_night())
	message("event", "The sky starts to churn in the torment of "
	  "of energy.  It starts to get darker around the realms.  It "
	  "becomes impossible for anyone to tell the time of day by "
	  "the sun.", users());
#else
    if(!query_night())
	message("event", "The sky starts to churn in the torment of "
	  "of energy.  It starts to get darker around the realms.  It "
	  "becomes impossible for anyone to tell the time of day by "
	  "the sun.", this_object());
#endif
    message("", "The dragons eyes begin to glow red.\n", this_object());
    this_player()->set_property("forsakened", 1);
    call_out("scene1", 3);
    forsakened=this_player();
    return 1;
}

void scene1() {
    message("", "The dragons eyes seems to glow brighter then before.  "
      "A redish light fills the darkened room.  The statue of "
      "the dragon seems to move a little.  Its mouth opens.\n", this_object());
    call_out("scene2", 9);
}

void scene2() {
    message("", "A deep voice echos through the room from the dragon.\n", this_object());
    call_out("scene3", 4);
}

void scene3() {
    object ob;
    ob=present("event_dragon", this_object());

    ob->force_me("say It seems like some intruders have "
      "finally managed to break the seal of the Door of Light.");
    ob->force_me("say I am the guardian to the Library of "
      "Light that lies beyond the doors of light.");
    call_out("scene4", 17);
}

void scene4() {
    object ob;
    ob=present("event_dragon", this_object());
    ob->force_me("say The Library of Light contains many "
      "spells of evil and good.  Magic in the realms are "
      "different then the magics of this realm.  Here, "
      "magic consists of the elements of the world.  "
      "In the Realm of Light, magic consists of additive "
      "and subtractive.");
    call_out("scene5", 20);
}

void scene5() {
    object ob;
    ob=present("event_dragon", this_object());
    ob->force_me("say In order for anyone to enter the Realm of "
      "Light, to mantain balance to the world, a soul must be "
      "offered.  It seems as if someone here has willing offered "
      "there soul.  "+capitalize(forsakened->query_name())+", "
      "it seems as if you have become the chosen one.  From "
      "now untill eternity, your soul will be cursed.");
    call_out("scene6", 19);
}

void scene6() {
    object ob;
    ob=present("event_dragon", this_object());
    ob->force_me("say The only way for the curse to be removed "
      "is for the problem by which you seek information in the "
      "Library of Light must be solved.");
    call_out("scene7", 20);
}

void scene7() {
    object ob;
    ob=present("event_dragon", this_object());
    ob->force_me("say In order for you to enter the library, "
      "you must do two things.  One is to find a pendant in the "
      "caverns that lead to this room.  By summoning me, the "
      "hidden forces in the caverns have been released.  One of "
      "those forces, has a pendant.  The cursed must wear this "
      "pendant while saying the \"The Chant of Light\".  If you "
      "do not know of this chant, you may aquire it from "
      "Alverest, Keeper of the Forest.  Second you must "
      "beat me.  I will not fight anyone untill the \"The "
      "Chant of Light\" is taken here.");
    call_out("scene8", 20);
}

void scene8() {
    object ob;
    ob=present("event_dragon", this_object());
    ob->force_me("say I have told you all of the information "
      "I can.  You must hurry, the Realm of Light will seal "
      "itself soon.");
    ob->force_me("say I will repeat my story if I am "
      "asked.  Just ask me to <repeat> my story.\n");
    done=1;
}

int repeat(string str) {
    if(!done) return 0;
    if(!str || str!="story") return notify_fail("Repeat what?\n");
    done=0;
    call_out("scene1", 1);
}

