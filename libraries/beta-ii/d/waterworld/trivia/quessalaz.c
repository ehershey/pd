#include <std.h>
#include <waterworld.h>
#include <security.h>
inherit "std/barkeep";

mapping quiz_track;
#define ANSWER 2
#define QUESTION 1
#define INDEX 0

void give_question(string pname);
void check_answer(string pname, string what);
void check_up(string pname);
void ambrosia_routine(string pname);
int list_prizes();

string immort;
void create()   {
    ::create();
    set_name("quessalaz");
    set_id(({"quessalaz","tourtoise","turtle"}));
    set_short("Quessalaz, the ancient sea turtle");
    set_long("This is the ancient sea turtle, Quessalaz."
      " He is a complete master of all informantion about his home around him, Tirun's Barrier Reef."
      " If you wish to pass this gate-keeper, You will have to answer his questions."
      "\n\n The commands are as follows;"
      "\n\n     1) Tell quessalaz next question please"
      "\n\n     2) Tell quessalaz the answer is _____"
    );
    set_level(200);
    set_body_type("fish");
    set_gender("male");
    set_race("turtle");
    set_class("fighter");
    set_subclass("warrior");
    quiz_track=([]);
    set_emotes(3,({
	"Quessalaz shifts through his record books to find some adventurer's status with him.",
	"Quessalaz works out on his 'Buff-o-matic' for awhile.",
	"Quessalaz looks you over slowly, snorts softly and goes to his books.",
	"Quessalaz lays in his bed of seagrass and slowly begins to dine.",
	"Quessalaz grumbles that to many pursue power over knowledge....",
	"Quessalaz appears to be totally zoned out on his 'Speedy Tourtoise'..."
      }),0);
}
//////////////////////////////////////
void catch_tell(string recieved)
{
    string pname;
    string what;
    if(!sizeof(quiz_track)) {
	restore_object("/wizards/ironman/waterworld/trivia/save/records.o");
    }
    ////// questions
    if(sscanf(recieved,"%s tells you: next question please",pname)==1)
    {
	call_out("give_question",2,pname);
	return;
    }
    ////  answers
    else if(sscanf(recieved,"%s tells you: the answer is %s",pname,what)==2)
    {
	call_out("check_answer",2,pname,what);
	return;
    }


}
//////////////////////////////////////////

void check_answer(string pname, string what)
{
    pname=lower_case(pname);
    if(!find_player(pname)) {return;}
    if(!quiz_track[pname] || !quiz_track[pname]["quiz"]) 
    {
	force_me("tell "+pname+"What are you talking about?");
	return;
    }
    if(what !=quiz_track[pname]["quiz"][ANSWER])
    {
	force_me("tell "+pname+" Sorry young one. Ya gotta look around more for that answer is wrong.");
	force_me("tell "+pname+" The question was as follows;\n"+quiz_track[pname]["quiz"][1]);
    }
    else {
	force_me("tell "+pname+" Now thats how ya make an ol' sea turtle proud!! Ya got it right.");
	quiz_track[pname]["quiz"]=0;
	quiz_track[pname]["score"]=(quiz_track[pname]["score"])+1;
	force_me("tell "+pname+" You have answered "+(quiz_track[pname]["score"])+" question(s) correctly for me to date.");
	save_object("/wizards/ironman/waterworld/trivia/save/records");
	if(quiz_track[pname]["score"]==200) {ambrosia_routine(pname); }
    }
    return;

}



/////////////////////////////////////////////////////

void give_question(string pname){
    pname=lower_case(pname);
    if(!find_player(pname)) return;
    if(!present(pname,environment()))   {
	force_me("tell "+pname+" Be polite to an ol' sea turtle youngun'\n  Come visit me if you wish to hear the next question.");
	return; }
    if (!quiz_track[pname]) {quiz_track[pname]=([]);}
    if (!quiz_track[pname]["quiz"]) {
	quiz_track[pname]["quiz"]=TRIVIA"TRIVIA_GAME.c"->trivia_engine();
	force_me("tell "+pname+" The question is as follows;\n"+quiz_track[pname]["quiz"][1]);
	save_object("/wizards/ironman/waterworld/trivia/save/records");
	return; }
    else {
	force_me("tell "+pname+" Now listen youngun'.\n I can only keep track of one question for a person at a time!!");
	force_me("tell "+pname+" You current question is as follows;\n\n"+quiz_track[pname]["quiz"][1]+"\n");
	return; }}
//////////////////////////////////////////////////////

int is_invincible() {
    object tp;

    tp=previous_object();

    message("info","%^GREEN%^Quessalaz%^RESET%^ snorts in your general direction as you approach him!!\n\n The force of the blast %^RED%^%^BOLD%^SLAMS%^ you into the far wall!!\n\n",tp);
    tp->damage(100);
    message("info","%^GREEN%^Quessalaz%^RESET%^ snorts in "+(tp->query_cap_name())+"'s direction!!\n\n They're slammed into the far wall!!",environment(tp),tp);
    force_me("say I'm older then time child..... How would you hope to attack someone such as me??\n\n");
    force_me("emote snorts again and returns to his bed of seagrass...\n\n");

    return 1;
}

