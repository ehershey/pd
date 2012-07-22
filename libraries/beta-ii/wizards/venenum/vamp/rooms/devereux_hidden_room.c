#include <std.h>
#include <venenum.h>
inherit ROOM;

int open, page;
string *pages = ({"The cover of this book reads, 'The Journal of Johnathon Devereux'.", 
  "<severeal pages have been carefully removed from this section>", 
  "children appeared to enjoy themselves. Particularly little Michael; he loved the cake which the maid's replacement had prepared. All in all, the picnic was an outstanding success!",
  "Femmeday, 3rd of Ransidal- Our maid, Anne, has finally returned back to work after a stretch with the pox. The source of her illness is not known, however, she appears to have made a full ",
  "recovery and is now enjoying her time back at work. Fortunately for us all her infection was not passed along to the children, nor myself or Diane, but still. It was a close call. Dinner ",
  "tonight was a delicious surloin steak with a side of oysters and a delicate salad. The oysters however were not quite fresh and I believe that the salesman who sold them to Pierre the cook ",
  "was definately peddling poor quality wares. I shall see what can be done about this in the morning.",
  "Jauntday, 4th of Ransidal- I investigated the man who was selling oysters and forced him to confess to his foul deed. In actual fact he was about to escape the city, but for my ",
  "intervention he his now languishing in the town jail. This should serve as a warning to all those who would follow his example and attempt to poison upstanding citizens such as my family.",
  "Glintday, 6th of Ransidal- Today is the worst day of my life. My loving wife, whom I have loved from the moment I set eyes upon her, has died inexplicably in the night. I am certain, ",
  "*certain* that the cause was the those foul oysters, but none of the rest of the family have been affected. Nevertheless, I pray to the Gods every night that they take her soul and deliver",
  "it to it's well earned rest. My poor wife, why di <there are several water stains at the base of this page which have smudged the remainder of the writing into irrecognition>",
  "Whenever- Things no longer matter to me anymore. Time slips by with no meaning. I have sent the children away to stay with my faithful servant in Roston. I cannot bear to let them see me in ",
  "my state of weakness. I do not remember how long it has been since I even saw the sun.",
  "Day unknown- Something strange happened to me tonight. I do not know how to begin to describe it, but I shall endevor to try. A person, clothed entirely in black with thick cloth covering",
  "every inch of his or her body, came to my door. This person spoke in a shadowy, hissing, unearthly voice- they demanded to be let inside immediately, seeming incapable of physically ", 
  "entering the building until I had granted my express permission. He or she seemed to know my house completely, giving rise to my growing suspition that I have for some period been under ", 
  "observation. I cannot explain this feeling only to say that it exists. Once he or she had him or herself settled she began to explain to me a proposition, a proposition which was interesting ",
  "to say the least. He or she claimed to be a member of an ancient order of necromancers- mages who deal in the spirits of the deceased- and made the obscene promise of being able to raise ",
  "my wife from the fallen! I was outraged- but still... could it be worth a try? I do not know.",
  "The person said he or she will return tomorrow night and ask for my answer. I do not want that person to fleace me of my most precious belongings so I had them secured in the safe. Tomorrow ",
  "shall bring interesting events, I believe... I will write here if I come upon a decision before the dawn's light.",
  "Adeum- I have decided. When this person returns, I will tell him or her that I will accept his or help. What do I have to loose except a little gold?",
  "Day unknown- The strange person returned to my home, just after dusk, as promised. I said that I would accept the offer, in exchange for knowing a few simple things- whom would be doing me ", "this service, the organization the person belonged to and how much exactly this was going to cost me. I said that money was no object, but I would not have a leech attaching itself to me, ",
  "draining my funds while providing me with nothing but false promises. I said that the return of my wife was more important to me then anything in the world, but I would bear no fraudsters.",
  "At this point, something shocking happened- the person pulled back the thick hood on their head... it was my wife, Diane! I was shocked beyond all reason. I nearly passed out. When I ",
  "had regained my senses I ran to give her a tight embrace, but she pushed me back. Confused, I asked her why- she explained. She had not died of any natural cause that night. The sickness ",
  "which had claimed her was far from natural... she did not know what it was. She was walking back from buying the oysters when she was lept upon by some man- an impossibly strong man- who",
  "held her down, silencing her screams with a huge hand. He bit her neck, draining her blood, sucking out her very life- or at least, he would have done, had he not been interupted by the ",
  "presense of a town guard walking his rounds. She only received a minor bite and was able to hide it under the garmet she wore that night. The guard never found either of them, but ",
  "<the remaining pages have been torn out forcefully>"
});

void create() {
    ::create();
    set_short("Dark Room");
    set_long("This cramped, dark room is tucked in below the study. The walls here are solid brick, covered in slime and mold. There is little of note here, apart from a book resting on a pedestal in the centre of this tiny room.");
    set_smell("default", "The scent of freshly tilled earth is strong here.");
    set_listen("default", "This place is eerily quiet.");
    set_properties(([
	"light" : 0,
	"night light" : -1,
      ]));
    set_items(([
	({"book"}) : "This large book appears to have suffered a large amount of damage over the years but should still be readable, although it is closed right now and will need to be opened.",
      ]));
    set_exits(([
	"up" : ROOMS"devereux_study.c",
      ]));
}

void init() 
{
    ::init();
    add_action("open", "open");
    add_action("turn", "turn");
    add_action("read", "read");
}

int open(str)

{
    if(str == "book")
    {
	write("You open the book.");
	message("room message", this_player()->query_cap_name()+" opens the book.", this_object(), this_player());
	open = 1;
	return 1;
    }
    else
    {
	write("Syntax: <open book>, <read page>, <turn page>, <turn back>.");
    }
    return 0;
}

int turn(str)

{
    if(str == "page" && open == 1 && page < sizeof(pages)-1)
    {
	write("You turn the page.");
	message("room message", this_player()->query_cap_name()+" turns the book foward a page.", this_object(), this_player());
	page++;
	return 1;
    }

    if(str == "back" && page > 0 && open == 1)
    {
	write("You turn back a page.");
	message("room message", this_player()->query_cap_name()+" turns the book back a page.", this_object(), this_player());
	page--;
	return 1;
    }
    else if (page == 0 && open == 1)
    {
	write("You are at the front.");
	return 1;
    }
    return 0;
}

int read(str)

{
    if (str == "book" && open == 1)
    {
	message("reading", pages[page], this_object());
	message("room message", this_player()->query_cap_name()+" reads a page of the book.", this_object(), this_player());
	return 1;
    }
}

