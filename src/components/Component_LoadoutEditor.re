open Belt;
open Mordwow;

[@react.component]
let make = (~loadout: Loadout.t) =>
  React.(
    <div>
      <h1> loadout.name->string </h1>
      <h2>
        {(
           "Points Remaining: "
           ++ loadout->Loadout.getRemainingPoints->string_of_int
         )
         ->string}
      </h2>
      <h2> "Armor"->string </h2>
      <h3> "Head"->string </h3>
      {switch (loadout.headArmor) {
       | Some(Equipment.Wearable.Head.Head(cost)) =>
         <div> <p> {("Level: " ++ cost->string_of_int)->string} </p> </div>
       | None => "None"->string
       }}
      <h3> "Body"->string </h3>
      {switch (loadout.bodyArmor) {
       | Some(Equipment.Wearable.Body.Body(cost)) =>
         <div> <p> {("Level: " ++ cost->string_of_int)->string} </p> </div>
       | None => "None"->string
       }}
      <h3> "Legs"->string </h3>
      {switch (loadout.legArmor) {
       | Some(Equipment.Wearable.Leg.Leg(cost)) =>
         <div> <p> {("Level: " ++ cost->string_of_int)->string} </p> </div>
       | None => "None"->string
       }}
      <h2> "Equipment"->string </h2>
      <ul>
        {[loadout.equipment1, loadout.equipment2, loadout.equipment3]
         ->List.map(eq =>
             switch (eq) {
             | Some(eq) =>
               <li key={eq->Equipment.Holdable.getName}>
                 <h3> {eq->Equipment.Holdable.getName->string} </h3>
                 <p>
                   {("Cost: " ++ eq->Equipment.Holdable.getCost->string_of_int)
                    ->string}
                 </p>
               </li>
             | None => null
             }
           )
         ->List.toArray
         ->array}
      </ul>
      <h2> "Perks"->string </h2>
      <ul>
        {loadout.perks
         ->List.map(p =>
             <li key={p.name}>
               <h3> p.name->string </h3>
               <p> {("Cost: " ++ p.cost->string_of_int)->string} </p>
             </li>
           )
         ->List.toArray
         ->array}
      </ul>
    </div>
  );
