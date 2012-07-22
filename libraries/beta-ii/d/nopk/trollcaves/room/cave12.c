// There appears to be an issue with this code. 
// The prisoner, when saved, produces a bug 
// message when removed; I'm not sure if this is
// actually a real bug or just something to do
// with builder's port as the prisoner does 
// indeed vanish when the rescue int is called.

#include <std.h>
#include <sakura.h>
inherit ROOM;

int increment=10;

int rescue_fmv();

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("Here the tunnel comes to an end with a large bulge, something which was probably a cesspool for water in days gone past but is now, apparently, used as a residence. Several torches line the walls here, the smoke chanelled up through the many holes in the ceiling. There is a large and heavily bloodstained oaken table resting to the south side of the room, and a heavy oak or yew chair resting to the far eastern side. To the north side lies a small kitchen, complete with stoves and cooking pots. One of the cooking pots has a partially-skeleton human hand poking out.");
    set_smell("default", "The rancid stench of rotting meat is incredible.");
    set_listen("default", "The cooking pot simmers quietly.");
    set_items(([
	({"table"}) : "This table has huge gashes across it's surface, apparently from a sword or some kind of large knife. In it's morbid state it resembles a carving table at a butcher's.",
	({"torch", "torches"}) : "The light these torches give is only faint, but it is more then enough to see by in these darkened conditions. The smoke is vented through the series of holes in the roof.",
	({"chair"}) : "It looks expensive. Or, rather, that it would be if you could get the blood off it.",
	({"pot"}) : "Your standard black cooking pot, large. However, a large human hand can be seen within.",
	({"arm", "hand", "skeleton"}) : "It's definately human. It could have been here for at least a day, stewing away. Looks almost ready."
      ]));
    set_properties(([
	"light" : -1,
	"night light" : -2,
      ]));
    set_exits(([
	"west" : ROOMS"cave11.c",
      ]));
}

void reset() {
    if(!present("troll"))
    {
	new(MOB"troll.c")->move(this_object());
	new(MOB"troll.c")->move(this_object());
	new(MOB"troll.c")->move(this_object());
    }
    if(!present("balzina"))
    {
	new(MOB"balzina.c")->move(this_object());
    }
    if(!present("prisoner"))
    {
	new(MOB"prisoner.c")->move(this_object());
    }
}

int receive_objects()
{  

    object ob = previous_object();

   if(this_player())
    this_player()->set("watching_fmv", 1);
    if(ob && userp(ob))
	call_out("start_fmv", 1, ob);
    //        tell_room( this_object(), ob->query_name() +"\n");
    return ::receive_objects(ob);
}


int start_fmv() 
{

    if (!this_player()) return 0;
    if (this_player()->query_current_attacker() == 0 && this_player()->query("watching_fmv") != 0 && present(this_player()) && present("troll") && present("balzina"))
    {
	this_player()->set_paralyzed(40, "Shh, they'll hear you!");
	message("info", "The sound of gleeful cackling over painful moans is heard. Balzina is here, and with her troll lackeys she is torturing a prisoner, prodding him with a red hot poker. So intent on her work is she that she doesn't notice you enter.", this_player());
	message("say", "%^CYAN%^Prisoner exclaims:%^RESET%^ Ahhrg...! ahh...!", this_player());
	message("say", "Balzina has a red hot poker in one hand and is using the other to cut the prisoner's skin with her claws.", this_player());
	message("info", "\n", this_player());

	call_out("fmv1",increment);
    }
    else
    {
	this_player()->set("watching_fmv", 0);
    }
}

int fmv1() {

    if (!this_player()) return 0;
    if (this_player()->query_current_attacker() == 0 && this_player()->query("watching_fmv") != 0 && present(this_player()) && present("troll") && present("balzina"))
    {
	message("say", "Balzina waves the hot poker around the prisoner's face teasingly for a moment, before burning his cheek with the glowing tip.", this_player());
	message("say", "%^CYAN%^Prisoner exclaims:%^RESET%^ No...! No! AAAAAAAAHHHHH!", this_player());
	message("say", "%^CYAN%^Balzina exclaims:%^RESET%^ What's that? More? Baaaahahahhaa!", this_player());
	message("info", "\n", this_player());

	call_out("fmv2",increment);
    }
    else
    {
	this_player()->set("watching_fmv", 0);
    }
}

