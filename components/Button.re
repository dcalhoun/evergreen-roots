let component = ReasonReact.statelessComponent("Button");

let make = (~_type="button", ~onClick=() => (), children) => {
  ...component,
  render: (_self) =>
    ReasonReact.createDomElement(
      "button",
      ~props={"onClick": onClick, "type": _type},
      children
    )
};
