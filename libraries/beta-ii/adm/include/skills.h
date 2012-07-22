#ifndef __SKILLS_H__
#define __SKILLS_H__

#include <daemons.h>

// this contains all skills in the mud
mapping skillcategories = ([
  "attack" : ({
    "attack", "charging", "defense", "double wielding", "melee",
    "rage", "riding",
  }),
  "weapons" : ({
    "axe", "blade", "blunt", "flail", "knife",
    "projectile", "ranged", "breath", "claw", "tail",
  }),
  "deception/other" : ({
    "agility", "bargaining", "discipline", "entertainment", "euphony",
    "ferocity", "flying", "locks", "murder", "perception",
    "stealing", "stealth", "valor",
  }),
  "magic" : ({
    "aeromancy", "aquamancy", "belief", "clairvoyance", "conjuring",
    "faith", "geomancy", "healing", "illusion", "magic attack",
    "magic defense", "nature", "necromancy", "psionics", "pyromancy",
    "summoning", "wizardry",
  }),
]);

// this is all classes and subs in the mud
mapping classes = ([
  "child" : ({ "none" }),
  "fighter" : ({ "warrior", "berserker", "ranger", "paladin", "antipaladin" }),
  "mage" : ({ "sorceror", "wizard", "necromancer", "conjurer", "illusionist", "pyromancer" }),
  "rogue" : ({ "assassin", "thief", "thug", "scout" }),
  "clergy" : ({ "monk", "cleric", "druid", "kataan", "shaman" }),
  "wanderer" : ({ "jester", "gypsy", "bard", "swashbuckler" }),
  "elementalist" : ({ "aeromancer", "aquamancer", "geomancer", /* "pyromancer", */ }),
  "dragon" : ({ "red", "black", "white", "blue" }),
  "animal" : ({ "strong", "fast", "sturdy" }),
  "vampire" : ({ "vampire" }),
]);

