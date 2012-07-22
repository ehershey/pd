// The Newspaper, by storm
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
 
 if (!str || (str!="interview" && str!="playerkill" && str!="war" && str!="sugarlove" && str!="letter" && str!="about"))
   {
    message("info", 
"The Tirun Times is a paper ran by the players of Primal Darkness. "
"All opinions, content, and stories are the opinion of those whom "
"wrote them and do not express the opinion of the PD staff. The PD "
"staff takes no responsibility for anything written here in and the "
"Pd staff reserves the right to make any changes.\n\n" 
"%^CYAN%^%^BOLD%^[ Table of Contents ]%^RESET%^\n"
" %^CYAN%^<read interview>%^RESET%^  COMING SOON... An interview with Stormbringer.\n"
" %^CYAN%^<read playerkill>%^RESET%^ PLAYER KILLING... The new system\n"
" %^CYAN%^<read war>%^RESET%^        THE TICKLE WAR... The state of the war in PD\n"
" %^CYAN%^<read sugarlove>%^RESET%^  DEAR SUGARLOVE... Love advice by Sugarcandy\n"
" %^CYAN%^<read letter>%^RESET%^     LETTERS TO THE EDITOR...\n"
" %^CYAN%^<read about>%^RESET%^      ABOUT HERMES... An opinion article\n"
,this_player());
   }
 if (str=="interview")
   {
write( @EndText
                                 COMING SOON...
                                 By Leviathas
I recently had the oportunity to have an interview with Stormbringer regarding
a few issues that I know players are very interested in.  Here is the
interview:
 
The sun shines high above this place. Lazy white clouds float by on their
journey to wherever it is that clouds go. Far below, a town can be seen, though
it is much to far to tell what town. This must be the home of Stormbringer, only
he would feel at home this far above the world where storms rule the air. 
Ozone fills your nostrals.
The silence of solitude.
 
Stormbringer grins evily.
Leviathas gasps in astonishment.
 
Stormbringer says:  Welcome to the clouds.
 
Leviathas says:     Well I wasn't expecting this.
 
Leviathas looks down.
Stormbringer smiles happily.
 
Stormbringer says:  Well, I have no time for trapesing around the realms for
                    interviews, better you to come here :)
 
Leviathas says:     As you know, I have some questions for the paper.
 
Stormbringer nods.
 
Stormbringer says:  Ask away :)
 
Leviathas asks:     Ok.  I know a lot of people in Tirun and the surrounding
                    areas have been wondering about the justice system. Can
                    you give us any hints as to what we can expect?
 
Stormbringer says:  sure. We are working on making Justice free areas. What
                    this means is once you enter cretain areas, there is no
                    law to come after you if you kill another player in one
                    of these areas. We are also working on a prison island,
                    once a PKer has been banished there, they may never 
                    return to the rest of the world, the Prison area will
                    also be a law free area. It will have everything needed
                    for exping.
 
Stormbringer asks:  did that make more questions?
 
Stormbringer winks with a sparkle.
 
Leviathas says:     I'm sure the readers will be curious, but they'll just
                    have to keep reading in the future to get more.
 
Stormbringer nods.
 
Leviathas asks:     Another area that a lot of people have been watching with
                    great anticipation:  The quest races.  Can we get a rough
                    estimate as to when we can expect them to all be complete?
 
Stormbringer says:  well, we are planning on Vampires to go in at the first of
                    January, which is phase 2's annivesery. I can't give any
                    more details as it could possibly ruin our plans, but know
                    that vamps will be a completely different kind of race, 
                    something never tried on Pd before. As to the others, they
                    will come after since we are planning them around the 
                    changes we are making for vamps.
 
Leviathas says:     Great.  It's good to know that they haven't been forgotten. 
                    I'm really eager to see them all in action.
 
Stormbringer says:  well, we never forget good ideas, only put them on hold
                    till we get other problems worked out.
 
Leviathas asks:     Are there any new areas in planning or creation stages?
 
