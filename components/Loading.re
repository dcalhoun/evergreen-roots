let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Loading");

let make = (_children) => {
  let sLoading =
    ReactDOMRe.Style.make(~fontFamily="sans-serif", ~textAlign="center", ());
  {
    ...component,
    render: (_self) => <div style=sLoading> (str("Loading...")) </div>
  }
};
