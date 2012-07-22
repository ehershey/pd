//      /adm/simul_efun/pluralize.c
//      from the Nightmare mudlib
//      simul_efun to pluralize nouns... description after header
//      created by Descartes of Borg 27 june 1993
/*
First: checks for exceptions in the ABNORMAL mapping
Second: Checks for words ending in "man"
Third: checks for rules based on the last 2 letters
Fourth: checks for rules based on the last letter
Fifth: Just tag on an "s"
*/
#define ABNORMAL ([ "moose":"moose", "mouse":"mice", "die":"dice", \
"index":"indices", "human":"humans", "sheep":"sheep", "fish":"fish", \
"child":"children", "ox":"oxen", "tooth":"teeth", "deer":"deer", "bus":"buses", \
"key":"keys", "giraffe":"giraffes", "robe":"robes", "boots":"boots", \
"foot":"feet", "day" : "days", \
"elf":"elves", "wolf":"wolves", "staff":"staves" ])
string pluralize(mixed single) {
    int x;
    string str, tmp;
    if(!single) return single;
    if(objectp(single)) {
        if(str = (string)single->query("plural name")) return str;
        else str = (string)single->query_name();
    }
    else str = (string)single;
    if(!str) return str;
    x = strlen(str);
    if(ABNORMAL[str]) return ABNORMAL[str];
    if(x > 2 && str[x-3..x-1] == "man")
        return str[0..x-3]+"en";
    if(x > 1) {
        tmp = str[x-2..x-1];
        switch(tmp) {
        case "ts": return str+"";
        case "ch": case "sh":
            return str+"es";
        case "ff": case "fe":
            return str[0..x-3]+"ves";
        case "us":
            return str[0..x-3]+"i";
        case "um":
            return str[0..x-3]+"a";
        case "ef":
            return str+"s";
        }
    }
    tmp = str[x-1..x-1];
    //  2 bug fixes by Whit
    if(str[sizeof(str)-2..sizeof(str)] == "ts") return str;
    if(str[sizeof(str)-2..sizeof(str)] == "es") return str;
    switch(tmp) {
    case "s":
        return str+"es";
    case "o": case "x": 
        return str+"es";
    case "wolf": return str[0..x-4]+"wolves";
    case "f": return str[0..x-2]+"ves";
    case "y" : return str[0..x-2]+"ies";
    }
    return str+"s";
}