Stormbringer says:  yes, there are always things in the planning stages. We
                    have more work than we have workers to complete. That is
                    why some things seem to take so long to get changed or 
                    added to the game, things have to be done in order, bugs
                    and problems first, balance and issues second, fixes and
                    changes to existing areas, then additions to the game. 
                    Mix all that in with having a life outside of PD the 
                    changes and additions can take a long time. There is 
                    plans on a thrid contenent, as large as the one tirun is
                    on. I say third because the second is already in the
                    works (prison island) and it, too, will be about the same
                    size as the Tirun continet. There is also preliminary
                    work being done on different plains of existance, such as
                    hades, elementals, etc. That is all I can say about those
                    though, no need to ruin the surprise.
 
Leviathas asks:     The rich community has been DYING to know: Are there any
                    powerful warriors to your knowledge that are going into
                    the drow mail order bride business?
 
Stormbringer says:  well..... I have heard some gossip, but who am I to start
                    rumours.
 
Leviathas says:     They will be pleased to know. Thank you very much for
                    your time.
 
Stormbringer smiles happily.
 
Leviathas says:     oh wait.
 
Leviathas asks: What is the meaning of life?
Stormbringer says: Primal Darkness calls, dang, sorry we are out of time...
 
Stormbringer winks with a sparkle.
 
As you can see, the avatars have a lot of cool stuff in the works.
EndText );
}
if (str=="playerkill")
  {
write( @EndText
                 PLAYER KILLING - The new system
                       By: Mochaprincess   
              
        As mamy players know, player killing was put on hold 
in early October of 2002. Not very good news for some, but for 
others it was great. It meant that they wouldn't be constantly 
killed, as for the rest it meant they couldn't kill others for awhile.
        Many players who were effected by this, particulary those
who could no longer PK did not take the time to find out
the reason it was banned. In a conversation with Nightshade I found out
about the player killing hold. I am not allowed to reveal why it
was put on hold, but I can say that when the player killing system
is opened again it will be basically the same except for a few changes.
        There will be a new contient specifically open for pk (player-
killing). It will also be used as a sort of prison area for those of
you (no names) who constantly kill others. It will be similar to Tirun
with oil and stone shops, also with the nessessary halls. I'm not sure
of everything that will be there, but as of now that is what I know.
This also includes stealing and killing guards/peacekeepers. So those 
of you who kill them for fun unless you want to be banished to the
new continent I would advise you to stop. Also, for those few people
who like to steal 24/7 I would also advise you not to do that on a 
regular basis.
        I would advise that anyone who does not wish to be freely pked,
to stay off of the continent. I can think of a few people who I know
should stay away from it, unless they just want to be pked. You will
also still be able to pk in Tirun, but not freely. So don't think that
you're totally free from getting pked.  
        As always the players of Primal Darkness have there opinion on
the player killing hold. Some them find it a better thing such as
Endbringer who said, "It's peacefull, I like there being no pk."
There were also those who don't like it, such as Seth, who simply
stated, "It's crap. I like the old system." As always there were those
who just didn't care like Joey, "Ahh it's cool, just wait for pk to
open."
 
EndText );
  }
if (str=="war")
  {
write( @EndText 
                            THE TICKLE WAR!
                              By: Hermes
Tirun-
 As tensions escalate between the two factions, crowds huddle in fear from the
fight that is going on above their homes.  The tickle war between the demons
and the angels is heating up, and no one feels safe.
"It's just horrible living here these days! At any moment you could be caught
in the middle of either side and... and... tickled!" cries on resident before
promptly being tickled by rogue angel Hermes.
Indeed, this war of ticklition has already had many casualities, the worst from
the apparent mutiney by several of the angels and the insanity of a few demons.
 Both of these deserters now wonder the street, tickling people at random with
such brute efficency that many fear to leave their homes.
Demon Seth, when asked for an interview, declared his intent to avenge the
tickle of his beloved slave wench Cookie and take revenge on the angel Hermes.
From the other side of the fence, a distraught Endbringer mooed sadly, rubbing
his wings and almost shaking from his recent tickle assult by two demons who
ambushed him.
Trully, this is a horrid war that the world will not forget.
EndText );
    return 1;
  }
