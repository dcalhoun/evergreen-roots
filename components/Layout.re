let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Layout");

let make = children => {
  ...component,
  render: _self =>
    <div>
      <Logo />
      <Nav />
      (
        ReasonReact.createDomElement(
          "div",
          ~props={"className": ""},
          children,
        )
      )
    </div>,
};
