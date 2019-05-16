type t = int;

type make = int => t;
let make = value => value;

type toInt = t => int;
let toInt = cost => cost;

type toString = t => string;
let toString = cost => cost->string_of_int;
