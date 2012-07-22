#include <std.h>
#include <venenum.h>
inherit ROOM;

int drank;

void create() {
    ::create();
    set_short("Deep within the Mausoleum");
    set_long("This passageway heads off to the south, ending to the north. A bowl rests upon a simple pedestal stands here, full to the brim with a dark red liquid.");
    set_smell("default", "A faint coppery smell can be found here.");
    set_listen("default", "You can hear the distant sound of dripping water.");
    set_items(([
	({"bowl"}) : "The bowl is filled up the very top with an unknown red liquid. It smells somewhat like copper.",
	({"liquid", "red liquid"}) : "The liquid looks suspiciously like blood.",
      ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
	"no teleport" : 1,
	"indoors" : 1,
	"outdoors" : 0,
      ]));
    set_exits(([
	"south" : ROOMS"tportpassaged.c",
      ]));
}

void init() 

{
    ::init();
    add_action("drink", "drink");
    add_action("take_coin", "take");

}

int drink(string str)

{
    if(str != "from bowl") { return 0; }

    if (this_player()->query_race() == "dragon")
    {
	write("You dip your muzzle down and lap from the bowl.");
	message("drink", this_player()->query_cap_name()+" dips "+this_player()->query_possessive()+" muzzle into the bowl, lapping from the liquid.", this_object(), this_player());
	call_out("failed",10);
    }
    else if (this_player()->query_race() == "demon")
    {
	write("You dip your scarred hands into the bowl, cup some of the liquid and bring it to your lips.");
	message("drink", this_player()->query_cap_name()+" dips "+this_player()->query_possessive()+" scarred hands into the liquid, cupping it and bringing it to "+this_player()->query_possessive()+" lips.", this_object(), this_player());
	call_out("failed",10);
    }
    else if (this_player()->query_race() == "archangel")
    {
	write("You dip your blessed and pure hands down, cup some of the liquid and bring it to your lips. The moment you touch the liquid, your body is wracked in spasms. Dark energy flows over you, then you pass out.");
	message("drink", this_player()->query_cap_name()+" dips "+this_player()->query_possessive()+" blessed and pure hands into the liquid, cupping it and bringing it to "+this_player()->query_possessive()+" lips.", this_object(), this_player());
	this_player()->set_paralyzed(100, "Your body is wracked with terrible pain.");
	message("drink", this_player()->query_cap_name()+" collapses, twitching and spasming furiously. "+this_player()->query_cap_possessive()+" body fades away into mist.", this_object(), this_player());
	this_player()->move("/d/tirun/square");
	message("square", this_player()->query_cap_name()+"'s body appears from a cloud of mist, scorched and spasming horribly.", this_object(), this_player());
    }
    else if (this_player()->query_race() == "lich")
    {
	write("You dip your boney hands into the bowl, cup some of the liquid and bring it to your lips.");
	call_out("failed",10);
    }
    else if (this_player()->query_race() == "sauran" || this_player()->query_race() == "weimic" || this_player()->query_race() == "raknid")
    {
	write("You dip your claws into the bowl, cup some of the liquid and bring it to your lips.");
	call_out("grasp2",10);
    }
    else if (this_player()->query_race() == "bastet")
    {
	write("You dip your paws into the bowl, cup some of the liquid and bring it to your lips.");
	call_out("grasp2",10);
    }
    else
    {
	write("You dip your hands into the bowl, cup some of the liquid and bring it to your lips.");
	call_out("grasp2",10);
    }
    return 1;
}

int failed()
{
    write("A slight tingling sensation runs down your spine.");
}

int grasp2()
{
    write("A soft sound is heard inside your mind, like the whisper of the gently moving wind.");
    call_out("grasp3",10);
}

int grasp3()
{
    write("All goes quiet.");
    call_out("grasp4",10);
}

int grasp4()
{
    write("The voice comes again. It almost appears to be saying something, then it is unintelligable again.");
    call_out("grasp5",10);
}

int grasp5()
{
    write("Words appear in your mind. '%^BOLD%^...lair...%^RESET%^' '%^BOLD%^...husband...%^RESET%^' '%^BOLD%^...found...%^RESET%^'");
    call_out("grasp6",10);
}

int grasp6()
{
    write("Suddenly, a hissing voice fills your head. '%^BOLD%^So, husband, you see me at last- or hear me, at least. I will be blunt; leave now. There is nothing here for you. I am hidden deep within the earth, far beyond your grasp. Your quest to exterminate me will fail.%^RESET%^' Then, it is gone and all is quiet. Mysteriously, the blood in the bowl has disappeared, to be replaced with a single coin.");
    write("With a snap-hiss of crackling energy, a glowing green portal comes into being.");
    set_long("This passageway heads off to the south, ending to the north. A bowl rests upon a simple pedestal stands here, a single gold coin resting at the centre. A glowing green portal stands just to one side.");
    set_smell("default", "The room smells of ozone.");
    set_listen("default", "You can hear the distant sound of dripping water.");
    set_items(([
	({"bowl"}) : "The bowl is empty save for a single coin resting at the bottom.",
	({"coin"}) : "This coin is a one-Isteus coin, a currency which hasn't been employed for over a thousand years.",
	({"portal"}) : "This portal's swirling green depths lead to places unknown.",
      ]));
    drank = 1;
    add_exit(ROOMS"tomb.c","portal");
    return 1;
}

int take_coin(string str)
{
    if(str != "coin" && drank != 1) { return 0; }
    write("You take the coin from the bowl.");
    set_long("This passageway heads off to the south, ending to the north. A bowl rests upon a simple pedestal stands here, completely empty. A glowing green portal stands just to one side.");
    set_smell("default", "The room smells of ozone.");
    set_listen("default", "You can hear the distant sound of dripping water.");
    set_items(([
	({"bowl"}) : "The bowl is empty.",
	({"portal"}) : "This portal's swirling green depths lead to places unknown.",
      ]));
    new(ITEM"coin.c")->move(this_player());
    drank = 2;    
    return 1;
}
