#ifndef K_IRONWING_H
#define K_IRONWING_H

#define QUESTION 0
#define ANSWER 1

///// Most information for this game was researched using the following ;
//
//        encyclopedia wikipedia   ---- en.wikipedia.org
//        oceans online            ---- www.oceansonline.com
//        sea and sky              ---- www.seasky.org
//       australian museum online ---- www.amonline.net.au/fishes
//        pbs online-Nova          ---- www.pbs.org/wgbh/nova
//        scuba travel             ---- www.scubatravel.co.uk
//

string* trivia = ({
   ({"What is the other common name for a seacow?","manatee"}),
   ({"What is the genus designation for the many races of seacows?","trichechus"}),
   ({"What other animal does the seahorse commonly use in a symbionic relationship to shield it from predators?","tube worms"}),
   ({"What breed of slug are immune to the toxins of most anemones and sponges??","nudibranch"}),
   ({"What crustacean likes to clean the bacteria off of sea anemone?","shrimp"}),
   ({"In what capacity does a sea anemone act for shrimps and clown fish that choose to form a symbionic with them?","defense"}),
   ({"What is the main source of food for shrimps?","bacteria"}),
   ({"What is the other name for squids and octopi ?","cephalopod"}),
   ({"What type of animal is a nautilus ?","cephalopod"}),
   ({"What is the divide that seperates the sections of a Nautilus' shell called ?","septum"}),
   ({"What is the tube called that connects all the chambers of a nautilus' shell called ?","siphuncle"}),
   ({"By what means does a nautilus maintain it's bouyancy in the water ? (2 words)","osmotic pressure"}),
   ({"What are the coloumns that a sponge forms called ?","spicules"}),
   ({"What is the method called by which sponges feed ?","filtration"}),
   ({"What breed of slug is immunte to a sponges toxins? In fact, this slug makes use of the toins for their own defense.","nudibranch"}),
   ({"What is the scientific classification for sponges?","porifera"}),
   ({"What is a stingray's tail made out of ?","cartilage"}),
   ({"What plant is a main food source for many fish in a reef biosystem ?","seagrass"}),
   ({"What is the rear fin of a fish called (2 words)?","caudal fin"}),
   ({"What do butterfly fish eat (2 words)?","sea anemones"}),
   ({"What is another name for anemone fish (2 words) ?","clown fish"}),
   ({"What body part on a lampray seperates them from eels (4 words) ?","dorsal and caudal fins"}),
   ({"What is a lampray's PRIMARY source of nurishment which they usually get from fish ?","blood"}),
   ({"What is a seal's main food sources (___ and ___) ?","fish and crawfish"}),
   ({"What protects a seal's organs from both attacks and thermal changes ?","blubber"}),
   ({"What is carbon dioxide poisoning commonly called by divers (two words) ?","the bends"}),
   ({"What can a seal store in their muscle tissues to assist them with diving for prey ?","oxygen"}),
   ({"Where do most breeds of crocodile live?","aquifer"}),
   ({"What is the region where salt and fresh water mix at the mouth of a river/bay called ?","aquifer"}),
   ({"What body part allows a crocodile to see underwater (2 words)?","nictitating membrane"}),
   ({"What is the average length of a barracuda (in inches) ?","24"}),
   ({"What is the technique called when prey is herded into an area and picked off slowly ?","corralling"}),
   ({"What is the technique called when an entire school of fish charge at one target ?","swarming"}),
   ({"What animal do some species of shrimp help by eating bacteria off of them in exchange for shelter from predators (2 words)?","sea anemone"}),
   ({"What do smaller fish commonly do to fool predators into thinking they're noe big fish (___ in ____s) ?","swim in schools"}),
   ({"In feet, how long can a tube worm grow (enter a #) ?","8"}),
   ({"What hair-like body parts act like gills for the tube worms?","filaments"}),
   ({"What chemical process do the bacteria near the thermal vents use to 'eat'?","chemosyntesis"}),
   ({"What causes the pompeii worm's gills to appear red?","haemoglobin"}),
   ({"What kills the pompeii worms when a sample is attepted to be retrieved for study ?","decompression"}),
   ({"What chemical/element does chemosyntesis use to make energy ?","sulfur"}),
   ({"What animal is a close relative of the Dugong ?","manatee"}),
   ({"In pounds, what is a dugong maximum adult wieght from currently known specimens (enter a #) ?","300"}),
   ({"In feet, what is a dugong maximum adult length from currently known specimens (enter a #) ?","9"}),
   ({"Other then the nudibranch slug, name one natural predator of corel and sponge (4 words, first 3 are -'d).","crown-of-thorns starfish"}),
   ({"What animal is a natural predator of the crown-of-thorns starfish (2 words)?","triton trumpet"}),
   ({"What process does an anti-coaguant slow down if not stop (2 words)?","blood clotting"}),
   ({"What type of animal is a Triton Trumpet?","snail"}),
   ({"What class of enzyme is used to paralyze a victim?","neuro-toxin"}),
   ({"What colors are a Tirun Cod's markings? (___ and ___)","silver and red"}),
   ({"How heavy in pounds can a Tirun Cod grow?","30"}),
   ({"How many legs does a crab have?","6"}),
   ({"What gang does Pelican Pete belong too?","fighting pelicans"}),
   ({"What is a Flaming Pelican (c) served in (3 words) ?","pelican egg shell"}),
   ({"Who is the general of the Atlantian armies?","kraken"}),
   ({"Who is the admiral of the Atlantian navies?","man-o-war"}),
   ({"What spell was used by Poseidon, The mer-king, to stop Tridryill's evil from consuming this world and level his stronghold?","tsunami"}),
   ({"What was the first stones, which Poseidon constructed, called (3 words)?","pearls of atlantis"}),
   ({"In what substance was Tridryill's remains imprisoned in by Poseidon?","amber"}),
   ({"Near which city did the Atantian armed forces surface during their war with Tridryill?","tirun"}),
   ({"What is the more common name for 'Tilapias' ?","whitefish"}),
   ({"What family do the Tilapias belong too ?","cichid"}),
   ({"What body part seperates the tilapias from basses and perchs (2 words) ?","dorsal fin"}),
   ({"How many Dorsal fins does a Tilapia have (1 word) ?","one"}),
   ({"What part of a porgy has evolved to assist them with eating their diet of shellfish and crustaceans (1 word) ?","jaws"}),
   ({"What is the adjective used to describe a creature that perfers to dwell on the bottom of the ocean or bay?","bentic"}),
   ({"What term means the adjusting of one's body chemistry to withstand the changes to one's enviroment?","osmoregulation"}),
   ({"What is the average weight in pounds of a salmon? (enter a number)","50"}),
   ({"What adjective is used to describe an animal that is born in freshwater but live most of their lives in saltwater?","anadromous"}),
   ({"What is an eel's average lifespan (enter a number) ?","19"}),
   ({"what is the term for a 'hibernation-like' state that slows the metabolism but not nessesarily to the point of sleep?","torpor"}),
   ({"What is a baby eel called once it hatches and before it grows into an adult?","elver"}),
   ({"What adjective describes animals that start life in saltwater and migrate into freshwater for the adulthood stage of their lives until they spawn?","catadromous"}),
   ({"What is the scientific classification of 'family' for the 'short-finned ell'?","anguillidae"}),
   ({"What family do 'Lion Fish' belong to? What type of fish is it? (____ fish)","scorpion fish"}),
   ({"In what body part are the spines containing the Lion fish's toxins located?(4 words=___ and ___ ___)","dorsal and pectoral fins"}),
   ({"In what capacity is the lion fish's toxins used?","defense"}),
   ({"What is the perfered food of a Lion Fish?","shrimp"}),
   ({"What organ contains the Lion fish's toxins within it's fins (plural form)?","spines"}),
   ({"What is the average length of a Lantern Fisn (give a number) in inches ?","6"}),
   ({"What is the scientific name for a Lantern Fish (two words) ?","symbolophorus bamardi"}),
   ({"What is the organ called that produces the light for the Lantern fish ?","photophores"}),
   ({"What is the process called by which an organism produces light?","bioluminescence"}),
   ({"Biolumenecent in fish is believed to be used for (___ and ___) ?","hunting and mating"}),
   ({"What do Hatchet fish usually eat (other then being scavengers) ?","copepods"}),
   ({"At what depth, in feet, can you start to see Hatchet Fish(enter a number) ?","600"}),
   ({"How is the Photophore organs located on the Hatchet Fish (hint-- Caudally means in the tail section) ?","ventrally"}),
   ({"What is a pelican eel's other name (2 words)?","pelican eel"}),
   ({"Which classification of order does the Pelican Eel belong too?","saccopharyngiformes"}),
   ({"What order of animals are yellow corals a member of ?","alcyonacea"}),
   ({"What do members of the Alcyonacea order of animals lack that other corals have (___ ___ of ____) ?","outer shell of calcium"}),
   ({"What are the yellow coral's 'branchs' called ?","spicules"}),
   ({"How many tenticles do each spicule on a yellow coral have ? (enter a #)","8"}),
   ({"What is the scientific name for cup corels (two words) ?","tubaestraea aurea"}),
   ({"What do cup corals lack that other corals have ?","symbiotic algae"}),
   ({"What is the leafy sea dragons 2 make foods (___ and ___) ?","amphipods and algea"}),
   ({"In months, what age do leafy sea dragons start mating (enter a #) ?","12"}),
   ({"About how many eggs does a female leafy sea dragon lay on the males brood patch (enter a #) ?","250"}),
   ({"What part of the fire corals produces it's defensive acids (and gives the fire coral its name) ?","nematocysts"}),
   ({"About how many species of angler fish are there(give a number)?","200"}),
   ({"What order of animals do angler fish belong to?","lophiiformes"}),
   ({"What are the three families that angler fish fall into?\n(Common names) (format -> ___ fish, ___ fish and ___ fish)","frog fish, monk fish and bat fish"}),
   ({"What is the organ called that an angler fish uses for hunting?","illicium"}),
   ({"What is the bioluminecent growth at the end of an angler fish's illicium called?","esca"}),
   ({"What are the three families that angler fish fall into?\n(Common names) (format -> ___, ___ and ___)","antennariidae,lophiidae and ogcocephalidae"}),
   ({"What scientific family do Ore fish fall into?","regalecidae"}),
   ({"What other animal are ore fish a close relative of?","lampray eel"}),
   ({"At a world record for fish, what is the average length in meters of an ore fish (give a number)?","11"}),
   ({"In kilograms, what is the heaviest ore fish on record? (give a number)","272"}),
   ({"what is the scientific name for a Vampire squid (2 words) ?","vamproteuthis infernalis"}),
   ({"What is the other common name for the fangtooth (____ fish) ?","ogre fish"}),
   ({"What is the maximum depth, in feet, that the fangtooth have been found at ?(enter a number)","18000"}),
   ({"What do vampire squids possess a battery of that distinguish them from other cephalopods (2 words)?","sensory filaments"}),
   ({"What differentiates a slipper sea cucumber from other types of sea cucumbers?(a ___ ___)","a flat body"}),
   ({"What does a sea urchin use to defend against predators?","spikes"}),
   ({"What animal class are sea urchins a member of?","echinodea"}),
   ({"What do all members of the echinodea class of animals have in common?(2 words)","radial symmetry"}),
   ({"How many poisonous spines does a rockfish house in their dorsal fins? (enter a number)","13"}),
   ({"What is the average length in centimeters of a stonefish (use #'s : __ to __ ) ?","35 to 50"}),
   ({"What part of a frogfish has evolved to form 'feet', allowing them to 'walk' along the coral reefs? (two words)","pectoral fins"}),
   ({"What are two of the hawkbill turtle's main foods?(___ and ___)","nudibranchs and sponges"}),
   ({"What is the hawkbill turtle's scientific name?","eretmochelys imbricata"}),
   ({"What is the average weight of a Hawkbill Turtle in kilgrams?(enter a #)","80"}),
   ({"What is the record weight in kilograms for the largest Hawkbill Turle?(enter a number)","127"}),
   ({"What is the average length of a Hawkbill turtle along it's dorsal carapace or shell?(enter a #)","90"}),
   ({"What is the average weight of a leatherback turtle in pounds??(enter a #)","1500"}),
   ({"What is the average speed in KNOTS for a leatherback turtle?(enter a #)","25"}),
   ({"What does the term KNOTS mean? ( ____ ____ per ____)","nautical miles per hour"}),
   ({"What animal do leatherbacks eat that most other animals can not?","jellyfish"}),
   ({"What do marine iguanas eat?","algea"}),
   ({"What must a marine iguana do once it surfaces from eating algea? (___ itself)","warm itself"}),
   ({"What does a marine iguana use to rid itself of excess sea salt?(2 words)","nasal glands"}),
   ({"How much more potent is a sea snake's venom over a king cobra?(___ times)","ten times"}),
   ({"What is the approximate size of the sea snake in meters?(give a #)","2"}),
   ({"What is the most common reef dwelling sea snake? (3 words)","olive sea snake"}),
   ({"What is the central section of an ocptopi's body called?","mantle"}),
   ({"What body part seperates the giant octopi from their smaller cousins?(_____ between _____ ______)","membrane between their tenticles"}),
   ({"What is the average length in feet of a large octopi's tenticles?(enter a #)","16"}),
   ({"In feet, what is the longest large octopi's tenticle on record?(enter a #)","20"}),
   ({"What is the heaviest large octopi's tenticle in pounds on record?(enter a #)","608"}),
   ({"What is the 'ink' that an octopus ejects in actuality?(it's ____)","saliva"}),
   ({"What is the outer layer of skin called on an animal?","epidermis"}),
   ({"What sense does the suckers on an octopus' tenticles possess?","taste"}),
   ({"What type of dorsal fin, or tail, does a Mako shark possess?(___ tail)","homocercal tail"}),
   ({"What is the anatomical name for the are directly below a Mako shark's Dorsal fin? (I do NOT mean that either...)","caudal peduncle"}),
   ({"What is the term that refers to the flow of water and/or the study of the flow of water?","hydrodynamics"}),
   ({"What is the top recorded speed of a Mako Shark in MPH?","42"}),
   ({"What is the term for animals that bear live off-spring like the reef sharks?","vivparous"}),
   ({"How many off-spring does a Mako shark average per litter? (__ to __ pups)","2 to 4 pups"}),
   ({"What is the length of a Mako Shark Pup at birth in cm?? (__ to __ cm)","33 to 52 cm"}),
   ({"What is a baby seacow called?","calf"})
});
#endif
