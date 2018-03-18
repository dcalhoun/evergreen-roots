let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Layout");

let make = children => {
  ...component,
  render: _self =>
    <div> <Logo /> <Nav /> (ReasonReact.arrayToElement(children)) </div>,
};
