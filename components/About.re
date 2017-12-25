let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("About");

let make = (_children) => {
  let sBody = ReactDOMRe.Style.make(~fontFamily="sans-serif", ());
  {
    ...component,
    render: (_self) =>
      <div style=sBody>
        (str("Beautiful, functional items sewn and stamped by hand."))
      </div>
  }
};
