#include <std.h>
#include <corinthor.h>

inherit MONSTER;

void create() {
     string *types, ctype;
   ::create();
     types = ({ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p" });
     ctype = types[random(16)];
     switch(ctype) {
      case "a" : case "b" : case "c" : case "d" :
        set_name("elven villager");
        set_id( ({"elf", "elven villager", "villager" }) );
        set_short("Elven villager");
        set_long("A typical elven resident of Corinthor with long silver hair and fair skin.");
        set_race("elf");
        if(random(2) == 1)
          set_gender("male");
        else
          set_gender("female");
        set_body_type("elf");
        set_level(random(5)+5);
        if(random(2) == 1)
          new(ELFARMOUR"grnshirt.c")->move(this_object());
        else
          new(ELFARMOUR"blushirt.c")->move(this_object());
        command("wear shirt");
        if(random(5) == 1) {
          new(ELFWEAPON"dagger.c")->move(this_object());
          command("wield dagger");
          }
	break;

      case "e" : case "f" : case "g" : case "h" :
        set_race("elf");
        if(random(2) == 1)
          set_gender("male");
        else
          set_gender("female");
        set_name("elven villager");
        set_id( ({"elf", "elven villager", "villager" }) );
        set_short("Elven villager");
        set_long("An elven resident of Corinthor, "+query_subjective()+" has long golden hair and darker skin.");
        set_body_type("elf");
        set_level(random(5)+5);
        new(ELFARMOUR"finepants.c")->move(this_object());
           command("wear pants");
        new(ELFARMOUR"finetunic.c")->move(this_object());
           command("wear tunic");
        if(random(3) == 1) {
          new(ELFARMOUR"brnrobes.c")->move(this_object());
          command("wear robes");
          }
        else if(random(2) == 1) {
          new(ELFARMOUR"gryrobes.c")->move(this_object());
          command("wear robes");
          }
	break;

      case "i" : case "j" : case "k" :
        if(random(2) == 1)
          set_gender("male");
        else
          set_gender("female");
        set_name("elven priest");
        set_id( ({"elf", "elven priest", "priest" }) );
        set_short("Elven priest");
        set_long("A priest of the elven clergy, "+query_subjective()+" walks about with "+query_possessive()+" head held high.");
        set_race("elf");
        set_body_type("elf");
        set_level(random(5)+5);
        if(random(3) == 1)
          new(ELFARMOUR"gryrobes.c")->move(this_object());
        else if(random(2) == 1)
          new(ELFARMOUR"brnrobes.c")->move(this_object());
        else if(random(2) == 1)
          new(ELFARMOUR"whirobes.c")->move(this_object());
        command("wear robes");
        break;

      case "l" : case "m" : case "n" :
        if(random(2) == 1)
          set_gender("male");
        else
          set_gender("female");
        set_name("elven guard");
        set_id( ({"elf", "elven guard", "guard" }) );
        set_short("a Guard of Corinthor");
        set_long("One of the many guards that defend Corinthor, "+query_subjective()+" takes "+query_possessive()+" role seriously.");
        set_race("elf");
        set_body_type("elf");
        set_level(random(5)+5);
        new(ELFARMOUR"elfchainmail.c")->move(this_object());
           command("wear chainmail");
        if(random(3) == 1) {
          new(ELFWEAPON"scimitar.c")->move(this_object());
          command("wield scimitar");
          }
        else if(random(2) == 1) {
          new(ELFWEAPON"metalstaff.c")->move(this_object());
          command("wield staff");
          }
        else {
          new(ELFWEAPON"flail.c")->move(this_object());
          command("wield flail");
          }
        break;

      case "o" : case "p" :
        set_name("elven mage");
        set_id( ({"elf", "elven mage", "mage" }) );
        set_short("Elven mage");
        set_long("One of the elven mages present in corinthor, out and about on some business or other.");
        set_race("elf");
        if(random(2) == 1)
          set_gender("male");
        else
          set_gender("female");
        set_body_type("elf");
        set_level(random(5)+5);
        new(ELFARMOUR"magecloak.c")->move(this_object());
        command("wear cloak");
        if(random(5) == 1) {
          new(ELFWEAPON"woodstaff.c")->move(this_object());
          command("wield staff");
          }
	break;
        }
}