// actual max = number / 2
// 10 == 5 per level, 9 == 4.5 per level, etc
mapping skillmaxes = ([
  // "animal" is a class for mobs
  "animal" : ([
    "attack" : 10,
    "defense" : 10,
    "melee" : 9,
    "perception" : 9,
    "claw" : 8,
    "tail" : 4,
  ]),
  "strong" : ([
    "attack" : 12,
    "defense" : 8,
    "claw" : 10,
    "perception" : 7,
  ]),
  "fast" : ([
    "attack" : 7,
    "perception" : 11,
    "agility" : 14,
    "stealth" : 8,
  ]),
  "sturdy" : ([
    "attack" : 9,
    "defense" : 12,
  ]),

  "fighter" : ([
    "attack" : 12,
    "defense" : 10,
    "double wielding" : 10,
    "melee" : 8,
    "riding" : 10,
    "axe" : 6,
    "blade" : 10,
    "blunt" : 6,
    "flail" : 6,
    "knife" : 6,
    "projectile" : 6,
    "ranged" : 6,
    "bargaining" : 7,
    "perception" : 8,
  ]),
  "paladin" : ([
    "riding" : 12,
    "blunt" : 10,
    "projectile" : 10,
    "valor" : 12,
    "faith" : 8,
    "healing" : 6,
    "magic defense" : 8,
  ]),
  "antipaladin" : ([
    "flail" : 10,
    "projectile" : 10,
    "ferocity" : 12,
    "faith" : 8,
    "healing" : 4,
    "magic attack" : 8,
    "magic defense" : 4,
  ]),
  "berserker" : ([
    "double wielding" : 8,
    "melee" : 12,
    "rage" : 12,
    "ferocity" : 10,
    "axe" : 10,
    "blunt" : 10,
    "perception" : 6,
  ]),
  "ranger" : ([
    "melee" : 10,
    "projectile" : 10,
    "ranged" : 12,
    "discipline" : 10,
    "perception" : 10,
    "stealth" : 6,
    "nature" : 11,
  ]),
  "warrior" : ([
    "double wielding" : 12,
    "axe" : 12,
    "blade" : 12,
    "blunt" : 12,
    "flail" : 12,
    "knife" : 12,
    "projectile" : 12,
    "ranged" : 8,
    "discipline" : 10,
  ]),

  "rogue" : ([
    "attack" : 10,
    "defense" : 8,
    "double wielding" : 10,
    "melee" : 7,
    "axe" : 2,
    "blade" : 6,
    "blunt" : 6,
    "flail" : 4,
    "knife" : 10,
    "projectile" : 4,
    "ranged" : 4,
    "agility" : 10,
    "bargaining" : 10,
    "perception" : 8,
    "stealth" : 10,
  ]),
  "assassin" : ([
    "ranged" : 8,
    "agility" : 12,
    "locks" : 8,
    "murder" : 12,
    "stealing" : 6,
  ]),
  "thief" : ([
    "attack" : 8,
    "locks" : 12,
    "murder" : 6,
    "perception" : 10,
    "stealing" : 12,
  ]),
  "thug" : ([
    "double wielding" : 8,
    "melee" : 12,
    "blunt" : 10,
    "agility" : 6,
    "bargaining" : 12,
    "locks" : 6,
    "murder" : 10,
    "stealing" : 8,
    "stealth" : 8,
  ]),
  "scout" : ([
    "double wielding" : 12,
    "knife" : 12,
    "locks" : 4,
    "murder" : 4,
    "perception" : 12,
    "stealing" : 4,
    "stealth" : 12,
    "ranged" : 6,
  ]),

  "wanderer" : ([
    "attack" : 8,
    "defense" : 10,
    "double wielding" : 5,
    "melee" : 5,
    "axe" : 4,
    "blade" : 6,
    "blunt" : 8,
    "flail" : 4,
    "knife" : 10,
    "projectile" : 2,
    "ranged" : 2,
    "bargaining" : 10,
    "perception" : 10,
  ]),
  "gypsy" : ([
    "defense" : 9,
    "double wielding" : 7,
    "blunt" : 10,
    "flail" : 8,
    "entertainment" : 10,
    "euphony" : 6,
    "stealing" : 6,
    "stealth" : 6,
    "clairvoyance" : 12,
  ]),
  "jester" : ([
    "blunt" : 12,
    "entertainment" : 12,
    "euphony" : 6,
    "perception" : 6,
    "stealth" : 8,
  ]),
  "bard" : ([
    "attack" : 6,
    "knife" : 6,
    "entertainment" : 8,
    "euphony" : 12,
  ]),
  "swashbuckler" : ([
    "attack" : 9,
    "double wielding" : 10,
    "blade" : 12,
    "knife" : 6,
    "entertainment" : 6,
    "perception" : 8,
  ]),

  "mage" : ([
    "attack" : 2,
    "defense" : 5,
    "double wielding" : 2,
    "melee" : 2,
    "axe" : 2,
    "blade" : 2,
    "blunt" : 6,
    "flail" : 2,
    "knife" : 2,
    "projectile" : 2,
    "ranged" : 2,
    "bargaining" : 6,
    "perception" : 8,
    "conjuring" : 9,
    "magic attack" : 12,
    "magic defense" : 8,
  ]),
  "sorceror" : ([
    "conjuring" : 8,
    "psionics" : 12,
  ]),
  "necromancer" : ([
    "necromancy" : 12,
  ]),
  "pyromancer" : ([
    "conjuring" : 8,
    "magic attack" : 11,
    "pyromancy" : 12,
  ]),
  "wizard" : ([
    "magic attack" : 10,
    "wizardry" : 12,
  ]),
  "conjurer" : ([
    "conjuring" : 12,
    "magic attack" : 8,
    "attack" : 6,
    "blade" : 7,
    "blunt" : 8,
    "knife" : 7,
  ]),
  "illusionist" : ([
    "conjuring" : 5,
    "magic attack" : 8,
    "illusion" : 12,
  ]),

  "elementalist" : ([
    "attack" : 4,
    "defense" : 6,
    "double wielding" : 2,
    "melee" : 4,
    "axe" : 4,
    "blade" : 4,
    "blunt" : 4,
    "flail" : 4,
    "knife" : 4,
    "projectile" : 4,
    "ranged" : 4,
    "bargaining" : 7,
    "perception" : 6,
  ]),
  "geomancer" : ([
    "attack" : 6,
    "melee" : 6,
    "blunt" : 6,
    "geomancy" : 12,
    "magic attack" : 6,
    "magic defense" : 8,
    "nature" : 7,
  ]),
  "aeromancer" : ([
    "projectile" : 6,
    "ranged" : 6,
    "aeromancy" : 12,
    "magic attack" : 9,
    "magic defense" : 7,
    "nature" : 6,
  ]),
  "aquamancer" : ([
    "defense" : 8,
    "flail" : 6,
    "aquamancy" : 12,
    "conjuring" : 5,
    "healing" : 9,
    "magic defense" : 9,
  ]),
  /*
  "pyromancer" : ([
    "blade" : 6,
    "knife" : 6,
    "conjuring" : 5,
    "magic attack" : 11,
    "magic defense" : 7,
    "pyromancy" : 12,
  ]),
  */

  "clergy" : ([
    "attack" : 4,
    "defense" : 6,
    "double wielding" : 2,
    "melee" : 4,
    "axe" : 2,
    "blade" : 2,
    "blunt" : 4,
    "flail" : 4,
    "knife" : 4,
    "projectile" : 4,
    "ranged" : 2,
    "bargaining" : 5,
    "perception" : 8,
    "faith" : 12,
  ]),
  "monk" : ([
    "attack" : 10,
    "defense" : 10,
    "melee" : 12,
    "healing" : 5,
    "magic defense" : 6,
  ]),
  "cleric" : ([
    "belief" : 12,
    "conjuring" : 6,
    "healing" : 12,
    "magic defense" : 10,
  ]),
  "kataan" : ([
    "attack" : 8,
    "defense" : 8,
    "projectile" : 12,
    "stealth" : 6,
    "magic attack" : 10,
    "magic defense" : 3,
    "summoning" : 12,
  ]),
  "druid" : ([
    "melee" : 6,
    "blunt" : 8,
    "conjuring" : 6,
    "magic attack" : 8,
    "magic defense" : 12,
    "nature" : 12,
  ]),
  "shaman" : ([
    "attack" : 6,
    "double wielding" : 4,
    "axe" : 6,
    "ranged" : 8,
    "healing" : 6,
    "magic attack" : 6,
    "magic defense" : 6,
    "nature" : 6,
  ]),

  "dragon" : ([
    "attack" : 9,
    "defense" : 12,
    "melee" : 10,
    "breath" : 10,
    "claw" : 10,
    "tail" : 10,
    "bargaining" : 5,
    "flying" : 7,
    "perception" : 8,
  ]),
  "black" : ([
    "conjuring" : 8,
    "magic attack" : 10,
    "magic defense" : 6,
    "wizardry" : 10,
    "claw" : 9,
    "tail" : 9,
  ]),
  "red" : ([
    "attack" : 11,
    "defense" : 13,
    "melee" : 11,
    "ferocity" : 10,
  ]),
  "white" : ([
    "conjuring" : 7,
    "faith" : 10,
    "magic attack" : 6,
    "magic defense" : 8,
  ]),
  "blue" : ([
    "flying" : 4,
    "conjuring" : 6,
    "faith" : 10,
    "healing" : 9,
    "magic defense" : 8,
    "claw" : 9,
    "tail" : 9,
  ]),

  "vampire" : ([
    "attack" : 11,
    "defense" : 9,
    "double wielding" : 6,
    "melee" : 11,
    "axe" : 4,
    "blade" : 8,
    "blunt" : 7,
    "flail" : 6,
    "knife" : 8,
    "projectile" : 4,
    "ranged" : 4,
    "agility" : 8,
    "bargaining" : 5,
    "ferocity" : 9,
    "flying" : 8,
    "perception" : 12,
    "stealth" : 7,
    "necromancy" : 9,
    "illusion" : 8,
  ]),

  // 'child' is before you join a class
  "child" : ([
    "attack" : 8,
    "defense" : 8,
    "double wielding" : 8,
    "melee" : 8,
    "axe" : 8,
    "blade" : 8,
    "blunt" : 8,
    "flail" : 8,
    "knife" : 8,
    "projectile" : 8,
    "ranged" : 8,
    "bargaining" : 2,
    "perception" : 4,
  ]),
]);
// anything not defined here will automatically start maxed
mapping skillstarts = ([
  "ranger" : ([
    "stealth" : 0,
  ]),
  "rogue" : ([
    "double wielding" : 3,
    "axe" : 0,
    "blade" : 0,
    "blunt" : 2,
    "flail" : 0,
    "projectile" : 0,
    "ranged" : 0,
  ]),
  "scout" : ([
    "double wielding" : 6,
    "ranged" : 0,
  ]),
  "thug" : ([
    "blunt" : 5,
  ]),
  "wanderer" : ([
    "axe" : 0,
    "flail" : 0,
    "ranged" : 0,
  ]),
  "jester" : ([
    "stealth" : 0,
  ]),
  "mage" : ([
    "attack" : 0,
    "defense" : 1,
    "double wielding" : 0,
    "melee" : 0,
    "axe" : 0,
    "blade" : 0,
    "flail" : 0,
    "knife" : 0,
    "projectile" : 0,
    "ranged" : 0,
  ]),
  "illusionist" : ([
    "conjuring" : 0,
  ]),
  "elementalist" : ([
    "attack" : 0,
    "double wielding" : 0,
    "melee" : 0,
    "axe" : 0,
    "blade" : 0,
    "blunt" : 0,
    "flail" : 0,
    "knife" : 0,
    "projectile" : 0,
    "ranged" : 0,
  ]),
  "geomancer" : ([
    "attack" : 3,
    "melee" : 3,
    "blunt" : 3,
  ]),
  "aeromancer" : ([
    "projectile" : 3,
    "ranged" : 3,
  ]),

  "aquamancer" : ([
    "flail" : 3,
  ]),
  /*
  "pyromancer" : ([
    "blade" : 3,
    "knife" : 3,
  ]),
  */

  "clergy" : ([
    "double wielding" : 0,
    "axe" : 0,
    "blade" : 0,
    "blunt" : 0,
    "flail" : 0,
    "knife" : 0,
    "projectile" : 0,
    "ranged" : 0,
    "bargaining" : 0
  ]),
  "kataan" : ([
    "projectile" : 6,
    "stealth" : 0,
  ]),
  "druid" : ([
    "melee" : 0,
    "blunt" : 2,
  ]),
  "child" : ([
    "attack" : 1,
    "defense" : 1,
    "double wielding" : 0,
    "melee" : 1,
    "axe" : 0,
    "blade" : 0,
    "blunt" : 0,
    "flail" : 0,
    "knife" : 0,
    "projectile" : 0,
    "ranged" : 0,
    "bargaining" : 0,
  ]),
]);

