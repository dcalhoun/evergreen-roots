let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("About");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div> (str("Beautiful, functional items sewn and stamped by hand.")) </div>
};
