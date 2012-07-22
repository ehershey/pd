#include <std.h>

inherit VIRTUALSERVER;

void create() {
    ::create();
    set_how_long(4);
    set_day_sentances( ({
	"%^GREEN%^The %^BOLD%^%^BLACK%^f%^WHITE%^o%^BLACK%^g%^RESET%^%^GREEN%^ covers the forest causing visibility to appear milky, as if peering through a liquid haze.%^RESET%^",
	"%^GREEN%^Large creatures can be heard crashing through the underbrush, their footfalls causing slight tremors in the forest floor.%^RESET%^",
	"%^GREEN%^The forest opens up into a grove of ancient elm trees.%^RESET%^",
	"%^GREEN%^This appears to be one of many such areas littered around the forest.%^RESET%^",
	"%^GREEN%^The trail leads deeper into the forest.%^RESET%^",
	"%^GREEN%^Dense clouds of fog lay heavy in the air draping over bush, branch and fern.%^RESET%^",
	"%^RED%^A sense of dread emanates from within the forest.%^RESET%^",
	"%^GREEN%^The trail follows one of the many streams of %^RED%^bo%^BOLD%^%^RED%^il%^RESET%^%^RED%^in%^BOLD%^%^RED%^g b%^RESET%^%^RED%^lo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d %^GREEN%^found in this creepy forest.%^RESET%^",
	"%^GREEN%^Whispers fill the air, seemingly coming from the trees themselves.%^RESET%^",
	"%^GREEN%^A foreboding forest trail, blanketed in a %^BOLD%^%^BLACK%^bl%^MAGENTA%^a%^BLACK%^ck %^MAGENTA%^v%^BLACK%^el%^MAGENTA%^ve%^BLACK%^t %^MAGENTA%^s%^BLACK%^k%^MAGENTA%^y%^RESET%^%^GREEN%^.%^RESET%^",
	"%^RED%^A stream of blood meanders down a sloping hill.%^RESET%^",
	"%^GREEN%^A wolf howls in the distance, calling to its' pack.%^RESET%^",
	"%^BOLD%^%^BLACK%^Black willow trees%^RESET%^%^GREEN%^ line the stream, their roots gnarled and bent.%^RESET%^",
	"%^GREEN%^Cracks in the bark of these willow trees ooze %^RED%^blood %^GREEN%^and a pitiful weeping can be heard in the air.%^RESET%^",
	"%^GREEN%^Pools of %^BOLD%^%^BLACK%^st%^CYAN%^ea%^BLACK%^m%^CYAN%^i%^BLACK%^ng b%^CYAN%^l%^BLACK%^ac%^CYAN%^k %^BLACK%^l%^CYAN%^i%^BLACK%^qu%^CYAN%^id%^RESET%^%^GREEN%^ hidden by the dense undergrowth of the forest serve to trap those who are unwary.%^RESET%^",
	"%^GREEN%^The %^BOLD%^%^BLACK%^f%^WHITE%^o%^BLACK%^g%^RESET%^%^GREEN%^ covers the forest causing visibility to appear milky, as if peering through a liquid haze. %^BOLD%^%^YELLOW%^S%^ORANGE%^tr%^MAGENTA%^a%^WHITE%^ng%^YELLOW%^e %^ORANGE%^b%^MAGENTA%^er%^WHITE%^r%^YELLOW%^ie%^ORANGE%^s%^RESET%^%^GREEN%^ grow in the dense tangle insects to them in clouds of fluttering wings.%^RESET%^",
	"%^GREEN%^High above the forest canopy, scavenger birds circle in the air.%^RESET%^",
	"%^GREEN%^Heaped beneath these berry plants lay bodies of creatures drawn to this luminous fruit.%^RESET%^",
	"%^GREEN%^The %^BOLD%^%^BLACK%^sh%^WHITE%^ad%^BLACK%^ow%^WHITE%^s%^RESET%^%^GREEN%^ move and sway as if possessed by some sentient being.%^RESET%^",
	"%^GREEN%^Some of the plants common to this forest appear to have large mouth like orafices.%^RESET%^",
	"%^GREEN%^Cuddly does not exist in this place, foaming mouths filled with jagged teeth that rip and tear at flesh are what the lone traveler is bound to encounter here.%^RESET%^",
	"%^GREEN%^To them, it is always night...and who knows what lurks in the %^BOLD%^%^BLACK%^sh%^WHITE%^ad%^BLACK%^ow%^WHITE%^s%^RESET%^%^GREEN%^ mere inches beyond the edge of the trail.%^RESET%^",
	"%^GREEN%^The smell of cooking flesh fills the air.%^RESET%^",
	"%^GREEN%^Small drifs of %^WHITE%^snow %^GREEN%^is piled against the trees in various spots.%^RESET%^",
	"%^GREEN%^The cold here is enough to numb unprotected extremities.%^RESET%^",
	"%^GREEN%^A few of the trees have %^WHITE%^snow %^GREEN%^piled upon thier branchs.%^RESET%^"
      }) );
    set_night_sentances( ({
	"%^GREEN%^The %^BOLD%^%^BLACK%^f%^WHITE%^o%^BLACK%^g%^RESET%^%^GREEN%^ covers the forest causing visibility to appear milky, as if peering through a liquid haze.%^RESET%^",
	"%^GREEN%^Large creatures can be heardcrashing through the underbrush, their footfalls causing slight tremors in the forest floor.%^RESET%^",
	"%^GREEN%^The forest opens up into a grove of ancient elm trees.%^RESET%^",
	"%^GREEN%^This appears to be one of many such areas littered around the forest.%^RESET%^",
	"%^GREEN%^The trail leads deeper into the forest.%^RESET%^",
	"%^GREEN%^Dense clouds of fog lay heavy in the air draping over bush, branch and fern.%^RESET%^",
	"%^RED%^A sense of dread emanates from within the forest.%^RESET%^",
	"%^GREEN%^The trail follows one of the many streams of %^RED%^bo%^BOLD%^%^RED%^il%^RESET%^%^RED%^in%^BOLD%^%^RED%^g b%^RESET%^%^RED%^lo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d %^GREEN%^found in this creepy forest.%^RESET%^",
	"%^GREEN%^Whispers fill the air, seemingly coming from the trees themselves.%^RESET%^",
	"%^GREEN%^A foreboding forest trail, blanketed in a %^BOLD%^%^BLACK%^bl%^MAGENTA%^a%^BLACK%^ck %^MAGENTA%^v%^BLACK%^el%^MAGENTA%^ve%^BLACK%^t %^MAGENTA%^s%^BLACK%^k%^MAGENTA%^y%^RESET%^%^GREEN%^.%^RESET%^",
	"%^RED%^A stream of blood meanders down a sloping hill.%^RESET%^",
	"%^GREEN%^A wolf howls in the distance, calling to its' pack.%^RESET%^",
	"%^BOLD%^%^BLACK%^Black willow trees%^RESET%^%^GREEN%^ line the stream, their roots gnarled and bent.%^RESET%^",
	"%^GREEN%^Cracks in the bark of these willow trees ooze %^RED%^blood %^GREEN%^and a pitiful weeping can be heard in the air.%^RESET%^",
	"%^GREEN%^Pools of %^BOLD%^%^BLACK%^st%^CYAN%^ea%^BLACK%^m%^CYAN%^i%^BLACK%^ng b%^CYAN%^l%^BLACK%^ac%^CYAN%^k %^BLACK%^l%^CYAN%^i%^BLACK%^qu%^CYAN%^id%^RESET%^%^GREEN%^ hidden by the dense undergrowth of the forest serve to trap those who are unwary.%^RESET%^",
	"%^GREEN%^The %^BOLD%^%^BLACK%^f%^WHITE%^o%^BLACK%^g%^RESET%^%^GREEN%^ covers the forest causing visibility to appear milky, as if peering through a liquid haze. %^BOLD%^%^YELLOW%^S%^ORANGE%^tr%^MAGENTA%^a%^WHITE%^ng%^YELLOW%^e %^ORANGE%^b%^MAGENTA%^er%^WHITE%^r%^YELLOW%^ie%^ORANGE%^s%^RESET%^%^GREEN%^ grow in the dense tangle insects to them in clouds of fluttering wings.%^RESET%^",
	"%^GREEN%^High above the forest canopy, scavenger birds circle in the air.%^RESET%^",
	"%^GREEN%^Heaped beneath these berry plants lay bodies of creatures drawn to this luminous fruit.%^RESET%^",
	"%^GREEN%^The %^BOLD%^%^BLACK%^sh%^WHITE%^ad%^BLACK%^ow%^WHITE%^s%^RESET%^%^GREEN%^ move and sway as if possessed by some sentient being.%^RESET%^",
	"%^GREEN%^Some of the plants common to this forest appear to have large mouth like orafices.%^RESET%^",
	"%^GREEN%^Cuddly does not exist in this place, foaming mouths filled with jagged teeth that rip and tear at flesh are what the lone traveler is bound to encounter here.%^RESET%^",
	"%^GREEN%^To them, it is always night...and who knows what lurks in the %^BOLD%^%^BLACK%^sh%^WHITE%^ad%^BLACK%^ow%^WHITE%^s%^RESET%^%^GREEN%^ mere inches beyond the edge of the trail.%^RESET%^",
	"%^GREEN%^The smell of cooking flesh fills the air.%^RESET%^",
	"%^GREEN%^Small drifs of %^WHITE%^snow %^GREEN%^is piled against the trees in various spots.%^RESET%^",
	"%^GREEN%^The cold here is enough to numb unprotected extremities.%^RESET%^",
	"%^GREEN%^A few of the trees have %^WHITE%^snow %^GREEN%^piled upon thier branchs.%^RESET%^"
      }) );
    set_item_list( ([
	"trees" : "Black willow Trees.",
	"sky" : "Black velvet sky.",
	"blood" : "Deep Red Blood.",
	"berries" : "Very Strange Berries.",
	"stream" : "A Stream made of blood.",     
	({"snow", "drift"}) : "Small amounts of snow piled up."
      ]) );
    set_smell("The smell of cooking flesh fills the air.");
    set_listen("Howling can be heard in the distance, trees crack, leaves rustle.");
    set_reset_list( ({
	"/wizards/detach/forbiden/mon/1",
	"/wizards/detach/forbiden/mon/2",
	"/wizards/detach/forbiden/mon/3",
	"/wizards/detach/forbiden/mon/4",
	"/wizards/detach/forbiden/mon/5",
	"/wizards/detach/forbiden/mon/6",
	"/wizards/detach/forbiden/mon/7",
	"/wizards/detach/forbiden/mon/8",
	"/wizards/detach/forbiden/mon/9",
	"/wizards/detach/forbiden/mon/hunter",
	"/wizards/detach/forbiden/mon/member"
      }) );
    set_properties( ([ "light" : 1,
	"outdoors" : 1,
	"no teleport" : 1,
	"forest": 1,
      ]) );
    set_short("The forbidden forest.");
}
