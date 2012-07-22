#include <std.h>
inherit OBJECT;
static void create()
{
 set_name("newspaper");
 set_short("The Tirun Times");
 set_long("This is the local player run paper. Type read for more instruction.");
 set_id( ({ "newspaper", "paper", "tirun times", "times" }) );
 set_mass(1);
 set_value(1);
}
void init()
{
 ::init();
 add_action("read", "read");
}
int read(string str)
{
 
 if (!str || (str!="Azzy" && str!="azzy" && str!="vamp" && str!="editor" && str!="sugarlove" && str!="letter" &&  
str!="contest"))
   {
    message("info", 
"The Tirun Times is a paper ran by the players of Primal Darkness. "
"All opinions, content, and stories are the opinion of those whom "
"wrote them and do not express the opinion of the PD staff. The PD "
"staff takes no responsibility for anything written here in and the "
"Pd staff reserves the right to make any changes.\n\n" 
"%^CYAN%^%^BOLD%^[ Table of Contents ]%^RESET%^\n"
" %^CYAN%^<read Azzy>%^RESET%^     Azzy's Corner... A new feature from our favorite Dragon.\n"
" %^CYAN%^<read vamp>%^RESET%^     Vampira Talks... And it's up to you to listen\n"
" %^CYAN%^<read editor>%^RESET%^   From the Editor... A weekly look into my insanity\n"
" %^CYAN%^<read sugarlove>%^RESET%^Dear Sugarlove... Love advice by Sugarcandy\n"
" %^CYAN%^<read letter>%^RESET%^   Letters to the editor...\n"
" %^CYAN%^<read contest>%^RESET%^  Popularity Contest... Who is the coolest cat around?\n"
,this_player());
   }
 if (str=="Azzy" || str == "azzy")
   {
write( @EndText
                                 Azzy's Corner
                                 By Azire
With my new position as Script Archon, I thought it would be appropriate if
for my first edition of 'Azzy's Corner' to be one of my favorite poems. This
is an excerpt from Lord Byron's "Stanzas for Music". Enjoy! 
1       There be none of Beauty's daughters
2         With a magic like thee;
3     And like music on the waters
4         Is thy sweet voice to me:
5     When, as if its sound were causing
6     The charmed ocean's pausing,
7     The waves lie still and gleaming,
8     And the lull'd winds seem dreaming:
9       And the midnight moon is weaving
10       Her bright chain o'er the deep;
11   Whose breast is gently heaving,
12       As an infant's asleep:
13   So the spirit bows before thee,
14   To listen and adore thee;
15   With a full but soft emotion,
16   Like the swell of Summer's ocean. 
Original Text: Byron, Works, 17 vols. (London: John Murray, 1832-33). PR 4351
M6 1832 ROBA. George Gordon, lord Byron, Hebrew Melodies (London: J. Murray,
1815). B-10 3742 Fisher Rare Book Library (Toronto).
EndText );
}
if (str=="vamp")
  {
write( @EndText
                        Vampira Talks
                        By: Vampira   
(Editors note: Despite my own personal feelings about the 
subject contained within, this is not my work, nor has it been 
influenced (directly or indirectly) by me in any way at all. 
As long as it contains no profanity or other such no-no's, 
I will publish any article from my regular writers.  
Any feelings about anyone from a person who is not on staff can be
submitted via a letter to the editor or as a freelance work.  
I reserve the right to begin rejecting negative pieces if I
feel the paper is turning into a name calling contest.)
 
 The Idiotic Dragon
      I got the idea for this article, when I was reading the Tirun
board. I had been sick for awhile, and when I returned, the board was
filled with almost 30 posts about a certain dragon. Talking about
how he is as some put it, annoying, childish, and immature. I believe
that in some ways these things are true. Because if he really wanted to
be the bigger person in his "situations" he should ignore them, but
instead he persistently argues on a childish level about some of them
most idiot things I have ever heard. No, I do not think it is all his
fault, some people just don't have to patience to deal with people like
this certain dragon. But, these certain persons also argue with him. 
Most of these people are older, and if they are as mature as they
say they are, they should also ignore him. It may not be that easy, but
it is possible. In my opinion this dragon can get annoying sometimes,
but so does everyone, including myself. He is immature in some ways,
and does have a strong childish nature to himself, which in some ways,
gets very annoying. But, instead of getting totally annoyed and blowing
up at him, you should remember the childish nature that has, most 
children are like that, and do not know when to stop. To return to my
opening sentence, the board was filled with nearly 30 posts about him,
most of them having a negative view to him, was in my opinion, a little
extreme. He is only one person, it is childish to let him have that 
much of an effect on you. He may be annoying and childish, but no 
person is worth getting that worked up over. To this certain dragon,
I do not have just negative views toward you, and I apologize if I have
hurt your feelings in any way.
Vampira.
EndText );
  }
if (str=="editor")
  {
write( @EndText 
                            
                                THE TICKLE WAR!
                                By: Hermes
(Editors Note: I've been a bit busy as of late, so I'm re-running the same
article.  Next edition will feature a different one.)
Tirun-
As tensions escalate between the two factions, crowds huddle in fear from the
fight that is going on above their homes.  The tickle war between the demons
and the angels is heating up, and no one feels safe. "It's just horrible
living here these days! At any moment you could be caught in the middle of
either side and... and... tickled!" cries on resident before
promptly being tickled by rogue angel Hermes. Indeed, this war of ticklition
has already had many causalities, the worst from
the apparent mutiny by several of the angels and the insanity of a few demons.
Both of these deserters now wonder the street, tickling people at random with
such brute efficiency that many fear to leave their homes. Demon Seth, when
asked for an interview, declared his intent to avenge the tickle of his
beloved slave wench Cookie and take revenge on the angel Hermes. From the
other side of the fence, a distraught Endbringer mooed sadly, rubbing
his wings and almost shaking from his recent tickle assault by two demons who
ambushed him.
Truly, this is a horrid war that the world will not forget.
EndText );
    return 1;
  }
if (str=="sugarlove")
  {
write( @EndText
Dear Sugarlove,
There is this sexy, hot, cute spider paladin that's been wondering 
around Tirun as of late. The only problem is she likes women! 
I desperately want her but I'm a guy... what can I do?!?
Sincerely,
Forlorn
 
-------------------------------------------------------------------------------
 
Dear Forlorn,
Two words.. "snip snip"  If you really want her badly enough you'll do
anything to make her happy, however I would suggest you taking a look at other
options within the realm.  There has to be at least one single, straight,
natural girl out there.  If not.. I hear Hermes is looking for new playthings.
After the last edition uncovering all those awful truths about him I'm sure
he'll take just about anyone.
Good luck to you,
Sugarlove
EndText );
  }
if (str=="letter")
  {
write( @EndText
                        LETTERS TO THE EDITOR
 
(When sending a letter to the editor, please mudmail Hermes with the subject: Letters - <Your subject>) 
Why people kill - from: Flash 
I believe that the reasons people kill is simply no more than:
#1 They want to tell all their friends they were stronger or more cunning than
someone and killed them.
#2 They want the exhilaration of the hunt.
#3 They want experience, and MOBS no longer hold any excitement for them.
#4 They want money or items that the person has.
Or, The most common:
#5 They deeply and intensely hate someone, so they want to kill them over and
over until the person loses heart and quits. 
                 
The Paper is lame - from: Lac 
(Editors note: Lac, your piece sent my spell check into melt down so I^Rm just printing it without modification)\n\n
k, i think that the paper was lame :/
ffs, there wasnt even a centerfold in it :p
and as for Autema, what the heck was he on about? what a waste of space he is.
my opinion on Pk, it should be bought back, as it added another element to the
game.
i know that some ppl have stopped playing here because of the Pk ban :/
and what do you get out of it..? the pk shakes and the strutness of it all ;)
   
(Editors note: I didn't know quite what to do with this one so I'm printing it without modification)
from: Venenum 
<The paper is brown and tattered as though many years old. There is a message
scrawled on it, in what looks to be ash or charcol. The handwriting is
appalingly bad, and extremely messy, as though the message was scrawled with a
stick instead of being written by a fluent quill. It is first written in
Dragonian, and then again in Selunian.> 
Ja'fgezppfew kj morrtilreezzr! Gewa wre'ddzz mowaf'dd'gezeeel hhzittbill'in
ka'dr fezzzurriel kilzttain' fa dofew. Ziltarra jr'rroz je Venenum ja Crimson,
gzzrattion feez kozeeltain! Frr'ftzorrtain, Guardians wtazz fewilzz nnmei'n.
Ka'zantiel fortranne kal torro. 
Public attention all Adventurer! Staying away mountains deep home you must.
Slow dying come if enter you do. Snow home to <incomprehensible> the Red, no
enter else cold body ice in snow! Ma-<incomprehensible>ze will you. Stealers
eatened on site.
<There is a small, indistinguishable drawing on the bottom of the page, but it
cannot be made out and could just be a smudge.
   
No activity - from: Prator
The past week has been the period with the LEAST amount activity from all admins ever.`This also comes at a time when there are two areas waiting to be checked and added to the realm. Bad luck
huh.

 *** Prator ***
[Admin note: Considering that one area had work left to be done and the other area was not even on the builders port, (I recieved a message from Loki stating he was almost finished) we will say that no matter what is ready on builders, areas are added when there is time, atfer there have been several walkthroughs by the staff, and when we find a place to connect them. As for idleness of the Staff, everyone who is a member of the PD Staff have real lives as well, families, friends, jobs, etc. they have to contend with. Everyone has things to do and players complaining about idleness does nothing but make the staff want to idle more, just so our point gets across, this is a private mud we build for the pleasure of others on our own time table, not anyone elses. -Stormy]
EndText );
   }
if (str=="contest")
  {
write( @EndText                                Who is the one we all love?
A few months ago, this paper sponsored a popularity contest to see who was 
the most loved in all of Primal Darkness.  
The winner was obvious, who else could be loved by so many people more then
our very own Azire?  But after Azire there were some other people and the
results will be now shown (Minus one omission at the request of the player)
Azire = 5
Hermes = 3
Ashram = 4
Stormbringer = 1
Flash = 1
Cookie = 1
EndText );
   }
 return 1;
}