if (str=="sugarlove")
  {
write( @EndText
Dear Sugarlove,
I have a cow that I'm madly in love in, the only problem is she seems scared of
me after she saw me at the local burger joint.  The other problem is her mother
is looks good enough to eat!  My friends say it's not natural to love something
with more then two breasts but I can't help it, I want this cow.
Sincerly,
Mooed in PD
 
-------------------------------------------------------------------------------
 
Dear Mooed in PD,
 
Become a vegan.  You can't ever hope to gain her confidence if you're always
insisting that her relatives come over for "dinner".  Of course.. If you ever
do decide to date something within the realms of your own race I'm sure we can
find.. something for you.  Maybe then the two of you can enjoy a date without
having to resort to dinner at Chick-fila.
 
Sugarlove
EndText );
  }
if (str=="letter")
  {
write( @EndText
                        LETTERS TO THE EDITOR
 
 
                      My two cents - Player killing.
                            By: Vampira.
 
        Player killing is an all around popular thing here in 
Primal Darkness. My opinion, what's the point? If you kill someone
it's not as if they are dead and can not come back. They will come 
back, and when this happens what do you gain from it? Sure you showed
them that you could do it. Isn't that what the arena is for? The few
times you may actually succeed in killing someone you usually do not 
get anything. On the rare occassion that they leave a corpse with 
something on it, it doesn't matter. They can always get whatever they
lost back. What do you gain from this? The satisfaction in knowing 
that you killed someone. Again, isn't that what the arena is for? 
Even if you do get there stuff, big deal. Unless you are killing 
someone who carries one hundred thousand gold on them you didn't 
accomplish much. So I ask you, what is the point of player killing?
                 
                 Player Killing From a Different Standpoint.
                                 By: Daos
So, the question remains what do you get out of killing another player?   There
are some who just do it for the exhileration rush.  For others, they need to
work out guild matters, or player differences, and this is one way to do that. 
A slight few kill just to prove it can be done, then they can tell the rest of
the world.
  
   
  
Have your opinion on almost anything and everything voiced, send in a letter!
Address letters to the editor to Hermes, subject: letters to the editor.
EndText );
   }
if (str=="about")
  {
write( @EndText
                    ABOUT HERMES... A word of paranoia!
                                By: Autema
        Hermes may pretend to be a typical clean cut Kansas boy most of the time.
However there are always two sides to the coin, for underneath his facade there
is a far more sinister side that lurks. For once this editor leaves the office
he becomes a creature of unbelievable perversion. For this reporter has learned
of a now, not so well kept secret, of his. For he has been having a tawdry
affair with endbringer, a well known assassin of the realm. Endbringer is
however married to self proclaimed lesbian, Suri. She too is an assassin. Suri
is completely unaware of her spouses activities with Hermes, I must stress.
        Endbringer is not what 'she' would appear to be, 'she' is in fact a
hermaphrodite. But that is not all, 'she' in fact has an alter-ego in which
'she' is a cow. It is with this cow persona that Hermes perverse side shows up
in a more blatant form. I don't believe this needs to be elaborated upon any
further. However there is sufficient proof to back this up as we have several
witnesses of these acts of unspeakable perversion. Wraith reports seeing them
break into Vennenums' house and defiling every square inch of the well guarded
place. Another report comes from Shogun who saw the two in the pit, after he
had been placed there by Daos who says to have been bored at the time. 
        One can only imagine what caused Hermes to go so far off the rails.
Was it that he harboured these perversions all his life, or could a significant
event have caused this? After an interview with his parents it became clear he
had a childhood that didn't appear to have had any indication of such
tendencies. Though his mother did say he always seemed rather subdued while
drinking his milk. Perhaps the not so feminine wiles of endbringer brought out
a well hidden side of Hermes' that none could have suspected even existed.
        People of Primal Darkness I believe we must try to stop this fowl
behaviour as soon as we can. This could potentially tarnish the reputation of
PD and thus we must start the clean up process immediately. Perhaps we should
start with Vennenums' house by the sounds of it. If anyone sights these two
interacting I suggest you get in contact with the law. I'm sure most of their
activities are illegal.
EndText );
   }
 return 1;
}
