type actions =
  | Add
  | Subtract;

let reducer = (state, action) =>
  switch (state, action) {
  | (s, Add) => s + 1
  | (0, Subtract) => 0
  | (s, Subtract) => s - 1
  };

let initialValue = 0;

[@react.component]
let make = _ => {
  open React;

  let (count, dispatch) = useReducer(reducer, initialValue);

  <main>
    <h1> "Mordwow"->string </h1>
    <h2> {("Count is: " ++ count->string_of_int)->string} </h2>
    <button onClick={_ => dispatch(Add)}> "+"->string </button>
    <button onClick={_ => dispatch(Subtract)}> "-"->string </button>
  </main>;
};
