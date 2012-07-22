//      /std/vendor.c
//      from the Nightmare Mudlib
//      a standard object that sells things in shops
//      created by Descartes of Borg 921024
//      rewritten by Descartes 931108

#include <teststd.h>
#include <money.h>
#include <daemons.h>

#define MAX_ITEMS 255

inherit MONSTER;

private mapping __Eco, __Values, __Costs, __Discriminate;
string *__Type;

static int __CheckDiscrimination();
static int __SellAll();
static int convert(int x);
int cost_bargaining(object who, int x);
static int value_bargaining(object who, int x);
static int __AlreadyThere(object ob);
int set_type(string *str);
int query_type();
int store_type(string *str) { return set_type(str); }
void init() {
    ::init();
    add_action("__Buy", "buy");
    add_action("__Sell", "sell");
    add_action("__Show", "show");
    add_action("__List", "list");
    add_action("__Value", "value");
    //    add_action("__Cost", "cost");
}

void create() {
    __Eco = ([]);
    __Values = ([]);
    __Costs = ([]);
    __Discriminate = ([]);
    __Type=({});
    ::create();
}

int set_type(string *str)
{
    __Type = str;
}

string *query_types() { return __Type; }

int valid_type(object ob)
{
    int n;
    n = sizeof(__Type);
    if (!n) return 1;
    while(n--)
    {
	if (__Type[n]=="weapon" && (ob->is_weapon())) return 1;
	if (__Type[n]=="armour" && (ob->is_armour())) return 1;
	if (__Type[n]=="light"  && (ob->is_light()))  return 1;
	if (__Type[n]=="skin"  && (ob->query_id()[0] == "skin"))  return 1;
	if (__Type[n]=="object" &&
	  !ob->is_weapon() && !ob->is_armour() &&
	  !ob->is_light() &&  (ob->query_id()[0] != "skin")) return 1;
    }
    return 0;
}
int __Buy(string str) {
    object ob;
    string tmp;
    int worth, val, x, z, enc, maxenc;
    mapping cur;

    if(!__Eco["storage object"])
	__Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    if(!(x = __CheckDiscrimination())) return 1;

    if(!str) {
	this_object()->force_me("say "+this_player()->query_cap_name()+", What do you wish to buy?");
	return 1;
    }
    if(!(ob = present(str, __Eco["storage object"])) && 
      !(ob = parse_objects(__Eco["storage object"]))) {
	this_object()->force_me("say "+this_player()->query_cap_name()+", I have nothing like that to sell.");
	return 1;
    }
    if(__Costs[tmp = (string)this_player()->query_name()])
	worth = __Costs[tmp][ob];

    if (!worth) {
	if ((cur = ob->query_curr_value()))
	{
	    if (cur[__Eco["currency"]])
		worth = cur[__Eco["currency"]];  else {
		z = cur[keys(cur)[0]]/currency_rate(keys(cur)[0]);
		worth = z*currency_rate(__Eco["currency"]);
	    }
	}
    }
    if((int)this_player()->query_money(__Eco["currency"]) < (cost_bargaining(this_player(), worth) < worth ? worth : cost_bargaining(this_player(), worth)) ) {
	write("You do not have enough "+__Eco["currency"]+" for that.");
	return 1;
    }
    if((int)this_player()->query_money(__Eco["currency"]) < 1) {
	write("You do not have enough "+__Eco["currency"]+" for that.");
	return 1;
    }
    enc = this_player()->query_internal_encumbrance();
    maxenc = this_player()->query_max_internal_encumbrance();
    if(enc + ob->query_weight() > maxenc) {
	write("You can't hold any more.");
	return 1;
    }
    else {
	if (worth > (val = cost_bargaining(this_player(), worth))) val = worth;
	this_object()->force_me("say Here is your "+str+" for "+val+" "+__Eco["currency"]+"!");
	message("other_action", query_cap_name()+" hands "+
	  (string)this_player()->query_cap_name()+" "+(string)ob->query_short()+".",
	  environment(this_object()), ({ this_player(), this_object() }));
	message("other_action", query_cap_name()+" hands you "+
	  (string)ob->query_short()+".", this_player());
	this_player()->add_money(__Eco["currency"], -val);
    }
    if(ob->move(this_player())) {
	message("my_action", "You drop it as fast as you get it!", this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " drops "+(string)ob->query_short()+".", environment(this_object()),

	  ({ this_player() }));
	ob->move(environment(this_object()));
    }
    return 1;
}

