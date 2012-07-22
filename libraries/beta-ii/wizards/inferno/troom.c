#include <std.h>
#define TOWERSIZE 100
inherit ROOM;

int towernum;
int query_tower();
int int_array(int x, int *array);
void set_tower(int x);
string query_long();

static string *descs = ({
"The tower stretches high into the sky, passing even the highest clouds.",
"Stairs spiral around the tower, leading high into the sky.",
"The stairs are a dark black with a silver stripe down the middle of the steps.",
"Through a window the large expanse of the clouds and sky stretch across the sky.",
"A stained glass window is in the southern wall. The window depicts some "
"strange occult rituals.",
"A large stained glass window takes up the entire northern wall. The "
"window shows black clouds against a starry night. Bats are flying about "
"outside.",
"A bat hangs upside down from a window on the western wall. The bat lies "
"so still it seems almost dead.",
"The world seems so small from this height it looks like a child's model "
"of some sort.",
"People far below this point look smaller than dwarves and their "
"features can't be made out.",
"The jet black steps twist around and around higher and higher towards "
"a spacy nothingness.",
"The surrounding peoples have many different names for the tower, all "
"of them evil. From Soulbane to Mind Wrencher, the names begin to make "
"sense.",
"The walls range from midnight blue to a deep black.",
"Snakes have been crudley painted and drawn all over the walls.",
"Strange and evil creatures, some standing over dead paladins and "
"knights, have been scribbled on the walls.",
"Drops of blood hang suspended in midair much like water is in very "
"humid places.",
"Strange bird-like shapes flutter around in the penetrating shadows.",
"Voices can be heard echoing from wall to wall, bouncing up and down "
"the tower, making it impossible to discern where they are comming from.",
"A low, evil sounding, laugh seems to be comming from the circular "
"walls of this room.",
"Voices can be heard, it sounds as if they come from somebody just a "
"short while up these stairs.",
"An evil feeling lingers in the air, as if a heavy shadow holds you "
"down, it is so strong.",
"Darkness fills the room, swirling up and down the stairs, engulfing "
"everything.",
"Visions of strange monsters, flame, and other strange hallucinations "
"appear then suddenly disapear.",
"There are two black stained glass windows in this room, one on the "
"eastern side of the tower and one on the western side. Both windows "
"are far too dark to see out of, and the light that come through them "
"is tinted a dark grey.",
"A heavy mist fills the room, like a thick fog.",
"A chokingly thick crimson mist lingers in the room.",
"A glowing silvery white sphere sits in the center of the room, but "
"every time you try to look directly at it, the sphere disapears.",
"You feel as though you are being watched.",
"Half-way invisible eyes begin to form in midair and on the walls, "
"watching the room.",
"A low humming noise can be heard, but the direction which it is comming "
"from cannot be guessed.",
"A low voiced cackling and laughing can be heard.",
"Mists and shadows flicker and dance about the walls.",
"An eerie howling echos through out the tower.",
"The tower is always dark as night, strange shadows fall where none "
"should be.",
"Death hangs heavily in the air.",
"A deep shadow falls across your face.",
"The tower has a great sense of evil about it.",
"The little light that manages to enter this tower is dim and unholy.",
"An unholy aura fills the room, sending darkness across the lands.",
"Night has decended within the tower and all life cowers before the "
"strange unholy wrath.",
"Olde holy and unholy symbols have been scrawled into the walls.",
"Strange glyphs on the walls depict a brutal sacrificial murder.",
"The tower stretches high into the limits of heavens, the largest "
"beacon to evil in the realms.",
"A strange inscription has been carved into the wall in a language that "
"you do not recongnize. It reads: 'Darkon sette il tak shal.'",
"Blood has been poured all over the ground.",
"Blood curtling screams pierce the air every few minutes.",
"Somebody can be heard screaming in great pain, probably from some "
"exotic form of torture.",
});

void create() {
 int i, x, *all = ({ });
 string long;
 ::create();
   set_properties(([
     "light" : 2, "night light" : 1, "indoors" : 1
   ]));
   switch (random(20)) {
     case 1:
       set_short("Within the tower of all evils");
       break;
     case 2:
       set_short("In a great tower");
       break;
     case 3:
       set_short("Inside the tower of night");
       break;
     case 4:
       set_short("In a huge black tower");
       break;
     case 5:
       set_short("Inside a monsterous tower");
       break;
     case 6:
       set_short("The tower of evil");
       break;
     case 7:
       set_short("The tower of night");
       break;
     case 8:
       set_short("Inside of a large tower");
       break;
     case 9:
       set_short("The great tower of darkness");
       break;
     case 10:
       set_short("The tower, Blackheart");
       break;
     case 11:
       set_short("The tower, Soul Breaker");
       break;
     case 12:
       set_short("The tower, Mind Wrencher");
       break;
     case 13:
       set_short("The tower, Life Bane");
       break;
     case 14:
       set_short("The tower, Light Bane");
       break;
     case 15:
       set_short("The night spiral tower");
       break;
     case 16:
       set_short("A huge tower");
       break;
     case 17:
       set_short("Climbing the black stairs");
       break;
     case 18:
       set_short("Scaling the black tower");
       break;
     case 19:
       set_short("Inside of a large tower");
       break;
     case 20:
       set_short("High in the sky");
       break;
     default:
       set_short("Within the tower of all evils");
   }
   x = random(4) + 1;
   if (x <= 1) x = 2;
   long = "";
   while (x--) {
     i = random(sizeof(descs));
    while (int_array(i, all) >= 1) {
       i = random(sizeof(descs));
     }
     long += descs[i] + " ";
     all += ({ i });
   }
   set_long(long);
}

int int_array(int x, int *array) {
   int i, result = 0;
   i = sizeof(array);
   while (i--) {
     if (array[i] == x) result++;
   }
   return result;
}

int query_tower() { return towernum; }

void set_tower(int x) { towernum = x; }

int try_it(string str) {
   write("Your ability to look into the next room is prevented by means "
     "of the twisting stairs.");
   return 1;
}

void init() {
 ::init();
   add_action("try_it", "peer");
   if (towernum >= TOWERSIZE) return;
   if (this_object()->query_exit("up") != "/d/standard/void") {
     message("info", this_object()->query_exit("up"), this_player());
     return;
   }
   this_object()->create_tower();
}

int create_tower() {
   object o;
   if (towernum >= TOWERSIZE) return 0;
   o = new("/wizards/inferno/troom");
   o->add_exit( file_name(this_object()), "down");
   o->set_tower(towernum + 1);
   this_object()->add_exit(file_name(o), "up");
   "/wizards/inferno/tracker"->add_tower(o);
   return 1;
}
