let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Logo");

let make = (_children) => {
  ...component,
  render: (_self) => <Heading> (str("Evergreen Roots")) </Heading>
};