mapping query_value() { return __Values; }
int __Sell(string str) {
    object ob, ob_bag, *baginv;
    string item, bag;
    int worth, val, x, n, tot, z;
    mapping cur;

    if(!(x = __CheckDiscrimination())) return 1;
    if(!str) {
	this_object()->force_me("say Sell what?");
	return 1;
    }
    if(!__Eco["storage object"])
	__Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    if(sizeof(all_inventory(__Eco["storage object"])) >= MAX_ITEMS) {
	this_object()->force_me("say I cannot get rid of what I have to sell right now!");
	return 1;
    }
    if (sscanf(str, "%s from %s", item, bag) == 2 ||
      sscanf(str, "%s in %s", item, bag) == 2)
    {
	ob_bag = present(bag, this_player());
	if (!ob_bag)
	{
	    this_object()->force_me("say What "+bag+" are you talking about?");
	    return 1;
	}
	if (item=="all")
	{
	    baginv = all_inventory(ob_bag);
	    if (sizeof(baginv)==0)
	    {
		this_object()->force_me("say Theres nothing in the "+bag+" to sell.");
		return 1; 
	    }
	} else {
	    if (!present(item, ob_bag)) return 
		force_me("say You dont have that to sell in your "+bag+".");
	    baginv = ({ present(item, ob_bag) });
	}
	n = sizeof(baginv);

	while(n--) {
	    worth=0;
	    ob = baginv[n];
	    if ((!ob) || (!valid_type(ob)))
	    {
		continue;
	    }
	    if ((cur = ob->query_curr_value()))
	    {
		if (cur[__Eco["currency"]])
		    worth = cur[__Eco["currency"]];  else {
		    z = cur[keys(cur)[0]]/currency_rate(keys(cur)[0]);
		    worth = z*currency_rate(__Eco["currency"]);
		}
	    }
	    if (!worth) continue;
	    if(worth < (val = value_bargaining(this_player(), worth))) val = worth;
	    this_player()->add_money(__Eco["currency"], val);
	    tot += val;
	    this_player()->add_skill_points("bargaining",
	      random(query_skill("bargaining")));
	    val = to_int(val);
	    message("other_action", (string)this_player()->query_cap_name()+
	      " sells "+(string)ob->query_short()+" from "+ob_bag->query_short()+".", environment(this_object()),
	      ({ this_player() }));
	    message("my_action", "You sell "+(string)ob->query_short()+" from "+ob_bag->query_short()+" for "+
	      val + " " + __Eco["currency"]+".", this_player());

	    if(ob->query_destroy()) ob->remove();
	    else if(__AlreadyThere(ob)) ob->remove();
	    else {
		ob->move(__Eco["storage object"]);

	    }
	    //            if(ob) destruct(ob);
	    worth = 0;
	}
	tot = to_int(tot);
	if (item=="all" && tot)
	    this_object()->force_me("say Thats a grand total of "+tot+" "+__Eco["currency"]+".");
	return 1;
    }      

    if(str == "all") return __SellAll();
    if(!(ob = present(str, this_player())) &&
      !(ob = parse_objects(this_player(), str))) {
	this_object()->force_me("say You do not have that to sell!");
	return 1;
    }
    /*
	if(__Values[tmp = (string)this_player()->query_name()])
	  {
	    worth = __Values[tmp][ob];
	    map_delete(__Values[tmp], ob);
	    if(!__Values[tmp] || !sizeof(__Values[tmp]))
	       map_delete(__Values, tmp);

	  }
    */
    if (!worth) {
	if ((cur = ob->query_curr_value()))
	{
	    if (cur[__Eco["currency"]]) 
		worth = cur[__Eco["currency"]];  else {
		z = cur[keys(cur)[0]]/currency_rate(keys(cur)[0]);
		worth = z*currency_rate(__Eco["currency"]);
	    }
	}
	if(worth < (val = value_bargaining(this_player(), worth))) val = worth;
    }
    if (ob->query_worn() || ob->query_wielded())
    {
	this_object()->force_me("say You need to remove that first.");
	return 1;
    }
    if (!valid_type(ob))
    {
	this_object()->force_me("say I do not have any use for that.");
	return 1;
    }
    if (!val) {
	this_object()->force_me("say That thing is worthless!");
	return 1;
    }
    if(val > 2000) {
	this_object()->force_me("say I am low on money.");
	val = 1000 + random(1000);
    }
    if(val < 0) {
	val = 0;
    }
    this_player()->add_money(__Eco["currency"], val);
    this_player()->add_skill_points("bargaining",
      random(query_skill("bargaining")));
    message("other_action", (string)this_player()->query_cap_name()+
      " sells "+(string)ob->query_short()+".", environment(this_object()),
      ({ this_player() }));
    val = to_int(val);
    message("my_action", "You sell "+(string)ob->query_short()+" for "+
      val + " " + __Eco["currency"]+".", this_player());
    if(ob->query_destroy()) ob->remove();
    else if(__AlreadyThere(ob)) ob->remove();
    else {
	ob->move(__Eco["storage object"]);
	return 1;
    }
    if(ob) destruct(ob);
    return 1;
}