function squared = (: ($1 * $1) :);
function squaredD3 = (: evaluate($(squared), $1)/3 :);
function squaredD2 = (: evaluate($(squared), $1)/2 :);
function squaredX3D2 = (: evaluate($(squared), $1)*3/2 :);
function squaredX2 = (: evaluate($(squared), $1)*2 :);
function squaredX5D2 = (: evaluate($(squared), $1)*5/2 :);
function squaredX3 = (: evaluate($(squared), $1)*3 :);
function squaredX4 = (: evaluate($(squared), $1)*4 :);
function squaredX5 = (: evaluate($(squared), $1)*5 :);
function squaredX6 = (: evaluate($(squared), $1)*6 :);
function squaredX7 = (: evaluate($(squared), $1)*7 :);
function squaredX8 = (: evaluate($(squared), $1)*8 :);
function cubed = (: evaluate($(squared), $1)*$1 :);

// subclass overrides class
// cost is based on current skill level
// example: squaredX3D2 == skill level squared, then *3 and /2
mapping skillcosts = ([
  "fighter" : ([
    "attack" : squaredD2,
    "defense" : squared,
    "charging" : squaredX2,
    "melee" : squaredX2,
    "axe" : squaredX2,
    "blade" : squaredX2,
    "blunt" : squaredX2,
    "flail" : squaredX2,
    "knife" : squaredX2,
    "projectile" : squaredX2,
    "ranged" : squaredX2,
    "double wielding" : squaredX5D2,
    "riding" : squaredX5D2,
    "bargaining" : squaredX3,
    "perception" : squaredX3,
    "default" : cubed,
  ]),
  "antipaladin" : ([
    "attack" : squared,
    "blade" : squared,
    "ferocity" : squared,
    "faith" : squared,
    "charging" : squaredX3D2,
    "riding" : squaredX2,
    "flail" : squaredX2,
    "projectile" : squaredX2,
    "magic attack" : squaredX3,
    "magic defense" : squaredX3,
    "axe" : squaredX4,
    "blunt" : squaredX4,
    "knife" : squaredX4,
    "ranged" : squaredX4,
    "bargaining" : squaredX4,
    "perception" : squaredX4,
    "healing" : squaredX4,
  ]),
  "paladin" : ([
    "attack" : squared,
    "charging" : squared,
    "blade" : squared,
    "valor" : squared,
    "faith" : squared,
    "riding" : squaredX3D2,
    "blunt" : squaredX2,
    "projectile" : squaredX2,
    "healing" : squaredX3,
    "magic defense" : squaredX3,
    "axe" : squaredX4,
    "flail" : squaredX4,
    "knife" : squaredX4,
    "ranged" : squaredX4,
    "bargaining" : squaredX4,
    "perception" : squaredX4,
  ]),
  "berserker" : ([
    "rage" : squaredD2,
    "ferocity" : squaredD2,
    "melee" : squared,
    "axe" : squared,
    "blade" : squared,
    "defense" : squaredX3,
    "double wielding" : squaredX3,
  ]),
  "ranger" : ([
    "ranged" : squaredD2,
    "discipline" : squaredD2,
    "nature" : squaredD2,
    "melee" : squared,
    "blade" : squared,
    "projectile" : squared,
    "perception" : squared,
    "charging" : squaredX3D2,
    "riding" : squaredX2,
    "stealth" : squaredX3,
  ]),
  "warrior" : ([
    "axe" : squaredD2,
    "blade" : squaredD2,
    "blunt" : squaredD2,
    "flail" : squaredD2,
    "knife" : squaredD2,
    "projectile" : squaredD2,
    "discipline" : squared,
    "double wielding" : squaredX3D2,
  ]),

  "clergy" : ([
    "defense" : squared,
    "faith" : squared,
    "magic defense" : squared,
    "blunt" : squaredX2,
    "flail" : squaredX2,
    "magic attack" : squaredX2,
    "attack" : squaredX3,
    "bargaining" : squaredX4,
    "perception" : squaredX4,
    "knife" : squaredX8,
    "conjuring" : squaredX8,
    "default" : cubed,
  ]),
  "cleric" : ([
    "belief" : squaredD2,
    "healing" : squared,
  ]),
  "druid" : ([
    "nature" : squaredD3,
    "melee" : squaredX4,
  ]),
  "kataan" : ([
    "projectile" : squared,
    "summoning" : squared,
    "attack" : squaredX3D2,
    "stealth" : squaredX5,
    "bargaining" : squaredX8,
    "magic defense" : squaredX8,
  ]),
  "monk" : ([
    "attack" : squared,
    "melee" : squared,
    "projectile" : squared,
    "healing" : squaredX6,
  ]),
  "shaman" : ([
    "attack" : squaredX3D2,
    "axe" : squaredX3D2,
    "magic attack" : squaredX3D2,
    "ranged" : squaredX2,
    "healing" : squaredX3,
    "nature" : squaredX3,
  ]),

  "mage" : ([
    "conjuring" : squared,
    "magic attack" : squared,
    "magic defense" : squared,
    "perception" : squaredX3,
    "blunt" : squaredX4,
    "flail" : squaredX4,
    "knife" : squaredX4,
    "attack" : squaredX8,
    "bargaining" : squaredX8,
    "default" : cubed,
  ]),
  "necromancer" : ([
    "necromancy" : squaredD3,
  ]),
  "sorceror" : ([
    "psionics" : squaredD3,
  ]),
  "pyromancer" : ([
    "pyromancy" : squaredD3,
  ]),
  "wizard" : ([
    "wizardry" : squaredD3,
  ]),
  "conjurer" : ([
    "conjuring" : squaredD3,
    "magic attack" : squaredX3D2,
    "attack" : squaredX2,
    "blunt" : squaredX2,
    "blade" : squaredX5D2,
    "knife" : squaredX5D2,
  ]),
  "illusionist" : ([
    "illusion" : squaredD3,
    "conjuring" : squaredX3,
  ]),

  "elementalist" : ([
    "magic defense" : squaredX3D2,
    "conjuring" : squaredX2,
    "magic attack" : squaredX2,
    "nature" : squaredX3,
    "defense" : squaredX3,
    "perception" : squaredX3,
    "attack" : squaredX4,
    "melee" : squaredX5,
    "axe" : squaredX5,
    "blade" : squaredX5,
    "blunt" : squaredX5,
    "flail" : squaredX5,
    "knife" : squaredX5,
    "projectile" : squaredX5,
    "ranged" : squaredX5,
    "default" : cubed,
  ]),
  "geomancer" : ([
    "geomancy" : squaredD2,
    "attack" : squaredX2,
    "melee" : squaredX2,
    "blunt" : squaredX2,
  ]),
  "aeromancer" : ([
    "aeromancy" : squaredD2,
    "projectile" : squaredX2,
    "ranged" : squaredX2,
  ]),
  "aquamancer" : ([
    "aquamancy" : squaredD2,
    "flail" : squaredX2,
    "defense" : squaredX2,
    "healing" : squaredX2,
  ]),
  /*
  "pyromancer" : ([
    "pyromancy" : squaredD2,
    "blade" : squaredX2,
    "knife" : squaredX2,
  ]),
  */

  "wanderer" : ([
    "defense" : squaredD3,
    "attack" : squared,
    "bargaining" : squared,
    "entertainment" : squared,
    "euphony" : squared,
    "blade" : squaredX2,
    "blunt" : squaredX2,
    "knife" : squaredX2,
    "perception" : squaredX3,
    "melee" : squaredX4,
    "double wielding" : squaredX7,
    "default" : cubed,
  ]),
  "bard" : ([
    "bargaining" : squaredD3,
    "euphony" : squaredD3,
    "perception" : squaredD3,
    "attack" : squaredX2
  ]),
  "jester" : ([
    "blunt" : squaredD3,
    "entertainment" : squaredD3,
    "blade" : squaredX4,
    "stealth" : squaredX4,
  ]),
  "gypsy" : ([
    "clairvoyance" : squaredD3,
    "knife" : squared,
    "flail" : squaredX2,
    "blade" : squaredX4,
    "stealing" : squaredX4,
    "stealth" : squaredX4,
  ]),
  "swashbuckler" : ([
    "blade" : squaredD3,
    "attack" : squaredD2,
    "double wielding" : squaredX2,
  ]),

  "rogue" : ([
    "murder" : squaredD2,
    "stealth" : squaredD2,
    "attack" : squared,
    "knife" : squared,
    "bargaining" : squared,
    "locks" : squared,
    "stealing" : squared,
    "defense" : squaredX2,
    "double wielding" : squaredX4,
    "melee" : squaredX4,
    "perception" : squaredX4,
    "blade" : squaredX6,
    "blunt" : squaredX6,
    "agility" : squaredX6,
    "default" : cubed,
  ]),
  "assassin" : ([
    "double wielding" : squaredX2,
    "ranged" : squaredX3,
    "stealing" : squaredX2,
  ]),
  "scout" : ([
    "double wielding" : squaredD3,
    "knife" : squaredD3,
    "perception" : squaredD3,
    "murder" : squaredX2,
    "ranged" : squaredX3,
    "locks" : squaredX6,
    "stealing" : squaredX6,
  ]),
  "thief" : ([
    "stealing" : squaredD3,
    "agility" : squaredX2,
    "attack" : squaredX4,
    "murder" : squaredX4,
  ]),
  "thug" : ([
    "melee" : squaredD2,
    "blunt" : squared,
    "agility" : squaredX8,
  ]),

  "dragon" : ([
    "flying" : squared,
    "breath" : squared,
    "claw" : squared,
    "tail" : squared,
    "defense" : squared,
    "attack" : squaredX2,
    "melee" : squaredX2,
    "perception" : squaredX5,
    "bargaining" : squaredX8,
    "default" : cubed,
  ]),
  "black" : ([
    "magic attack" : squaredD3,
    "wizardry" : squaredD3,
    "conjuring" : squared,
    "magic defense" : squared,
    "claw" : squaredX3D2,
    "tail" : squaredX3D2,
  ]),
  "white" : ([
    "faith" : squaredD3,
    "magic defense" : squaredD3,
    "conjuring" : squared,
    "magic attack" : squaredX2,
  ]),
  "blue" : ([
    "faith" : squaredD3,
    "magic defense" : squaredD3,
    "conjuring" : squared,
    "healing" : squared,
    "claw" : squaredX3D2,
    "tail" : squaredX3D2,
    "flying" : squaredX6,
  ]),
  "red" : ([
    "melee" : squaredD3,
    "attack" : squared,
    "ferocity" : squaredX2,
  ]),

  "vampire" : ([
    "melee" : squaredD2,
    "ferocity" : squaredD2,
    "flying" : squaredD2,
    "attack" : squared,
    "perception" : squared,
    "defense" : squaredX2,
    "agility" : squaredX2,
    "stealth" : squaredX2,
    "necromancy" : squaredX2,
    "blade" : squaredX3,
    "knife" : squaredX3,
    "double wielding" : squaredX4,
    "blunt" : squaredX4,
    "illusion" : squaredX4,
    "axe" : squaredX7,
    "flail" : squaredX7,
    "projectile" : squaredX7,
    "ranged" : squaredX7,
    "bargaining" : squaredX7,
    "default" : cubed,
  ]),

  // 'child' is before you join a class
  "child" : ([
    "attack" : cubed,
    "defense" : cubed,
    "double wielding" : cubed,
    "melee" : cubed,
    "axe" : cubed,
    "blade" : cubed,
    "blunt" : cubed,
    "flail" : cubed,
    "knife" : cubed,
    "projectile" : cubed,
    "ranged" : cubed,
    "bargaining" : cubed,
    "perception" : cubed,
    "default" : cubed,
  ]),

]);

