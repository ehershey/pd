#include <security.h>
inherit ARMOUR;

string names="";
string owner = "tsuke";
string dir = "/wizards/helena/save/sigil.c";
string desc = "%^BOLD%^%^BLACK%^Crafted from pure light, these translucent wings form a cover for the wings of the Arch-Angels. This particular set was hand crafted by a nameless armour for the mighty Arch-Angel Tsuke.\n %^BOLD%^%^BLACK%^ Each feather on ethereal wings has a glowing angelic %^CYAN%^sigil%^BLACK%^ crafted upon it, glowing with light of righteousness. Each is unique, representing a sinner sent to face final judgement by Tsuke's hands. \n \n %^BOLD%^%^BLACK%^Of all the sigils present, they are all unrecognisable.";
string extralook =  "%^BOLD%^%^BLACK%^Of all the sigils present, they are all unrecognisable.";
string extra_look();

void create() {
    ::create();
    set_name("wings");
    set("id", ({"wings ", "ethereal wings"}) );
    set_short("%^BOLD%^%^WHITE%^E%^BLACK%^t%^WHITE%^h%^BLACK%^er%^WHITE%^e%^BLACK%^a%^WHITE%^l Wi%^BLACK%^n%^WHITE%^gs%^RESET%^");
    set_type("wing armour");
    set_limbs( ({"right wing", "left wing"}) );
    set_heart_beat(1);
    restore_object(dir);
    set_long(desc);
}

int query_auto_load() {
    if(this_player()->query_name() == owner)
	return 1;
}

void heart_beat() 
{
    if (environment(this_object()) != find_player(owner))
    {
	message("say", "%^BOLD%^%^CYAN%^Your %^YELLOW%^golden wings%^CYAN%^ flap their way back into your inventory.", find_player(owner));
	this_object()->move(find_player(owner));
    }
}

void init() 

{
    ::init();
    add_action("reveal", "reveal");
    add_action("conceal", "conceal");
}

int reveal(string str){
    if (str == "") {write("Reveal who?"); return 1;}
    if (names == ""){
	names = "%^CYAN%^" + str; save_object(dir); write("%^BOLD%^%^CYAN%^You reveal the name of your first sinner, "+str+"%^CYAN%^. A bright light glows from your wings and a sigil reveals itself.%^RESET%^"); desc = "%^BOLD%^%^BLACK%^Crafted from pure light, these translucent wings form a cover for the wings of the Arch-Angels. This particular set was hand crafted by a nameless armour for the mighty Arch-Angel Tsuke.\n %^BOLD%^%^BLACK%^ Each feather on ethereal wings has a glowing angelic %^CYAN%^sigil%^BLACK%^ crafted upon it, glowing with light of righteousness. Each is unique, representing a sinner sent to face final judgement by Tsuke's hands. \n \n %^BOLD%^%^BLACK%^Only one of the symbols may be recognised: "+names+"."; extralook = "%^BOLD%^%^BLACK%^Only one of the symbols may be recognised: "+names+"."; set_long(desc); return 1;}
    else {
	names += ", " + str;
	write("%^BOLD%^%^CYAN%^You reveal the name of another sinner, "+str+"%^CYAN%^. A bright light glows from your wings and another sigil reveals itself.%^RESET%^");
	desc = "%^BOLD%^%^BLACK%^Crafted from pure light, these translucent wings form a cover for the wings of the Arch-Angels. This particular set was hand crafted by a nameless armour for the mighty Arch-Angel Tsuke.\n %^BOLD%^%^BLACK%^ Each feather on ethereal wings has a glowing angelic %^CYAN%^sigil%^BLACK%^ crafted upon it, glowing with light of righteousness. Each is unique, representing a sinner sent to face final judgement by Tsuke's hands. \n \n %^BOLD%^%^BLACK%^Of all the sigils present, the following may be recognised: "+names+".";
	extralook = "%^BOLD%^%^BLACK%^Of all the sigils present, the following may be recognised: "+names+".";
	set_long(desc);
	seteuid(UID_CRESAVE);
	seteuid(geteuid());
	save_object(dir);
	return 1;
    }
}

int drop() { return 1; }

int get() { return 1; }

int give() { return 1; }

string extra_look() {return extralook+"\n";}

int conceal(){write("%^BOLD%^%^BLACK%^You conceal your %^CYAN%^sigils%^BLACK%^ once more."); extralook = "%^BOLD%^%^BLACK%^Of all the sigils present, they are all unrecognisable."; desc = "%^BOLD%^%^BLACK%^Crafted from pure light, these translucent wings form a cover for the wings of the Arch-Angels. This particular set was hand crafted by a nameless armour for the mighty Arch-Angel Tsuke.\n %^BOLD%^%^BLACK%^ Each feather on ethereal wings has a glowing angelic %^CYAN%^sigil%^BLACK%^ crafted upon it, glowing with light of righteousness. Each is unique, representing a sinner sent to face final judgement by Tsuke's hands. \n \n %^BOLD%^%^BLACK%^Of all the sigils present, they are all unrecognisable."; names=""; set_long(desc); return 1;}