int __Show(string str) {
    object ob;
    //    string tmp;


    if(!__CheckDiscrimination()) return 1;
    if(!str) {
	this_object()->force_me("Show you what?");
	return 1;
    }
    if(!__Eco["storage object"])
	__Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    if(!(ob = present(str, __Eco["storage object"])) &&
      !(ob = parse_objects(__Eco["storage object"]))) {
	this_object()->force_me("say I do not have that here to show you.");
	return 1;
    }
    message("other_action", query_cap_name()+" shows you "+
      (string)ob->query_short()+".", this_player());
    message("info", (string)ob->query_long(), this_player());
    if (ob->query_auto_load())
	message("info", "This item will autoload for you.", this_player());
    else
	message("info", "This item will NOT autoload for you.", this_player());
    return 1;
}

int __List(string str) {
    object *inv;
    string *tmp;
    string tmps;
    int i, x, z;
    mapping cur;
    string tempor;
    int worth, val; 
    tmps = "";
    if(!__CheckDiscrimination()) return 1;
    if(!__Eco["storage object"])
	__Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    if(!__Eco["storage object"]) {
	this_object()->force_me("say I have nothing to sell right now.");
	return 1;
    }
    i = sizeof(inv = filter_array(all_inventory(__Eco["storage object"]), 
	"filter_list", this_object(), str));
    if(!i) {
	this_object()->force_me("say I have nothing like that to sell.");
	return 1;
    }
    tmp = ({});
    tmps = "\n";
    tmp = ({ tmps });
    tmps ="%^BLUE%^+=+%^BOLD%^( %^WHITE%^Item%^BLUE%^ )%^RESET%^%^BLUE%^+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+%^BOLD%^( %^WHITE%^Value%^BLUE%^ )%^RESET%^%^BLUE%^=+=+=+=+=+=+";
    tmp += ({ tmps });

    for(x=0; x<i; x++)
    {  
	if(__Costs[tempor = (string)this_player()->query_name()])
	    worth = __Costs[tempor][inv[x]];

	if (!worth) {
	    if ((cur = inv[x]->query_curr_value()))
	    {
		if (cur[__Eco["currency"]])
		    worth = cur[__Eco["currency"]];  else {
		    z = cur[keys(cur)[0]]/currency_rate(keys(cur)[0]);
		    worth = z*currency_rate(__Eco["currency"]);
		}
	    }
	    if(worth > (val = cost_bargaining(this_player(), worth))) val = worth;
	}
	/*
	  if (!worth) if(!(worth = (int)inv[x]->query_value())) worth = 1;
		if(worth > (val = cost_bargaining(this_player(), worth))) val = worth;
	       val = convert(val);
	*/

	tmps= sprintf("%-55s %d %s",TERMINAL_D->no_colours((string)inv[x]->query_short()),
	  val, __Eco["currency"]);
	worth = 0;
	tmp += ({ tmps });

    }
    tmp += ({ "%^BLUE%^"+repeat_string("+=", 38)+"+" });
    this_player()->more(tmp);

    return 1;
}