function times2 = (: $1 * 2 :);
function times5D2 = (: $1 * 5 / 2 :);
function times3 = (: $1 * 3 :);
function times4 = (: $1 * 4 :);

// will only be used for classless mobs
mapping skillmobs = ([
  "default" : times4,
  "melee" : times3,
  "bargaining" : times5D2,
  "magic defense" : times5D2,
  "agility" : times2,
]);

mapping specialmaxes(object tp, mapping skills) {
  string race = tp->query_body_type() || tp->query_race();

  if (tp->is_monster() && nullp(skills["flying"]) &&
      sizeof(regexp(tp->query_limbs(), " wing"))) {
    switch (race) {
      case "dragon":
      break; // handled by class skills
  
      case "imp":
      case "faerie":
      break; // cannot fly at this time
  
      default:
        skills["flying"] = ([ "level" :  tp->query_level() * 5 ]);
      break; // for things like birds, bats, griffins, etc
  
    }
  }

  if (RACE_D->query_rideable(race)) {
    if (tp->query_class() == "fighter")
      skills["charging"] = copy(skills["riding"]);
    map_delete(skills, "riding");
  }

  return skills;
}

mapping racemaxes(object tp, mapping skills) {
  string race = tp->query_body_type() || tp->query_race();
  string *rskills = RACE_D->query_race_skills(race);

  if (tp->is_monster()) {
    foreach (string sk in rskills) {
      skills[sk] = ([ "level" :  tp->query_level() * RACE_D->query_skill_max(sk, race) / 2 ]);
    }
  }
  else {
    foreach (string sk in rskills) {
      skills[sk] = ([
        "max" : RACE_D->query_skill_max(sk, race),
        "level" : RACE_D->query_skill_start(sk, race),
        "points" : 0,
      ]);
    }
  }

  return skills;
}

mixed specialcosts(object tp, string skill) {
  return 0;
}

mixed racecosts(object tp, string skill) {
  string race = tp->query_body_type() || tp->query_race();
  int cost = RACE_D->query_skill_cost(skill, race);

  if (cost)
    return (: $1 * $1 * $(cost) / 100 :);

  return 0;
}

#endif
