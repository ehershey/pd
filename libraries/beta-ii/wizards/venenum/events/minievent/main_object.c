#include <std.h>
inherit OBJECT;

int counter = 0;

void create() {
    ::create();
    set_name("");
    set_id( ({ "main_quest_object_thingie_woot"}) );
    set_short("");
    set_long("");
    set_mass(100);
    set_prevent_get("You feel confused.");
    set_heart_beat(1);
}


void heart_beat() 
{

    string whole_mud=environment(this_object());

    counter++;
    if (counter == 1) {this_object()->move("/d/nopk/tirun/square");}
    if (counter == 10) {message("nfo","%^BOLD%^%^WHITE%^With a crack of thunder, the sky begins to cloud over inexplicably.%^RESET%^", whole_mud); new("/wizards/venenum/minievent/sasayaki.c")->move(environment(this_object()));}
    if (counter == 20) {message("nfo","%^BOLD%^%^BLACK%^The sky becomes darker and darker, black thunderclouds covering the sky entirely.%^RESET%^", whole_mud);}
    if (counter == 30) {message("nfo","%^BOLD%^%^BLACK%^%^BOLD%^%^BLACK%^A faint drop of %^RED%^crimson%^BLACK%^ blood falls down from the sky. Then another.%^RESET%^", whole_mud);}
    if (counter == 40) {message("nfo","%^BOLD%^%^BLACK%^Soon a light shower of blood falls from the sky, soaking the earth with it's coppery smell.%^RESET%^", whole_mud);}
    if (counter == 50) {message("nfo","%^BOLD%^%^BLACK%^The drops of blood seem to come to life, squirming their way like small snakes towards the centre of Tirun. As they arrive, they join a thick puddle, which slowly takes shape and becomes translucent, forming the body of a dark, demonic figure with bright glowing %^RED%^red%^BLACK%^ pits for eyes.%^RESET%^", whole_mud); new("/wizards/venenum/minievent/asmodeus.c")->move(environment(this_object()));}
    if (counter == 60) {message("nfo","%^BOLD%^%^CYAN%^Sasayaki gasps out aloud, recognising his master. '%^YELLOW%^It cannot be... Asmodeus, my lord!%^CYAN%^'%^RESET%^", whole_mud);}
    if (counter == 70) {message("nfo","%^BOLD%^%^BLUE%^A deep, booming voice echos throughout the land. '%^CYAN%^It is I.%^BLUE%^'.%^RESET%^", whole_mud); present("figure", environment(this_object()))->reveal();}
    if (counter == 80) {message("nfo","%^BOLD%^%^CYAN%^Sasayaki kneels down before the Lord of the Netherworld respectfully. '%^YELLOW%^How can I serve you, my lord?%^CYAN%^'.%^RESET%^", whole_mud);}
    if (counter == 90) {message("nfo","%^BOLD%^%^BLUE%^Asmodeus speaks again. '%^CYAN%^I require a body that I may begin a conquest of the heavens themselves... A demonic body.%^BLUE%^'.%^RESET%^", whole_mud);}
    if (counter == 100) {message("nfo","%^BOLD%^%^CYAN%^Sasayaki bows his head, kneeling still. '%^YELLOW%^My sword and body are yours, my lord.%^CYAN%^'.%^RESET%^", whole_mud);}
    if (counter == 110) {message("nfo","%^BOLD%^%^BLUE%^Asmodeus seems to shimmer, then Sasayaki is engulfed with a bright yellow light. Asmodeus closes his eyes, appearing to enter a trance-like state.%^RESET%^", whole_mud);}
    if (counter == 120) {message("nfo","%^ORANGE%^The faint sound of hollow laughter rings out throughout the land. It seems to be coming from Sasayaki.%^RESET%^", whole_mud);}
    if (counter == 130) {message("nfo","%^BOLD%^%^BLACK%^As the brusied black flesh of thunderstorms swirl over head, Sasayaki's Katana drops to the ground with a metallic tink. He brings himself to his feet, much larger then he was. In his hand appears a blade created of pure lightning. The shadowy form of Asmodeus watches on, his eyes closed.%^RESET%^", whole_mud);}
    if (counter == 140) {message("nfo","%^BOLD%^%^BLUE%^Sasayaki thrusts his lightning blade to the heavens, cackling loudly. '%^CYAN%^Hear me Angelic beings! You shall fall before the forces of the netherworld!%^BLUE%^'%^RESET%^", whole_mud);}
    if (counter == 150) {message("nfo","%^BOLD%^%^BLACK%^Sasayaki flaps his bat-like wings, pulling his giant body into the air. He drags his blade across the sky in a wide arc, causing a rift in the overhead clouds.%^RESET%^", whole_mud);}
    if (counter == 160) {message("nfo","%^ORANGE%^A hurricane-force wind whips from the sword for a second or two, then all is still once more. From just beyond the rift above, a creature tumbles; crimson scales cloaked in flame. A %^RED%^red dragon%^ORANGE%^ spirals down towards the square, his flight clearly upset by the wind.%^RESET%^", whole_mud);}
    if (counter == 170) {message("nfo","%^RED%^The dragon seems about to spear headfirst into the ground, but strains his wings, pulling out of his spin just in time- almost. He clips the fountain with a wing, slamming into the ground hard, rolling and tumbling across the earth, a huge cloud of dirt and dust being thrown up in his wake. He lays still.%^RESET%^", whole_mud); new("/wizards/venenum/minievent/venenum.c")->move(environment(this_object()));}
    if (counter == 180) {message("nfo","%^BOLD%^%^BLUE%^Sasayaki strides over to the fallen dragon casually, each footstep creating a dull thud as it strikes the ground. '%^CYAN%^Foolish creature. The Dragonkin are no match for the powers of the Netherworld.%^BLUE%^'%^RESET%^", whole_mud);}
    if (counter == 190) {message("nfo","%^RED%^The dragon twitches a little, then slowly begins to climb back up to his claws, his eyes flicking open angrily. '%^BOLD%^And who, pray tell, are you?%^RESET%^%^RED%^' He doesn't seem too worse for wear, despite his fearsome crash.%^RESET%^", whole_mud);}
    if (counter == 200) {message("nfo","%^BOLD%^%^BLUE%^Sasayaki stops just in front of the dragon, his lightning blade crackling gently. '%^CYAN%^I am Asmodeus the Demon Lord. And what is your name, wormling?%^BLUE%^'%^RESET%^", whole_mud);}
    if (counter == 210) {message("nfo","%^RED%^The dragon snarls angrily, bearing his sizable canines to the demon. '%^BOLD%^I am Venenum the Red, son of Quex'trilixil the Red.%^RESET%^%^RED%^' He stares down the demonic creature, seeming cautious and guarded but putting on an aggressive show.%^RESET%^", whole_mud); present("dragon", environment(this_object()))->reveal();}
    if (counter == 220) {message("nfo","%^BOLD%^%^BLUE%^Sasayaki simply points the tip of his blade towards Venenum. A bolt of fiece white lighting arcs out towards the creature, racing straight towards him.%^RESET%^", whole_mud);}
    if (counter == 230) {message("nfo","%^RED%^Venenum roars loudly as his body is struck by the force of the lightning. He falls to the ground with a thud, spasming and twitching before fading into silence. A translucent spectre rises up from the body, then is sucked into the sword.%^RESET%^", whole_mud); present("venenum", environment(this_object()))->kill();}
    if (counter == 230) {message("nfo","%^BOLD%^%^BLUE%^Sasayaki bursts into laughter, raising a fist to the air. '%^CYAN%^Even the mighty dragons fall before us? Can nobody stop the master of the Netherworld? Hah! Let them come! Let them all fight me!%^BLUE%^'.%^RESET%^", whole_mud); present("sasayaki", environment(this_object()))->set_killable(); present("sasayaki", environment(this_object()))->force_me("north"); present("asmodeus", environment(this_object()))->force_me("north"); this_object()->remove();}
}