int __Value(string str) {
    object ob;
    string tmp, cn;
    int worth, val, z;
    mapping cur;

    if(!__CheckDiscrimination()) return 1;
    if(!str) {
	this_object()->force_me("say The value of what?");
	return 1;
    }
    if(!(ob = present(str, this_player()))) {
	if(!(ob = parse_objects(this_player(), str))) {
	    this_object()->force_me("say You don't have that!");
	    return 1;
	}
    }
    message("other_action", (cn=(string)this_player()->query_cap_name())+
      " asks for an appraisal.", environment(this_object()), ({this_object(),this_player()}));
    if(__Values[tmp=(string)this_player()->query_name()] &&
      __Values[tmp][ob]) {
	this_object()->force_me("say You have my offer!");
	return 1;
    }
    if ((cur = ob->query_curr_value()))
    {
	if (cur[__Eco["currency"]])
	    worth = cur[__Eco["currency"]];  else {
	    z = cur[keys(cur)[0]]/currency_rate(keys(cur)[0]);
	    worth = z*currency_rate(__Eco["currency"]);
	}
    }
    if(worth < (val = value_bargaining(this_player(), worth))) val = worth;
    if(val > 2000) {
	this_object()->force_me("say I am low on money.");
	val = 1000 + random(1000);
    }
    //    val = convert(val);
    /*    if(!__Values[tmp]) __Values[tmp] = ([]);
	__Values[tmp][ob] = val;
    */
    if(cn == "Someone") cn = "Invisible person";
    this_object()->force_me("say "+cn+", I will offer you "+val+" "+
      __Eco["currency"]+" for it.");
    return 1;
}

/* i think this is pretty lame.. its more efficient to just
   type list and itll tell you all the objects with a price next to it 
*/
/*
int __Cost(string str) {
    object ob;
    string cn, tmp;
    int val, worth;

    if(!__Eco["storage object"])
	__Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    if(!__CheckDiscrimination()) return 1;
    if(!str) {
	this_object()->force_me("say The cost of what?");
	return 1;
    }
    if(!(ob = present(str, __Eco["storage object"])) &&
      !(ob = parse_objects(__Eco["storage object"], str))) {
	this_object()->force_me("say I do not have any "+str+" to sell.");
	return 1;
    }
    message("other_action", (cn=(string)this_player()->query_cap_name())+
      "asks about the cost of an item for sale.", environment(this_object()),
      ({ this_object(), this_player() }));
    if(__Costs[tmp = (string)this_player()->query_name()] && __Costs[tmp][ob]) {
	this_object()->force_me("say I will charge no less!");
	return 1;
    }
    if(!(worth = (int)ob->query("value"))) worth = 1;
    if(worth > (val = cost_bargaining(this_player(), worth))) val = worth;
    val = convert(val);
    if(!__Costs[tmp]) __Costs[tmp] = ([]);
    __Costs[tmp][ob] = val;
    if(cn == "Someone") cn = "Invisible person";
    this_object()->force_me("say "+cn+", I will take "+val+" "+__Eco["currency"]+" for it.");
    return 1;
}
*/
int filter_list(object ob, string str) {
    if(!str || str == "") return 1;
    switch(str) {
    case "weapon": case "weapons": return (int)ob->is_weapon();
    case "armor": case "armour": case "armors": case "armours":
	return (int)ob->is_armour();
    case "bag": case "bags": return (int)ob->is_bag();
    case "light" : case "lights" : return (int)ob->is_light();
    case "skin" : case "skins" : return ob->query_id() == "skin";
    case "other": return (!((int)ob->is_weapon()) &&
	  !((int)ob->is_armour()) && !(ob->query_id() == "skin"));
    default:
	return ((string)ob->query_type() == str || ob->id(str));
    }
    return 0;  // just to be safe... Did I just comment some code?
}

