let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Heading");

let make = (~priority=1, ~scale=priority, children) => {
  let typeScale = ["2rem", "1.5rem", "1rem", ".875rem"];
  let sHeading =
    ReactDOMRe.Style.make(
      ~fontFamily="sans-serif",
      ~fontSize=List.nth(typeScale, scale - 1),
      ()
    );
  let tag =
    switch priority {
    | 1 => "h1"
    | 2 => "h2"
    | 3 => "h3"
    | 4 => "h4"
    | 5 => "h5"
    | 6 => "h6"
    | _ => "h1"
    };
  {
    ...component,
    render: (_self) =>
      ReasonReact.createDomElement(tag, ~props={"style": sHeading}, children)
  }
};
