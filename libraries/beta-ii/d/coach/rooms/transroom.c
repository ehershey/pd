#include <std.h>
#include <coach.h>
inherit ROOM;

int time;

string destination;

void create() {
    ::create();
    set_short("Inside a horse and coach");
    set_long("This small but comfortable coach is just big enough for you. It consists of simply four curved walls and two bench-seats, although there are spacious windows providing ample viewing of the passing area.");
    set_smell("default", "It smells strongly of horses, although some effort has been made to disguise the scent with flowers.");
    set_listen("default", "The creaking and groaning of the cart is heard here.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
	"no magic" : 1,
	"indoors" : 1,
	"outdoors" : 0,
        "no teleport" : 1,
	"no kill" : 1,
      ]));
}

int start_fmv(string str)
{
    write("The cart pulls away from the station at a brisk pace.");
    destination = str;
    switch (destination) {
    case "tirun":
	time = 7;
	call_out("tirun1", time);
	break;
    case "roston":
	time = 17;
	call_out("roston1", time);
	break;
    case "tenebrae":
	time = 12;
	call_out("tenebrae1", time);
	break;
    case "lodos":
	time = 9;
	call_out("lodos1", time);
	break;
    }


}

int tirun1()
{
    write("The coach creaks along the road as it turns towards the city of Tirun.");
    call_out("tirun2", time);
}

int tirun2()
{
    write("The Daroq mountains loom up ahead, their many peaks thrust towards the sky like the teeth of a shark.");
    call_out("tirun3", time);
}

int tirun3()
{
    write("The coach winds between the mountains, inching closer to the city.");
    call_out("tirun4", time);
}

int tirun4()
{
    write("The coach pulls in at the western gate of Tirun and you are politely escorted from your seat.");
    this_player()->move(ROOMS"tirun_coach.c");
    return 1;
}

int lodos1()
{
    write("The driver sings a merry tune as he pilots the cart towards Lodos.");
    call_out("lodos2", time);
}

int lodos2()
{
    write("The forested mountains of Daroq grow larger as the cart winds through mountain passes and rugged terrain.");
    call_out("lodos3", time);
}

int lodos3()
{
    write("The city rises up in one of the valleys, the cart approaching rapidly.");
    call_out("lodos4", time);
}

int lodos4()
{
    write("The coach pulls up outside the gates of Lodos and you are politely escorted from your seat.");
    this_player()->move(ROOMS"lodos_coach.c");
    return 1;
}

int tenebrae1()
{
    write("The driver of the cart bounces in his seat as the cart pulls towards Tenebrae.");
    call_out("tenebrae2", time);
}

int tenebrae2()
{
    write("The dark forest outside Tenebrae approaches all too rapidly, closing in around you like misty fog.");
    call_out("tenebrae3", time);
}

int tenebrae3()
{
    write("The journey through the forest ends quickly when the trees melt away like snow faced with the rising sun.");
    call_out("tenebrae4", time);
}

int tenebrae4()
{
    write("The coach pulls in just outside the city of Tenebrae and you are politely escorted from your seat.");
    this_player()->move(ROOMS"tenebrae_coach.c");
    return 1;
}

int roston1()
{
    write("The cart slowly trundles off towards Roston, wheels creaking slowly all the way, the horses paced to keep them fresh.");
    call_out("roston2", time);
}

int roston2()
{
    write("The cart enters a thick forest. Passage is slow due to the badly developed road and occasional animal blocking the path.");
    call_out("roston3", time);
}

int roston3()
{
    write("Finally the cart leaves the forest, beginning the long climb upwards on a back road towards the city of Roston.");
    call_out("roston4", time);
}

int roston4()
{
    write("The coach pulls in at the edge of Roston and you are politely escorted from your seat.");
    this_player()->move(ROOMS"roston_coach.c");
    return 1;
}
