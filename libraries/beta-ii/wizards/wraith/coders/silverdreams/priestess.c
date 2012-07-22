#include <std.h>
#include <wedding.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("The Priestess");
   set_short("The Priestess");
   set_id(({"monster", "priestess"}));
   set_long("the priestess is a short woman with brown hair and eyes "
"that penetrate into your soul.  She is dressed in white robes with a golden "
"belt that brushes the floor.  Her hair is braided at the sides and the back is "
"left to flow free.");
   set_level(55+random(10));
   set("aggressive", 0);
   set_gender("female");
   set_race("human");
   set_heart_beat(1);
   set_class("fighter");
   set_subclass("warrior");
   set_body_type("human");


}

void catch_tell(string str) {
    object ob;
    string a, b;

    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%senters the circle and kneels%s", a, b) == 2) {
        this_object()->force_me("emote watches from behind a pavilion as the female escort wraps a robe around her shoulders and kneels beside her.  The male kneels beside Wraith.");
        return;
    }
    if(sscanf(str, "%skneels in front of the alter%s", a, b) == 2) {
        this_object()->force_me("emote enters, holding high a crystal chalice.  She intones, 'Great "
"Mother, we are gathered here in your sight to witness the bond between two "
"who love one another.  Let peace reign in our hearts so that we might find "
"peace and love.'");
        return;
    }
    if(sscanf(str, "%sPeace and love.%s", a, b) == 2) {
        this_object()->force_me("emote and the crowd responds: Peace and love."
"\n\n\n\n\n\n\n\n The priestess fills the chalice with red wine and asks for Delthia's and "
"Wraith's hands.  She takes the dagger and pierces the index finger of both and drops in "
"two drops for each. She then lifts the chalice up and asks for the blessings of the goddess and "
"Mannon.  The chalice  is then held to Wraith's lips.  She says, 'Will you drink this cup in the full "
"knowledge that this binds you to Delthia more tightly than any other that you have "
"ever known?'");
        return;
    }

    if(sscanf(str, "%sI vow to love and honor Delthia%s", a, b) == 2) {
        this_object()->force_me("emote tilts the cup for Wraith to drink.  He drinks and she turns the cup to "
"Delthis and puts it to her lips. 'Will you drink this cup in the full knowledge "
"that this binds you to Wraith more tightly to the grave and beyond?'");
        return;
    }

    if(sscanf(str, "%sYes.%s", a, b) == 2) {
        this_object()->force_me("emote tilts the cup for her to drink and sets the cup aside.  She says, "
"'We, who are here today in the sight of the goddess and Mannon, do witness "
"the promises you have given one another.  I wish blessings and long life on "
"you both.  Please stand and bow to circle and alter.'");
        return;
    }

    if(sscanf(str, "%sThank you.%s", a, b) == 2) {
        this_object()->force_me("emote watches as both Wraith and Delthia stand and bow to the alter and circle of "
"protection. They exit the circle, married in an old druidic style.");
        return;
    }
}
