open Belt;
module Equipment = Mordwow_Equipment;
module Perk = Mordwow_Perk;
module Cost = Mordwow_Cost;

let maxLoadoutCost = 16;

type t = {
  name: string,
  headArmor: option(Equipment.Wearable.Head.t),
  bodyArmor: option(Equipment.Wearable.Body.t),
  legArmor: option(Equipment.Wearable.Leg.t),
  equipment1: option(Equipment.Holdable.t),
  equipment2: option(Equipment.Holdable.t),
  equipment3: option(Equipment.Holdable.t),
  perks: list(Perk.t),
};

let empty = {
  name: "New Loadout",
  headArmor: None,
  bodyArmor: None,
  legArmor: None,
  equipment1: None,
  equipment2: None,
  equipment3: None,
  perks: [],
};

let getTotalCost = loadout => {
  let headCost =
    switch (loadout.headArmor) {
    | Some(armor) => armor->Equipment.Wearable.Head.getCost
    | None => 0
    };

  let bodyCost =
    switch (loadout.bodyArmor) {
    | Some(armor) => armor->Equipment.Wearable.Body.getCost
    | None => 0
    };

  let legCost =
    switch (loadout.legArmor) {
    | Some(armor) => armor->Equipment.Wearable.Leg.getCost
    | None => 0
    };

  let equipmentCost =
    [loadout.equipment1, loadout.equipment2, loadout.equipment3]
    ->List.reduce(0, (acc, eq) =>
        switch (eq) {
        | Some(equipment) => acc + equipment->Equipment.Holdable.getCost
        | None => 0
        }
      );

  let perksCost = loadout.perks->List.reduce(0, (acc, {cost}) => acc + cost);

  headCost + bodyCost + legCost + equipmentCost + perksCost;
};

let getRemainingPoints = loadout => maxLoadoutCost - loadout->getTotalCost;

let isValid = unvalidatedLoadout =>
  switch (unvalidatedLoadout) {
  | {name: ""} => false
  | loadout when loadout->getTotalCost > maxLoadoutCost => false
  | _ => true
  };
