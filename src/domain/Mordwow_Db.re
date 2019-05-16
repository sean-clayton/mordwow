module Equipment = Mordwow_Equipment;
module Perk = Mordwow_Perk;

module Config = {
  let url = "/db.json";
};

type t = {
  equipment: list(Equipment.Holdable.t),
  perks: list(Perk.t),
};

let make = (~equipment, ~perks) => {equipment, perks};

let fetchRemote = () => Config.url;
