let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Heading");

let make = (~priority=1, ~scale=priority, ~tagless=false, children) => {
  let typeScale = ["2rem", "1.5rem", "1rem", ".875rem"];
  let sHeading =
    ReactDOMRe.Style.make(
      ~fontFamily="sans-serif",
      ~fontSize=List.nth(typeScale, scale - 1),
      ()
    );
  let tag =
    switch (priority, tagless) {
    | (_, true) => "div"
    | (1, false) => "h1"
    | (2, false) => "h2"
    | (3, false) => "h3"
    | (4, false) => "h4"
    | (5, false) => "h5"
    | (6, false) => "h6"
    | (_, false) => "h1"
    };
  {
    ...component,
    render: (_self) =>
      ReasonReact.createDomElement(tag, ~props={"style": sHeading}, children)
  }
};
