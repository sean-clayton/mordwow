module Cost = Mordwow_Cost;

type metadata = {
  name: string,
  description: string,
  cost: Cost.t,
};

module Wearable = {
  module Head = {
    type t =
      | Head(metadata);

    let getCost = (Head({cost})) => cost;
  };

  module Body = {
    type t =
      | Body(metadata);

    let getCost = (Body({cost})) => cost;
  };

  module Leg = {
    type t =
      | Leg(metadata);

    let getCost = (Leg({cost})) => cost;
  };
};

module Holdable = {
  module Damage = {
    type armorDamage = (int, int, int, int);
    type t = {
      headDamage: armorDamage,
      bodyDamage: armorDamage,
      legDamage: armorDamage,
    };
  };

  module MeleeWeaponSpeed = {
    type t = {
      windup: int,
      combo: int,
      release: int,
      recovery: int,
    };
  };

  module MeleeWeapon = {
    type blockViewTolerances = {
      up: int,
      leftRight: int,
      down: int,
    };

    type turnCap = {
      x: int,
      y: int,
    };

    type base = {
      damage: Damage.t,
      speed: MeleeWeaponSpeed.t,
      blockViewTolerances,
      turnCap,
      missCost: int,
      feintCost: int,
      staminaDrain: int,
      parryDrainNegation: int,
      stopOnHit: bool,
      canCombo: bool,
      hitKnockback: int,
      woodDamage: int,
      length: int,
    };

    type strike = base;
    type thrust = base;

    type t = {
      strike,
      thrust,
    };
  };

  module RangedWeaponSpeed = {
    type t = {
      draw: int,
      reload: int,
    };
  };

  module RangedWeapon = {
    type t = {
      damage: Damage.t,
      speed: RangedWeaponSpeed.t,
      projectileSpeed: int,
      maxAmmo: int,
    };
  };

  module ThrowableMeleeWeapon = {
    type t = {
      meleeStats: MeleeWeapon.t,
      throw: RangedWeapon.t,
    };
  };

  module OneHanded = {
    type t = {
      meleeStats: MeleeWeapon.t,
      altStats: option(MeleeWeapon.t),
    };
  };

  module TwoHanded = {
    type t = {
      meleeStats: MeleeWeapon.t,
      altStats: option(MeleeWeapon.t),
    };
  };

  module ThrowableOneHanded = {
    type t = {
      meleeStats: MeleeWeapon.t,
      throwDamage: Damage.t,
    };
  };

  module ThrowableTwoHanded = {
    type t = {
      meleeStats: MeleeWeapon.t,
      throwDamage: Damage.t,
    };
  };

  module Ranged = {
    type t = RangedWeapon.t;
  };

  module Throwable = {
    type t = RangedWeapon.t;
  };

  module Consumable = {
    type t =
      | Consumable;
  };

  type t =
    | OneHanded(metadata, OneHanded.t)
    | TwoHanded(metadata, TwoHanded.t)
    | ThrowableOneHanded(metadata, ThrowableOneHanded.t)
    | ThrowableTwoHanded(metadata, ThrowableTwoHanded.t)
    | Ranged(metadata, Ranged.t)
    | Throwable(metadata, Throwable.t)
    | Consumable(metadata, Consumable.t);

  let getCost = weapon =>
    switch (weapon) {
    | OneHanded({cost}, _) => cost
    | TwoHanded({cost}, _) => cost
    | ThrowableOneHanded({cost}, _) => cost
    | ThrowableTwoHanded({cost}, _) => cost
    | Ranged({cost}, _) => cost
    | Throwable({cost}, _) => cost
    | Consumable({cost}, _) => cost
    };
};
