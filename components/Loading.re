let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Loading");

let make = (_children) => {
  ...component,
  render: (_self) => <div> (str("Loading...")) </div>
};
