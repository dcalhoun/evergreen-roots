let str = ReasonReact.stringToElement;

/* TODO: Add additional API to bs-next */
module ActiveLink = {
  let component = ReasonReact.statelessComponent("ActiveLink");
  let make = _children => {
    ...component,
    render: _self => <div> (str("ActiveLink")) </div>,
  };
};

let component = ReasonReact.statelessComponent("Nav");

let make = _children => {
  let sNav = ReactDOMRe.Style.make(~fontFamily="sans-serif", ());
  {
    ...component,
    render: _self =>
      <nav style=sNav>
        <Next.Link href="/" prefetch=(Js.Boolean.to_js_boolean(true))>
          <a> (str("Home")) </a>
        </Next.Link>
        (str(" | "))
        <Next.Link href="/contact" prefetch=(Js.Boolean.to_js_boolean(true))>
          <a> (str("Contact")) </a>
        </Next.Link>
      </nav>,
  };
};
