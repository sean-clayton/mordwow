type t = int;

type make = int => t;
let make = value => value;

type toInt = t => int;
let toInt = cost => cost;
