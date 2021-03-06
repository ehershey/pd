//      /d/standard/setter.c
//      Starting room for new characters choosing races
//      from the Nightmare Mudlib
//      created by Shadowwolf@Nightmare july 1992
//      modified by Descartes of Borg for the race daemon 10 june 1993
#include <std.h>
#include <rooms.h>
#include <daemons.h>
#include <tirun.h>
inherit ROOM;
void do_rolls();
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_property("no attack", 1);
    set_property("no map", 1);
    set("long",
      "You are in a small box of both infinite and no dimensions. "
      "%^BOLD%^%^BLACK%^Reality is black and without material.%^RESET%^ "
      "You are being created. You intuit a list of possible races you "
      "might become, and even read it. Once you pick your race, you can "
      "begin your journey through the reality of %^BOLD%^%^RED%^Primal Darkness%^RESET%^! "
      "\n\nType %^BOLD%^%^CYAN%^<read list> %^RESET%^to see the list of races.\n"
"\nWhen you are ready to pick a race, type %^BOLD%^%^CYAN%^<pick %^BLUE%^[race desired]%^CYAN%^>%^RESET%^."
"\n\n%^BOLD%^%^RED%^!IMPORTANT!%^RESET%^ - Please be sure to read %^BOLD%^%^CYAN%^<help rules>%^RESET%^ and%^BOLD%^%^CYAN%^ <help name policy>%^RESET%^ before proceeding!");
    skip_obvious();
    set_items(
      (["room" : "The nothingness from which you will be born "
	"into Primal Darkness.",
	"list" : "A list of races that exist in the world of Primal Darkness."]) );
}
void init() {
    ::init();
    add_action("recall", "recall");
    add_action("read", "read");
    add_action("pick","pick");
    if (this_player()->query_exp() != 0) {
	write("\nWelcome to %^BLUE%^P%^BOLD%^rimal %^RESET%^%^BLUE%^D%^BOLD%^arkness%^RESET%^!\n"
	  "Please choose a race for yourself.  Your race determines your main "
	  "attributes: strength, intelligence, dexterity, constitution, wisdom "
	  "and charisma.");
	this_player()->set_rolls(0);
    }
}
int recall(string str) {
    return 1;
}
int pick(string str) {
    string classs;
    classs = "child";
    if(!str) {
	write("To pick a race, type <pick [whatever]>, where whatever is the race.");
	return 1;
    }
    str = lower_case(str);
    if(member_array(str, (string *)RACE_D->query_new_player_races()) == -1) {
	write("You must pick a race from the list!\nType <read list>\n");
	return 1;
    }
    if (member_array(this_player()->query_gender(), RACE_D->query_genders(str)) == -1) {
      write("You must be "+list(RACE_D->query_genders(str), 0, "or")+
          " to be "+indefinite_article(str)+"!\nPlease pick again.");
      return 1;
    }
    this_player()->set_race(str);
    this_player()->new_body();
    this_player()->set_class(classs);
    if( (string)this_player()->query_gender() == "male") this_player()->setenv("TITLE", "Newbie $N the boy");
    else this_player()->setenv("TITLE", "Newbie $N the girl");
    this_player()->init_skills(classs);
    write("You may reroll your stats in the hall of the class you will soon choose.");
    do_rolls();
    write("You awake in a strange place ready to begin your life anew...");
    switch(str) {
    case "raknid":
	new(ARM"raknidarmour")->move(this_player());
	new(ARM"helmet")->move(this_player());
	new(WEP"sword")->move(this_player());
	new(OBJ"newbieguide")->move(this_player());
	break;
    case "centaur":
	new(ARM"centaurblanket")->move(this_player());
	new(ARM"breastplate")->move(this_player());
	new(ARM"helmet")->move(this_player());
	new(OBJ"newbieguide")->move(this_player());
	break;
    case "weimic":
	new(ARM"weimicblanket")->move(this_player());
	new(ARM"breastplate")->move(this_player());
	new(ARM"helmet")->move(this_player());
	new(OBJ"newbieguide")->move(this_player());
	break;
    case "minotaur":
	new(ARM"breastplate")->move(this_player());
	new(ARM"helmet")->move(this_player());
	new(OBJ"newbieguide")->move(this_player());
	break;
    default:
	new(ARM"boots")->move(this_player());
	new(ARM"chainmail")->move(this_player());
	new(ARM"helmet")->move(this_player());
	new(OBJ"newbieguide")->move(this_player());
    }
    this_player()->add_hp(this_player()->query_max_hp());
    this_player()->add_sp(this_player()->query_max_sp());
    this_player()->add_mp(this_player()->query_max_mp());
    this_player()->add_money("gold", 600);
    this_player()->move_player(ROOM_START);
    write("%^BOLD%^%^RED%^The town guard tells you:%^RESET%^ Welcome to Primal Darkness. The first thing you should do"
      " is check out the faq and help rules. I notice you do not have a weapon, you should"
      " go see Rejik the peddler in the next room and say list weapons to him. He thinks we"
      " do not know he sells weapons but the guards know most everything that goes on in"
      " Tirun. If you need any help that is not in the faq or help files try asking your"
      " question on the newbie line, I am sure one of the fine people of this realm would be"
      " happy to help you. Have a great time and Happy Mudding!");
    return 1;
}
void do_rolls() {
    string *which;
    mapping borg;
    int i, tmp;
    write("You roll your stats.");
    for(i=0, tmp=sizeof(which=keys(borg=(mapping)RACE_D->do_rolls((string)this_player()->query("race")))); i<tmp; i++) 
	this_player()->set_stats(which[i], borg[which[i]]);
    this_player()->force_me("stats");
    return;
}
int read(string str) {
    if(!str) {
	notify_fail("\nWhat do you want to read? A list?\n");
	return 0;
    }
    if(str != "list") {
	notify_fail("\nThat is not here to be read.\n");
	return 0;
    }
    write("\nThese are the following races available for you to pick:");
    write("%^BOLD%^%^CYAN%^-----------------------------------------------------------%^RESET%^");
    message("Ninfo", format_page((string *)sort_array(RACE_D->query_new_player_races(), 1), 4),
      this_player());
    write("%^BOLD%^%^CYAN%^----------------------------------------------------------%^RESET%^");
    write("Only females may be nymphs.");
    write("pick %^BOLD%^%^CYAN%^<race>%^RESET%^ will forever make you one "
      "of these races. Type %^BOLD%^%^CYAN%^<help races>%^RESET%^ for "
      "more information. Type %^BOLD%^%^CYAN%^<ansi on>%^RESET%^ to "
      "view a world of colors!\n");
    write("Type %^BOLD%^%^CYAN%^help <racename>%^RESET%^ for more information. Remember to replace <racename> with the race you wish to have help on.");
    return 1;
}