int fmv2() {

    if (!this_player()) return 0;
    if (this_player()->query_current_attacker() == 0 && this_player()->query("watching_fmv") != 0 && present(this_player()) && present("troll") && present("balzina"))
    {

	message("say", "One of the other troll spits in the prisoner's face. The spit hisses as it touches the burn.", this_player());
	message("say", "%^CYAN%^Troll exclaims:%^RESET%^ We killed your companion, the stupid one with the broken sword, and we ate your priest fellow... you're next, don't you worry!", this_player());
	message("say", "The troll emits an evil cackle.", this_object());
	message("say", "%^CYAN%^Balzina exclaims: %^RESET%^Yeah! I hope you taste half as good as he did, we'll have ourselves a feast!", this_player());
	message("info", "\n", this_player());

	call_out("fmv3",increment);
    }
    else
    {
	this_player()->set("watching_fmv", 0);
    }
}

int fmv3() {

    if (!this_player()) return 0;
    if (this_player()->query_current_attacker() == 0 && this_player()->query("watching_fmv") != 0 && present(this_player()) && present("troll") && present("balzina"))
    {

	message("say", "The prisoner snarls through his tears of pain.", this_player());
	message("say", "%^CYAN%^Prisoner says: %^RESET%^Just get it over with already! I'm not afraid of death.", this_player());
	message("say", "Another of the trolls sniggers.", this_player());
	message("say", "%^CYAN%^Balzina exclaims:%^RESET%^ But we're not finished having fun with you just yet, hehehe!", this_player());
	message("info", "\n", this_player());

	call_out("fmv4",increment);
    }
    else
    {
	this_player()->set("watching_fmv", 3);
    }
}

int fmv4() {

    if (!this_player()) return 0;
    if (this_player()->query_current_attacker() == 0 && this_player()->query("watching_fmv") != 0 && present(this_player()) && present("troll") && present("balzina"))
    {

	message("say", "Balzina pauses, sniffing.", this_player());
	message("say", "%^CYAN%^Troll asks: %^RESET%^What's wrong, mistress?", this_player());
	message("say", "Balzina suddenly looks in your direction.", this_object());
	message("say", "%^CYAN%^Balzina exclaims: %^RESET%^Intruders! Ah-hah, more stock for the soup! Get 'em boys!", this_player());

	present("balzina")->force_me("kill "+this_player()->query_name());

	this_player()->set("watching_fmv", 0);

	return 1;
    }
}



void init() 

{
    ::init();
    add_action("rescue", "rescue");

}

int rescue( string str )

{
    if(!str) { return notify_fail("Uh, rescue whom?"); }
    if(str == "prisoner") { return rescue_fmv(); }
}

int rescue_fmv()
{

    if(!present("prisoner")) {
	return notify_fail("Uh, rescue whom?");
    }

    if(present("troll") || present("balzina")) {
	return notify_fail("You really have to kill the trolls before you can save the guy.");
    }

    message("info", "With the trolls soundly dispatched you untie the prisoner.", this_object());
    present("prisoner")->force_me("say Thank you, stranger. You have my gratitude. These horrid beasts killed my companions, ate Mui my priest and they were going to eat me too... if you are ever in Minori, drop in and see my family, the Tenshi's. They're sure to reward you!");
    message("info", "The prisoner bows towards you rather formally, then scampers out of the cave.", this_object());
    if(present("prisoner"))
    {
	present("prisoner")->move("/d/nopk/standard/void.c");
    }
    if(!this_player()->set_mini_quest("Samurai Soup", 5000, "You dispatched Balzina the Troll Butcher and her troll minions, saving Moshi Tenshi from being made into samurai soup.\n"));
    return 1;
}
