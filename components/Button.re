let component = ReasonReact.statelessComponent("Button");

let make = (~_type="button", ~onClick=(_event) => (), children) => {
  let sButton =
    ReactDOMRe.Style.make(
      ~border="1px solid #ccc",
      ~borderRadius="3px",
      ~fontFamily="sans-serif",
      ~fontSize="1rem",
      ~padding="1rem",
      ()
    );
  {
    ...component,
    render: (_self) =>
      <button _type onClick style=sButton>
        (ReasonReact.arrayToElement(children))
      </button>
    /* ReasonReact.createDomElement(
         "button",
         ~props={"onClick": onClick, "type": _type},
         children
       ) */
  }
};