/////////////////////////////////////////////////////////
int inquiry(string pname) {
    restore_object("/wizards/ironman/waterworld/trivia/save/records.o");
    if(quiz_track[pname]) {return quiz_track[pname]["score"]; }
    else {return 0;}
}
///////////////////////////////////////////////////////////////
void check_up(string pname) {
    object TP=this_player();
    message("info","%^RED%^%^BOLD%^STATUS REPORT%^RESET%^ for player >> "+pname,TP);
    restore_object("/wizards/ironman/waterworld/trivia/save/records.o");
    if(!quiz_track[pname]) {
	message("info","\n\nI have no records at all for "+pname+".\n\n",TP);
	return;
    }
    if(!quiz_track[pname]["quiz"]) {
	message("info","\n\n"+pname+" has no outstanding question with me at this time.",TP);
	message("info","\n\n"+pname+"'s current score is ----"+(quiz_track[pname]["score"]),TP);
	message("info","\n\n",TP);
	return;
    }
    else {
	message("info","\n%^ORANGE%^%^BOLD%^QUESTION%^RESET%^\n"+(quiz_track[pname]["quiz"][1]),TP);
	message("info","\n%^ORANGE%^%^BOLD%^ANSWER%^RESET%^\n"+(quiz_track[pname]["quiz"][2]),TP);
	message("info","\n%^ORANGE%^%^BOLD%^SCORE%^RESET%^\n"+(quiz_track[pname]["score"]),TP);
	message("info","\n\n",TP);
    }
}

///////////////////////////////////////////////////////////////
void give_credit(string pname) {
    object TP=this_player();
    string cap_tp=TP->query_cap_name();
    restore_object("/wizards/ironman/waterworld/trivia/save/records.o");

    if(!quiz_track[pname]) {
	message("info","\n\n%^GREEN%^%^BOLD%^I will not credit a player i have no records for..\nThe report is as follows...\n\n%^RESET%^",TP);

	check_up(pname);
	return;
    }
    else if(!quiz_track[pname]["quiz"]) {
	message("info","\n\n%^ORANGE%^No credit issued for "+pname+"!!\n\nThey have no outstanding question with me...\nHere's the report....\n\n",TP);
	check_up(pname);
	return;
    }
    else {

	quiz_track[pname]["quiz"]=0;
	quiz_track[pname]["score"]=quiz_track[pname]["score"]+1;
	message("info","\n\n%^CYAN%^Question wiped out and credit given to "+pname+"\n\n%^RESET%^",TP);
	save_object("/wizards/ironman/waterworld/trivia/save/records");
	check_up(pname);
	return;
    }
}
///////////////////////////////////////////////////////////////////
void remove_player(string pname) {
    object TP=this_player();
    restore_object("/wizards/ironman/waterworld/trivia/save/records.o");
    if(!quiz_track[pname]) message("info","There are no records for "+pname+" in Quessalaz's memory banks..\n\n",TP);
    message("info","\n\n"+pname+"'s records with Quessalaz have been obliterated.....",TP);
    map_delete(quiz_track,pname);
    save_object("/wizards/ironman/waterworld/trivia/save/records.o");
}
///////////////////////////////////////////////////////////////////


void ambrosia_routine(string pname) {
    object TP=this_player();
    object grandp=new(PRIZES"ambrosia.c");
    string cap_tp=TP->query_cap_name();

    force_me("tell "+pname+" Congratulations "+cap_tp+", You have gone well above the call of duty to learn this much about our community here on the Tirun reef!!");
    force_me("emote swims over to his books and grabs a vial");
    force_me("tell "+pname+" As a reward, I have given you a vial of our most guarded treasure, the Atlantian Ambrosia !!");

    grandp->move(TP);
    return;
}

///////////////////////////////////////////////////////////////////
void summary_report() {
    object TP=this_player();
    string *membership;
    string pname;
    string trivia;
    mixed OUTPUT;
    int counter;
    int pscore;
    int x;

    restore_object("/wizards/ironman/waterworld/trivia/save/records.o");

    membership=keys(quiz_track);
    membership=sort_array(membership,-1);
    counter=sizeof(quiz_track);
    x=0;

    message("info","%^RED%^%^BOLD%^\n\n              TOTAL MEMBERSHIP SCORES\n\n%^RESET%^",TP);

    message("info","\n       %^CYAN%^PLAYER%^RESET%^       %^YELLOW%^SCORE%^RESET%^     %^GREEN%^Outstanding question?%^RESET%^",TP);
    message("info","\n",TP);
    for(counter;counter>0;counter--) {
	pname=membership[counter-1];
	pscore=quiz_track[pname]["score"];
	trivia=quiz_track[pname]["quiz"] ? "%^BLACK%^%^BOLD%^NO%^RESET%^" : "%^RED%^%^BOLD%^YES%^RESET%^";
	OUTPUT=sprintf("%-20s  %-d               %10s",pname,pscore,trivia);
	message("info",OUTPUT,TP);
    }
    message("info","\n\n",TP);
    return;
}
