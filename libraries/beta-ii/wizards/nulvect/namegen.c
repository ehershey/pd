
#include <std.h>

inherit DAEMON;

string *singlevowels = ({
  "a", "e", "i", "o", "u", "y",
});
string *doublevowels = ({
  "ee", "oo",
});
string *diphthongs = ({
  "ae", "ai", "au", "aw", "ay",
  "ea", "ei",
  "ia", "ie", "io",
  "oa", "oi", "ow", "oy",
  "ua", "ue", "ui",
});
string *startvowels = singlevowels;
string *middlevowels = singlevowels + doublevowels + diphthongs;
string *endvowels = singlevowels + doublevowels;

string *singleconsonants = ({
  "b", "c", "d", "f", "g", "h", "j",
  "k", "l", "m", "n", "p", "qu", "r",
  "s", "t", "v", "w", "x", "y", "z",
});

string *c_plus_r = ({
  "br", "cr", "dr", "fr", "gr",
  "kr", "pr", "tr", "str",
});

string *c_plus_l = ({
  "bl", "cl", "fl", "gl", "kl",
  "pl", "sl",
});

string *c_plus_h = ({
  "ch", "gh", "ph", "sh", "th", "wh",
});

string *c_double = ({
  "bb", "cc", "dd", "ff", "gg",
  "kk", "ll", "mm", "nn", "pp",
  "rr", "ss", "tt",
});


varargs string query_random_name(int syllables) {
  string ret = "";
  int vowel = random(2);

  if (nullp(syllables))
    syllables = 3+random(4);

  for (int i = 0; i <= syllables; i++) {
    if (vowel) {
      ret += singlevowels[random(sizeof(singlevowels))];
      if (!random(5) && (sizeof(ret) || i == syllables) )
        ret += singlevowels[random(sizeof(singlevowels))];
    }
    else {
      ret += singleconsonants[random(sizeof(singleconsonants))];
      if (!random(5) && (sizeof(ret) || i == syllables) )
        ret += singleconsonants[random(sizeof(singleconsonants))];
    }
    vowel = !vowel;
  }

  return ret;
}

