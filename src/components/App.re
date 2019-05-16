module Styles = {
  open Css;

  let main = style([flex(1)]);
};

[@react.component]
let make = () =>
  React.(
    <main className=Styles.main>
      <Components.LoadoutEditor loadout=Mordwow.Loadout.empty />
    </main>
  );