static int __SellAll() {
    object *inv;
    int i, worth, val, total, z;
    mapping cur;

    total = 0;
    if(!(i = sizeof(inv = all_inventory(this_player())))) {
	this_object()->force_me("say You have nothing to sell!");
	return 1;
    }
    while(i--) {
	if (inv[i]->query_wielded() || inv[i]->query_worn()) continue;
	if (!valid_type(inv[i]))
	{
	    this_object()->force_me("say I do not have any use for "+a_or_an(inv[i]->query_name())+" "+inv[i]->query_name()+".");
	    continue;
	}

	if ((cur = inv[i]->query_curr_value()))
	{
	    if (cur[__Eco["currency"]])
		worth = cur[__Eco["currency"]];  else {
		z = cur[keys(cur)[0]]/currency_rate(keys(cur)[0]);
		worth = z*currency_rate(__Eco["currency"]);
	    }
	} else { this_object()->force_me("say "+capitalize(inv[i]->query_short())+" is worthless."); continue; }

	if(worth < (val = value_bargaining(this_player(), worth))) val = worth;
	if(val > 2000) val= 1000 + random(1000);
	if (val < 0) val = 0;
	total += val;
	this_player()->add_money(__Eco["currency"], val);
	message("my_action", "You sell "+(string)inv[i]->query_short()+".",
	  this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " sells "+(string)inv[i]->query_short()+".", 
	  environment(this_object()), ({ this_player() }));
	if(inv[i]->query_destroy()) inv[i]->remove();
	else if(__AlreadyThere(inv[i])) inv[i]->remove();
	else inv[i]->move(__Eco["storage object"]);
    }
    if(total)
	this_object()->force_me(sprintf("say Your total comes to %d %s.",
	    total, __Eco["currency"]));  //Kalinash 1-14-94
    this_object()->force_me("say Thank you for your business!");
    return 1;
}

int cost_bargaining(object who, int x) {
    int val, pl, cha;

    pl = (int)who->query_skill("bargaining");
    cha = (int)who->query_stats("bargaining");
    val = (2*x) + ((x*10)/100) + ((query_skill("bargaining")-cha)*x)/200;
    val -= (pl*x)/200;
    val = (int)to_int(val);
    return val;
}

static int value_bargaining(object who, int x) {
    int val, pl, cha;

    pl = (int)who->query_skill("bargaining");
    cha = (int)who->query_stats("charisma");
    val = x + ((pl*x)/200) - ((query_skill("bargaining")-cha)*x)/200;
    val = (int)to_int(val);
    return val;
}

static int __AlreadyThere(object ob) {
    object *inv;
    int i;

    if(!(i = sizeof(inv = all_inventory(__Eco["storage object"])))) return 0;
    while(i--) 
	if((string)inv[i]->query_short() == (string)ob->query_short()) return 1;
    return 0;
}

static int __CheckDiscrimination() {
    int x, tmp, i;

    if(__Discriminate["class"] &&
      member_array((string)this_player()->query_class(), __Discriminate["class"]) == -1) {
	this_object()->force_me("say I do not do business with people like you.");
	return 0;
    }
    if(__Discriminate["race"] && member_array((string)this_player()->query_class(), __Discriminate["race"]) == -1) {
	this_object()->force_me("say I do not do business with people like you.");
	return 0;
    }
    if(__Discriminate["language"] && i = sizeof(__Discriminate["language"])) {
	while(i--) 
	    if(x < (tmp = (int)this_player()->query_lang_prof(
		  __Discriminate["language"][i]))) x = tmp;
	if(!x) {
	    this_object()->force_me("say I do not understand you.");
	    return 0;
	}
	return x;
    }
    return 10;
}

static int convert(int x) {
    if(!x) return 0;
    return 1 + to_int(x * __Eco["exchange rate"]);
}

varargs void set_currency(string str) {

    __Eco["currency"] = str;
    /*
	__Eco["exchange rate"] =currency_rate(str);
    */
    __Eco["exchange rate"] = (float)ECONOMY_D->__Query(str, "rate");
}

void set_discriminate(string who, string *which) { __Discriminate[who]=which; }

void set_storage_room(string str) { 
    __Eco["storage object"] =find_object_or_load(__Eco["storage file"] = str);
}

string query_currency() { return __Eco["currency"]; }

object query_storage_room() { return __Eco["storage object"]; }
